#include "vector.hpp"
#include "logger.hpp"

#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
#include <sstream>

namespace fmi{
namespace oop{
    
    Vector::Vector()
    {
        AutoLog;        // Чрез този логер може да се тества коя функция кога се извиква 

        data = new double[1];
        len = 1;
        data[0] = 0;
    }


    Vector::Vector(unsigned len)
    {
        AutoLog; 

        data = new double[len];
        this->len = len;
        memset(data, 0, len*sizeof(double));
    }

    Vector::Vector(const Vector& v)
    {
        AutoLog;

        copy(v.data, v.len);
    }

    Vector::Vector(const double* values, unsigned cnt)
    {
        AutoLog;

        copy(values, cnt);
    }

    Vector::~Vector()
    {
        AutoLog;

        clear();
    }

    Vector& Vector::operator=(const Vector& rhs)
    {
        AutoLog;

        if (this != &rhs)           // Задължителна проверка за самоприсвояване
        {
            clear();
            copy(rhs.data, rhs.len);
        }

        return *this;
    }


    Vector& Vector::operator+= (double value)
    {
        AutoLog;
        // Този оператор съдържа същинската логика за събирането
        extend();
        data[len++] = value;
        return *this;
    }

    Vector Vector::operator+(double value) const
    {
        AutoLog;
        // Този само използва горния. Забележете, че логиката е в += !
        Vector res(*this);
        res += value;
        return res;
    }

    Vector& Vector::operator+=(const Vector& rhs)
    {
        AutoLog;
        // Отново тук е логиката за събиране

        extend(rhs.len);
        for (unsigned i = 0; i < rhs.len; ++i)
            data[len + i] = rhs.data[i];
        len += rhs.len;

        return *this;
    }

    Vector operator+(const Vector& v1, const Vector& v2)
    {
        AutoLog;

        // А този работи аналогично на V + d, въпреки, че е външна функция
        Vector res(v1);
        res += v2;
        return res;
    }

    Vector& Vector::operator*=(double mul)
    {
        AutoLog;

        for (unsigned i = 0; i < len; ++i)
            data[i] *= mul;
        return *this;
    }

    Vector Vector::operator*(double mul) const
    {
        AutoLog;

        Vector res(*this);
        res *= mul;
        return res;
    }

    Vector operator* (double mul, const Vector& v)
    {
        AutoLog;
        // При лявото умножение може да се обърнем към лявото, поради комутативността
        return v*mul;
    }

    // Пример за оператор за делене, който използва реципрочно умножение
    Vector operator/(const Vector& v, double mul)
    {
        AutoLog;
        return v*(1/mul);
    }

    Vector& Vector::operator--()
    {
        AutoLog;
        // Имплементация на декрементирането
        // Логиката е в префиксния оператор. Това отново спестява излишно копиране
        if (len)
        {
            extend(-1);
            --len;
        }
        return *this;
    }

    Vector Vector::operator--(int)
    {
        AutoLog;

        Vector res(*this);
        --(*this);
        return res;
    }

    double& Vector::operator[](int index)
    {
        AutoLog;

        // Понеже връщаме по псевдоним няма как да се справим
        // с невалидни индекси, освен с изключение
        if (index < 0 || index >= (int)len)
            throw "Bad index!";

        return data[index];
    }

    double Vector::operator[](int index) const
    {
        AutoLog;
        // Тук връщаме по стойност и може да приемем, че 
        // вектора е допълнен с безкрайно много нули
        if (index < 0 || index >= (int)len)
            return 0;

        return data[index];
    }

    double Vector::operator()() const
    {
        AutoLog;

        double sum = 0;
        for (unsigned i = 0; i < len; ++i)
            sum += data[i] * data[i];

        return std::sqrt(sum);
    }

    void Vector::operator()(unsigned start, unsigned len)
    {
        AutoLog;
        
        // Проверка за валидност на началния индекс
        if (start >= this->len) throw "Bad start index!";
        
        // Ако дължината е прекалено голяма отрязваме до края на вектора
        if (start + len >= this->len)
            len = this->len - start - 1;
        
        // Заделяме памет в която да сложим отрязаните елементи
        double * tmpData = NULL;
        try
        {
            tmpData = new double[len];
        }
        catch (std::bad_alloc& ba)
        {
            // Ако няма памет за тази цел
            std::cerr << "No memory for splice ... \n";
            std::cerr << ba.what() << std::endl;
            // Преместваме данните в началото на масива
            // Така ще изпълним операцията, но ще остане неизползвана памет в края

            for (unsigned i = 0; i < len; ++i)
                data[i] = data[start + i];
            this->len = len;
            return;
        }

        for (unsigned i = 0; i < len; ++i)
            tmpData[i] = data[start + i];
        delete[] data;
        data = tmpData;
        this->len = len;
    }

    Vector::operator const char* () const
    {
        AutoLog;
        
        // За удобство използвам символен поток string stream
        // и предефинирания оператор << 
        std::stringstream res;
        res << *this;
        
        // Взимам получения стринг. За целта използвам статична променлива, 
        // защото връщания низ трябва да живее някъде. Това няма да е проблем в еднонишкова програма.
        static std::string tmp;
        tmp = res.str();
        return tmp.c_str();
    }

    bool Vector::operator==(const Vector& rhs) const
    {
        if (len != rhs.len) return false;
        for (unsigned i = 0; i < len; ++i)
            if (data[i] != rhs.data[i])
                return false;
        return true;
    }

    bool Vector::operator!= (const Vector& v2) const
    {
        return !(*this == v2);
    }


    ostream& operator << (ostream& out, const Vector& v)
    {
        AutoLog;

        out << "(";
        for (unsigned i = 0; i < v.len; ++i)
            out << v.data[i] << (i < v.len - 1 ? ", " : "");
        out << ")";
        return out;
    }

    istream& operator >> (istream& in, Vector& v)
    {
        AutoLog;

        char c;     // използвам за да прочитам ненужните символи - скоби и запетайки
        in >> c;    // прочита (
        
        for (unsigned i = 0; i < v.len; ++i)
        {
            in >> v.data[i];
            if (i < v.len - 1) in >> c;     // ако не е последен, прочита запетайката
        }
        in >> c;        // и накрая )
        return in;
    }

    void Vector::copy(const double* vals, unsigned size)
    {
        AutoLog;

        data = new double[size];
        for (unsigned i = 0; i < size; ++i)
            data[i] = vals[i];
        len = size;
    }

    void Vector::extend(int cnt)
    {
        assert(cnt + (int)len >= 0);
        
        AutoLog;
        
        if (cnt == 0) return;
        double* tmpData = new double[len + cnt];
        for (unsigned i = 0; i < len && i < len + cnt; ++i)
            tmpData[i] = data[i];
        
        delete[] data;
        data = tmpData;
    }


    // При тези оператори забеелжете как логиката е само в <
    // Всички останали я използват благодарение на свойствата на пълната наредба. (Учете ДС!)
    bool operator < (const Vector& v1, const Vector& v2)
    {
        return v1() < v2();
    }

    bool operator <= (const Vector& v1, const Vector& v2)
    {
        return !(v1 > v2);
    }

    bool operator > (const Vector& v1, const Vector& v2)
    {
        return v2 < v1;
    }

    bool operator >= (const Vector& v1, const Vector& v2)
    {
        return !(v1 < v2);
    }
}
}


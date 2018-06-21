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
        AutoLog;        // ���� ���� ����� ���� �� �� ������ ��� ������� ���� �� ������� 

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

        if (this != &rhs)           // ������������ �������� �� ���������������
        {
            clear();
            copy(rhs.data, rhs.len);
        }

        return *this;
    }


    Vector& Vector::operator+= (double value)
    {
        AutoLog;
        // ���� �������� ������� ���������� ������ �� ����������
        extend();
        data[len++] = value;
        return *this;
    }

    Vector Vector::operator+(double value) const
    {
        AutoLog;
        // ���� ���� �������� ������. ����������, �� �������� � � += !
        Vector res(*this);
        res += value;
        return res;
    }

    Vector& Vector::operator+=(const Vector& rhs)
    {
        AutoLog;
        // ������ ��� � �������� �� ��������

        extend(rhs.len);
        for (unsigned i = 0; i < rhs.len; ++i)
            data[len + i] = rhs.data[i];
        len += rhs.len;

        return *this;
    }

    Vector operator+(const Vector& v1, const Vector& v2)
    {
        AutoLog;

        // � ���� ������ ���������� �� V + d, �������, �� � ������ �������
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
        // ��� ������ ��������� ���� �� �� ������� ��� ������, ������ ���������������
        return v*mul;
    }

    // ������ �� �������� �� ������, ����� �������� ���������� ���������
    Vector operator/(const Vector& v, double mul)
    {
        AutoLog;
        return v*(1/mul);
    }

    Vector& Vector::operator--()
    {
        AutoLog;
        // ������������� �� ����������������
        // �������� � � ���������� ��������. ���� ������ �������� ������� ��������
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

        // ������ ������� �� ��������� ���� ��� �� �� �������
        // � ��������� �������, ����� � ����������
        if (index < 0 || index >= (int)len)
            throw "Bad index!";

        return data[index];
    }

    double Vector::operator[](int index) const
    {
        AutoLog;
        // ��� ������� �� �������� � ���� �� �������, �� 
        // ������� � �������� � ��������� ����� ����
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
        
        // �������� �� ��������� �� �������� ������
        if (start >= this->len) throw "Bad start index!";
        
        // ��� ��������� � ��������� ������ ��������� �� ���� �� �������
        if (start + len >= this->len)
            len = this->len - start - 1;
        
        // �������� ����� � ����� �� ������ ���������� ��������
        double * tmpData = NULL;
        try
        {
            tmpData = new double[len];
        }
        catch (std::bad_alloc& ba)
        {
            // ��� ���� ����� �� ���� ���
            std::cerr << "No memory for splice ... \n";
            std::cerr << ba.what() << std::endl;
            // ����������� ������� � �������� �� ������
            // ���� �� �������� ����������, �� �� ������ ������������ ����� � ����

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
        
        // �� �������� ��������� �������� ����� string stream
        // � �������������� �������� << 
        std::stringstream res;
        res << *this;
        
        // ������ ��������� ������. �� ����� ��������� �������� ����������, 
        // ������ �������� ��� ������ �� ����� ������. ���� ���� �� � ������� � ����������� ��������.
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

        char c;     // ��������� �� �� �������� ��������� ������� - ����� � ���������
        in >> c;    // ������� (
        
        for (unsigned i = 0; i < v.len; ++i)
        {
            in >> v.data[i];
            if (i < v.len - 1) in >> c;     // ��� �� � ��������, ������� �����������
        }
        in >> c;        // � ������ )
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


    // ��� ���� ��������� ���������� ��� �������� � ���� � <
    // ������ �������� � ��������� ������������ �� ���������� �� ������� �������. (����� ��!)
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


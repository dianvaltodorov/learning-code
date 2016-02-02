#include <iostream>

using namespace std;

class Fibonachi
{
private:
    int MaxSize;
    unsigned long long *Calculated;
public:
    Fibbonachi(int MaxSize);
    ~Fibbonachi();
    unsigned long long GetNth(int n);
    unsigned long long operator()(int n);

private:
    void Generate();
};

Fibbonachi::Fibbonachi(int MaxSize)
{
    if(MaxSize < 2)
        throw std::exception();
    try
    {
        Calculated = new unsigned long long[MaxSize];
    }
    catch(std::bad_alloc &e)
    {

    }

    this->MaxSize = MaxSize;
    Generate();
}


Fibbonachi::~Fibbonachi(int MaxSize)
{
   delete[] Calculated;
}

void Fibbonachi::Generate()
{
    for(int i = 2; i < maxSize; i++)
    {
        Calculated[i] = Calculated[i - 1] + Calculated[i - 2];
    }
}


unsigned long long Fibbonachi::operator()(int n)
{

}

class Rational
{
private:
    int numerator;
    int denominator;
public:
    Rational(int numerator, int denominator);
public:
    void Add(Rational const r);
    Rational Sum(Rational const r);
    Rational operator+(Rational const r);
    void operator +=(int n);
    void operator +=(Rational n);
    void operator +(int n);
    void operator +(Rational r);
    int GetNumerator() const;
    void SetNumerator(int numerator);
    int GetDenominator() const;
    void SetDenominator(int denominator);
    float toFloat();
    double toDouble();
};

Rational::Rational(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = numerator;
}
int Rational::GetNumerator() const
{
    return this->numerator;
}
void Rational::SetNumerator(int numerator)
{
    this->numerator = numerator;
}

int Rational::GetDenominator() const
{
    return this->denominator;
}
void Rational::SetDenominator(int denominator)
{
    this->denominator = denominator;
}

void Rational::Add(Rational const r)
{
    SetNumerator(GetNumerator() * r.GetDenominator()+  GetDenominator()*r.GetNumerator());
    SetDenominator(GetDenominator() * r.GetDenominator());
}

//Global function
int operator+(int x, Rational r)
{
    return (x * r.GetDenominator() + r.GetDenominator());
}

//Global function, I have no access to this code. I cannot do it
operator::ostream& operator<<(std::ostream&out, Rational c)
{

}


Rational Rational::Sum(Rational const r)
{
    Rational temp(r);
    temp.Add(*this);
    return temp; //  връщаме копие и тя умира. Ако беше с псевдоним, щяхме да върнем указател към нищо, тогава щеше да е със
}

Rational Rational::operator+(Rational const r)
{
   Rational temp(r);
   temp.operator+=(r);
}

Rational::Rational();

int main(int argc, char *argv[])
{
    Rational oneThird(1,3);
    Rational oneFourth(1,3);
    Rational oneFifth(1,5);

    oneThird.Sum(oneFourth);

    Rational sum = oneThird + oneFourth;
    Rational sum = oneThird.Sum(oneFourth);
    Rational sum = oneThird.operator+(OneFourth);

    int x = 5 + 6;
    cout << "Hello World!" << endl;
    (((cout << 1) << 2) << 3); // ляво асоциатевен, първо се извършва това от ляво.

    int x = OneThird; // calls the function operator int
    double x = oneThird // calls the functiO

    cout << OneThird << endl;
//=======================================

    Fibbonachi fib = Fibbonachi(10);
    cout << fib.GetNth(10);
    cout << fib(50) <<endl;

    try
    {
        Fibbonachi fib(0);
    } catch(std::exception & e) // има амперсанд, защото се започваме да се връщане назад по паметта в кол стека. Ловим по псевдном
    {
        sdt::cerr<< "caithy an exception: " << e.what() << "\n";
    }

    return 0;
}

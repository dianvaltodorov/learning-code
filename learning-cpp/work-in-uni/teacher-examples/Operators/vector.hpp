/* �������� ��� �� ������������ �� ������������� �� ���������� ������� 
 ���, ��� 2016
*/
#ifndef __VECTOR_HEADER_INCLUDED_
#define __VECTOR_HEADER_INCLUDED_

#include <iostream>
using std::istream;
using std::ostream;

namespace fmi{
namespace oop{

    // �� ����� �� ������� �� ���������� ���� ������, ����� �� ��� ����� 
    // �������� �� ������������ ������� � ����� �� ����������� ������
    class Vector
    {
        // ��������� �� ���� � ����� - ���-������� ������ �� ���������� ���������
        friend ostream& operator << (ostream& out, const Vector& v);
        friend istream& operator >> (istream& in, Vector& v);

    public:
        //////////////
        //�4

        // �������� ������������
        Vector();                         // ������� ������ � ���� ������� - 0
        explicit Vector(unsigned d);      // ������� ������ � ��������� ���� �������� � ��������� 0
        Vector(const Vector& v);          // ������� �����������
        Vector(const double* data, unsigned len); // ������� ������ �� ������� ����� �� ����������
        
        ~Vector();

        Vector& operator= (const Vector& rhs);
        //////////////

        //��������� �� �������� � ����� - ������� ������� � ���� �� �������
        Vector  operator+ (double d) const;     // V + d ������� ��� ����� - ���������� � �����
        Vector& operator+= (double d);          // V += d 

        Vector& operator+= (const Vector& v);   // ����������� ��� ������� V += V

        // ������������� ������ � �����
        Vector  operator* (double d) const;
        Vector& operator*= (double d);

        // ��������� �� �������������� - ��������� ������������� ����� �������
        bool operator== (const Vector& rhs) const;
        bool operator!= (const Vector& rhs) const;


        // �������� �� �������������� - �������� ��������� �������, ��� ��� �����
        Vector& operator-- ();   // --V 
        Vector  operator-- (int); // V-- ���������� ��������� ��������, ����� � ��������� ������!

        // ��������� �� �����������
        double& operator[] (int index);        // ����� �������� �� ��������� - ���������� �� ������� (l-value)
        double  operator[] (int index) const;  // ����� �������� �� �������� - �� ��������� ������� �� ������. 

        // ��������� () (������������ ���������)
        double operator() () const;             // ����� ����� �� ������� (����� �� �������� �������)
        void   operator() (unsigned start, unsigned len);  // ������� ������� �� ����� � �������� ������ � �������
        
        operator const char* () const;      // ������������� ��� ������

        unsigned length() const { return len; } // ���������� �� �������

    protected: 
        // ����� ������� �������

        double* getData() { return data; } // ������ �� �������� �����
        void clear() { delete[] data; }    // ������� ��������� �������� �� ������

        void copy(const double* vals, unsigned size);   // ������ ������� � �� ������������� �����.

        void extend(int cnt = 1);   // ������� ������� �� ������� � ���������� �����. ��������� ����������� � �������

    private:
        double * data;
        unsigned len;
    };

    // ������ ���������� �������

    Vector operator + (const Vector& v1, const Vector& v2); // ������������ V+V
    Vector operator * (double mul, const Vector& v);        // ���� ���������: d*V

    // ����� ��������� �� ������� - ��������� �� ��������� �� �����.
    // ��������� � �����.
    bool operator <  (const Vector& v1, const Vector& v2);
    bool operator <= (const Vector& v1, const Vector& v2);
    bool operator >  (const Vector& v1, const Vector& v2);
    bool operator >= (const Vector& v1, const Vector& v2);

} // oop
} // fmi

#endif //__VECTOR_HEADER_INCLUDED_
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<ctype.h>
unsigned n, m;
const double EPS = 1e-20;

int p[12];

void input()
{
    scanf("%d ", &m);
    for(int i = 0; i <= m; i++)
    {
        scanf("%d", &p[i]);
    }
}

double f(double x)
{
    double res=0.0f;
    for(int i = 0; i <= m; i++)
   {
        res = res * x + p[i];
    }

    return res;
}

// double ternarySearch(double left,double right)
// {
//     double leftThird ;
//     double rightThird;
//     while(fabs(f(right) - f(left)) < epsilon)
//     {
//         //printf("left = %lf , leftthird = %lf, rightthird = %lf right = %lf\n", left, leftThird, rightThird, right);
//
//         printf("left = %lf, right = %lf\n", left, right);
//         leftThird = left + (right - left)/3;
//         rightThird = right - (right - left)/3;
//
//         printf("L: f(%lf) = %lf ", leftThird, f(leftThird));
//         printf("R: f(%lf) = %lf\n\n", rightThird, f(rightThird));
//
//
//         if(f(leftThird)  > f(rightThird))
//             left = leftThird;
//         else
//             right = rightThird;
//
//         if(fabs(f(right) - f(left)) < epsilon)
//         {
//                 printf("XXXXXXXXXxXXXXXXXXXX%.9lf %.9lf %.9lf\n", f(right) , f(left) , f(right) - f(left));
//                 return left;
//         }
//     }
// }

double ternarySearch(double left, double right)
{
  double leftThird, rightThird;
  while (1)
  {
      if(right - left < EPS)
        return (left + right)/2;

    leftThird = left + (right - left)/3;
    rightThird = right - (right - left)/3;
    printf("left = %.9lf, right = %.9lf, leftThird = %.9lf rightThird = %.9lf\n", left, right, leftThird, rightThird);

    if (f(leftThird) > f(rightThird))
        left = leftThird;
    else
        right = rightThird;
  }
}
//
// double ternarySearch(double l, double r)
// {
//
//     while (r - l > EPS)
//     {
//       double m1 = l + (r - l) / 3,  m2 = r - (r - l) / 3;
//       printf("l = %lf, r = %lf, m1 = %lf m2 = %lf\n", l, r, m1, m2);
//       if (f (m1) < f (m2))
//         l = m1;
//       else
//         r = m2;
//     }
//     return r;
// }


int main()
{
    scanf("%d", &n);
    for(unsigned i = 1; i <= n ; i++)
    {
        input();
        printf("%.9lf\n", ternarySearch(-100.0f, 100.0f));
    }
    return 0;
}

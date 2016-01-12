#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;
stack<int> numbers;
int main ()
{
    int a;
    while(scanf("%d", &a))
    {
        numbers.push(a);
    }

    while (!numbers.empty())
    {
     printf("%lf\n", sqrt(numbers.top()));
     numbers.pop();
    }
    return 0;
}


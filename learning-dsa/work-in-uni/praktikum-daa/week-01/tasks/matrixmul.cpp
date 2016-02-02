#include<stdio.h>
/*
//MxN
const int a[20][20]=
{
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16},
    {17, 18, 19, 20}
};

//NxK
const int b[20][20]= {
    {-1, -3, -5},
    {6, 7, 19},
    {2, 4, 10},
    {2, 56, 5 }};

const int m = 5;
const int n = 4;
const int k = 3;


/*
//MxN
const int a[20][20]=
{
    {1, 2, 3},
    {4, 5, 6}
};

//NxK
const int b[20][20]= {
    {7, 8},
    {9, 10},
    {11, 12}
};

const int m = 2;
const int n = 3;
const int k = 2;
*/
//MxK
long long a[20][20]; //MxN
long long b[20][20]; //NxK
long long c[20][20]; //MxK
int main()
{
    unsigned i, j;
    unsigned m, n, k;
    scanf("%u%u%u",&m, &n, &k);

    for(i = 0; i < m; i++ )
    {
      for(j = 0 ; j < n; j++ )
        {
          scanf("%lld",&a[i][j]);
        }
    }

    for(i = 0; i < n; i++ )
    {
      for(j = 0 ; j < k; j++ )
        {
          scanf("%lld",&b[i][j]);
        }
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < k; j++)
        {
            //printf("sum = ");
            long long sum = 0;
			for (int  inner = 0; inner < n; inner++)
			{
                //printf(" %d * %d +", a[i][inner],b[inner][j]);
				sum += a[i][inner] * b[inner][j];
			}
			c[i][j] = sum;
			//printf("\nc[%d][%d] = %d\n\n", i ,j , sum);
        }
    }

    for(i = 0; i < m; i++ )
    {
        for(j = 0 ; j < k - 1; j++ )
        {
          printf("%lld ",c[i][j]);
        }
        printf("%lld\n", c[i][j]);
    }
    return 0;
}

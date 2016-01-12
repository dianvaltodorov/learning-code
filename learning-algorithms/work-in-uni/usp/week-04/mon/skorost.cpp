#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include <vector>       // std::vector
#include <stdio.h>
using namespace std;
/*Един студент във ФМИ искал да си подреди парите, които имал. Естествено
това били все монети. Студента учел в специалност Компютърни науки и
решил, че ще е полезно ако стотинките със стойност под някакво число X ги
сортира в нарастващ ред, а тези със стойности по-големи или равни на X – в
намаляващ ред. Първо идват тези, които са по-малки от X (сортирани
нарастващо), а след тях останалите (сортирани намаляващо). Все още не е
напълно известно каква е логиката зад това. Предполага се че е нещо свързано
с науката наречена Анализ, която студента тъкмо изучавал.
За случаите, когато монетите са прекалено много е подходящо да се напише
програма, която да прави сортирането. Това е вашата задача.
Данните се четат от стандартния вход и се пишат на стандартния изход. На
първия ред са зададени броя тестове във входа. За всеки тест са зададени две
числа – N и X. N е броя стотинки, а X границата, която студента си поставил. На
втория ред във всеки тест има N числа, описващи стойностите на стотинките.
Тези стойности са цели числа в интервала [1, 99]. За N е известно, че 1<= N <=
100.
Изходните данни се извеждат на стандартния изход. За всеки тест се извежда
по един ред с N числа. Това са стойностите на монетите подредени в изискания
ред.*/

int n;
int x;
int number_of_tests;
int c;
int current;

int main ()
{

    vector<int> bigger_or_equal;
    vector<int> smaller;
    scanf("%d", &number_of_tests);
    for (int k = 1; k <= number_of_tests; k++)
    {
        scanf("%d", &n);
        scanf("%d", &x);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &current);

            if(current >= x)
                bigger_or_equal.push_back(current);
            else
                smaller.push_back(current);
        }
        sort(smaller.begin(), smaller.end());
        sort(bigger_or_equal.rbegin(), bigger_or_equal.rend());
//        reverse(bigger_or_equal.begin(), bigger_or_equal.end());

        int i;
        for(i = 0; i < smaller.size(); i++)
        {
            printf("%d ", smaller[i]);
        }
        for(i = 0; i < bigger_or_equal.size() - 1 ; i++)
        {
            printf("%d ", bigger_or_equal[i]);
        }
        printf("%d\n", bigger_or_equal[i]);
        bigger_or_equal.clear();
        smaller.clear();


    }

    return 0;
}

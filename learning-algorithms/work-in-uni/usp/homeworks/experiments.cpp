#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
  /*vector<int> myvec;
    for(int i = 0; i <= 5; i++)
        myvec.push_back(i);
    for(int i = 0; i <= myvec.size() - 1; i++)
        printf("%d ", myvec[i]);
    printf("\n");
    myvec.pop_back();
    for(int i = 0; i <= myvec.size() - 1; i++)
        printf("%d ", myvec[i]);
    */
    priority_queue<int> mypq;

    mypq.push(30);
    mypq.push(100);
    mypq.push(25);
    mypq.push(40);


    while(!mypq.empty())
    {
        printf("%d ",mypq.top());
        mypq.pop();
    }
    printf("\n");

    vector <int> v;
    v.push_back(1);
    printf("%d", v[1]);
    vector < vector < pair <int, double > > > ne;




}

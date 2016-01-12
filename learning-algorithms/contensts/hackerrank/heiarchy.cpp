#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<stack>
#include<map>
using namespace std;

std::map< string , vector < string > > rel;
std::map< string , bool > used;
string beg1;
string beg2;
string sen;
string jun;
string ans;

/*
 * Complete the function below.
 */

 bool ok = false;

 void dfs(string i)
 {
   if(ok) return;
   used[i] = true;
   vector < string > subord = rel[i];
   cout<<i<<endl;
   for(int k = 0; k < subord.size(); k++)
   {
     if(used[subord[k] ])
     if(!used[subord[k]])
     {
       dfs(subord[k]);
     }
     else
     {
       ans = subord[k];
       ok = true;
     }
   }
 }

void OutputCommonManager(int count) {

  cin >> beg1;
  cin >> beg2;
  string start;

  cin >> sen >> jun;
  rel[sen].push_back(jun);
  used[sen] = false;
  used[jun] = false;
  start = sen;

  for(int i = 2; i < count; i++)
  {
    cin >> sen >> jun;
    rel[sen].push_back(jun);
    used[sen] = false;
    used[jun] = false;
  }
  dfs(start);
  used[start] = false;

  cout << start<<endl;
}



int main()
{
  int _count;
  cin >> _count;
  OutputCommonManager(_count);
  return 0;
}

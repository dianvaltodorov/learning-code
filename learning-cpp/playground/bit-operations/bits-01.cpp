#include <iostream>
#include <stack>
using namespace std;

void toBinary(int);

int main()
{
  int x = 15;
  toBinary(x);
  cout << x << endl;
  int y = x ;
  cout << y << endl;;
  toBinary(y);
}

void toBinary(int n)
{
  stack<int> st;
  while(n)
  {
    st.push(n%2);
    n/=2;
  }
  while(!st.empty())
  {
    cout << st.top();
    st.pop();
  }
  cout << endl;
}

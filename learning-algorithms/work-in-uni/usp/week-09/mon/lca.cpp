#include <bits/stdc++.h>
using namespace std;

#define time __time

const int MAXN = 100000;
const int LOG = 20;

map<string, int> translations;
map<int, string> original_name;
int GetName(const string& vr){
  if(translations.count(vr)){
    return translations[vr];
  } else {
    translations[vr] = translations.size() - 1;
    original_name[translations[vr]] = vr;
    return translations[vr];
  }
}

int ReadOne(){
  string tmp;
  cin >> tmp;
  return GetName(tmp);
}

int n;
vector<int> follower[MAXN];
int time = 0;
int first_time[MAXN];
int last_time[MAXN];
int jump[MAXN][LOG];

void dfs(int vr, int parent){
  first_time[vr] = time++;

  jump[vr][0] = parent;
  for(int i = 1;i < LOG;++i){
    jump[vr][i] = jump[jump[vr][i-1]][i-1];
  }

  for(int next : follower[vr]){
    dfs(next, vr);
  }

  last_time[vr] = time++;
}

// Checks if a is parent of b
bool IsParent(int a, int b){
  return first_time[a] <= first_time[b] &&
         first_time[b] <= last_time[a];
}

int Lca(int a, int b){
  if(IsParent(a, b)) return a;
  if(IsParent(b, a)) return b;

  for(int i = LOG - 1;i >= 0;){
    int top = jump[a][i];
    if(IsParent(top, b)) --i;
    else a = top;
  }

  return jump[a][0];
}

int main(){
  int edges;
  int start;
  int finish;
  int root = -1;

  cin >> edges;
  start = ReadOne();
  finish = ReadOne();

  for(int i = 0;i < edges;++i){
    int a = ReadOne();
    int b = ReadOne();
    if(root == -1) root = a;
    follower[a].push_back(b);
  }

  dfs(root, root);

  n = translations.size();

  cout << original_name[Lca(start, finish)] << '\n';

  return 0;
}

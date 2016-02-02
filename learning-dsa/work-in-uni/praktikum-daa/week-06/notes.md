Представяне на граф:

int visited[MAXN];
vector <int> neigh[1024];
int n, m;
int a, b;

int input()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; ++i)
  {
    scanf("%d%d", &a, &b);
    neigh[a].push_back(b);
    neigh[b].push_back(a);

  }
}
int main()
{

  input();
  soplve();
}

#inlcude<cstdio>
using namespace std;
const int N =  1 << 10;
int n, m;

int neiCount[N];
int neiList[N];
int neiWeift[N];
const int n = 1 << 10;
void addEdge(int x, int y, int w)
{
  neiList[x][neiCount[x]] = y;
  neiWeight[x][neiCount[x]] = w;
  ++neiCount[x];
}

void doInput()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i)
  {
    int x, y, w;
    scanf("%d %d %d", x, y, w);
    --x;
    --y;
    addEdge(x, y, w);
    addEdge(y, x, w);
  }
}

int main()
{
  cons
}

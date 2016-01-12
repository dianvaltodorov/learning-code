претеглен граф - ребрата иматнякакви тежекти

Kruskal -  по лесен за обясняване, сложност O(m*logm +  m*A + n*B)
Prim algorithm


Крускал
-----------
обхожда всички ребра, подредени по големина и решава дали да ги добави
в случай че не образува цикъл. Крайната цел е да се получи една свързана компонента
Целта е да имаме  n - 1
Трябва да ршеим дали ще добавяме.

Union Find - функциите, които се извършват върху  disjoint set
Disjoint Set - използва се в алгоритъм на крускал, за да се оптимизира и да не се пуска дфс


struct Edge{
  int a, b, w;
}

vector<Edge> v;
int connected[n];
int count = 0;
int i = 0;
int min = 0;


int p[];
int find(int a)
{
  while(p[a]!=a)
    a=p[a];
  return a;
}

int find(int a)
{
  if(a == p[a])
    return a;
  else
    return find(p[a]);
}

Можем да се направи по лесно, като слагаме един и същ родител на всички.
int find(int a)
{
  if(a == p[a])
    return a;
  else{
    p[a] = find(p[a]);
    return a;
  }
}

пазим рангове на компоненти и този ранг го използваме за да изберем

void union(int a, int b)
{
  if(rank[a] < rand[b])
    p[a] = b;
  else if(rank[a] > rank[b])
    p[b] = a;
  else{
    p[b]=a;
  }
}

прим прави дърво
крусал прави кореново дърво

Прим
------------
на всяка стъпка правим това което на теория правим
С един булев масив ще отбелязваме дали е в дървото или не е

Може да има повече едно минимално покриващо дърво. Пример е дърво с
```
Struct Edge
{
  int from, to w;
  Edge(a,b,c).from(a).to(b).w(){}
  bool operator <(const Edge&r) const{
    return w > r.w
  }
}
```

Този Edge ще влиза в едно
priority_queue<Edge> pq;
Имаме проблем.
Важно е преди да добавим реброто, трябва да проверим дали е валидно. Ако е невалидно
значи не го добавяме. В противен случай го добавяме.


```
vector<vector<pairs<int, int>>> ne;
int prim(int start)
{
  memset(used, 0, sizeof(used));
  memset(p, -1, sizeof(p));
  priority_queue<Edge> pq;
  pq.push(Edge(-2), start, 0);
  int total// обща тежест на дървотом
  while()
  {
    int size = 0;
    while(size < n)
    {
      Edge cur = pq.top();
      pq.pop();
      if(used[cut.to]) continue;
      p[cur.to] = cur.from;
      size++;
      used[cur.to] = true;
      total += cur.w;
      if(size == n) return total;
      for(int i = 0; i < ne[cur.to].size(); ++i){
        int vert = ne[cur.to][i].first;
        int w = ne[cur.to][i].second;
        if(used[vert]) continue;
  }
}
```
дърво на минималните пътища- намира минималния път от корена до всички останали.
Разликата с Прим и алгоритъм на Дейкстра е че при Прим слагаме тежеста на реброто,
а при Дейкстра слагаме тежестта текущия път + дължината на реброто

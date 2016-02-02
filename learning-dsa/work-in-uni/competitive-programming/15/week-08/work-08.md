Solutions:

1. Evil

Искаме да намерим покритите точки. Разделяме си точките по такъв начи. Имаме отваряща интервала точка и точка затваряща интервала. Отваряме някакваскоба и на местата където свършва затваряме. Целия този интервал е покрит.

Разбиваме на отварящи и затварящи. За всяка отваряща вдигаме и 3

Интервалите се моделират,

| 2  | 3  | 5  | 7  | 9  | 9 |
| :- | :- | :- | :- | :- | :-|
| 0  | 0  | 1  | 1  | 0  | 1 |
Когато стане нула смятаме рзлика
```
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int x, y;
  vector < <pair < int,  int > > v;
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d", &x, &y);
    v.push_back(make_pair(x, 0));
    v.push_back(make_pair(y, 1));
  }

  sort(v.begin(), v.end());
  int start = 0;
  int cnt = 0;
  for(int i = 0; i <  m * 2; ++i)
  {
    if(v[i].second == 0)
    {
      cnt++;
      if(cnt == 1)
        start = i;
    }
    else
    {
      cnt--;
      if(cnt == 0)
        ans = v[i].first - v[start].first + 1;
    }
  }
}
```


2. Sequence

Функцията е линейна.

```
isPossible(int x)
{
  int cnt = 0;
  for(int i = 0; i < n; ++i)
  {
    if(mas[i] => x) cnt++;
    if(cnt >= k )
  }
}
int main()
{
  scanf("%d %d", &n, &k);
  scanf("%d", &mas[0]);
  minE = maxE = mas[0];
  for(int i = 0; i < n; ++i)
  {
    scanf("%d", &mas[i]);
    if(mas[i] < minE) minE = mas[i];
    if(mas[i] > maxE) maxE = maspi];
  }

  int l = minE, r = maxE + 1;
  while(l < r / 2)
  {
    int min
  }

#include <cstdio>
#include <algorithm>
#include <climits>
#include <queue>
#include <functional>
int edges, vertecies;
std::vector<std::pair<int, int> > graph[3005];
int vis[3005];
int dist[3005];
int startingNode;
void solution()
{
	int mst = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>> , std::greater<std::pair<int, int>>> q;

	q.push(std::make_pair(0, startingNode));
	dist[startingNode] = 0;
	while (!q.empty())
	{
		std::pair<int, int> Qtop = q.top(); q.pop();
		int currentDist = Qtop.first;
		int currentNode = Qtop.second;
		if (vis[currentNode]) { continue; }
		vis[currentNode] = 1;
		mst += dist[currentNode];
		for (int i = 0; i < graph[currentNode].size(); ++i)
		{
			int nextNode = graph[currentNode][i].second;
			int nextDist = graph[currentNode][i].first;
			dist[nextNode] = std::min(dist[nextNode], nextDist);
			q.push(std::make_pair(dist[nextNode], nextNode));
		}


	}
	printf("%d\n", mst);
}


int main() {
	scanf("%d %d", &vertecies, &edges);
	int x, y, z;
	for (int i = 0; i < edges; ++i)
	{
		scanf("%d %d %d", &x, &y, &z);
		--x; --y;
		graph[x].push_back(std::make_pair(z, y));
		graph[y].push_back(std::make_pair(z, x));
	}
	scanf("%d", &startingNode);
	--startingNode;
	for (int i = 0; i < 3005; ++i)
	{
		dist[i] = INT_MAX;
	}
	solution();
	system("PAUSE");
	return 0;
}

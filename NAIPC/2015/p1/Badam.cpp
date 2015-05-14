#include <cstdio>
#include <cassert>
#include <queue>
#include <iostream>

#define MAX_NODES	600000

typedef struct
{
	char state;
	int par;
	long long balls;
	int left, right;
} node_t;

using namespace std;

node_t nodes[MAX_NODES + 1];
bool vis[MAX_NODES];
void dfs(int node)
{
	if(node == 0 || vis[node])
		return;

	vis[node] = true;

	nodes[nodes[node].left].par ++;
	nodes[nodes[node].right].par ++;

	dfs(nodes[node].left);
	dfs(nodes[node].right);
}

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m;
	int i;
	std::queue<int> q;


	cin >> nodes[1].balls >> m;

	for(i = 0; i <= m; i ++)
		nodes[i].par = 0;

	nodes[0].balls = 0;
	for(i = 1; i <= m; i ++)
	{
		cin >> nodes[i].state >> nodes[i].left >> nodes[i].right;
		//scanf(" %c %d %d", &nodes[i].state, &nodes[i].left, &nodes[i].right);

		assert(nodes[i].state == 'L' || nodes[i].state == 'R');

		if(i != 1) nodes[i].balls = 0;

/*		nodes[nodes[i].left].par ++;
		nodes[nodes[i].right].par ++;*/
	}

	dfs(1);

	//assert(nodes[1].par == 0);

	q.push(1);
	while(!q.empty())
	{
		i = q.front();
		q.pop();

		if(i == 0)
		{
			assert(q.empty());
			break;
		}

		nodes[nodes[i].left].balls += nodes[i].balls / 2;
		nodes[nodes[i].right].balls += nodes[i].balls / 2;

		if(nodes[i].balls % 2 == 1)
		{
			if(nodes[i].state == 'L')
			{
				nodes[i].state = 'R';
				 nodes[nodes[i].left].balls ++;
			}
			else
			{
				nodes[i].state = 'L';
				nodes[nodes[i].right].balls ++;
			}
		}

		if((-- nodes[nodes[i].left].par) == 0)
			q.push(nodes[i].left);

		if((-- nodes[nodes[i].right].par) == 0)
			q.push(nodes[i].right);
	}

	assert(nodes[0].balls == nodes[1].balls);

	for(i = 1; i <= m; i ++)
		cout << nodes[i].state;
	cout << '\n';

	return 0;
}

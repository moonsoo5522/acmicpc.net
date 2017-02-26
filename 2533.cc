#include <stdio.h>
#include <vector>

using namespace std;

vector< vector<int> > v(1000001);
int visited[1000001];
int early[1000001][2];
int n;
int cnt;

#define MIN(x,y) (x>y?y:x)

void sibal(int n)
{
	visited[n] = 1;
	
	early[n][1]++;
	for(int i=0; i<v[n].size(); i++)
	{
		if(!visited[v[n][i]])
		{
			sibal(v[n][i]);
			early[n][0] += early[v[n][i]][1];
			early[n][1] += MIN(early[v[n][i]][0], early[v[n][i]][1]);
		}
	}

}
int main()
{
	scanf("%d", &n);
	
	int a, b;
	for(int i=0; i<n-1; i++)
	{
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	sibal(1);
	
	printf("%d", MIN(early[1][0], early[1][1]));
}
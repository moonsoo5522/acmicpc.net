#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int len;
priority_queue<int> pq;
vector< pair<int, int> > v;
int res = 0;
bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}
int main()
{
	scanf("%d", &n);
	int h, o;
	for(int i=0; i<n; i++)
	{
		scanf("%d %d", &h, &o);
		if(o > h) v.push_back(make_pair(h, o));
		else v.push_back(make_pair(o, h));
	}
	scanf("%d", &len);
	sort(v.begin(), v.end(), compare);
	
	for(int i=0; i<v.size(); i++)
	{
		pq.push(-v[i].first);
		while(!pq.empty())
		{
			int top = -pq.top();
			if(v[i].second - len <= top) break;
			
			pq.pop();
		}
		int size = pq.size();
		res = max(res, size);
	}
	printf("%d", res);
}

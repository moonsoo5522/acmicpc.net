#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int nA, nB;
vector<int> a, b;
int checked[500001];
int main()
{
	scanf("%d %d", &nA, &nB);
	int t;
	for(int i=0; i<nA; i++)
	{
		scanf("%d", &t);
		a.push_back(t);
	}
	for(int i=0; i<nB; i++)
	{
		scanf("%d", &t);
		b.push_back(t);
	}
	sort(a.begin(), a.end());
	
	for(int i=0; i<b.size(); i++)
	{
		int pos = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
		if(a[pos] == b[i]) nA--, checked[pos] = 1;
	}
	printf("%d\n", nA);
	for(int i=0; i<a.size(); i++)
		if(!checked[i])
			printf("%d ", a[i]);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 999999999

int arr[260];
int n;
int dp[260][260];
int m[260][260];

int min(int x, int y) { return x > y ? y : x; }
int solve(int start, int end)
{
	if(start == end) return 0;
	if(start+1 == end)
	{
		m[start][end] = min(arr[start], arr[end]);
		return abs(arr[start] - arr[end]);
	}
	if(dp[start][end] != -1) return dp[start][end];
	
	int minvalue = INF;
	int val = 0, idx = 0;
	for(int i=start; i<end; i++)
	{
		int temp = min(minvalue, solve(start, i) + solve(i+1, end) + abs(m[start][i] - m[i+1][end]));
		if(temp < minvalue)
		{
			
			minvalue = temp;
			idx = i;
		}
	}
	m[start][end] = min(m[start][idx], m[idx+1][end]);
	return dp[start][end] = minvalue;
}
int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
		m[i][i] = arr[i];
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", solve(0, n-1));
}

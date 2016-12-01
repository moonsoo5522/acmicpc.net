#include <stdio.h>

int len;
int arr[2001];
int dp[2001][2001];
int num;
int main()
{
	scanf("%d", &len);
	for(int i=1; i<=len; i++)
	{
		dp[i][i]=1;
		scanf("%d", &arr[i]);
	}
	for(int i=2; i<=len; i++)
		dp[i-1][i] = dp[i][i-1] = arr[i] == arr[i-1] ? 1 : 0;
	
	for(int i=2; i<len; i++)
	{
		for(int j=1; j<=len-i; j++)
		{
			if(dp[j+1][j+i-1] && (arr[j] == arr[j+i]))
				dp[j][j+i]=dp[j+i][j]=1;
		}
	}
	
	scanf("%d", &num);
	int a, b;
	for(int i=0; i<num; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
}
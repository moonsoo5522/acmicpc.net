#define _CRT_SECURE_NO_WARNINGS

int n;
int arr[101];
long long dp[101][1001];
int dest;

long long solve(int sum, int idx)
{
	if (sum < 0 || sum > 20) return 0;
	if (idx == n - 1)
	{
		if (sum == dest)
			dp[idx][sum] = 1;
		else
			dp[idx][sum] = 0;
		return dp[idx][sum];
	}

	if (dp[idx][sum] != -1)
		return dp[idx][sum];

	long long val = 0;

	val += solve(sum + arr[idx + 1], idx + 1);
	val += solve(sum - arr[idx + 1], idx + 1);

	return dp[idx][sum] = val;
}
int main()
{
	scanf("%d", &n);
	n--;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &dest);

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 1001; j++)
			dp[i][j] = -1;

	printf("%lld", solve(arr[0], 0));
}
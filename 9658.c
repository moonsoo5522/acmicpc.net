#include <stdio.h>

int main()
{
    int num, dp[1001]={0,};
    scanf("%d", &num);
    dp[1]=dp[3]=1;
    
    for(int i=4; i<=num; i++)
        if(!dp[i-1] && !dp[i-3] && !dp[i-4])
            dp[i]=1;
    printf(dp[num]?"CY":"SK");
    return 0;
}
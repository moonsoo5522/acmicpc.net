#include <stdio.h>

int n;
int main()
{
	scanf("%d", &n);
	int a, b;
	for(int t=0; t<n; t++)
	{
		scanf("%d %d", &a, &b);
		if(a == b)
		{
			printf("%d\n", a);
			continue;
		}
		int res = 0;
		for(int i=30; i>=1; i--)
		{
			if(b & (1<<i))
				if((b & ((1<<i)-1))%2 == 0) res ^= (1<<i);
			
			if(a & (1<<i))
				if((a & ((1<<i)-1))%2) res ^= (1<<i);
		}
		if(a%2==0 && b%2) res |= ((b-a+1)/2)%2;
		if(a%2 && b%2) res |= !(((b-a)/2)%2);
		if(a%2 && b%2==0) res |= ((b-a+1)/2)%2;
		if(a%2==0 && b%2==0) res |= ((b-a)/2)%2;
		printf("%d\n", res);
	}
}

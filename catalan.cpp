#include<stdio.h>

int cat(int n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{
	    int res=0;
	    for(int i=0;i<n;i++)
	    {
	        res+=cat(i)*cat(n-i-1);
	    }
	    return res;
	}
}
int main()
{
    int n;
    scanf("%d",&n);
	printf("%d",cat(n));
	return 0;
}

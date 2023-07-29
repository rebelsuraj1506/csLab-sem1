#include<iostream>
using namespace std;

int cat(int n)
{
	if(!n) return 1;
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
int main(){
	int n;
	cin>>n;
	cout<<cat(n);
}


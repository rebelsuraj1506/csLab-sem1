#include<bits/stdc++.h>
using namespace std;

unsigned long arr[10000];//Declared global array to store catalan numbers.

unsigned long cat(int n)
{
    if(arr[n])//If catalan number for n computed earlier return it.
    return arr[n];
    unsigned long res=0;
    for(int i=0;i<n;i++)
    {
        res+=cat(i)*cat(n-i-1);
    }
    arr[n]=res;
    return res;
}
int main(){
	int n;
	cin>>n;
    arr[0]=1; //base condition
	cout<<cat(n)<<endl;//Printing value of catalan number.
}
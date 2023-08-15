#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int i,int j,int t)
{
    while(i<=j)
    {
        int m=(i+j)/2;
        if(arr[m]==t)
        {
            return m;
        }
        if(arr[m]<arr[j])
        {
            if(arr[m]<t&& t<=arr[j])
            {
            i=m+1;
            }
            else{
            j=m-1;
            }
        }
        else
        {
            if(arr[i]<=t && t<arr[m])
            {
                j=m-1;
            }
            else{
                i=m+1;
            }
        }
    }  
    return -1;
}
int main()
{
    int n,target;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Target is: ";
    cin>>target;
    int index=binarySearch(arr,0,n-1,target);
    if(index==-1)
    {
        cout<<"Target is not in resultant array."<<endl;
    }
    else{
        cout<<"Index of Target is "<<index<<endl;
    }
}
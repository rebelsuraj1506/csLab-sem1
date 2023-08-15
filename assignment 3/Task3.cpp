#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Number of cities: ";
    cin>>n;
    int province;
    province=n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        if(!(visited[i]))
        visited[i]=false;
        for(int j=0;j<n;j++)
        {
            if(!a[i][j]){
            if(i!=j){
            if(!visited[i] || !visited[j])
            {
                province--;
                visited[i]=true;
                visited[j]=true;
            }
            }
        }
        }
    }
    cout<<province;
    cout<<endl;
}
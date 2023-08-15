#include<bits/stdc++.h>
using namespace std;
class edge{
public:
int s;
int d;
int wt;
};


int main()
{
int n,m;
cout<<"Enter number of Houses: ";
cin>>n;
cout<<"Enter number of dirt roads: ";
cin>>m;
edge arr[m];
for(int i=0;i<m;i++)
{
cin>>arr[i].s;
cin>>arr[i].d;
cin>>arr[i].wt;
}
edge temp;
for(int i=0;i<m;i++)
{
for(int j=1;j<m-i;j++)
{
if(arr[j-1].wt>arr[j].wt)
{
temp=arr[j-1];
arr[j-1]=arr[j];
arr[j]=temp;
}
}
}
bool visited[n];
for(int i=0;i<n;i++)
{
visited[i]=false;
}
int cost=0;
for(int i=0;i<m;i++)
{
if(!(visited[arr[i].s]) || !(visited[arr[i].d]))
{
cost+=arr[i].wt;
visited[arr[i].s]=true;
visited[arr[i].d]=true;
}
}
cout<<"Minimum cost is "<<cost<<endl;
}

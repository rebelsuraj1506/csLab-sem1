#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
class Graph{
int v;
list<pair<int,int>>*adj;
public:
Graph(int v);
void addEdge(int u,int v,int wt);
void shortestPath(int,int);
void path_record(int i, vector<int> &parent, vector<int>&path){
if(i==-1) return;
path_record(parent[i],parent,path);
path.push_back(i);
}
};
Graph::Graph(int n)
{
this->v=n;
adj=new list<iPair>[v+1];
}
void Graph::addEdge(int u,int v,int wt)
{
adj[u].push_back(make_pair(v,wt));
}
void Graph::shortestPath(int src,int dest)
{
priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
vector<int> dist(v+1,INT_MAX);
vector<int> parent(v+1,-1);
pq.push(make_pair(1,src));
dist[src]=1;
while(!pq.empty())
{
int u=pq.top().second;
pq.pop();
for(auto it=adj[u].begin();it!=adj[u].end();++it)
{
int v=(*it).first;
int wt=(*it).second;
if(dist[v]>dist[u]*wt)
{
dist[v]=dist[u]*wt;
parent[v] = u;
pq.push(make_pair(dist[v],v));
}
}
}
if(parent[dest]==-1)
{
cout<<"-1";
}
else{
vector<int> path;
path_record(dest,parent,path);
cout<<"The path with the smallest product of edges will be ";
for(auto x: path) cout<<x<<" ";
cout<<"with the product as "<<dist[dest];
cout<<endl;
}
}
int main()
{
int n,e;
cout<<"Enter number of nodes: ";
cin>>n;
cout<<"Enter number of edges: ";
cin>>e;
Graph g(n);
int u,v,wt;
for(int i=0;i<e;i++)
{
cin>>u>>v>>wt;
g.addEdge(u,v,wt);
}
int src;
int dest;
cout<<"Enter source: ";
cin>>src;
cout<<"Enter destination: ";
cin>>dest;
g.shortestPath(src,dest);
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<vector<pi> > graph;
// Function for adding edges to graph
void addedge(int x, int y, int cost)
{
graph[x].push_back(make_pair(cost, y));
graph[y].push_back(make_pair(cost, x));
}
void best_first_search(int source, int target, int n)
{
vector<bool> visited(n, false);
// MIN HEAP priority queue
priority_queue<pi, vector<pi>, greater<pi> > pq;
// sorting in pq gets done by first value of pair
pq.push(make_pair(0, source));
int s = source;
visited[s] = true;
while (!pq.empty()) {
int x = pq.top().second;
// Displaying the path having lowest cost
cout << x << " ";
pq.pop();
if (x == target)
break;
for (int i = 0; i < graph[x].size(); i++) {
if (!visited[graph[x][i].second]) {
visited[graph[x][i].second] = true;
pq.push(make_pair(graph[x][i].first,graph[x][i].second));
}
}
}
}
// Driver code to test above methods
int main()
{
// No. of Nodes
int v;
cout<<"Enter no of nodes :"<<endl;
cin>>v;
graph.resize(v);
int edge;
cout<<"Enter no of edge: "<<endl;
cin>>edge;
// The nodes shown in above example(by alphabets) are
// implemented using integers addedge(x,y,cost);
for(int i=0;i<edge;i++){
int u,v,cost;
cin>>u>>v>>cost;
addedge(u, v, cost);
}
int source,target;
cout<<"Enter source and target :"<<endl;
cin>>source>>target;
// Function call
best_first_search(source, target, v);
return 0;
}

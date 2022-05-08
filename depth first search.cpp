#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>graph[],vector<bool>&visited,int node){
    if(visited[node]==false)
    cout<<node<<" ";
    visited[node]=true;
    for(auto it:graph[node]){
        if(visited[it]==false){
            dfs(graph,visited,it);
        }
    }
}
int main() {
    int n,e;
	cout<<"Enter number of nodes: ";
	cin>>n;
	cout<<endl;
	cout<<"Enter nuber of edges: ";
	cin>>e;
	vector<int>graph[n];
	for(int i=0;i<e;i++){
	    int start,end;
	    cin>>start>>end;
	    graph[start].push_back(end);
	}
	vector<bool>visited(n,false);
	

	for(int i=0;i<n;i++){
	    if(visited[i]==false)
	    dfs(graph,visited,i);
	}
	return 0;
}

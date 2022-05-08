#include <iostream>
#include<bits/stdc++.h>
using namespace std;


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
	
	queue<int>q1;
	
	q1.push(0);
	while(!q1.empty()){
	    int a=q1.front();
	    visited[a]=true;
	    cout<<a<<" ";
	    q1.pop();
	    for(auto it:graph[a]){
	        if(visited[it]==false){
	            q1.push(it);
	            
	        }
	    }
	}
	
	return 0;
}

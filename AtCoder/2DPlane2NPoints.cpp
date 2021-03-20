#include <bits/stdc++.h>
using namespace std;
 
#define V 300
 
bool bfs(int rGraph[V][V], int s, int t, int parent[]){
	bool visited[V];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v = 0;v < V;v++){
			if(visited[v] == false && rGraph[u][v] > 0){
				if(v == t){
					parent[v] = u;
					return true;
				}
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
	return false;
}
 
int fordFulkerson(int graph[V][V], int s, int t){
	int u, v;
	int rGraph[V][V];
	for(u = 0;u < V;u++)
		for(v = 0;v < V;v++)
			rGraph[u][v] = graph[u][v];
	int parent[V];
	int max_flow = 0;
	while(bfs(rGraph, s, t, parent)){
		int path_flow = INT_MAX;
		for(v = t;v != s;v = parent[v]){
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}
		for(v = t;v != s;v = parent[v]){
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}
 
int main(){
	int graph[V][V];
	int n;cin >> n;
	int s = 299;
	int t = 298;
	vector<pair<int, int>> red;
	vector<pair<int, int>> blue;
	for(int i = 0;i < V;i++)
		for(int j = 0;j < V;j++)
			graph[i][j] = 0;
	//blue + 100
	for(int i = 0;i < n;i++){
		graph[s][i] = 1;
		graph[i + 100][t] = 1;
	}
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		red.emplace_back(a, b);
	}
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		blue.emplace_back(a, b);
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(red[i].first < blue[j].first &&
					red[i].second < blue[j].second){
				graph[i][j + 100] = 1;
			}
		}
	}
	cout << fordFulkerson(graph, s, t) << endl;
}

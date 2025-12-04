#include<iostream>
using namespace std;

int graph[10][10];
int visited[10];

void dfs(int node, int n){
    visited[node] = 1;
    cout << node << " ";

    for(int i = 1; i <= n; i++){
        if(graph[node][i] == 1 && visited[i] ==0){
            dfs(i,n);
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    dfs(1,n);
}
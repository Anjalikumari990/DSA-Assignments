#include<iostream>
using namespace std;

int graph[10][10];
int visited[10];
int q[20];
int front = 0, rear = 0;

void enqueue(int x){
    q[rear++] = x;
}

int dequeue(){
    return q[front++]; 
}

bool isEmpty(){
    return front == rear;
}

void bsf(int start, int n){
    enqueue(start);
    visited[start] = 1;

    while(!isEmpty()){
        int node = dequeue();
        cout << node << " ";

        for(int i = 1; i <=n; i++){
            if(graph[node][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;

    for(int i = 0; i<e; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    bsf(1,n);
}
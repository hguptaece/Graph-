#include<bits/stdc++.h>
using namespace std;

#define maxN 1000

int parent [maxN];
int disc [maxN];
int low [maxN];
int visited [maxN];
int time1 = 1;

set<int> artic_point;

void dfs(int u,int parent, vector<int> adj[]){
    disc[u] = low[u] = time1++;
    visited[u] = true;
    for(int v : adj[u]){
        if(v == parent){
            continue;
        }else if(visited[v]){
            low[u] = min(low[u], disc[v]);
        }else{           
            dfs(v,u,adj);
            low[u] = min(low[u], low[v]);

            if(low[v] > disc[u]){
                artic_point.insert(u);
                artic_point.insert(v);
            }
        }
    }
}

int main(){
    int n, e;
    cout<<"Enter the number of nodes and edges in your graph :\n";
    cin>>n>>e;
    vector<int> adj[n+1];
    cout<<"Enter the edges of your graph :\n";
    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<maxN; i++){
        low[i] = INT_MAX;
        disc[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    
    dfs(1,-1,adj);
    cout<<"articulation Point are:"<<"\n";
    for(int a: artic_point){
        cout<<a<<"\n";
    }
    cout<<"\n";
    
    return 0;
}

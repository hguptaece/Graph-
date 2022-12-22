# Graph-
#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Please Enter the number of vertices and edges in your graph..\n";
    int v,e;
    cin>>v>>e;

    //for adjacency Matrix Representation
    vector<vector<int>> adjMat(v,vector<int>(v,0));
    //for adjacency List Representation
    vector<int> adjList[v];
    //for Edge List Representation
    vector<pair<int,int>> edges;             

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;

        adjMat[u][v]=true;
        adjMat[v][u]=true;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

        edges.push_back({u,v});
        edges.push_back({v,u});
    }

    cout<<"Your Graph Adjacency Matrix Representation is: \n\n";
    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Your Graph Adjacency List Representation is: \n\n";

    for(int i=0;i<v;i++){
        cout<<i<<": ";
        for(int nbr: adjList[i]){
            cout<<nbr<<" ";
        }
        cout<<"\n";
    }

    cout<<"Your Graph Edge List Representation is: \n\n";

    for(pair<int,int> edge:edges){
        cout<<edge.first<<"->"<<edge.second<<" \n";
    }

    return 0;
} 

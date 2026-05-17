#include <bits/stdc++.h>
using namespace std;


void dijkstras(vector<vector<int>>&V, vector<int>&dist){
    dist[0]=0;

    

    int v=V.size();
    vector<bool>vis(V.size(),false);

    for(int i=0;i<v-1;i++){
        int minInd=-1;
        int mini=INT_MAX;

        for(int j=0;j<v;j++){
            if(!vis[j] && dist[j]<mini){
                mini=dist[j];
                minInd=j;
            }
        }

        vis[minInd]=true;

        for(int j=0;j<v;j++){
            if(!vis[j] && V[minInd][j]!=0 && V[minInd][j]+mini<dist[j]){
                dist[j]=V[minInd][j]+mini;
            }
        }
    }
}



int main() {
    

    cout<<"Enter no of vertices"<<endl;
    int n;
    cin>>n;

    vector<vector<int>>V(n,vector<int>(n));

    for(int i=0;i<n;i++){
        V[i][i]=0;
        for(int j=i+1;j<n;j++){
            cout<<"Enter edge between edge "<<i<<" and "<<j<<" ";
            cin>>V[i][j];
            V[j][i]=V[i][j];
        }
    }
    
    vector<int>dist(n,INT_MAX);

    dijkstras(V,dist);

    for(int i=0;i<n;i++){
        cout<<dist[i]<<endl;
    }

    return 0;
}
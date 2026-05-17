#include <bits/stdc++.h>
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void dfs(int i,int j,vector<vector<int>>&arr,vector<vector<bool>>& vis){
    vis[i][j]=true;

    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dy[k];

        if(nx>=0 && ny>=0 && nx <arr.size() && ny<arr[0].size() && arr[nx][ny]==1 && !vis[nx][ny]){
            dfs(nx,ny,arr,vis);
        }
    }
}

int main() {

    int n;
    cout<<"Enter rows"<<endl;
    cin>>n;

    int m;
    cout<<"Enter Cols:"<<endl;
    cin>>m;

    vector<vector<int>>arr(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans=0;
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1 && !vis[i][j]){
                ans++;
                dfs(i,j,arr,vis);
            }
        }
    }

    cout<<"No of islands is "<<ans<<endl;

    

    return 0;
}
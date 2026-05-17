#include <bits/stdc++.h>
using namespace std;




int main() {
    int n;
    cout<<"Enter rows"<<endl;
    cin>>n;

    int m;
    cout<<"Enter Cols:"<<endl;
    cin>>m;

    vector<vector<char>>arr(n,vector<char>(m));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<int>>time(n,vector<int>(m,-1));
    queue<vector<int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='I'){
                time[i][j]=0;
                vis[i][j]=true;
                q.push({i,j,0});
            }
        }
    }
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};

    while(!q.empty()){
        vector<int>curr=q.front();
        q.pop();
        int currx=curr[0];
        int curry=curr[1];
        int currtime=curr[2];

        

        for(int i=0;i<4;i++){

            int nx =  dx[i] + currx ;
            int ny = dy[i]+ curry ;

            if(nx >=0 && ny>=0 && nx<n && ny<m && arr[nx][ny]=='P' && !vis[nx][ny]){
                q.push({nx,ny,currtime+1});
                time[nx][ny]=currtime+1;
                vis[nx][ny]=true;
            }
        }

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<time[i][j]<<" ";
        }
        cout<<endl;
    }



    

    return 0;
}
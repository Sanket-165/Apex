#include <bits/stdc++.h>
using namespace std;

int heu(pair<int,int>& st,pair<int,int>& end) {
    return abs(st.first-end.first)+abs(st.second-end.second);
}




void astar(vector<vector<int>>& grid,pair<int,int>& st,pair<int,int>& end) {
    vector<vector<pair<int,int>>> parent(
    grid.size(),
    vector<pair<int,int>>(grid[0].size(), {-1,-1})
    );
    int h=heu(st,end);
    vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    int x = st.first;
    int y=st.second;
    int g=0;
    int f=h+g;

    pq.push({f,g,x,y,-1,-1});

    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    bool found = false;

    while(!pq.empty()){
        vector<int>curr=pq.top();
        pq.pop();

        int cx=curr[2];
        int cy=curr[3];
        int cf=curr[0];
        int cg=curr[1];
        int cpx=curr[4];
        int cpy=curr[5];

        if(vis[cx][cy]){
            continue;
        }

        vis[cx][cy]=true;
        parent[cx][cy]={cpx,cpy};

        

        if(cx==end.first && cy==end.second){
            found = true;
            break;
        }

        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==0 && !vis[nx][ny]){
                pair<int,int>np={nx,ny};
                int nh=heu(np,end);
                int ng=cg+1;
                int nf=nh+ng;

                pq.push({nf,ng,nx,ny,cx,cy});

            }
        }


    }

    if(!found) cout<<"Path does not exist"<<endl;
    else{
        vector<pair<int,int>>path;
        pair<int,int>curr=end;
        while(curr!=st){
            path.push_back(curr);
            curr=parent[curr.first][curr.second];
        }

        path.push_back(st);
        int i = path.size()-1;

        while(i>=0){
            pair<int,int>cur=path[i];
            cout<<"Visited "<<cur.first<<" "<<cur.second<<" "<<endl;
            i--;
        }
    }

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cout<<"Enter rows of board"<<endl;
    int n;
    cin>>n;
    cout<<"Enter cols of board"<<endl;
    int m;
    cin>>m;

    

    vector<vector<int>>grid(n,vector<int>(m));
   cout<<"Enter Grid"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<"Enter start node"<<endl;
    pair<int,int>st;
    cin>>st.first;
    cin>>st.second;

    cout<<"Enter end node"<<endl;
    pair<int,int>end;
    cin>>end.first;
    cin>>end.second;

    astar(grid,st,end);

    return 0;
}
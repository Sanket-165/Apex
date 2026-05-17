#include <bits/stdc++.h>
using namespace std;



bool solve(int r, int n, vector<vector<int>>& grid,vector<bool>& col,vector<bool>& d1,vector<bool>& d2){
    if(r==n) return true;

    for(int i=0;i<n;i++){
        if(!col[i] && !d1[r-i+n] && !d2[r+i]){
            grid[r][i]=1;
            col[i]=true;
            d1[r-i+n]=true;
            d2[r+i]=true;

            if(solve(r+1,n,grid,col,d1,d2)){
                return true;
            }
            grid[r][i]=0;
            col[i]=false;
            d1[r-i+n]=false;
            d2[r+i]=false;
        }
    }
    return false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<"Enter size of board"<<endl;

    int n;
    cin>>n;

    vector<vector<int>>grid(n,vector<int>(n,0));
    vector<bool>d1(2*n,false);
    vector<bool>col(n,false);
    vector<bool>d2(2*n,false);

    if(solve(0,n,grid,col,d1,d2)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"No possible Placement"<<endl;
    }

    return 0;
}
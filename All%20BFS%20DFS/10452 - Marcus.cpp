#include<bits/stdc++.h>
using namespace std;

char a[10][10];
bool visited[10][10];
vector<int>v;
int dx[] = { 0, -1, 0 };
int dy[] = { -1, 0, 1 };
int r,c;

void dfs(int x,int y){

    visited[x][y]=true;
    for(int i=0;i<3;i++){
        int xp = x+dx[i];
        int yp = y+dy[i];
        if(visited[xp][yp]==false && (a[xp][yp]=='I' ||  a[xp][yp]=='E' || a[xp][yp]=='H' || a[xp][yp]=='O' || a[xp][yp]=='V' || a[xp][yp]=='A') && xp>=0 && yp>=0 && xp<r && yp<c){
            v.push_back(i);
            dfs(xp,yp);
        }
        else if(visited[xp][yp]==false && (a[xp][yp]=='#' ) && xp>=0 && yp>=0 && xp<r && yp<c){
            v.push_back(i);
            return;
        }
    }

}

int main(){

    int t;
    cin>>t;
    while(t--){

        int x,y;
        int x1,y1;

        memset(visited,false,sizeof(visited));

        v.clear();

        cin>>r>>c;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a[i][j];
                if(a[i][j]=='@'){
                    x = i;
                    y= j;
                }
            }
        }


        dfs(x,y);

        for(int i=0;i<v.size();i++){
            if(v[i]==0) cout<<"left";
            else if(v[i]==1) cout<<"forth";
            else if(v[i]==2) cout<<"right";
            if(i!=v.size()-1) cout<<" ";
        }

        cout<<"\n";


    }


}

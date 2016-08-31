#include<bits/stdc++.h>
using namespace std;

char a[105][105];
bool visited[105][105];
bool flag;
 int r,c;

int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={1,1,1,0,0,-1,-1,-1};

void dfs(int x,int y){

    visited[x][y]=true;
    for(int i=0;i<8;i++){
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx>=0 && yy>=0 && xx<r && yy<c && visited[xx][yy]==false && a[xx][yy]=='*'){
            flag=1;
            dfs(xx,yy);
        }
    }

}

int main(){


    while(cin>>r>>c){
        if(r==0 && c==0) break;

        memset(visited,false,sizeof(visited));

        for(int i=0;i<r;i++){
            cin>>a[i];
        }

        int cou = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]=='*' && visited[i][j]==false){
                    flag=0;
                    dfs(i,j);
                    if(flag==0) cou++;
                }
            }
        }

        cout<<cou<<"\n";

    }

}

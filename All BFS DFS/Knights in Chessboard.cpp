#include<bits/stdc++.h>
using namespace std;

int b[205][205];
bool visited[205][205];
int dx[]={1,2,-1,-2,-2,-1,1,2};
int dy[]={2,1,2,1,-1,-2,-2,-1};

void bfs(int x,int y,int r,int c){
    queue<int>Q;
    Q.push(x);
    Q.push(y);
    visited[x][y]=true;
    while(!Q.empty()){
        int xx = Q.front();
        Q.pop();
        int yy = Q.front();
        Q.pop();
        visited[xx][yy]=true;

        for(int i=0;i<8;i++){
            int x1= xx + dx[i];
            int y1= yy + dy[i];
            if(x1>0 && y1>0 && x1<=r && y1<=c && visited[x1][y1]==false){
                visited[x1][y1]=true;
                Q.push(x1);
                Q.push(y1);
            }
        }
    }

}


int main(){

    int t;
    cin>>t;
    int cou;
    for(int i=0;i<t;i++){
        memset(visited,false,sizeof(visited));
        int r,c;
        cin>>r>>c;
        cou=0;
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                if(visited[j][k]==false){
                    cou++;
                    bfs(j,k,r,c);
                }
            }
        }

        printf("Case %d: %d\n",i+1,cou);



    }

    return 0;

}

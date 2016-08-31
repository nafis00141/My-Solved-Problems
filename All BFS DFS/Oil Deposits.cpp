#include<bits/stdc++.h>
using namespace std;

char m[105][105];
int n,ma;

bool visited[105][105];

int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};


bool valid(int x,int y){
    if(m[x][y]=='@' && x>=0 && y<ma  && x<n && y>=0 && !visited[x][y]) return true;
    return false;
}


void bfs(int x,int y){
    queue<int>Q;
    Q.push(x);
    Q.push(y);
    visited[x][y]=true;

    while(!Q.empty()){

        int xx = Q.front();
        Q.pop();
        int yy = Q.front();
        Q.pop();
        visited[xx][yy] = true;


        for(int i=0;i<8;i++){
            int x1=xx+dx[i];
            int y1=yy+dy[i];
            if(valid(x1,y1)){
                visited[x1][y1]=true;
                Q.push(x1);
                Q.push(y1);
            }
        }


    }
}

int main(){

    int cou=0;

    while(scanf("%d %d",&n,&ma)){
            cou=0;
        if(n==0 && ma==0)
            break;


        for(int i=0;i<n;i++){
                cin >> m[i];
        }

        memset( visited, false, sizeof( visited ) );

        for(int i=0;i<n;i++){
            for(int j=0;j<ma;j++){
                if(m[i][j]=='@' && !visited[i][j]){
                    bfs(i,j);
                    cou++;
                }
            }
        }

        printf("%d\n",cou);

    }

}

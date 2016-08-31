#include<bits/stdc++.h>
using namespace std;

int r,c;
char mat[25][25];
bool visited[25][25];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int sum;

bool valid(int x,int y){

    if(x>=0 && y>=0 && x<r && y<c && !visited[x][y] && mat[x][y]!='#') return true;
    return false;

}

void bfs(int x,int y){
    queue<int>Q;
    Q.push(x);
    Q.push(y);
    sum++;
    visited[x][y]=true;
    while(!Q.empty()){
        int xx = Q.front();
        Q.pop();
        int yy = Q.front();
        Q.pop();
        visited[xx][yy]=true;

        for(int i=0;i<4;i++){
            int x1= xx + dx[i];
            int y1= yy + dy[i];
            if(valid(x1,y1)){
                sum++;
                visited[x1][y1]=true;
                Q.push(x1);
                Q.push(y1);
            }
        }
    }

}

int main(){

    int t,p;
    int sx;
    int sy;
    scanf("%d",&t);
    for(int k=0;k<t;k++){
        scanf("%d %d",&c,&r);

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                visited[i][j]=false;
            }
        }

        for(int i=0;i<r;i++){
                cin >> mat[i];
        }

        p=0;
        for(int i=0;i<r && p==0;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]=='@'){
                    sx=i;
                    sy=j;
                    p=1;
                    break;
                }
            }
        }

        sum=0;
        bfs(sx,sy);

        printf("Case %d: %d\n",k+1,sum);



    }

    return 0;
}

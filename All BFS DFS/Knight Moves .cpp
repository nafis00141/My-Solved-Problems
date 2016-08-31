#include<bits/stdc++.h>
using namespace std;

int ix,iy,fx,fy;
int m[10][10];
bool visited[10][10];
int sum;
int dx[]={1,2,-1,-2,-2,-1,1,2};
int dy[]={2,1,2,1,-1,-2,-2,-1};
int cost[20][20];

int bfs(int x,int y,int fx,int fy){


    queue<int>Q;
    Q.push(x);
    Q.push(y);
    visited[x][y]=true;
    cost[x][y]=0;
    while(!Q.empty()){
        int xx = Q.front();
        Q.pop();
        int yy = Q.front();
        Q.pop();

        if(xx==fx && yy == fy) return cost[xx][yy];

        for(int i=0;i<8;i++){
            int x1 = xx + dx[i];
            int y1 = yy + dy[i];
            if(x1>0 && y1>0 && x1<=8 && y1<=8 && visited[x1][y1]==false){
                visited[x1][y1]=true;
                cost[x1][y1]=cost[xx][yy]+1;
                Q.push(x1);
                Q.push(y1);

            }
        }
    }

    return 0;
}

int main(){
    char a[100],b[100];
    while(scanf("%s %s",a,b)!=EOF){
        ix=a[0]-'a'+1;
        iy=a[1]-'0';
        fx=b[0]-'a'+1;
        fy=b[1]-'0';

        //printf("ix=%d iy=%d fx=%d fy=%d\n",ix,iy,fx,fy);

        memset(m,0,sizeof(m));
        memset(visited,false,sizeof(visited));

        m[ix][iy]=1;


        int ans = bfs(ix,iy,fx,fy);


        printf("To get from %s to %s takes %d knight moves.\n",a,b,ans);
    }

    return 0;

}

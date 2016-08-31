#include<bits/stdc++.h>
using namespace std;

int n,ma;
int b;
bool visited[1010][1010];
int m[1010][1010];
int ix,iy;
int fx,fy;
int cost[1010][1010];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool valid(int x,int y){
    if(x>=0 && y>=0 && x<n && y<ma && !visited[x][y]) return true;
    return false;
}

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

        if(xx== fx && yy==fy) return cost[xx][yy];

        for(int i=0;i<4;i++){
            int x1=xx+dx[i];
            int y1=yy+dy[i];
            if(valid(x1,y1)){
                Q.push(x1);
                Q.push(y1);
                visited[x1][y1]=true;
                cost[x1][y1]=cost[xx][yy]+1;
            }

        }

    }

    return 0;
}

int main(){

    while(scanf("%d %d",&n,&ma)){
        if(n==0 && ma==0)
            break;

        scanf("%d",&b);
        for(int i=0;i<n;i++){
            for(int j=0;j<ma;j++){
                visited[i][j]=false;
            }
        }

        for(int i=0;i<b;i++){
            int a,num;
            scanf("%d %d",&a,&num);
            for(int j=0;j<num;j++){
                int d;
                scanf("%d",&d);
                visited[a][d]=true;
            }
        }

        scanf("%d %d",&ix,&iy);
        scanf("%d %d",&fx,&fy);

        int ans = bfs(ix,iy,fx,fy);

        printf("%d\n",ans);
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int r,c;
char m[25][25];
bool visited[25][25];
int cost[25][25];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


bool valid(int x,int y){

    if(x>=0 && y>=0 && x<r && y<c && !visited[x][y] && m[x][y]!='#' && m[x][y]!='m') return true;
    return false;
}

int bfs(int x,int y){

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

        if(m[xx][yy]=='h') return cost[xx][yy];

        for(int i=0;i<4;i++){
            int x1 = xx+ dx[i];
            int y1 = yy + dy[i];
            if(valid(x1,y1)){
                visited[xx][yy]=true;
                cost[x1][y1]=cost[xx][yy]+1;
                Q.push(x1);
                Q.push(y1);

            }

        }

    }

    return 0;


}

int main(){

    int t;
    int ans;
    int pre=-1;

    scanf("%d",&t);
    for(int k=0;k<t;k++){
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++){
            cin>>m[i];
        }

        memset( visited, false, sizeof( visited ) );


        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(m[i][j]=='a'||m[i][j]=='b'||m[i][j]=='c'){
                    ans=bfs(i,j);
                    if(ans>pre) pre=ans;
                    memset( visited, false, sizeof( visited ) );
                }
            }
        }


        printf("Case %d: %d\n",k+1,pre);


    }



    return 0;

}

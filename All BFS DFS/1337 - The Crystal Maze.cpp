#include<bits/stdc++.h>
using namespace std;

int r,c,q;
char a[505][505];
bool visited[505][505];
int rep[505][505];
int p[505];
int  k;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
map<int,int>m;
bool valid(int x,int y){

    if(x>=0 && y>=0 && x<r && y<c && !visited[x][y] && a[x][y]!='#') return true;
    return false;

}

int bfs(int x,int y){
    int sum=0;
    queue<int>Q;
    Q.push(x);
    Q.push(y);
    visited[x][y]=true;
    if(a[x][y]=='C') sum++;
    rep[x][y]=k;
    //cout<<x<<" "<<y<<"\n";
    while(!Q.empty()){
        int xx = Q.front();
        Q.pop();
        int yy = Q.front();
        Q.pop();
        visited[xx][yy]=true;
        rep[xx][yy]=k;
        for(int i=0;i<4;i++){
            int x1= xx + dx[i];
            int y1= yy + dy[i];
            if(valid(x1,y1)){
                if(a[x1][y1]=='C') sum++;
                //cout<<x1<<" "<<y1<<"\n";
                visited[x1][y1]=true;
                rep[x1][y1]=k;
                Q.push(x1);
                Q.push(y1);
            }
        }
    }

    return sum;

}

int main(){

    int t;
    scanf("%d",&t);
    for(int y=1;y<=t;y++){

        scanf("%d %d %d",&r,&c,&q);

        memset(visited,false,sizeof(visited));

        for(int i=0;i<r;i++)
            scanf("%s",a[i]);

        k = 1;
        printf("Case %d:\n",y);
        while(q--){

            int x,y;
            scanf("%d %d",&x,&y);

            if(visited[x-1][y-1]==false){

                int sum = bfs(x-1,y-1);
                cout<<sum<<"\n";
                m[k]= sum;
                k++;

            }
            else{

                int p = rep[x-1][y-1];

                cout<<m[p]<<"\n";
            }


        }

    }

}

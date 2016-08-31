#include<bits/stdc++.h>
using namespace std;
char a[35][85];
bool visited[35][85];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void dfs(int x,int y){
    a[x][y]='#';
    visited[x][y]==true;
    for(int i=0;i<4;i++){
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(visited[xx][yy]==false && a[xx][yy]==' '){
            dfs(xx,yy);
        }
    }

}

int main(){

    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    int t,e,x,y,flag;
    cin>>t;
    getchar();
    for(int k=0;k<t;k++){
        memset(visited,false,sizeof(visited));
        for(int i=0;i<35;i++){
            gets(a[i]);
            if(a[i][strlen(a[i])-1]=='_') {
                    e =i;
                    break;
            }
        }

        for(int i=0;i<=e;i++){
            for(int j=0;j<strlen(a[i]);j++){
                if(a[i][j]=='*'){
                    dfs(i,j);
                }
            }
        }


        for(int i=0;i<=e;i++){
            puts(a[i]);
        }

    }

    return 0;

}

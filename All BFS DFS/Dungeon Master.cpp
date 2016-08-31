#include<bits/stdc++.h>
using namespace std;

int t,r,c;
char m[35][35][35];
bool visited[35][35][35];
int di[]={1, 0, -1, 0, 0, 0};
int dj[]={0, -1, 0, 1, 0, 0};
int dk[]={0, 0, 0, 0, 1, -1};
int cost[35][35][35];

bool valid(int k,int j,int i){
    if(m[k][i][j]!='#' && k>=0 && j>=0 && i>=0 && k<t && j<c && i<r && !visited[k][i][j]) return true;
    return false;
}

int bfs(int k,int i,int j){
    queue<int>Q;
    Q.push(k);
    Q.push(i);
    Q.push(j);
    visited[k][i][j]=true;
    cost[k][i][j]=0;
    while(!Q.empty()){
        int kk=Q.front();
            Q.pop();
        int ii=Q.front();
            Q.pop();
        int jj=Q.front();
            Q.pop();
        if(m[kk][ii][jj]=='E') {
            return cost[kk][ii][jj];
        }


        for(int i=0;i<6;i++){
            int k1= kk + dk[i];
            int j1= jj + dj[i];
            int i1= ii + di[i];

            if(valid(k1,j1,i1)){
                Q.push(k1);
                Q.push(i1);
                Q.push(j1);
                visited[k1][i1][j1]=true;
                cost[k1][i1][j1]=cost[kk][ii][jj]+1;

            }
        }
    }

    return 0;
}

int main(){


    int a;
    while(scanf("%d %d %d",&t,&r,&c)){
        if(t==0 && r==0 && c==0) break;

        for(int k=0;k<t;k++){

                for(int i=0;i<r;i++){
                    cin >> m[k][i];
                }

        }

        memset( visited, false, sizeof( visited ) );


        for(int k=0;k<t;k++){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(m[k][i][j]=='S'){
                        a= bfs(k,i,j);
                        break;
                    }
                }
            }
        }



        if(a>0) printf("Escaped in %d minute(s).\n",a);
        else printf("Trapped!\n");

    }

    return 0;
}

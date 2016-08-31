#include<bits/stdc++.h>
using namespace std;

int n;
char m[15][15];

bool visited[15][15];
int cost[15][15];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int bfs(int x,int y){

    queue<int>Q;
    Q.push(x);
    Q.push(y);
    visited[x][y]=true;
    cost[x][y]=

    while()

}


int main(){

    int t,a,b,c;
    cin>>t;

    for(int k=0;k<t;k++){

        cin>>n;
        for(int i=0;i<n;i++){
            cin>>m[i];
        }

        a=0;b=0;c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]=='A'){
                    a = bfs(i,j);
                }

                if(m[i][j]=='B'){
                    b = bfs(i,j);
                }

                if(m[i][j]=='C'){
                    c = bfs(i,j);
                }

            }
        }

        if(a!=0 && b!=0 && c!=0)ans=max(max(a,b),c);


        if(ans>0) printf("Case %d: %d\n",k+1,ans);
        else printf("Case %d: trapped\n",k+1;)



    }



    return 0;



}

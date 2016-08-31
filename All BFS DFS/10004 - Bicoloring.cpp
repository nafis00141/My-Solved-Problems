#include<bits/stdc++.h>
using namespace std;
vector<int>v[205];
bool visited[205];
char col[205];

void bfs(int x){

    queue<int>Q;
    Q.push(x);
    while(Q.empty()==false){
        int u = Q.front();
        Q.pop();
        for(int i=0;i<v[u].size();i++){
            int x=v[u][i];
            if(visited[x]==false){
                if(col[u]=='b') col[x]='w';
                else col[x]='b';
                visited[x]=true;
                Q.push(x);
            }
        }
    }

}

int main(){

    int n;

    while(scanf("%d",&n)==1){
        if(n==0) break;
        int e;
        cin>>e;

        memset(col,'a',sizeof(col));

        for(int i=0;i<205;i++){
            v[i].clear();
            visited[i]=false;
        }

        for(int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        col[0]='b';
        bfs(0);

         /*for(int j=0;j<n;j++) cout<<col[j]<<" ";
         cout<<"\n";*/
        int flag=0;
        for(int i=0;i<n;i++){
                //cout<<"source "<<i<<"\n";
        for(int j=0;j<v[i].size();j++){
            int p=v[i][j];

            //cout<<p<<" color "<<col[p]<<"\n";
            if(col[i]==col[p]){
                flag=1;
                break;
            }
        }
            if(flag==1) break;
        }

    if(flag==1) cout<<"NOT BICOLORABLE.\n";
    else cout<<"BICOLORABLE.\n";
    }

    return 0;

}
/*
1
0
6
9
0 1
0 4
0 5
1 2
1 3
1 4
2 3
2 5
3 5
4
3
0 1
1 2
2 3
*/

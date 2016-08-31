#include<bits/stdc++.h>
using namespace std;
int n,e;

vector<int>v[105];
bool visited[105];
int cost[105];
int cost1[105];

void bfs1(int q){

    visited[q] = true;
    queue <int> Q;
    Q.push(q);
    while(Q.empty() == false){
        int x = Q.front();
        Q.pop();
        for(int i = 0;i < v[x].size();i++){
            int xx = v[x][i];
            if(visited[xx] == false){
                visited[xx] = true;
                cost[xx] = cost[x]+1;
                Q.push(xx);
            }
        }
    }

}


void bfs2(int q){

    visited[q] = true;
    queue <int> Q;
    Q.push(q);
    while(Q.empty() == false){
        int x = Q.front();
        Q.pop();
        for(int i = 0;i < v[x].size();i++){
            int xx = v[x][i];
            if(visited[xx] == false){
                visited[xx] = true;
                cost1[xx] = cost1[x]+1;
                Q.push(xx);
            }
        }
    }

}

int main(){

    int t;
    cin>>t;
    for(int y=1;y<=t;y++){

        cin>>n>>e;

        for(int i=0;i<n;i++){
            cost[i]=0;
            cost1[i]=0;
            v[i].clear();
        }
        memset(visited,false,sizeof(visited));
        int a,b;

        while(e--){

            cin>>a>>b;

            v[a].push_back(b);
            v[b].push_back(a);

        }

        int s,d;

        cin>>s>>d;

        bfs1(s);

        /*for(int i=0;i<n;i++){
            cout<<cost[i]<<" ";
        }
        cout<<"\n";*/
        memset(visited,false,sizeof(visited));
        bfs2(d);

         /*for(int i=0;i<n;i++){
            cout<<cost1[i]<<" ";
        }*/

        for(int i=0;i<n;i++){
            cost[i]=cost[i]+cost1[i];
        }

        sort(cost,cost+n);

        printf("Case %d: %d\n",y,cost[n-1]);



    }

}

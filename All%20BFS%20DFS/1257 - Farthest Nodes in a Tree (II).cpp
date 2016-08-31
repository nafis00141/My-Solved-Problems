#include<bits/stdc++.h>
using namespace std;
vector<int>V[30000];
vector<int>C[30000];
bool visited[30000];
int cost[30000];
int co[30000];
int a;
int p;

void dfs(int x){

    visited[x]=true;
    for(int i=0;i<V[x].size();i++){
        int xx  = V[x][i];
        if(visited[xx]==false){
            cost[xx]=cost[x]+C[x][i];
            if(p<cost[xx]){
                p = cost[xx];
                a = xx;
            }
            dfs(xx);
        }
    }

}

void dfs2(int x){

    visited[x]=true;
    for(int i=0;i<V[x].size();i++){
        int xx  = V[x][i];
        if(visited[xx]==false){
            co[xx]=co[x]+C[x][i];
            dfs2(xx);
        }
    }

}

int main(){

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        memset(visited,false,sizeof(visited));
        memset(cost,0,sizeof(cost));
        memset(co,0,sizeof(co));
        for(int j=0;j<n-1;j++){
            int d,b,c;
            cin>>d>>b>>c;

            V[d].push_back(b);
            V[b].push_back(d);
            C[d].push_back(c);
            C[b].push_back(c);


        }

        p=0;
        dfs(0);

        memset(visited,false,sizeof(visited));
        memset(cost,0,sizeof(cost));
        p=0;
        dfs(a);


        memset(visited,false,sizeof(visited));
        memset(co,0,sizeof(co));

        dfs2(a);

        printf("Case %d:\n",i+1);

        for(int i=0;i<n;i++){
            printf("%d\n",max(cost[i],co[i]));
            V[i].clear();
            C[i].clear();
        }

    }


}


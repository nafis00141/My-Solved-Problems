#include<bits/stdc++.h>
using namespace std;

vector<int>v[100005],u;
bool visited[100005];
int cost[100005];
int m;
void dfs(int a){

    visited[a]=true;
    for(int i=0;i<v[a].size();i++){
        int xx = v[a][i];
        if(visited[xx]==false){
            if(cost[xx]!=0)cost[xx]=cost[xx]+cost[a];
            if(cost[xx]>m) continue;
            dfs(xx);
            if(v[xx].size()==1 && v[xx][0]==a) u.push_back(xx);
        }
    }

}

int main(){

    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    int e=0;
    for(int i=0;i<u.size();i++){
        if(cost[u[i]]<=m) e++;
        //cout<<u[i]<<"\n";
    }

    cout<<e<<"\n";

}

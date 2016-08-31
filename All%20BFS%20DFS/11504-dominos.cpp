#include<bits/stdc++.h>
using namespace std;
vector<int>V[100005];
bool visited[100005];
stack<int>s;
void dfs(int a){
    visited[a]=true;
    for(int i=0;i<V[a].size();i++){
        int w = V[a][i];
        if(visited[w]==false){
            dfs(w);
        }
    }
    s.push(a);
}

void dfs2(int a){
    visited[a]=true;
    for(int i=0;i<V[a].size();i++){
        int w = V[a][i];
        if(visited[w]==false){
            dfs(w);
        }
    }
}

int main(){
    int t;
    int n,e;
    cin>>t;
    for(int i=0;i<t;i++){
        memset(visited,false,sizeof(visited));
        for(int i=0;i<100005;i++) V[i].clear();
        cin>>n>>e;
        for(int j=0;j<e;j++){
            int a,b;
            cin>>a>>b;
            V[a].push_back(b);
        }

        for(int k=1;k<=n;k++){
            if(visited[k]==false){
                dfs(k);
            }
        }
        memset(visited,false,sizeof(visited));
        int c=0;
        while(s.empty()==false){
            int u=s.top();
            s.pop();
            if(visited[u]==false){
                dfs2(u);
                c++;
            }
        }

        cout<<c<<"\n";

    }
}

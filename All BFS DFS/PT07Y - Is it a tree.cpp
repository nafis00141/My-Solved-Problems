#include<bits/stdc++.h>
using namespace std;
vector<int>V[10005];
bool visited[10005];

void bfs(int a){

    queue<int>Q;
    visited[a]=true;
    Q.push(a);
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        for(int i=0;i<V[x].size();i++){
            int  d = V[x][i];
            if(visited[d]==false){
                visited[d]=true;
                Q.push(d);
            }
        }
    }
}

int main(){

    memset(visited,false,sizeof(visited));
    int n,e,a,b;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    if(n==(e+1)){

        bfs(1);
        for(int i=1;i<=n;i++){
            if(visited[i]==false){
                printf("NO\n");
                return 0;
            }
        }

        printf("YES\n");

    }
    else{
        printf("NO\n");
    }

    return 0;

}

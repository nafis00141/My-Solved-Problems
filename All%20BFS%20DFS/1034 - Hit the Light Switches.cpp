#include<bits/stdc++.h>
using namespace std;

int n,e;

vector<int>v[10005];
bool visited[10005];
bool indeg[10005];
stack<int>s;


void dfs(int a){

    visited[a]=true;

    for(int i=0;i<v[a].size();i++){
        int w = v[a][i];
        if(visited[w]==false){
            dfs(w);
        }

    }
    s.push(a);
}


void dfs2(int a){
    visited[a]=true;
    for(int i=0;i<v[a].size();i++){
        int w = v[a][i];
        if(visited[w]==false){
            dfs(w);
        }
    }
}



int main(){

    int t;
    scanf("%d",&t);

    for(int y=1;y<=t;y++){

        memset(visited,false,sizeof(visited));
        memset(indeg,false,sizeof(indeg));

        for(int i=0;i<=n;i++){

            v[i].clear();

        }

        scanf("%d %d",&n,&e);
        int a,b;
        while(e--){

            scanf("%d %d",&a,&b);
            v[a].push_back(b);

        }

        int sum=0;


        for(int i=1;i<=n;i++){

            if(visited[i]==false){

                dfs(i);

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

        printf("Case %d: %d\n",y,c);


    }

    return 0;

}

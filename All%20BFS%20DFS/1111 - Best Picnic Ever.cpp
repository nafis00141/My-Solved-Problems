#include<bits/stdc++.h>
using namespace std;
int k,n,e;

int node[1005];
bool visited[1005];
vector<int>v[1005];
vector<int>p;

void dfs(int x){

    visited[x]=true;
    node[x]++;
    //cout<<x<<" ";
    for(int i=0;i<v[x].size();i++){
        int xx = v[x][i];
        if(visited[xx]==false){
            dfs(xx);
        }
    }

}

int main(){

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){

        cin>>k>>n>>e;

        //memset(visited,false,sizeof(visited));

        p.clear();

        for(int l=0;l<=n;l++){

            node[l]=0;

            v[l].clear();

        }



        int r;

        for(int l=1;l<=k;l++){

            cin>>r;
            p.push_back(r);

        }


        int a,b;
        while(e--){

            cin>>a>>b;
            v[a].push_back(b);

        }

        for(int l=0;l<p.size();l++){

            memset(visited,false,sizeof(visited));
            dfs(p[l]);
            //cout<<"\n";

        }

        int cou=0;

        for(int l=1;l<=n;l++){

            if(node[l]==k) cou++;

        }

        printf("Case %d: %d\n",i,cou);


    }

}

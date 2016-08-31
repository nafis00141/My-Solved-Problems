#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>v[105];
bool visited[105];
vector<int>r;

void dfs(int x){

    for(int i=0;i<v[x].size();i++){
        int xx = v[x][i];
        if(visited[xx]==false){
            visited[xx]=true;
            dfs(xx);
        }
    }

}

int main(){

    while(cin>>n,n!=0){

        for(int i=1;i<=n;i++) v[i].clear();

        int a;
        while(cin>>a,a!=0){

            int b;
            while(cin>>b,b!=0){
                v[a].push_back(b);
            }

        }

        int t;
        cin>>t;
        while(t--){
            memset(visited,false,sizeof(visited));
            int p;
            cin>>p;
            dfs(p);
            for(int i=1;i<=n;i++){
                if(visited[i]==false){
                    r.push_back(i);
                }
            }

            cout<<r.size();
            for(int e=0;e<r.size();e++){
                if(e==0)cout<<" ";
                cout<<r[e];
                if(e<(r.size()-1)) cout<<" ";
            }
            cout<<"\n";
            r.clear();
        }

    }

}

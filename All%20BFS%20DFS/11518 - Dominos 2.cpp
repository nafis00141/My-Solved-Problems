#include<bits/stdc++.h>
using namespace std;

vector<int>V[10005];
bool visited[10005];

void dfs(int a){
    visited[a]=true;
    for(int i=0;i<V[a].size();i++){
        int b =V[a][i];
        if(visited[b]==false){
            dfs(b);
        }
    }
}

void Vclear(){
    for(int i=0;i<10005;i++){
        V[i].clear();
        visited[i]=false;
    }

}
int main(){

    int t;
    cin>>t;

    for(int k=0;k<t;k++){
        Vclear();
        int n,m,l;
        cin>>n>>m>>l;
        for(int j=0;j<m;j++){
            int a,b;
            cin>>a>>b;
            V[a].push_back(b);
        }

        for(int j=0;j<l;j++){
            int a;
            cin>>a;
            dfs(a);
        }
        int cou=0;
        for(int j=1;j<=n;j++){
            if(visited[j]==true) cou++;
        }

        cout<<cou<<"\n";

        return 0;


    }


}

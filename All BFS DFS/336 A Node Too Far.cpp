#include<bits/stdc++.h>
using namespace std;

int e;
vector<int>v[40];
map<int,int>m;
bool visited[40];
int cost[40];

void bfs(int a){

    queue<int>Q;
    visited[a]=true;
    cost[a]=0;
    Q.push(a);
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        for(int i=0;i<v[x].size();i++){
            int  d = v[x][i];
            if(visited[d]==false){
                visited[d]=true;
                cost[d]=cost[x]+1;
                Q.push(d);
            }
        }
    }
}

int main(){

    int y=1;
    while(cin>>e,e!=0){
        int a,b;
        int i=1;
        for(int j=0;j<40;j++) {
                cost[j]=INT_MAX/3;
        }
        while(e--){

            cin>>a>>b;
            if(m.find(a)==m.end()){
                m[a]=i;
                i++;
            }

            if(m.find(b)==m.end()){
                m[b]=i;
                i++;
            }

            v[m[a]].push_back(m[b]);
            v[m[b]].push_back(m[a]);

        }

        while(cin>>a>>b){

            if(a==0 && b==0) {
                m.clear();
                for(int j=0;j<i;j++) {
                    v[j].clear();
                }
                break;
            }

            bfs(m[a]);

            int cou=0;
            for(int p = 1;p < i;p++){
                if(b < cost[p]) cou++;
            }

            cout<<"Case "<< y<<": "<<cou<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<".\n";
            y++;

            for(int j=0;j<40;j++) {
                cost[j]=INT_MAX/3;
            }
            memset(visited,false,sizeof(visited));

        }

    }

}

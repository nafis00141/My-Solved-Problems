#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
map<int,string>mp;
vector<int>v[100005];
bool visited[100005];
int par[100005];

void bfs(int x){

    visited[x]=true;
    queue<int>q;
    q.push(x);
    while(!q.empty()){

        int x = q.front();
        q.pop();
        for(int j=0;j<v[x].size();j++){
            int xx = v[x][j];
            if(visited[xx]==false){
                visited[xx]=true;
                par[xx]=x;
                q.push(xx);
            }
        }

    }

}
int main(){

    int e,z;
    z=1;
    string a,b;
    while(scanf("%d",&e)!=EOF){
        if(z!=1) cout<<"\n";
        m.clear();
        mp.clear();
        memset(visited,false,sizeof(visited));
        memset(par,0,sizeof(par));
        int i=1;
        while(e--){

            cin>>a>>b;
            if(m.find(a) == m.end()){
                m[a] =i;
                mp[i]=a;
                i++;
            }

            if(m.find(b) == m.end()){
                m[b] =i;
                mp[i]=b;
                i++;
            }

            v[m[a]].push_back(m[b]);
            v[m[b]].push_back(m[a]);

        }

        cin>>a>>b;

        if(m.find(a) == m.end()){
                m[a] =i;
                mp[i]=a;
                i++;
        }

        if(m.find(b) == m.end()){
                m[b] =i;
                mp[i]=b;
                i++;
        }

        bfs(m[a]);
        //cout<<"ab\n";

        if(visited[m[b]]){

            //cout<<"aa\n";
            stack<int>p,c;
            int i=m[b];
            while(i!=m[a]){
                p.push(par[i]);
                c.push(i);
                i=par[i];
            }

            while(!p.empty()){
                int x = p.top();
                p.pop();
                int y = c.top();
                c.pop();
                cout<<mp[x]<<" "<<mp[y]<<"\n";
            }

        }
        else cout<<"No route\n";


        for(int p=1;p<=i;p++) v[p].clear();
        z++;
    }

}

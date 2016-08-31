#include<bits/stdc++.h>
using namespace std;

map<char,int>m;
map<int,char>mp;
vector<int>v[100005];
bool visited[100005];
int par[100005];

void bfs(int x,int y){

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
                if(xx==y) return;
                q.push(xx);
            }
        }

    }

}

int main(){

    int t,i;
    char u='R';
    cin>>t;
    for(int p=1;p<=t;p++){
        int e,n;
        mp.clear();
        m.clear();
        memset(visited,false,sizeof(visited));
        memset(par,0,sizeof(par));
        i=1;
        mp[i]=u;
        m[u]=i;
        i++;
        cin>>e>>n;

        while(e--){
            string a,b;
            cin>>a>>b;

             if(m.find(a[0]) == m.end()){
                m[a[0]] =i;
                mp[i]=a[0];
                i++;
            }

            if(m.find(b[0]) == m.end()){
                m[b[0]] =i;
                mp[i]=b[0];
                i++;
            }

            v[m[a[0]]].push_back(m[b[0]]);
            v[m[b[0]]].push_back(m[a[0]]);
        }



        while(n--){
            string a,b;
            cin>>a>>b;
            bfs(m[a[0]],m[b[0]]);

            int k=m[b[0]];
            stack<char>q;
            while(k!=m[a[0]]){
                //cout<<mp[k];
                q.push(mp[k]);
                k=par[k];
            }
            q.push(a[0]);

            while(q.empty()==false){
                char d = q.top();
                cout<<d;
                q.pop();
            }

            cout<<"\n";

            memset(visited,false,sizeof(visited));
            memset(par,0,sizeof(par));

        }

        if(p!=t)cout<<"\n";

        for(int p=1;p<=i;p++) v[p].clear();

    }

}

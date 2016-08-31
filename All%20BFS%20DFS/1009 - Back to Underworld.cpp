#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000+10];
bool visited[100000+10];
int race[100000+10];
//bool check[100000+10];
map<int,int>m;
int e;
int va;
int l;

void dfs(int x){

    visited[x]=true;
    if(race[x]==1) va++;
    else if(race[x]==2) l++;
    for(int i=0;i<v[x].size();i++){
        int a = v[x][i];
        if(visited[a]==false){
            if(race[x]==1) race[a]=2;
            else if(race[x]==2) race[a]=1;
            dfs(a);
        }
    }

}

int main(){

    int t;
    cin>>t;
    for(int p=1;p<=t;p++){

        memset(visited,false,sizeof(visited));
        //memset(check,false,sizeof(check));

        cin>>e;
        int n=1;
        int a,b;
        while(e--){

            cin>>a>>b;

            if(m.find(a)==m.end()){

                m[a]=n;
                n++;
            }

             if(m.find(b)==m.end()){

                m[b]=n;
                n++;
            }

            v[m[a]].push_back(m[b]);
            v[m[b]].push_back(m[a]);

            //cout<<m[a]<<" "<<m[b]<<"\n";

        }

        for(int i=1;i<n;i++) race[i]=1;
        int r=0;

        for(int i=1;i<n;i++){
            va=0;
            l=0;
            if(visited[i]==false) dfs(i);
            r = r+max(va,l);
        }


        for(int i=1;i<n;i++){
            v[i].clear();
        }

        printf("Case %d: %d\n",p,r);
        m.clear();

    }

}

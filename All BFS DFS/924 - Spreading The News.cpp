#include<bits/stdc++.h>
using namespace std;

vector<int>v[2505];
bool visited[2505];
int cost[2505],co[2505];
bool flag;
set<int>se;
map<int,int>mp;

void bfs(int s){

    cost[s]=0;
    visited[s]=true;
    queue<int>Q;
    Q.push(s);

    while(!Q.empty()){

        int x = Q.front();
        Q.pop();
        for(int i=0;i<v[x].size();i++){

            int xx = v[x][i];

            if(visited[xx]==false){
                flag=1;
                visited[xx]=true;
                cost[xx]=cost[x]+1;
                Q.push(xx);
            }
        }
    }
}


int main(){

   int n;
   cin>>n;
   for(int i=0;i<n;i++){
        int e,a;
        cin>>e;
        while(e--){
            cin>>a;
            v[i].push_back(a);
        }
   }

   int t;
   cin>>t;
   while(t--){

        int s;
        cin>>s;
        flag=0;
        memset(cost,0,sizeof(cost));
        memset(visited,false,sizeof(visited));

        bfs(s);

        if(flag==0){
            cout<<"0\n";
        }
        else{
            for(int i=0;i<n;i++){
                if(i==s) continue;
                se.insert(cost[i]);
                if(mp.find(cost[i])==mp.end()){
                    mp[cost[i]]=1;
                }
                else mp[cost[i]]++;
            }

            int ma=0;
            int f=0;

            set<int>::iterator it;

            for(it=se.begin();it !=se.end();it++){
                if(mp[*it]>ma && *it!=0 ){
                    ma=mp[*it];
                    f=*it;
                }
            }

            cout<<ma<<" "<<f<<"\n";

            se.clear();
            mp.clear();



        }

   }

   return 0;

}

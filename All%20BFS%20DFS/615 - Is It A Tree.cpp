#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
vector<int>v[10000000];
bool t[10000000];
bool in[10000000];

int e;

void dfs(int x){

    t[x] = true;
    for(int i=0;i<v[x].size();i++){
        int y = v[x][i];
        if(t[y]==false){
            dfs(y);
        }
        else e = 1;
    }
}

int main(){

    int a,b;
    int i=1;
    int edge=0;
    int k=1;
    memset(t,false,sizeof(t));
    memset(in,false,sizeof(in));
    m.clear();
    while(cin>>a>>b){

        if(a<0 && b<0) break;

        else{

            if(a==0 && b==0){
                int j;
                int flag = 0;
                for(j=1;j<i;j++){
                    if(in[j]==false) break;
                }

                e = 0;

                dfs(j);

                if(e==0){

                    for(int j=1;j<i;j++){
                        if(t[j]==false) {
                            flag = 1;
                        }
                    }

                }
                else flag = 1;


                if(flag == 0) cout<<"Case "<<k<<" is a tree.\n";
                else cout<<"Case "<<k<<" is not a tree.\n";

                for(int j=0;j<10000000;j++) v[j].clear();
                memset(t,false,sizeof(t));
                memset(in,false,sizeof(in));
                m.clear();
                k++;
                i=1;
                continue;

            }

            edge ++;

            if(m.find(a) == m.end()){

                m[a] =i;
                i++;
            }

            if(m.find(b) == m.end()){

                m[b] =i;
                i++;

            }

            v[m[a]].push_back(m[b]);
            in[m[b]]=true;

        }

    }

}

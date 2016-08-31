#include<bits/stdc++.h>
using namespace std;
vector<int>V[30000];
vector<int>C[30000];
bool visited[30000];
int cost[30000];
int a;

int bfs( int x )
{
	queue<int>Q;
	Q.push(x);
    visited[x] = true;

    while(!Q.empty()){
    	int xx = Q.front();
    	Q.pop();
    	for(int i=0;i<V[xx].size();i++){
            int x1 = V[xx][i];
            if(!visited[x1]){
                visited[x1]=true;
                Q.push(x1);
                cost[x1]=cost[xx]+C[xx][i];
                if(cost[x1]>cost[a])a=x1;
            }
    	}
    }
}

int main(){

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        memset(visited,false,sizeof(visited));
        memset(cost,0,sizeof(cost));
        memset(V,0,sizeof(V));
        memset(C,0,sizeof(C));
        for(int j=0;j<n-1;j++){
            int d,b,c;
            cin>>d>>b>>c;

            V[d].push_back(b);
            V[b].push_back(d);
            C[d].push_back(c);
            C[b].push_back(c);


        }

        bfs(0);
        memset(visited,false,sizeof(visited));
        memset(cost,0,sizeof(cost));
        bfs(a);

        printf("Case %d: %d\n",i+1,cost[a]);

    }


}

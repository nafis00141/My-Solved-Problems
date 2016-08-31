#include<bits/stdc++.h>
using namespace std;
string a[30];
bool visited[30][30];
int i;

int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,1, -1,-1};

bool valid(int x,int y){
    if(x>=0 && y>=0 && x<i && y<i && !visited[x][y] && a[x][y]!='0') return true;
    return false;
}

int bfs(int x,int y){
    queue<int>Q;
    Q.push(x);
    Q.push(y);
    visited[x][y]=true;
    int s=1;
    while(!Q.empty()){

        int xx = Q.front();
        Q.pop();
        int yy = Q.front();
        Q.pop();

        for(int i=0;i<8;i++){
            int x1=xx+dx[i];
            int y1=yy+dy[i];
            if(valid(x1,y1)){
                s++;
                Q.push(x1);
                Q.push(y1);
                visited[x1][y1]=true;
            }
        }
    }

    return s;

}
int main(){

    int t;
    cin>>t;
    getchar();
    getchar();
    for(int e=1;e<=t;e++){

        i=0;
        memset(visited,false,sizeof(visited));
         while(getline(cin,a[i]) && a[i]!=""){
            i++;
        }

        int s=0,sum=0;

        for(int k=0;k<i;k++){
            for(int j=0;j<a[k].size();j++){
                if(visited[k][j]==false && a[k][j]=='1') {
                    s= bfs(k,j);
                    sum=max(sum,s);
                }
            }
        }


        cout<<sum<<"\n";
        if(e!=t) cout<<"\n";

    }

}

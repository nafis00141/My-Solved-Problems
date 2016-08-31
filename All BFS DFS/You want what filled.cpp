#include<bits/stdc++.h>
using namespace std;
#define u 100
int r,c;
char m[u][u];
bool visited[u][u];
int cost[u][u];

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

int bfs(int x,int y,char ch){

    int xx,yy;
    int x1,y1;
    queue<int>Q;
    Q.push(x);
    Q.push(y);
    visited[x][y]=true;
    cost[x][y]=1;
    int sum=0;
    while(!Q.empty()){
        xx = Q.front();
        Q.pop();
        yy = Q.front();
        Q.pop();

        for(int i=0;i<4;i++){
            x1 = xx + dx[i];
            y1 = yy + dy[i];

            if(x1>=0 && y1>=0 && x1<r && y1<c && visited[x1][y1]==false && m[x1][y1]==ch){
                visited[x1][y1]=true;
                cost[x1][y1]=cost[xx][yy]+1;
                Q.push(x1);
                Q.push(y1);
            }
        }

        sum++;
    }

    return sum;

}

struct node{
    char a;
    int b;
}arr[100000];

bool cmp( node x, node y )
{
    if ( x.b > y.b ) return true;
    if ( x.b == y.b && x.a < y.a ) return true;

    return false;
}

int main(){
    char s[1000];
    int val[1000];
    int p=1;
    while(scanf("%d %d",&r,&c)){

        if(r==0 && c==0){
            break;
        }

        memset(visited,false,sizeof( visited ));
        //memset(cost,0,sizeof( cost ));
        for(int i=0;i<u;i++)
            for(int j=0;j<u;j++)
                cost[i][j]=0;

        for(int i=0;i<r;i++)
            cin>>m[i];

        int cou=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(m[i][j]>='A' && m[i][j]<='Z'){
                    cou++;
                }
            }
        }
        printf("Problem %d:\n",p);
        char ch='A';
        int coun=0;
        for(int k=0;k<cou;k++){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(m[i][j]==ch && visited[i][j]==false){
                        int ans = bfs(i,j,ch);
                        arr[coun].a=ch;
                        arr[coun].b=ans;
                        //s[coun]=ch;
                        //val[coun]=ans;
                        coun++;
                    }
                }
            }

            ch=ch+1;
            if(ch>'Z') break;

        }

        sort( arr, arr+ coun , cmp );

        /*int temp;
        char t;
        for(int i=0;i<coun;i++){
            for(int j=i+1;j<coun;j++){
                if(val[i]<val[j]){
                    temp=val[i];
                    val[i]=val[j];
                    val[j]=temp;
                    temp=val[i+1];
                    val[i+1]=val[j];
                    val[j]=temp;
                    t=s[i];
                    s[i]=s[j];
                    s[j]=t;
                    t=s[i+1];
                    s[i+1]=s[j];
                    s[j]=t;
                }
            }
        }*/

        //printf("\n");


        for(int i=0;i<coun;i++){
            cout<<arr[i].a<<" "<<arr[i].b<<"\n";
        }

        p++;

    }

    return 0;


}

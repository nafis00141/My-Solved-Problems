#include<bits/stdc++.h>
using namespace std;

int rep[1005];
vector<int>t[1005];
bool visited[1005];

struct edge{
    int a, b , c;
}arr[1005];

void makeset(int n){
    for(int i=1;i<=n;i++) rep[i]=i;
}

int findr( int x ){
    if( rep[x] == x ) return x;
    return rep[x] = findr( rep[x] );
}

int unio(int i,int sum){
    int x,y;
    x = findr( arr[i].a );
    y = findr( arr[i].b );
    if( x != y ){
        rep[x] = y;
        sum++;
    }
    return sum;
}

int main()
{
    int n , m;
    cin >> n >> m;

    makeset(n);

    for( int i = 0; i < m; i++ ){
        int a, b, c ;
        cin >> a >> b;
        visited[a]=true;
        visited[b]=true;
        arr[i].a = a;
        arr[i].b = b;
        arr[i].c = 1;
    }

    int sum=0;
    for(int i=0;i<m;i++){
           sum=unio(i,sum);
    }

    int flag=0;

    for(int i=1;i<=n;i++)
        if(visited[i]==false) flag=1;

    if(sum==m && flag==0) cout<<"yes\n";
    else cout<<"no\n";
}

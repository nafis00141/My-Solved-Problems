#include<bits/stdc++.h>
using namespace std;

vector<int>pf;
map<int,int>m;
map<int,int>v;

void primeFactors(int n)
{
    int a = n;
    if(n%2==0 && n>2) pf.push_back(2);
    while (n%2 == 0)
    {
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2){

        if(n%i==0) pf.push_back(i);
        while (n%i == 0){
            n = n/i;
        }
    }

    if (n > 2 && n!=a) pf.push_back(n);
}


int bfs(int s,int f){

    queue<int>Q;
    Q.push(s);
    m[s]=0;
    while(!Q.empty()){

         int x = Q.front();
        Q.pop();
        pf.clear();
        primeFactors(x);
        if(x==f) return x;
        v[x]=1;
        for(int i=0;i<pf.size();i++){
            int xx = x + pf[i];
            if(v[xx]==0){

                if(xx==f) {
                    m[xx]=m[x]+1;
                    return xx;
                }
                else if(xx<f) {
                    m[xx]=m[x]+1;
                    v[xx]=1;
                    Q.push(xx);
                }

            }

        }

    }

    return -1;

}

int main(){

    int f,g;
    int i=1;
    while(scanf("%d %d",&f,&g)){

        if(f==0 && g==0) break;

        pf.clear();
        m.clear();
        v.clear();

        int a= bfs(f,g);

        if(a==-1) printf("Case %d: %d\n",i,a);
        else printf("Case %d: %d\n",i,m[a]);

        i++;

    }

    return 0;

}


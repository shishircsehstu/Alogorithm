//BISMILLAHIR RAHMANIR RAHIM
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<set>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
#define sii(a,b) scanf("%d%d",&a,&b)

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl

#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
#define MAX 100000
int n, e;
int par[MAX], visited[MAX];
vector< int > G[MAX];
bool is_bipartite()
{
    int i, u, v, start;
    queue< int > Q;
    start = 1;
    Q.push(start);
    par[start] = 1;
    visited[start] = 1;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(i=0; i < G[u].size(); i++)
        {
            v = G[u][i];
            if(par[u] == par[v]) return false;
            if(visited[v] == 0)
            {
                visited[v] = 1;
                par[v] = 3 - par[u];
                Q.push(v);
            }
        }
    }
    return true;
}

int main()
{
    int i, u, v;
    scanf("%d",&n);
    scanf("%d",&e);
    for(i = 0; i < e; i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(is_bipartite()) printf("Yes Bipartit.\n");
    else printf("NOT Bipartit.\n");
    memset(par,0,sizeof par);
    memset(visited,0,sizeof visited);
    for(i=0; i<=n; i++)
        G[i].clear();
    return 0;
}



#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LL;
typedef unsigned long long int ULL;

#define dbg(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;
#define IMAX ((unsigned)1<<31)-1
#define eps 1e-11
#define mem(a,v) memset(a,v,sizeof (a))
#define SZ(X) ((int)X.size())
#define VI vector<LL>
#define VS vector<string>
#define PB push_back
#define PI acos(-1.0)
#define mk make_pair
#define pll pair<LL,LL>
#define xx first
#define yy second
#define all(a) a.begin(),a.end()


#define MOD 1000000007
#define MX 100000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


//I/O

#define  S                         scanf
#define  P                         printf

#define I(X)                       scanf("%I64", &(X))
#define II(X, Y)                   scanf("%I64%I64", &(X), &(Y))
#define III(X, Y, Z)               scanf("%I64%I64%I64", &(X), &(Y), &(Z))


// Loop

#define  F(i,a,b)                  for(int i=a;i<b; i++)
#define  FF(i,a,b)                 for(int i=a;i<=b;i++)

LL n,m,k,ar[MX];
string str;
VI grap[1009];

int dp[1009][1009];

bool vis[1009];

int fun( int pos, int par, int parent )
{
    //show(pos,par);
    int &ret=dp[pos][par];
    if( ret != -1 ) return ret;

    vis[pos]=1;
    ret=0;
    if( par == 1 )
    {
        for( int i=0; i<SZ(grap[pos]); i++ )
        {
            int val=grap[pos][i];
            if( parent != val )
            {
                int cost1=fun(val,0,pos);
                ret+=cost1;
            }
        }
    }
    else
    {
        for( int i=0; i<SZ(grap[pos]); i++ )
        {

            int val=grap[pos][i];
            if( parent != val )
            {
                int cost1=fun(val,0,pos);
                int cost2=fun(val,1,pos)+1;
                cost1=max(cost1,cost2);
                ret+=cost1;
            }
        }
    }
    return dp[pos][par]=ret;
}

int main()
{
    SYN;
    int T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>m>>n;
        mem(dp,-1);
        mem(vis,0);
        int u,v;
        for( int i=0; i<n; i++ )
        {
            cin>>u>>v;
            grap[u].PB(v);
            grap[v].PB(u);
        }
        int sum=0,cost1=0,cost2=0;
        for( int i=1; i<=m; i++ )
        {
            if( !vis[i] )
            {
                cost1=fun(i,0,0);
                cost2=fun(i,1,0)+1;
                cost1=max(cost1,cost2);
                sum+=cost1;
            }

        }
        printf("Case %d: %d\n",t,sum);
        for( int i=0; i<=m; i++ ) grap[i].clear();
    }
    return 0;
}


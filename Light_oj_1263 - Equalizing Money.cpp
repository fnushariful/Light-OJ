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



LL n,m,k,ar[1009];
string str;

VI grap[1009];
int vis[1009];

int cnt=0;

int dfs( int x )
{
    if(vis[x] ) return 0;
    vis[x]=1;
    cnt++;
    int sum=ar[x];

    for( int i=0; i<SZ(grap[x]); i++ )
    {
        int tmp=grap[x][i];
        sum+=dfs(tmp);
    }
    return sum;
}

int main()
{
    SYN;
    int T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>n>>m;
        for( int i=1; i<=n; i++ )
        {
            cin>>ar[i];
        }

        LL u,v;
        for( int i=0; i<m; i++ )
        {
            cin>>u>>v;
            grap[u].PB(v);
            grap[v].PB(u);
        }

        set<int> st;
        LL val=0;
        bool ok=0;
        mem(vis,0);
        for( int i=1; i<=n; i++ )
        {
            val=0,cnt=0;
            if(!vis[i] )
            {
                val=dfs(i);
                if( val%cnt )
                {
                    ok=1;
                    break;
                }
                st.insert(val/cnt);
            }
        }
        if( SZ(st) == 1 && !ok ) printf("Case %d: Yes\n",t);
        else printf("Case %d: No\n",t);
        for( int i=1; i<=n; i++ )
        {
            grap[i].clear();
        }
        mem(ar,0);
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LL;
typedef unsigned long long int ULL;

#define mem(a,v) memset(a,v,sizeof (a))
#define SZ(X) ((int)X.size())
#define VI vector<LLI>
#define VS vector<string>
#define PB push_back


LL n,m,k;
string str;

vector<int> v[30009],cost[30009];
int vis[30009];
int ret=0;

int dfs( int src,int rst )
{
    //dbg(rst);
    for( int i=0; i<SZ(v[src]); i++ )
    {
        int val=v[src][i];
        if( !vis[val] )
        {
            vis[val]=1;
            int tmp=cost[src][i];
            //dbg(rst+tmp);
            dfs(val,rst+tmp);
            //ret=max(ret,);
        }
    }
    ret=max(ret,rst);
    return ret;
}

int main()
{
    SYN;
    int T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>n;
        int x,y,z;
        for( int i=0; i<n-1; i++ )
        {
            cin>>x>>y>>z;
            v[x].PB(y);
            v[y].PB(x);
            cost[x].PB(z);
            cost[y].PB(z);
        }
        cout<<"Case "<<t<<": "<<endl;
        for( int i=0; i<n; i++ )
        {
            vis[i]=1;
            dfs(i,0);
            cout<<ret<<endl;
            ret=0;
            mem(vis,0);
        }
        for( int i=0; i<n; i++ )
        {
            v[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

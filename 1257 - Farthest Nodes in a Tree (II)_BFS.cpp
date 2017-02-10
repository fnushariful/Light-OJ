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
int fst[30009],snd[30009];


int bfs(int src )
{
    bool vis[30009];
    queue<int> q;
    q.push(src);
    mem(vis,0);
    vis[src]=1;

    int top;
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        for( int i=0; i<SZ(v[top]); i++ )
        {
            int x=v[top][i];
            if( !vis[x] )
            {
                vis[x]=1;
                q.push(x);
            }
        }
    }
    return top;
}


int bfs1(int src )
{
    bool vis[30009];
    mem(vis,0);

    queue<int> q;
    q.push(src);
    vis[src]=1;
    fst[src]=0;
    int top;
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        for( int i=0; i<SZ(v[top]); i++ )
        {
            int x=v[top][i];
            int y=cost[top][i];
            if( !vis[x] )
            {
                vis[x]=1;
                fst[x]=fst[top]+y;
                q.push(x);
            }
        }
    }
    return top;
}


int bfs2(int src )
{
    bool vis[30009];
    mem(vis,0);
    queue<int> q;
    q.push(src);
    vis[src]=1;
    snd[src]=0;

    int top;
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        for( int i=0; i<SZ(v[top]); i++ )
        {
            int x=v[top][i];
            int y=cost[top][i];
            if( !vis[x] )
            {
                vis[x]=1;
                snd[x]=snd[top]+y;
                q.push(x);
            }
        }
    }
}


int main()
{
    SYN;
    int T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>n;
        int u,vv,w;
        for( int i=0; i<n-1; i++ )
        {
            cin>>u>>vv>>w;
            v[u].PB(vv);
            v[vv].PB(u);
            cost[u].PB(w);
            cost[vv].PB(w);
        }
        int top=bfs(u);
        //cout<<top<<endl;
        top=bfs1(top);
        //cout<<top<<endl;
        bfs2(top);

        cout<<"Case "<<t<<":"<<endl;
        for( int i=0; i<n; i++ )
        {
            int val=max(fst[i],snd[i]);
            cout<<val<<endl;
        }
        for( int i=0; i<n; i++ )
        {
            v[i].clear();
            cost[i].clear();
        }
        mem(fst,0);
        mem(snd,0);
    }
    return 0;
}


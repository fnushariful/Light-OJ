#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;

#define mem(a,v) memset(a,v,sizeof (a))
#define SZ(X) ((int)X.size())
#define PB push_back


// Loop

#define  F(i,a,b)                  for(int i=a;i<b; i++)
#define  FF(i,a,b)                 for(int i=a;i<=b;i++)

LLI n,m,k;
string str;

vector<LLI> v[1009],cost[1009];
LLI vis[1009];

LLI BFS( LLI source )
{
    mem(vis,0);
    queue<LLI> q;
    q.push(source);
    vis[source]=1;
    LLI sum=0;
    while(!q.empty())
    {
        LLI val=q.front();
        q.pop();
        F(i,0,SZ(v[val]))
        {
            LLI tmp=v[val][i];
            if( !vis[tmp] )
            {
                q.push(tmp);
                vis[tmp]=1;
                if( cost[val][i] < 0 ) sum+=(-1*cost[val][i]);
                break;
            }
        }
    }
    return sum;
}

int main()
{
    SYN;
    LLI x,y,z,p,q,r,T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>n;
        bool ok=0;
        F(i,0,n)
        {
            cin>>x>>y>>z;
            if( !ok ) m=x,ok=1;
            v[x].PB(y);
            v[y].PB(x);
            cost[x].PB(z);
            cost[y].PB(-z);
        }
        LLI sum=BFS(m);
        if( cost[m][1] >= 0 ) sum+=cost[m][1];
        //dbg(sum);
        swap(v[m][0],v[m][1]);
        swap(cost[m][0],cost[m][1]);
        LLI sum1=BFS(m);
        if( cost[m][1] >= 0 ) sum1+=cost[m][1];
        printf("Case %d: %lld\n",t,min(sum1,sum));
        for( int i=0; i<n+1; i++ )
        {
            cost[i].clear();
            v[i].clear();
        }
    }
    return 0;
}

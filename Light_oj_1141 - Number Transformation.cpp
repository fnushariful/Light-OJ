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



#define MX 10009
#define MOD 1000000007

LL n,m,k;
string str;
bool status[MX];
int prime[MX];
vector<int> v[1009];

void sieve()
{
    int sqrtN=sqrt(MX);
    for( int i=3; i<=sqrtN; i++ )
    {
        if( !status[i] )
        {
            for( int j=i*i; j<=MX; j+=2*i )
                status[j]=1;
        }
    }
    int k=1;
    prime[0]=2;
    for( int i=3; i<=MX; i+=2 )
    {
        if( !status[i])
            prime[k++]=i;
    }
    //cout<<prime[k-1]<<endl;
}

void factor(int val)
{
    int tmp=val;
    bool ok=0;
    for( int i=0; prime[i]*prime[i]<=val; i++ )
    {
        ok=0;
        while( val%prime[i] == 0 )
        {
            val/=prime[i];
            ok=1;
        }
        if(ok)
        {
            ok=0;
            v[tmp].PB(prime[i]);
        }
    }
    if( val > 1 && val != tmp ) v[tmp].PB(val);
}

int bfs(int src,int des)
{
    int dis[10009];
    int vis[10009];
    mem(dis,0);
    mem(vis,0);

    queue<int> qq;
    qq.push(src);
    dis[src]=0;
    vis[src]=1;
    //show(src,des);
    while(!qq.empty())
    {
        int tmp=qq.front();
        qq.pop();
        if( tmp == des ) return dis[des];
        //if( tmp > des ) return -1;
        if( tmp <= des )
        {
            for( int i=0; i<SZ(v[tmp]); i++)
            {
                int res=v[tmp][i]+tmp;
                if(!vis[res])
                {
                    vis[res]=1;
                    dis[res]=dis[tmp]+1;
                    //dbg(res);
                    qq.push(res);
                }
            }
        }
    }
    return -1;
}

int main()
{
    SYN;
    sieve();
    for( int i=2; i<=1009; i++ )
    {
        factor(i);
    }
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%lld%lld",&n,&m);
        int val=bfs(n,m);
        printf("Case %d: %d\n",t,val);
    }
    return 0;
}


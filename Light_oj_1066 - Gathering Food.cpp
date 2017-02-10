#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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


void show()
{
    cout<<'\n';
}
template<typename T,typename... Args>
void show(T a, Args... args)
{
    cout<<a<<" ";
    show(args...);
}
template<typename T>
void show_c(T& a)
{
    for ( auto &x:a )
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

const int fx[]= {+1,-1,+0,+0};
const int fy[]= {+0,+0,+1,-1};

LL n,m,k,ar[MX],table[MX];
string str[30];

bool boundery_cheek(int x,int y)
{
    if( x>=0 && x<=n && y>=0 && y<=n ) return 1;
    return 0;
}

LL bfs( pll src,pll des )
{
    str[src.xx][src.yy]='.';
    bool vis[30][30];
    mem(vis,0);
    LL dis[30][30];
    mem(dis,0);
    queue<pll> qq;
    vis[src.xx][src.yy]=1;
    qq.push(mk(src.xx,src.yy));
    dis[src.xx][src.yy]=0;
    //show(src.xx,src.yy);
    while(!qq.empty())
    {
        pll top=qq.front();
        qq.pop();
        for( int i=0; i<4; i++ )
        {
            LL p=top.xx+fx[i];
            LL q=top.yy+fy[i];
            if( boundery_cheek(p,q) && !vis[p][q] && ( str[p][q] == '.' || (des.xx == p && des.yy == q ) ) )
            {
                //show(p,q);
                str[p][q]='.';
                vis[p][q]=1;
                dis[p][q]=dis[top.xx][top.yy]+1;
                qq.push(mk(p,q));
            }
        }
    }
    return dis[des.xx][des.yy];
}


int main()
{
    SYN;
    int T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>n;
        string tmp;
        map<char,pll> mp;
        F(i,0,n)
        {
            cin>>tmp;
            for( int j=0; j<SZ(tmp); j++ )
            {
                if( isalpha(tmp[j]) )
                {
                    mp[tmp[j]]=mk(i,j);
                }
            }
            str[i]+=tmp;
        }
        vector<pll> v;
        for( auto x:mp ) v.PB(x.yy);
        LL sum=0;
        //for( auto x:v ) cout<<x.xx<<" "<<x.yy<<endl;
        bool ok=0;
        for( int i=0; i<SZ(v)-1; i++ )
        {
            pll p=v[i];
            pll q=v[i+1];
            int val=bfs(p,q);
            //dbg(val);
            if( val == 0 ) ok=1;
            sum+=val;
        }
        if( ok ) printf("Case %d: Impossible\n",t);
        else
            printf("Case %d: %lld\n",t,sum);
        for( int i=0; i<n; i++ ) str[i].clear();
    }
    return 0;
}


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



LL n,m,k,ar[MX];
string str;

VI grap[50009];
int par[50009];

int find_parent(int x)
{
    if( par[x] == x ) return par[x];
    return par[x]=find_parent(par[x]);
}

int union_find(int x,int y)
{
    int a=find_parent(x);
    int b=find_parent(y);
    if( a != b )
        par[b]=a;
}

int main()
{
    SYN;
    while(cin>>n)
    {
        LL x,y;
        for(int i=0; i<n; i++ )
        {
            cin>>x>>y;
            grap[x].PB(y);
        }
        for( int i=1; i<=n; i++ ) par[i]=i;
        for( int i=1; i<=n; i++ )
        {
            x=i;
            for( int j=0; j<SZ(grap[i]); j++ )
            {
                y=grap[i][j];
                if( par[x] != par[y] ) union_find(x,y);
            }
        }
        for( int i=1; i<=n; i++ ) cout<<par[i]<<" ";
        cout<<endl;
    }
    return 0;
}


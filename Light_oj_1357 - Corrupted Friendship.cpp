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

#define MX 100000
#define MOD 1000000007

LL n,m,k,ar[MX];
string str;

vector<int> v[1000];

int vis[MX];

int fun(int pos)
{
    if( vis[pos] ) return 0;
    if( SZ(v[pos]) == 1  ) return 1;
    int ret=0,tot=1;
    vis[pos]=1;
    for( int i=0; i<SZ(v[pos]); i++ )
    {
        int val=v[pos][i];
        tot*=fun(val);
        dbg(tot);
        ret+=tot;
        dbg(ret);
    }
    ret+=1;
    return ret;
}

int main()
{
    SYN;
    while(~S("%lld",&n))
    {
        int uu,vv;
        for( int i=0; i<n-1; i++ )
        {
            S("%d%d",&uu,&vv);
            v[uu].PB(vv);
        }
        int val=fun(1);
        cout<<val<<endl;
    }
    return 0;
}


/*


12
1 2
1 3
1 4
2 5
2 6
5 6
5 7
3 8
3 9
4 10
4 11













*/

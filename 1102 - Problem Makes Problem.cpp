
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





template<class T> inline T BIGMOD( T n,T m,T mod )
{
    LL ans = 1LL;
    LL k = n;
    while(m)
    {
        if( m & 1LL)
        {
            ans *=k;
            if( ans > mod ) ans %=mod;
        }
        k *=k;
        if(k>mod) k %= mod;
        m>>=1LL;
    }
    return ans;
}

template < class T > T modInverse(T b, T m)
{
    return BIGMOD(b, m-2, m);
}

#define MX 2000009LL
#define MOD 1000000007LL

LL n,m,k;
string str;

LL fact[MX];

int main()
{
    SYN;
    fact[0]=1;
    for( LL i=1; i<=2000008LL; i++ )
    {
        fact[i]=fact[i-1]*i;
        if( fact[i] >= MOD ) fact[i]=fact[i]%MOD;
    }
    int T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>n>>m;
        LL sum=n+m-1;
        LL res=fact[n]*fact[m-1];

        if( res >= MOD ) res=res%MOD;
        res=modInverse(res,MOD);
        res=res*fact[n+m-1];
        if( res >= MOD ) res%=MOD;

        printf("Case %d: %lld\n",t,res);

    }
    return 0;
}

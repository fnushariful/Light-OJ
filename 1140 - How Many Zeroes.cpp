#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned long long int ULLI;

#define dbg(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;
#define IMAX ((unsigned)1<<31)-1
#define eps 1e-11
#define mem(a,v) memset(a,v,sizeof (a))
#define SZ(X) ((int)X.size())
#define VI vector<LLI>
#define VS vector<string>
#define PB push_back
#define PI acos(-1.0)
#define mk make_pair
#define pll pair<LLI,LLI>
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

LLI n,m,k;
string str;

LLI toLInt(string s)
{
    LLI r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}

template<class T> string toString(T n)
{
    ostringstream ost;
    ost << n;
    ost.flush();
    return ost.str();
}


LLI dp[10][2][10][10];

LLI fun( LLI pos,bool coto,bool pre,LLI rst )
{
    if( pos == n )
    {
        //dbg(pos);
        //dbg(num);
        return rst;
    }
    LLI &ret=dp[pos][coto][pre][rst];

    if( ret != -1 ) return dp[pos][coto][pre][rst];
    ret=0;

    LLI hi=9,cnt=0;
    bool nx;
    if( coto == 1 )
    {
        hi=str[pos]-'0';
    }
    for( int i=0; i<=hi; i++ )
    {
        bool next;
        if( pre > 0 )
        {
            if( i == 0 ) cnt=1;
            else cnt=0;
            nx=pre;
        }
        else nx=i|pre,cnt=0;
        if( coto == 1 )
        {
            if( i == hi ) next=1;
            else next=0;
        }
        else next=coto;
        ret+=fun(pos+1,next,nx,rst+cnt);
    }
    return dp[pos][coto][pre][rst]=ret;
}

int main()
{
    string a,b;
    SYN;
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        cin>>a>>b;
        mem(dp,-1);
        str=a;
        m=toLInt(a);
        if( m != 0 ) m-=1;
        str=toString(m);
        n=SZ(str);
        LLI x=fun(0,1,0,0);
        mem(dp,-1);
        str=b;
        n=SZ(str);
        LLI y=fun(0,1,0,0);
        if( m == 0 ) y+=1;
        printf("Case %d: %lld\n",t,y-x);
    }
    return 0;
}

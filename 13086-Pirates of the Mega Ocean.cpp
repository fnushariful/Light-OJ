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

#define MX 100009
#define MOD 1000007LL

LL n,m,k,ar[MX],sr[MX],fst[MX],snd[MX],table[MX];
string str;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    SYN;
    int T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>n>>m;
        LL p,q,r,x,y,z;
        cin>>p>>q>>r>>x>>y>>z;
        LL mi=INT_MAX,val1,val2,val3;
        for( int i=1; i<=n; i++ )
        {
            val1=((i%MOD)*(i%MOD))%MOD;
            val1=((p%MOD)*(val1%MOD))%MOD;
            val2=((q%MOD)*(i%MOD))%MOD;
            //show(val1,val2);
            val2=((val2%MOD)+(r%MOD))%MOD;
            //show(val1,val2);
            ar[i]=((val1%MOD)+(val2%MOD))%MOD;
            //dbg(ar[i]);
            //ar[i]=(p*(i*i)+(q*i)+r)%1000007;
        }
        set<LL> st;
        for( int i=1; i<=m; i++ )
        {
            val1=((i%n)*(i%n))%n;
            val1=((x%n)*(val1%n))%n;
            val2=((y%n)*(i%n))%n;
            val2=((val2%n)+(z%n))%n;
            val1=((val1%n)+(val2%n))%n;
            sr[i]=val1+1;
            //dbg(sr[i]);

            st.insert(sr[i]);
        }
//        for( auto x:st ) cout<<x<<" ";
//        cout<<endl;
//        for( int i=1; i<=n; i++ ) cout<<ar[i]<<" ";
//        cout<<endl;
        LL pos;
        for( int i=1; i<=n; i++ )
        {
            if( ar[i] < mi && st.find(i) == st.end() )
            {
                mi=ar[i];
                pos=i;
            }
        }

        LL sum=0;
        for( int i=1; i<=n; i++ )
        {
            if( pos != i  )
            {
                sum+=ar[i]*mi;
            }
        }
        //sum/=3;

//        for( int i=1; i<=m; i++ )
//        {
//            sum+=ar[sr[i]]*mi;
//        }
        printf("Case %d: %lld\n",t,sum);
    }
    return 0;
}


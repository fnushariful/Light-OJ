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
#define MX 100009
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))


//I/O

#define  S                         scanf
#define  P                         printf

#define I(X)                       scanf("%I64", &(X))
#define II(X, Y)                   scanf("%I64%I64", &(X), &(Y))
#define III(X, Y, Z)               scanf("%I64%I64%I64", &(X), &(Y), &(Z))


// Loop

#define  F(i,a,b)                  for(LLI i=a;i<b; i++)
#define  FF(i,a,b)                 for(LLI i=a;i<=b;i++)


LLI n,m,k;
string str;

vector<LLI> mat[109];
LLI indgree[MX];

LLI topsort()
{
    priority_queue<LLI> pq;
    F(i,0,k)
    {
        if( indgree[i] == 0 )
        {
            pq.push(-i);
        }
    }
    vector<LLI> stor;
    while(!pq.empty())
    {
        m=(-1)*pq.top();
        pq.pop();

        F(i,0,SZ(mat[m]))
        {
            indgree[mat[m][i]]--;
            if( indgree[mat[m][i]] == 0 ) pq.push(-1*mat[m][i]);
        }
        stor.PB(m);
    }
    if( SZ(stor) == k ) return 1;
    return 0;
}

int main()
{
    SYN;
    map<string,LLI> mp;
    string a,b;
    int T;
    scanf("%d",&T);
    FF(t,1,T)
    {
        scanf("%lld",&n);
        LLI p,q;
        k=0;
        F(i,0,n)
        {
            cin>>a>>b;
            if( mp.find(a) == mp.end() ) mp[a]=k++;
            if( mp.find(b) == mp.end() ) mp[b]=k++;
            p=mp[a];
            q=mp[b];
            mat[p].PB(q);
            indgree[q]++;
        }
        if( topsort() == 1 )
            printf("Case %d: Yes\n",t);
        else printf("Case %d: No\n",t);
        mp.clear();
        mem(indgree,0);
        F(i,0,k) mat[i].clear();
    }
    return 0;
}

/*

2
soda wine
water wine

*/

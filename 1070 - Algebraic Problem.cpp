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
#define MSI map<string,int>
#define MLLI map<LLI,LLI>
#define MCI map<char,int>
#define PI acos(-1.0)
#define mk make_pair
#define pll pair<LLI,LLI>
#define xx first
#define yy second

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

ULLI row,col;
ULLI md,val;
struct st
{
    ULLI x[17][17];
};

typedef st matrix;

void print_matrix( int r,int c,matrix &a )
{
    for( int i=0; i<r; i++ )
    {
        for(int j=0; j<c; j++ )
            cout<<a.x[i][j]<<" ";
        cout<<endl;
    }
}

matrix set_zero(ULLI r,ULLI c)
{
    matrix rst;
    for( ULLI i=0; i<r; i++ )
    {
        for( ULLI j=0; j<c; j++ )
            rst.x[i][j]=0;
    }
    return rst;
}

matrix set_identity(ULLI r,ULLI c)
{
    matrix identity=set_zero(r,c);
    for( ULLI i=0; i<r; i++ )
    {
        identity.x[i][i]=1;
    }
    return identity;
}

matrix maltiplication( matrix &a,matrix &b)
{
    matrix rst=set_zero(row,col);
    //dbg("ok");
    for( ULLI i=0; i<row; i++ )
    {
        for( ULLI j=0; j<col; j++ )
        {
            for( ULLI k=0; k<col; k++ )
            {
                rst.x[i][j]=(rst.x[i][j]+(a.x[i][k]*b.x[k][j]));
                //dbg(rst.x[i][j]);
            }
        }
    }
    return rst;
}

matrix big_power( ULLI val ,matrix &a )
{
    matrix rst,tmp=a;
    //print_matrix(row,col,a);
    rst=set_identity(row,col);
    while( val )
    {
        //dbg("ok");
        if( val&1 )
        {
            rst=maltiplication(rst,tmp);
            //cout<<endl;
            //print_matrix(row,col,rst);
        }
        tmp=maltiplication(tmp,tmp);
        //cout<<endl;
        //print_matrix(row,col,tmp);
        val>>=1;
        //print_matrix(row,1,tmp);
    }
    return rst;
}


ULLI fastexpo(ULLI b,ULLI p)
{
    ULLI rst=1;
    while(p)
    {
        if(p&1) rst=rst*b;
        b=b*b;
        p>>=1;
    }
    return rst;
}

matrix set_base(ULLI r,ULLI c ,ULLI ar[])
{
    matrix a;
    memset(a.x,0,sizeof a.x);
    for( int i=0; i<c; i++ ) a.x[0][i]=ar[i]%md;
    for( int i=1,j=0; i<r; i++,j++ )
    {
        a.x[i][j]=1;
    }
    return a;
}

int main()
{
    //freopen("output.txt","w",stdout);
    ULLI a,b,n,m,d,ar[100],p,q;
    int T;
    scanf("%d",&T);
    for( int t=1; t<=T; t++ )
    {
        scanf("%llu%llu%llu",&p,&q,&n);
        matrix fibo,base;

        base.x[0][0]=p;
        base.x[0][1]=-q;
        base.x[1][0]=1;
        base.x[1][1]=0;

        row=2,col=2;
        matrix rst;
        rst=big_power(n-1,base);

        //print_matrix(2,2,rst);
        fibo.x[0][0]=p;
        fibo.x[1][0]=2;

        rst=maltiplication(rst,fibo);
        if( n == 0 ) printf("Case %d: 2\n",t);
        else
            printf("Case %d: %llu\n",t,rst.x[0][0]);
    }
    return 0;
}

/*

2 10 7
2 4
1 1

*/


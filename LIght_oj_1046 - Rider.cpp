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

const int fx[]= {-2, -2, -1, -1,  1,  1,  2,  2}; // Knights Move
const int fy[]= {-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

#define MX 15
#define MOD 1000000007

LL n,m,k,ar[MX],fst[MX],snd[MX],table[MX];
string str;

struct st
{
    int a,b;
};

int rw,col;

char mat[MX][MX];
int dis[MX][MX][MX];
int vis[MX][MX][MX];

bool check(int x,int y )
{
    if( (x>=0 && x<=rw) && (y>=0 && y<=col) ) return 1;
    return 0;
}

void bfs(int pos,st src,int op)
{
    //show(pos,src.a,src.b,op);
    queue<st> qq;
    qq.push(src);
    vis[pos][src.a][src.b]=1;
    dis[pos][src.a][src.b]=0;

    while(!qq.empty())
    {
        st top=qq.front();
        //show("104",top.a,top.b);
        qq.pop();
        for( int i=0; i<8; i++ )
        {
            for( int j=op; j>=1; j-- )
            {
                int x=top.a+(fx[i]*j);
                int y=top.b+(fy[i]*j);
                //show("112",x,y);
                if( !vis[pos][x][y] && check(x,y) )
                {
                    st tmp;
                    tmp.a=x;
                    tmp.b=y;
                    vis[pos][x][y]=1;
                    dis[pos][x][y]=dis[pos][top.a][top.b]+1;
                    //show("118",pos,x,y);
                    qq.push(tmp);
                }
            }
        }
    }
}

int main()
{
    SYN;
    while(cin>>rw>>col)
    {
        char ch;
        for( int i=0; i<rw; i++ )
        {
            scanf("%s",&mat[i]);
        }
        int cnt=0;
        st tmp;
        for( int i=0; i<rw; i++ )
        {
            for( int j=0; j<col; j++ )
            {
                //show(i,j);
                if( isalnum(mat[i][j]) )
                {
                    tmp.a=i;
                    tmp.b=j;
                    //show(tmp.a,tmp.b);
                    bfs(cnt,tmp,mat[i][j]-'0');
                    cnt++;
                }
            }
        }
        //cout<<"ok"<<endl;
        int stor[MX][MX];
        mem(stor,0);
        int mi=INT_MAX;
        for( int i=0; i<cnt; i++ )
        {
            for( int j=0; j<rw; j++ )
            {
                for( int k=0; k<col; k++ )
                {
                    stor[j][k]+=dis[i][j][k];
                    //mi=min(mi,stor[i][j]);
                }
            }
        }
        for( int i=0; i<rw; i++ )
        {
            for( int j=0; j<col; j++ )
                mi=min(stor[i][j],mi);
        }
        cout<<mi<<endl;
    }
    return 0;
}

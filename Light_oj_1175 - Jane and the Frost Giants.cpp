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



#define MX 100000
#define MOD 1000000007

int n,m,k;
string str;

struct st
{
    int x,y;
};

char mat[205][205];

const int fx[]= {+1,-1,+0,+0};
const int fy[]= {+0,+0,+1,-1};


bool check(int a,int b)
{
    if( (a>=0 && a<n) && (b>=0 && b<m) ) return 1;
    return 0;
}

int print(string sp)
{
    cout<<sp<<endl;
    for( int i=0; i<n; i++ )
    {
        for( int j=0; j<m; j++ )
            P("%c",mat[i][j]);
        P("\n");
    }
    P("\n");
    cout<<sp<<" end"<<endl;
}

int bfs(st src,queue<st> tm)
{
    int dis[205][205];
    bool vis[205][205];
    mem(dis,0);
    mem(vis,0);
    queue<st> qq,fir;
    fir=tm;
    qq.push(src);
    vis[src.x][src.y]=1;
    dis[src.x][src.y]=0;

    int cnt=SZ(fir),tmp;
    st tp;
    int cnt1=1,tmp1=0;

    while(!qq.empty())
    {
        tmp=0;
        for( int i=0; i<cnt; i++ )
        {
            st tm=fir.front();
            fir.pop();
            for( int j=0; j<4; j++ )
            {
                tp.x=tm.x+fx[j];
                tp.y=tm.y+fy[j];
                if( mat[tp.x][tp.y] != '#' && mat[tp.x][tp.y] != '1' && check(tp.x,tp.y) )
                {
                    mat[tp.x][tp.y]='1';
                    fir.push(tp);
                    //print("Fir");
                    tmp++;
                }
            }
        }
        cnt=tmp;

        tmp1=0;
        for( int j=0; j<cnt1; j++ )
        {
            st top=qq.front();
            //cout<<"108 "<<top.x<<" "<<top.y<<endl<<endl;;
            if( top.x == 0 || top.x == n-1 || top.y == 0 || top.y == m-1 ) return dis[top.x][top.y];
            qq.pop();

            for( int i=0; i<4; i++ )
            {
                tp.x=top.x+fx[i];
                tp.y=top.y+fy[i];
                //cout<<"128 "<<tp.x<<" "<<tp.y<<endl;
                if( mat[tp.x][tp.y] == '.' && mat[tp.x][tp.y] != '#' && mat[tp.x][tp.y] != '1' && check(tp.x,tp.y) && !vis[tp.x][tp.y] )
                {
                    vis[tp.x][tp.y]=1;
                    //cout<<"137 "<<tp.x<<" "<<tp.y<<endl;
                    //mat[tp.x][tp.y]='2';
                    dis[tp.x][tp.y]=dis[top.x][top.y]+1;
                    //print("Jane");
                    qq.push(tp);
                    tmp1++;
                }
            }
        }
        cnt1=tmp1;
    }
    return -1;
}


int main()
{
    SYN;
    int T;
    S("%d",&T);
    getchar();
    for( int t=1; t<=T; t++ )
    {
        S("%d%d",&n,&m);
        queue<st> fi;
        getchar();
        st jan,fir;
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<m; j++ )
            {
                S("%c",&mat[i][j]);
                if( mat[i][j] == 'J' ) jan.x=i,jan.y=j;
                if( mat[i][j] == 'F' )
                {
                    fir.x=i,fir.y=j;
                    fi.push(fir);
                }
            }
            getchar();
        }

        int val=bfs(jan,fi);
        if( val == -1 ) P("Case %d: IMPOSSIBLE\n",t);
        else P("Case %d: %d\n",t,val+1);
    }
    return 0;
}

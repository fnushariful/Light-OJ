
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

#define MX 45

LL n,m,k,ar[MX],table[MX];

char mat[MX][MX];

struct st
{
    int x1,x2,y1,y2;
};

bool vis[MX][MX][MX][MX];
int dis[MX][MX][MX][MX];

const int fx[]= {+1,+0,-1,+0};
const int fy[]= {+0,-1,+0,+1};
const int fxx[]= {+1,+0,-1,+0};
const int fyy[]= {+0,+1,+0,-1};

int row,col;
bool fun(int x,int y)
{
    if( (x>=0 && x<row) && (y>=0 && y<col) ) return 1;
    return 0;
}


LL bfs(st src,st des)
{
    //cout<<src.x1<<" "<<src.y1<<" "<<src.x2<<" "<<src.y2<<endl;
    mem(vis,0);
    mem(dis,0);
    queue<st> pq;
    vis[src.x1][src.y1][src.x2][src.y2]=1;
    dis[src.x1][src.y1][src.x2][src.y2]=0;
    pq.push(src);
    int ps1,ps2;
    st rst;
    while(!pq.empty())
    {
        st tmp=pq.front();
        pq.pop();
        if( tmp.x1 == des.x1 && tmp.y1 == des.y1 && tmp.x2 == des.x2 && tmp.y2 == des.y2 ) return dis[tmp.x1][tmp.y1][tmp.x2][tmp.y2];
        //cout<<"109 "<<tmp.x1<<" "<<tmp.y1<<" "<<tmp.x2<<" "<<tmp.y2<<endl;

        for( int i=0; i<4; i++ )
        {
            if( i&1 )
            {
                if( i == 1 ) ps1=i,ps2=3;
                else if( i == 3 ) ps1=i,ps2=1;
                rst.x1=tmp.x1+fx[ps1];
                rst.y1=tmp.y1+fy[ps1];
                rst.x2=tmp.x2+fx[ps2];
                rst.y2=tmp.y2+fy[ps2];
            }
            else
            {
                rst.x1=tmp.x1+fx[i];
                rst.y1=tmp.y1+fy[i];
                rst.x2=tmp.x2+fx[i];
                rst.y2=tmp.y2+fy[i];
            }
            //cout<<"128 "<<rst.x1<<" "<<rst.y1<<" "<<rst.x2<<" "<<rst.y2<<endl;
            if( !fun(rst.x2,rst.y2) || mat[rst.x2][rst.y2] == '#' ) rst.x2=tmp.x2,rst.y2=tmp.y2;
            else if( !fun(rst.x1,rst.y1) || mat[rst.x1][rst.y1] == '#' ) rst.x1=tmp.x1,rst.y1=tmp.y1;
            else if( (mat[rst.x1][rst.y1] == '.' && mat[rst.x2][rst.y2] == '.') ) {}
            else continue;

            if( fun(rst.x1,rst.y1) && fun(rst.x2,rst.y2) && !vis[rst.x1][rst.y1][rst.x2][rst.y2] )
            {
                {
                    cout<<rst.x1<<" "<<rst.y1<<" "<<rst.x2<<" "<<rst.y2<<endl;
                    vis[rst.x1][rst.y1][rst.x2][rst.y2]=1;
                    //dbg(dis[tmp.x1][tmp.y1][tmp.x2][tmp.y2]);
                    //dbg(dis[rst.x1][rst.y1][rst.x2][rst.y2]);
                    dis[rst.x1][rst.y1][rst.x2][rst.y2]=(dis[tmp.x1][tmp.y1][tmp.x2][tmp.y2])+1;
                    //dbg(dis[rst.x1][rst.y1][rst.x2][rst.y2]);
                    pq.push(rst);
                }
            }
        }
    }
    return -1;
}


int main()
{
    SYN;
    while(~scanf("%d%d",&row,&col))
    {
        int cl1,cl2,cl3,cl4,cl5,cl6;
        scanf("%d%d%d%d%d%d",&cl1,&cl2,&cl3,&cl4,&cl5,&cl6);
        getchar();

        for( int i=0; i<row; i++ )
        {
            for( int j=0; j<col; j++ )
            {
                scanf("%c",&mat[i][j]);
            }
            getchar();
        }
        show(cl1,cl2,cl3,cl4,cl5,cl6);
        st str,ed;

        str.x1=cl3-1;
        str.y1=cl4-1;
        str.x2=cl5-1;
        str.y2=cl6-1;

        ed.x1=cl1-1;
        ed.y1=cl2-1;
        ed.x2=cl1-1;
        ed.y2=cl2-1;

        int val=bfs(str,ed);
        //printf("%d\n",val);
        cout<<val<<endl;

        for( int i=0; i<row; i++ )
        {
            for( int j=0; j<col; j++ )
            {
                printf("%c",mat[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

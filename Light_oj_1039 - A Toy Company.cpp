#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LL;
typedef unsigned long long int ULL;

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


char fx[]= {1,-1};

string str;


LL n,m,k;
bool chk[30][30][30];

int bfs( string src,string des )
{
    bool vis[26][26][26];
    mem(vis,0);
    vis[src[0]-'a'][src[1]-'a'][src[2]-'a']=1;
    int dis[26][26][26];
    mem(dis,0);
    dis[src[0]-'a'][src[1]-'a'][src[2]-'a']=0;

    queue<string> q;
    q.push(src);
    while(!q.empty())
    {
        string top=q.front();
        if( chk[top[0]-'a'][top[1]-'a'][top[2]-'a'] == 1 ) return -1;
        if( top == des ) return dis[top[0]-'a'][top[1]-'a'][top[2]-'a'];
        string val;
        q.pop();
        for( int i=0; i<3; i++ )
        {
            for( int j=0; j<2; j++ )
            {
                val=top;
                if( val[i] == 'a' && j == 1 ) val[i]='z';
                else if( val[i] == 'z' && j == 0 ) val[i]='a';
                else val[i]=val[i]+fx[j];

                if( !vis[val[0]-'a'][val[1]-'a'][val[2]-'a'] && !chk[val[0]-'a'][val[1]-'a'][val[2]-'a'] )
                {
                    vis[val[0]-'a'][val[1]-'a'][val[2]-'a']=1;
                    dis[val[0]-'a'][val[1]-'a'][val[2]-'a']=dis[top[0]-'a'][top[1]-'a'][top[2]-'a']+1;
                    q.push(val);
                }
            }
        }
    }
    return -1;
}

int main()
{
    SYN;
    string fst,snd;
    int T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>fst>>snd>>n;
        string st1,st2,st3;
        for( int i=0; i<n; i++ )
        {
            cin>>st1>>st2>>st3;
            for( int j=0; j<SZ(st1); j++ )
            {
                for( int k=0; k<SZ(st2); k++ )
                {
                    for( int l=0; l<SZ(st3); l++ )
                    {
                        int x,y,z;
                        x=st1[j]-'a';
                        y=st2[k]-'a';
                        z=st3[l]-'a';
                        chk[x][y][z]=1;
                    }
                }
            }
        }
        int val=bfs(fst,snd);
        printf("Case %d: %d\n",t,val);
        mem(chk,0);
    }
    return 0;
}

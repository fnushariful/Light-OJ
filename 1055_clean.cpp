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
#define VI vector<LLI>
#define VS vector<string>
#define PB push_back
#define PI acos(-1.0)
#define mk make_pair
#define pll pair<LLI,LLI>
#define xx first
#define yy second
#define all(a) a.begin(),a.end()


//void show()
//{
//    cout<<'\n';
//}
//template<typename T,typename... Args>
//void show(T a, Args... args)
//{
//    cout<<a<<" ";
//    show(args...);
//}
//template<typename T>
//void show_c(T& a)
//{
//    for ( auto &x:a )
//    {
//        cout<<x<<" ";
//    }
//    cout<<endl;
//}
//


LL n,m,k ;
string str[12];


bool boundery_cheek(int x,int y)
{
    if( x>=0 && x<n && y>=0 && y<n ) return 1;
    return 0;
}

pair<int,int> a,b,c,_a,_b,_c;

int dis[11][11][11][11][11][11];

int KS;
const int fx[]= {+1,-1,+0,+0};
const int fy[]= {+0,+0,+1,-1};


struct node
{
    int x[3],y[3];
    node()
    {
        mem(x,-1);
        mem(y,-1);
    }
    node(int a,int b,int c,int d,int e,int f)
    {
        x[0]=a;
        x[1]=b;
        x[2]=c;
        y[0]=d;
        y[1]=e;
        y[2]=f;
    }
    void print()
    {
        for(int i = 0; i<3; i++)cout<<x[i]+1<<" "<<y[i]+1<<" ";
        cout<<endl;
    }
};
queue<node> q;



int bfs(node src,node des )
{

//    src.print();
//    des.print();
    KS =3;
    mem(dis,-1);
    dis[src.x[0]][src.x[1]][src.x[2]][src.y[0]][src.y[1]][src.y[2]]=0;
    while(!q.empty()) q.pop();
    q.push(src);
    while(!q.empty())
    {
        node top=q.front();
        q.pop();

        for( int i=0; i<4; i++ )
        {
            node tmp;
            for( int j=0; j<3; j++ )
            {
                tmp.x[j]=top.x[j]+fx[i];
                tmp.y[j]=top.y[j]+fy[i];
                if( ! boundery_cheek(tmp.x[j],tmp.y[j]) || str[tmp.x[j]][tmp.y[j]] == '#' )
                {
                    tmp.x[j]=top.x[j];
                    tmp.y[j]=top.y[j];
                }
            }

            vector<int>v;
            set< pair<int,int> >St;

            bool flag = 1;

            for(int j = 0; j<3; j++) St.insert(make_pair(tmp.x[j],tmp.y[j] ) );
            if(St.size()==3)
            {
                if( dis[tmp.x[0]][tmp.x[1]][tmp.x[2]][tmp.y[0]][tmp.y[1]][tmp.y[2]] == -1 )
                {
                    dis[tmp.x[0]][tmp.x[1]][tmp.x[2]][tmp.y[0]][tmp.y[1]][tmp.y[2]]=
                        dis[top.x[0]][top.x[1]][top.x[2]][top.y[0]][top.y[1]][top.y[2]]+1;
                    q.push(tmp);
                }

            }
            else if(St.size()==2)
            {

                if(tmp.x[0] == tmp.x[1] && tmp.y[0]==tmp.y[1] )
                {
                    tmp.x[0] = top.x[0];
                    tmp.y[0] = top.y[0];
                    tmp.x[1] = top.x[1];
                    tmp.y[1] = top.y[1];

                }
                else if(tmp.x[0] == tmp.x[2] && tmp.y[0]==tmp.y[2] )
                {
                    tmp.x[0] = top.x[0];
                    tmp.y[0] = top.y[0];
                    tmp.x[2] = top.x[2];
                    tmp.y[2] = top.y[2];

                }
                else
                {
                    tmp.x[2] = top.x[2];
                    tmp.y[2] = top.y[2];
                    tmp.x[1] = top.x[1];
                    tmp.y[1] = top.y[1];

                }
                if( dis[tmp.x[0]][tmp.x[1]][tmp.x[2]][tmp.y[0]][tmp.y[1]][tmp.y[2]] == -1 )
                {
                    dis[tmp.x[0]][tmp.x[1]][tmp.x[2]][tmp.y[0]][tmp.y[1]][tmp.y[2]]=
                        dis[top.x[0]][top.x[1]][top.x[2]][top.y[0]][top.y[1]][top.y[2]]+1;
                    q.push(tmp);
                }
            }
        }
    }
    int res = IMAX;
    vector<int>v;// {0,1,2};
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    do
    {
        int c = dis[des.x[v[0]]][des.x[v[1]]][des.x[v[2]]][des.y[v[0]]][des.y[v[1]]][des.y[v[2]]];
        if(c!=-1)res = min(res,c);
    }
    while(next_permutation(all(v)));

    return  res;
}


int main()
{
    SYN;
    int ks,cas;
    cin>>ks;
    for(int cas=1; cas<=ks; cas++)
    {
        cin>>n;
        {
            string inp;
            bool ok1=0,ok2=0,ok3=0;
            node src,des;
            int cnt=0;
            for( int i=0; i<n; i++ )
            {
                cin>>inp;

                for( int j=0; j<SZ(inp); j++ )
                {
                    if( inp[j] == 'A' ) src.x[0]=i,src.y[0]=j;
                    else if( inp[j] == 'B' ) src.x[1]=i,src.y[1]=j;
                    else if( inp[j] == 'C' ) src.x[2]=i,src.y[2]=j;
                    else if( inp[j] == 'X'  )
                    {
                        des.x[cnt]=i,des.y[cnt]=j ;
                        cnt++;
                    }
                }
                str[i]=inp;
            }
            int res=IMAX;
//            des.print();
            res = bfs(src,des);
            cout<<"Case "<<cas<<": ";
            if(res==IMAX)cout<<"trapped\n";

            else cout<<res<<endl;
        }
    }

    return 0;
}


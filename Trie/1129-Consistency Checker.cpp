#include <bits/stdc++.h>

using namespace std;

#define SYN ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int LLI;
typedef unsigned long long int ULLI;

#define debug(x)         cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;
#define IMAX ((unsigned)1<<31)-1
#define eps 1e-11
#define fill(a,v) memset(a,v,sizeof (a))
#define SZ(X) ((int)X.size())
#define VI vector<LLI>
#define VS vector<string>
#define PB push_back
#define MSI map<string,int>
#define MLLI map<LLI,LLI>
#define MCI map<char,int>
#define PI acos(-1.0)
#define mk make_pair
#define pLLI pair<LLI,LLI>
#define xx first
#define yy second

#define MOD 1000000007
#define MX 1000000
#define RADIANS(x)       (((1.0 * x * PI) / 180.0))
#define DEGREES(x)       (((x * 180.0) / (1.0 * PI)))

string str;
int len,mxlen;

struct trie
{
    trie *cild[11];
    bool ed=false;
    trie()
    {
        memset(cild,NULL,sizeof cild);
    }
};

void insrt(trie *node,int idx)
{
    int pos=str[idx]-'0';
    if( len-1 == idx )
    {
        if( node->cild[pos] == NULL )
        {
            node->cild[pos]=new trie();
        }
        node->ed=1;
        return ;
    }
    if( node->cild[pos] == NULL )
    {
        node->cild[pos]=new trie();
    }
    insrt(node->cild[pos],idx+1);
}

int srch(trie *node,int idx)
{
    int pos=str[idx]-'0';
    if( len-1 == idx )
    {
        //debug(str);
        if( node->cild[pos] == NULL ) return false;
        if( idx< mxlen-1 ) return true;
        //debug(mxlen);
        //debug(idx);
        if( idx == mxlen-1 ) return node->ed;
    }
    if( node->cild[pos] == NULL ) return false;
    else srch(node->cild[pos],idx+1);
}


bool cmp(string a,string b)
{
    return a.size()>b.size();
}

void del(trie *cur)
{
    for(int i=0; i<11; i++)
        if(cur->cild[i])
            del(cur->cild[i]) ;
    delete(cur) ;
}
int main()
{
    SYN;
    int n,m,k,T;
    cin>>T;
    for( int t=1; t<=T; t++ )
    {
        cin>>n;
        vector<string> v;
        mxlen=INT_MIN;
        for( int i=0; i<n; i++ )
        {
            cin>>str;
            len=str.size();
            mxlen=max(mxlen,len);
            v.PB(str);
        }
        //debug(mxlen);
        sort(v.begin(),v.end(),cmp);
        //for( auto x: v ) cout<<x<<" ";
        trie *root= new trie();
        bool ok=0;
        int pos=n;
        for( int i=0; i<n; i++ )
        {
            ok=0;
            str=v[i];
            len=str.size();
            if( srch(root,0) )
            {
                ok=1;
                pos=i;
                break;
            }
            insrt(root,0);
        }
        if( ok )
        {
            cout<<"Case "<<t<<": "<<"NO"<<endl;
        }
        else if(!ok) cout<<"Case "<<t<<": "<<"YES"<<endl;
        del(root);
    }
    return 0;
}


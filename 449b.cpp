//joyneel
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

//#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

VII g[100005];
set< pair<LL,int> > s;
const LL INF = 1e18;
int vs[100005],mark[100005];
LL d[100005];

int main(){
  int n,m,k;
  si(n);si(m);si(k);
  for(int i=0;i<m;i++){
    int a,b,c;
    si(a);si(b);si(c);
    g[a].PB(MP(b,c));
    g[b].PB(MP(a,c));
  }
  for(int i=1;i<=n;i++) d[i] = INF;
  for(int i=0;i<k;i++){
    int a,c;
    si(a);si(c);
    mark[a] = 1;
    d[a] = min(1LL*c,d[a]);
  }
  d[1] = 0;
  for(int i=1;i<=n;i++) if(mark[i]) s.insert(MP(d[i],i)); 
  s.insert(MP(d[1],1));
  while(!s.empty()){
    int u = s.begin()->S;
    s.erase(s.begin());
    vs[u] = 1;
    for(int i=0;i<SZ(g[u]);i++){
      int w = g[u][i].F;
      LL edge = g[u][i].S;
      if(vs[w]) continue;
      if(d[u] + edge <= d[w]){
        mark[w] = 0;
        if(s.find(MP(d[w],w))!=s.end()) s.erase(s.find(MP(d[w],w)));
        d[w] = d[u] + edge;
        s.insert(MP(d[w],w));
      }
    }
  }
  int ans = 0;
  for(int i=1;i<=n;i++){
    if(mark[i]) ans++;
  }
  dout(k-ans);
	return 0;
}

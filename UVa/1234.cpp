#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

vi p,rnk;
int nbSets;
int V,E;

int findSet(int u){
   return p[u]==u? u: p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u),b=findSet(v);
   if(a==b) return;
   nbSets--;
   if(rnk[b]>rnk[a]) swap(a,b);
   p[b]=a;
   if(rnk[a]==rnk[b]) rnk[a]++;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      cin>>V>>E;
      p.resize(V+1); for (int i=1;i<=V;i++) p[i]=i;
      rnk.assign(V+1,0);
      nbSets=V;

      vector<pair<int,pi>> vec;
      int u,v,w;
      int res=0;
      for (int i=0; i<E; i++){
         cin>>u>>v>>w;
         vec.pb({w,{u,v}});
         res+=w;
      }
      sort(vec.rbegin(),vec.rend());
      for (int i=0; i<sz(vec); i++){
         u=vec[i].se.fi; v=vec[i].se.se; w=vec[i].fi;
         if(findSet(u)!=findSet(v)){
            unionSet(u,v);
            res-=w;
         }
         if(nbSets==1) break;
      }
      cout << res << endl;
      //cout << endl << endl;
   }
   cin>>V;


   return 0;
}


//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

const int MX=1e4+1;
int V,E;
vpi adj[MX];
vi vec;
bool vis[MX];

void dfs(int u){
   vis[u]=true;
   for(auto v: adj[u]) if(!vis[v.fi]) dfs(v.fi);
   vec.pb(u);
}

int32_t main(){
   boost;
   memset(vis,0,MX);
   cin>>V>>E;
   for(int i=0; i<E; i++){
      int u,v; cin>>u>>v;
      adj[u].pb({v,1});
   }
   dfs(1);
   reverse(all(vec));

	int res[V+1];
	for(int i=0; i<V+1; i++) res[i]=0;
	res[1]=1;
	for(auto u: vec){
      for(auto v: adj[u]) res[v.fi]+=res[u];
	}
	cout << res[V] << endl;

   return 0;
}

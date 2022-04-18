//Never stop trying
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

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=3e5+10;
int N;
vi adj[MX];

int node,mx;
void dfs(int u, int p, int d){
	if(d>mx){
		mx=d;
		node=u;
	}
	for(auto v: adj[u]) if(v!=p) dfs(v,u,d+1);
}

int32_t main(){
   boost;
   IO();


   cin>>N; 
	for(int i=0; i<N-1; i++){
		int u,v; cin>>u>>v;
		adj[u].pb(v); adj[v].pb(u);
	}

	mx=-1;
	dfs(1,1,0);

	mx=-1;
	dfs(node,node,0); 

	cout << 3*mx << endl;



   return 0;
}


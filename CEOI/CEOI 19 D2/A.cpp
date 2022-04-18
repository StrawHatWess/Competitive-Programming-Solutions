//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}
#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

int N,M,U[MX],V[MX],vis[MX],cy;
vi adj[MX];

void dfs(int u){
	vis[u]=1;

	for(int v: adj[u]){
		if(!vis[v]) dfs(v);
		else if(vis[v]==1) cy=1;
	}

	vis[u]=2;
}

bool check(){
	FOR(i,1,N+1) vis[i]=0;
	cy=0;
	FOR(i,1,N+1) if(!vis[i]){
		dfs(i);
		if(cy) return 0;
	}	
	return 1;
}

int main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,0,M) cin>>U[i]>>V[i];
    
    int ans=0;
    FOR(m,0,1<<M){
    	FOR(i,1,N+1) adj[i].clear();

    	int cnt=0;
    	FOR(i,0,M){
    		int u=U[i],v=V[i];
    		if((m>>i)&1){
    			cnt++;
    			adj[v].pb(u);
			}
			else adj[u].pb(v);
		}

		if(check()){
			ans+=cnt; 
			ans%=MOD;
		}
    }
    cout << ans << endl;

    

    

    return 0;
}
//Change your approach 
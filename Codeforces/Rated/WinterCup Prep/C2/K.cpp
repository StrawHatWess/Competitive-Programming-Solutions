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

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
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

int N; 
vi vec[MX],par(MX,-1);


bool check(int u, int idx){
	int v=vec[u][idx];
	vi vis(N+1,0);
	FOR(i,0,idx) vis[vec[u][i]]=1;

	for(auto cur: vec[v]){
		if(cur==u) return 1;
		if(vis[cur]) return 0;
	}
	return 1;
}

int main() {
    boost; IO();
    
    int t; cin>>t;
    while(t--){
    	cin>>N; 
    	FOR(i,1,N+1) vec[i].clear(),par[i]=-1;
    	FOR(i,1,N+1){
    		int u; cin>>u;
    		FOR(j,2,N+1){
    			cin>>u;
    			vec[i].pb(u);
    		}
    	}

    	//cout << check(1,3) << endl;

    	queue<int>q; q.push(1);
    	while(!q.empty()){
    		int i=q.front(); q.pop();
    		//dbg(i)
    		int l=0,r=N-2,idx;
    		while(l<=r){
    			int m=(l+r)/2;
    			if(check(i,m)){
    				idx=m;
    				l=m+1;
    			}
    			else r=m-1;
    		}
    		FOR(j,0,idx+1) if(vec[i][j]!=par[i]) 
    			par[vec[i][j]]=i,q.push(vec[i][j]);

    		/*vi vv;
			FOR(j,0,idx+1) vv.pb(vec[i][j]);
			dbgv(vv)*/
    	}
    	FOR(i,2,N+1) cout << i << ' ' << par[i] << endl;
    	cout << endl;
    }

    return 0;
}
//Change your approach 
//Never stop trying
#ifndef LOCAL
#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#endif
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 100;
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

int N,M; 
bitset<19> g[19];
bitset<(1)<<(19)> a;
int memo[(1)<<(19)];
int mx;

int solve(int m){
	if(m==mx-1) return 0;
	if(memo[m]!=-1) return memo[m];

	int ans=INF;
	vi v; 
	FOR(i,0,N) if(!(((m)>>(i))&1)) v.pb(i);
	int n=sz(v);
	FOR(m2,1,(1)<<(n)){
		int cur=0;
		FOR(i,0,n) if((m2)&((1)<<(i))) cur+=((1)<<(v[i]));
		if(a[cur]) ckmin(ans,solve(((m)|(cur)))+1);
	}

	return memo[m]=ans;
}

int main() {
    boost; IO();
    	
    cin>>N>>M;
    FOR(i,0,M){
    	int u,v; cin>>u>>v;
    	u--; v--;
    	g[u][v]=g[v][u]=1;
    }

    mx=(1)<<(N);
    FOR(m,0,mx){
    	vi vec; 
    	FOR(i,0,N) if(((m)&((1)<<(i)))) vec.pb(i);
    	bool y=true;
    	FOR(i,0,sz(vec)) FOR(j,i+1,sz(vec)) y&=g[vec[i]][vec[j]];
    	a[m]=y;
    }

    memset(memo,-1,sizeof(memo));
    cout << solve(0) << endl;
	

    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/
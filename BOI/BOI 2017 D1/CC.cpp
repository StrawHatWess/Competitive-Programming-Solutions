//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//#define int long long
typedef string str;
typedef long long ll;
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
 
const int MOD = 1e9 + 7; //998244353
const ll INF = 2e9;
const int MX = 5e4 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up
 
template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))
 
#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
 
void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
 
inline int read(){
   int x=0; bool s=1; char c=getchar();
   while(c<'0'||c>'9'){ if(c=='-') s=0; c=getchar();}
   while(c>='0' && c<='9'){ x=(x<<3)+(x<<1)+c-'0'; c=getchar();}
   return s? x: -x;}
 
 
int K,N,M,Q;
vpi adj[MX]; 

int main() {
	boost; IO();
 
	K=read(); N=read(); M=read(); Q=read();
	FOR(i,0,M){
		int u,v,w; 
		u=read(); v=read(); w=read();
		adj[u].pb({v,w});
	}
 
	while(Q--){
		int a,b; 
		a=read(); b=read();
		int dist[N]; FOR(i,a,b+1) dist[i]=INF;
		dist[a]=0;
		for(int i=a; i<b+1; i++) if(dist[i]!=INF){
			for(auto v: adj[i]) if(ckmin(dist[v.fi],dist[i]+v.se));
		}
		int ans=dist[b];
		if(ans==INF) cout << -1 << endl;
		else cout << ans << endl;
	}
 
	return 0;
}
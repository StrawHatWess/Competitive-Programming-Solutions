//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
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
 
ll modpow(int x, int p){
	if(p==0) return 1;
	ll v=modpow(x,p/2);
	v*=v; v%=MOD;
	if(p%2){
		v*=x; v%=MOD;
	}
	return v;
}
 
ll modinv(int x){return modpow(x,MOD-2);}
 
 
ll f[MX];
ll C(int n, int p){
	p=n-p;
	ll x=1; 
	FOR(i,2,n-p+1) x*=i,x%=MOD;
	ll ans= (f[n] * modinv(f[p]))%MOD;
	ans*=modinv(x); ans%=MOD;
	return ans;
}
 
int main() {
    boost; IO();
 
    f[0]=1;
    FOR(i,1,MX) f[i]=f[i-1]*i,f[i]%=MOD;
 
    int TC; cin>>TC;
    while(TC--){
    	int N,M,K; cin>>N>>M>>K;	
    	vi a(N); 
    	FOR(i,0,N) cin>>a[i];
    	sort(all(a));
 
    	ll ans=0;
    	FOR(i,0,N){
    		int j=upper_bound(all(a),a[i]+K)-a.begin(); j--;
    		int L=j-i;
    		
    		if(M-1<=L) 
    			ans+=C(L,M-1);
			ans%=MOD;
			
    	}
    	cout << ans << endl;
    }
    
 
    return 0;
}
//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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

int modpow(int x, int p){
	if(!p) return 1;
	int v=modpow(x,p/2);
	v*=v; v%=MOD;
	if(p&1) v*=x,v%=MOD; 
	return v;
}

int modinv(int x){
	return modpow(x,MOD-2);
}

int32_t main() {
    boost; IO();

    int N; cin>>N;
    int power[N+1];
    power[0]=1;
    FOR(i,1,N+1) power[i]=(power[i-1]*2)%MOD;

    map<int,int>mp;
   	FOR(i,0,N){
   		int x; cin>>x;
   		mp[x]++;
   	} 
   	vpi vec;
   	for(auto x: mp) vec.eb(x);

    //for(auto x: vec) cout << x.fi << ' '; cout << endl;

   	int val=0,ans=0;
    for(auto it: vec){
    	int x=it.fi,n=it.se;

    	val*=power[n]; val%=MOD;

    	int v=x*x; v%=MOD;
    	v*=(power[n]-1+MOD)%MOD; v%=MOD;
    	ans+=v; ans%=MOD;

    	v=x*val; v%=MOD; 
    	v*=modinv(4); v%=MOD;
    	ans+=v; ans%=MOD;

    	val+=(x*power[n])%MOD; val%=MOD;
    }
    cout << ans << endl;
    

    return 0;
}
//Change your approach 
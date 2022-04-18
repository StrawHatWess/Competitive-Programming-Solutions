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
ll MOD;
ll memo[401][401][401];

ll solve(int i, int r, int rr){
	if(i>=N){
		if(!r && !rr) return 1;
		return 0;
	}

	ll &ind=memo[i][r][rr];
	if(ind!=-1) return ind;

	ll ans=0;
	if(i!=N-2 && r){
		ans+=solve(i+2,r-1,rr);
	}

	FOR(j,i+1,N) if(j!=N-2 && rr){
		int s=j-i+1;
		int val=2; 
		if(s>2) val+=2;
		if(s>3) val+=2*(s-3);

		ans+=(val*solve(j+2,r,rr-1))%MOD;
		ans%=MOD;
	}

	return ind=ans; 
}

int main() {
    boost; IO();

    memset(memo,-1,sizeof(memo));
    cin>>N>>MOD;

    ll f[2*N+1]; f[0]=1;
    FOR(i,1,2*N+1) f[i]=(f[i-1]*i)%MOD;
    
    ll ans=0;
    FOR(i,0,N+1) FOR(j,0,N+1){
    	ans+=(solve(0,i,j)*f[i+j])%MOD; 
    	ans%=MOD;
    }
    cout << ans << endl;
    

    return 0;
}
//Change your approach 
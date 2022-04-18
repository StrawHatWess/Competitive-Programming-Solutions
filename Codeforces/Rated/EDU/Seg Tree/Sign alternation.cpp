//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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
const int MX = 1e5 + 10;
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

int N;
vpi t(MX*4,{0,0});	

pi combine(int tl, int tm, pi a, pi b){
	pi c;
	c.fi=a.fi; 
	if((tm-tl+1)&1) c.fi+=b.se;
	else c.fi+=b.fi;

	c.se=a.se;
	if((tm-tl+1)&1) c.se+=b.fi;
	else c.se+=b.se;

	return c;
}

void upd(int i, int x, int pos=1, int tl=1, int tr=N){
	if(tl==tr){
		t[pos]={x,-x};
		return;
	}
	int tm=(tl+tr)/2;
	if(i<=tm) upd(i,x,pos*2,tl,tm);
	else upd(i,x,pos*2+1,tm+1,tr);
	t[pos]=combine(tl,tm,t[pos*2],t[pos*2+1]);
}

int get(int l, int r, int s=1, int pos=1, int tl=1, int tr=N){
	if(l>r) return 0;
	if(l==tl && r==tr){
		return s ? t[pos].fi : t[pos].se;
	}
	int tm=(tl+tr)/2;
	int x=max(0ll,min(r,tm)-l+1);
	return get(l,min(r,tm),s,pos*2,tl,tm) + get(max(l,tm+1),r,s^(x&1),pos*2+1,tm+1,tr);
}

int32_t main() {
    boost; IO();

    cin>>N;
    FOR(i,1,N+1){
    	int x; cin>>x;
    	upd(i,x);
    }
    int Q; cin>>Q;
    while(Q--){
    	int t; cin>>t;
    	if(t==0){
    		int i,x; cin>>i>>x;
    		upd(i,x);
    	}
    	else{
    		int l,r; cin>>l>>r;
    		cout << get(l,r) << endl;
    	}
    }
    

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
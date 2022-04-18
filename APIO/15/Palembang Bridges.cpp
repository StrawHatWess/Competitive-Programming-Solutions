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

int32_t main() {
    boost; IO();

    int K,N; cin>>K>>N;
    if(K==1){
		int ans=0;
		vi vec;
		FOR(i,0,N){
			char a,b; int x,xx; cin>>a>>x>>b>>xx;
			if(a==b){
				ans+=abs(x-xx);
			}else{
				vec.pb(x); vec.pb(xx);
			}
		}
		sort(all(vec));

	    if(sz(vec)) ans+=sz(vec)/2;
	    int m=(sz(vec))/2;
	    FOR(i,0,sz(vec)){
	    	ans+=abs(vec[i]-vec[m]);
	    }
	    cout << ans << endl;
    }
    else{
    	int ans=0;
    	int v[N],vv[N];
    	vi vec;
    	vi vvv;
    	FOR(i,0,N){
    		char a,b; int x,xx; cin>>a>>x>>b>>xx;
    		v[i]=x; vv[i]=xx;
    		if(a==b) ans+=abs(x-xx);
    		else{
    			vec.pb(x),vec.pb(xx);
    			vvv.pb(i);
			}
    	}
    	sort(all(vec));

    	int mn=INF;
    	FOR(i,0,sz(vec)) FOR(j,0,sz(vec)){
    		int cur=0;
    		for(auto k: vvv){
					cur+= 1 + min( abs(v[k]-vec[i]) + abs(vv[k]-vec[i]) ,
					abs(v[k]-vec[j]) + abs(vv[k]-vec[j])  );
    		}

    		ckmin(mn,cur);
			
    	}
    	if(mn==INF) mn=0;
    	cout << ans+mn << endl;
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
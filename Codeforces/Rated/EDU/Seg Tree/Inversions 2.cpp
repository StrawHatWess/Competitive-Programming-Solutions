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
vi a(MX),t(MX*4,0);

void upd(int i, int x, int pos=1, int tl=1, int tr=N){
	if(tl==tr){
		t[pos]=x;
		return;
	}
	int tm=(tl+tr)/2;
	if(i<=tm) upd(i,x,pos*2,tl,tm);
	else upd(i,x,pos*2+1,tm+1,tr);
	t[pos]=t[pos*2]+t[pos*2+1];
}

int get(int k, int pos=1, int tl=1, int tr=N){
	if(tl==tr) return tl;
	int tm=(tl+tr)/2;
	if(t[pos*2+1]>=k) return get(k,pos*2+1,tm+1,tr);
	return get(k-t[pos*2+1],pos*2,tl,tm);
}

int main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N){
    	cin>>a[i];
    	upd(i+1,1);
	}

	vi p(N);
    ROF(i,0,N){
    	p[i]=get(a[i]+1);
    	upd(p[i],0);
    }
    FOR(i,0,N) cout << p[i] << ' '; 
    cout << endl;

    

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
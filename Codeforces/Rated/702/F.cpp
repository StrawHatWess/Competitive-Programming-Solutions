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
const ll INF = 2e9;
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


int main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	int N; cin>>N;
    	vi b(N);
    	FOR(i,0,N) cin>>b[i];
    	sort(all(b));

    	vi a;
    	int cnt=0;
    	FOR(i,0,N){
    		cnt++;
    		if((i+1<N && b[i]!=b[i+1]) || i==N-1){
    			a.pb(cnt);
    			cnt=0;
    		}
    	}
    	sort(all(a));

    	vi mp(N+1,0);
    	for(auto x: a) mp[x]++;
    	
    	int pref=0,suf=0;
    	for(auto x: a) suf+=x;

    	int ans=INF;
    	FOR(i,0,sz(a)){
    		suf-=a[i];
    		if(!(i+1<sz(a) && a[i]==a[i+1])){
    			int v=pref-(mp[a[i]]-1)*a[i]+suf-a[i]*(sz(a)-1-i);
    			ckmin(ans,v);
    		}
    		pref+=a[i];
    	}
    	cout << ans << endl;
    }
    

    return 0;
}
//Change your approach 
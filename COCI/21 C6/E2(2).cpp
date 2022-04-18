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

const int S=600;

int N,Q;
vi a(MX),t(MX,0);  
V<pair<pi,int>> q;

bool mo(pair<pi,int> a, pair<pi,int> b){
	int l1=a.fi.fi,l2=b.fi.fi,r1=a.fi.se,r2=b.fi.se;
	if(l1/S!=l2/S) return l1/S<l2/S;
	return (l1/S)&1 ? r1<r2 : r1>r2;
}


void upd(int i, int v){
	for(;i<MX; i+=i&-i) t[i]+=v;
}

int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans;
}

int solve(int n){
	int l=1,r=n,ans;
	while(l<=r){
		int m=(l+r)/2;
		if(n-get(m-1)>=m){
			ans=m;
			l=m+1;
		}
		else r=m-1;
	}
	return ans;
}

int main() {
    boost; IO();

    cin>>N>>Q;
    FOR(i,1,N+1) cin>>a[i];

    FOR(i,0,Q){
    	int l,r; cin>>l>>r;
    	q.pb({{l,r},i});
    }
    sort(all(q),mo);

    int cl=1,cr=0,ans[Q];
    for(auto it: q){
    	int l=it.fi.fi,r=it.fi.se,idx=it.se;
    	while(cl<l){
    		upd(a[cl],-1);
    		cl++;
    	}
    	while(cl>l){
    		cl--;
    		upd(a[cl],1);
    	}
    	while(cr<r){
    		cr++;
    		upd(a[cr],1);
    	}
    	while(cr>r){
    		upd(a[cr],-1);
    		cr--;
    	}

    	ans[idx]=solve(r-l+1);
    }

    FOR(i,0,Q) cout << ans[i] << endl;


    
    

    return 0;
}
//Change your approach 
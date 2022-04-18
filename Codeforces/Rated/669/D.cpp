//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
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
const ll INF = 1e18;
const int MX = 3e5 + 10;
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

// min, max
int N; 
vpi t;

void update(int i, int v, int l=1, int r=N, int pos=1){
	if(l==r){
		t[pos].fi=t[pos].se=v;
		return;
	}
	int m=(l+r)/2;
	if(i<=m) update(i,v,l,m,pos*2);
	else update(i,v,m+1,r,pos*2+1);
	t[pos].fi=min(t[pos*2].fi,t[pos*2+1].fi);
	t[pos].se=max(t[pos*2].se,t[pos*2+1].se);
}

pi query(int l, int r, int tl=1, int tr=N, int pos=1){
	if(l>r) return {INF,-INF};
	if(l==tl && r==tr){
		return t[pos];
	}
	int tm=(tl+tr)/2;
	pi a=query(l,min(r,tm),tl,tm,pos*2),b=query(max(tm+1,l),r,tm+1,tr,pos*2+1);
	a.fi=min(a.fi,b.fi); a.se=max(a.se,b.se);
	return a;
}

int32_t main() {
	boost; IO();

	t.assign(4*MX,{INF,-INF});
	cin>>N;
	vi a(N+1);
	FOR(i,1,N+1) cin>>a[i],update(i,a[i]);

	int ans=0;
	for(int i=1; i<N;){
		int nxt; 
		if(a[i]==a[i+1]) nxt=i+1;
		else{
			int st=0;
			if(a[i+1]>a[i]) st=1;

			int l=i+1,r=N;
			int bs=INF;
			while(l<=r){
				int m=(l+r)/2;
				if(!st){
					if(query(i+1,m).se<a[i]) bs=m, l=m+1;
					else r=m-1;
				}
				else{
					//cout << query(i+1,m).se << endl;
					if(query(i+1,m).fi>a[i]) bs=m, l=m+1;
					else r=m-1;
				}
			}
			nxt=bs+1;
		}
		cout << i << ' ' << nxt << endl;
		i=nxt;
		ans++;
	}

	cout << ans << endl;



	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/

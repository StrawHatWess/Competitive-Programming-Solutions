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
const int MX = 2e5 + 10;
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


int32_t main() {
	boost; IO();

	int TC; cin>>TC;
	FOR(t,1,TC+1){
		int N,X; cin>>N>>X;
		vi a(N);
		FOR(i,0,N) cin>>a[i];
		sort(all(a));

		int cum[N]; 
		FOR(i,0,N){
			cum[i]=a[i];
			if(i) cum[i]+=cum[i-1];
		}

		int ans=INF;
		FOR(i,0,N){
			int l=0,r=i;
			int left,right;

			while(l<=r){
				int m=(l+r)/2;
				if(a[i]-a[m]<=X/2){
					left=m; r=m-1;
				}
				else l=m+1;
			}

			l=i,r=N-1;
			while(l<=r){
				int m=(l+r)/2;
				if(a[m]-a[i]<=X/2){
					right=m; l=m+1;
				}
				else r=m-1;
			}

			//dbgs(left,right);

			int x=(cum[right]-cum[i])-(a[i]*(right-i));
			x+=a[i]*(i-left); if(i) x-= cum[i-1]; if(left) x+=cum[left-1];
			x+=(X+a[i])*(N-1-right) - (cum[N-1]-cum[right]);
			x+=(X-a[i])*left; if(left){x+=cum[left-1];}

			ckmin(ans,x);

		}
		cout << "Case #" << t << ": " << ans << endl;
	}



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

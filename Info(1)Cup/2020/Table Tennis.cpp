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


int N,K;
vi a(MX);
deque<int>d;

bool check(int i, int j){
	d.clear();
	d.push_front(i); d.pb(j);
	int x=0,y=0,n=1;
	while(i || j+1<N+K){
		if(x<=y){
			if(!i) break;
			x+=a[i]-a[i-1];
			i--;
		}
		else{
			if(j==N+K-1) break;
			y+=a[j+1]-a[j];
			j++;
		}
		if(x==y){
			n++;
			x=0,y=0;
			d.push_front(i); d.pb(j);
		}
	}
	
	return n>=N/2;
}

int32_t main() {
    boost; IO();

    cin>>N>>K;
    FOR(i,0,N+K) cin>>a[i];

    deque<int>ans;
    FOR(i,N/2-1,N+K-N/2+1) FOR(j,i+1,N+K-N/2+1){
    	if(check(i,j)){
    		ans.assign(all(d));
    	}
    }

    while(sz(ans)>N) ans.pop_front(),ans.pop_back();
    assert(sz(ans)==N);
    for(auto x: ans) cout << a[x] << ' '; cout << endl;

    

    return 0;
}
//Change your approach 
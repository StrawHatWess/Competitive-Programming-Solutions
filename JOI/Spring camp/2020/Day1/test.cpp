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


int main() {
    boost; IO();

    int N; cin>>N;
    N*=2;
    vi a(N),b(N);
    FOR(i,0,N) cin>>a[i];
    FOR(i,0,N) cin>>b[i];
   
    	
    bitset<MX>A,B; 
    A[1]=1; B[0]=1;

    bitset<MX>curb; 
    FOR(i,1,N){
    	curb=B;

    	//choose B
    	if(b[i]>=b[i-1] && b[i]>=a[i-1]) B|=A;
    	else if(b[i]>=b[i-1]);
    	else if(b[i]>=a[i-1]) B=A;
    	else B.reset();

    	//Choose A
    	if(a[i]>=a[i-1] && a[i]>=b[i-1]){
    		A|=curb;
    		A<<=1;
    	}
    	else if(a[i]>=a[i-1]){
    		A<<=1;
    	}
    	else if(a[i]>=b[i-1]){
    		A=curb;
    		A<<=1;
    	}
    	else A.reset();
    }
    if(!A[N/2] && !B[N/2]){
    	cout << -1 << endl;
    	return 0;
    }

    if(A[N/2]){
    	int n=N/2;
    	int cur=0;
    	str ans="A";
    	ROF(i,1,N){
    		if(cur==0){

    		}
    	}
    	reverse(all(ans));
    	cout << ans << endl;
    }


    return 0;
}
//Change your approach 
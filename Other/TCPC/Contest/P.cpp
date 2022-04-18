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
#else
    freopen("xor.in", "r", stdin);
#endif
}

int N=100001;
int dp[MX][2][2]; 

int main() {
    boost; IO();

    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    FOR(i,1,N+1){
        FOR(j,0,2) FOR(k,0,2){
            int jj=(j+1)%2;
            dp[i][j][k]+=dp[i-1][j][k]; 
            if(dp[i][j][k]>=MOD) dp[i][j][k]-=MOD;
            dp[i][j][k]+=dp[i-1][j][k]; 
            if(dp[i][j][k]>=MOD) dp[i][j][k]-=MOD;
            if(k){
                dp[i][j][k]+=dp[i-1][jj][1]; 
                if(dp[i][j][k]>=MOD) dp[i][j][k]-=MOD;
                dp[i][j][k]+=dp[i-1][jj][0]; 
                if(dp[i][j][k]>=MOD) dp[i][j][k]-=MOD;
                dp[i][j][k]+=dp[i-1][jj][1]; 
                if(dp[i][j][k]>=MOD) dp[i][j][k]-=MOD;
            }
        }
    }
	
    int TC; cin>>TC;
    while(TC--){
        int N; cin>>N;
        ll ans=dp[N][1][0] + dp[N][1][1];
        if(ans>MOD) ans-=MOD;
        cout << ans << endl;
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
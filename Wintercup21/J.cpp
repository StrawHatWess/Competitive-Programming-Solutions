#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define inf 1000000000
#define sz(x) (ll)x.size()
#define boost() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair< int , pii> piii;
typedef pair<int,bool> pib;
typedef vector<pii> vii;
typedef vector<pib> vib;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<string,string> pss;
typedef pair<ll , ll> pll;
typedef vector<pss> vss;
typedef pair<ld , ld> pdd;
typedef vector<ld> vd;
typedef vector<vector<pib>> vvib;
typedef vector<piii> viii;
typedef vector<viii> vviii;
typedef vector<bool> vb;
typedef pair<pii , bool> piib;
typedef vector<pair<pii , bool>> viib;
const int   MOD = 1e9 + 7; //998244353;
const int N = 500005;


int dp[1005][1005];
int a[1005], b[1005];
vvi graph;
int solve(int x, int y){
    if(y < 0 || a[x] > y)return 0;
    if(dp[x][y] != 0)return dp[x][y];
    dp[x][y] = 1;
    for(int i : graph[x]){
        dp[x][y] = max(dp[x][y] , 1+ solve(i , y - a[x]));
    }

    //cout << x << " " << y << " " << dp[x][y] << endl;
    return dp[x][y];
}
int main() {
    boost();
    int t;
    cin >> t;

    while(t--){
        int n , B;
        cin >> n >> B;
        memset(dp , 0 ,sizeof dp);

        graph.assign( n, vi(0));
        for(int i = 0;i<n;i++)cin >> a[i];
        for(int i = 0;i<n;i++)cin >> b[i];
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                if(b[j] >= b[i]){
                    graph[j].pb(i);
                }
            }
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            res = max(res , solve(i , B));
        }
        cout << res << endl;
    }
}

/*
 * 1
 * 3 10
 */
//NEVER GIVE UP
//LONG LONGht
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int memo[80]={-1};
int N;

int dp(int i){
   //cout << i << endl;
   if(i==1 || i==2) return 1;
   if(i<=0) return 0;
   int &ind=memo[i];
   if(ind!=-1) return ind;
   return ind=dp(i-2)+dp(i-3);
}

int32_t main(){
   boost;
   for (int i=0; i<80; i++) memo[i]=-1;
   cin>>N;
   while(!cin.fail()){
      cout << dp(N)+dp(N-1) << endl;
      //for (int i=0; i<N; i++) cout << memo[i] << ' ';
      cin>>N;
   }

}


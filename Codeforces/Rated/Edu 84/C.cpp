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



int32_t main(){
   boost;
   int N,M; cin>>N>>M;
   int K; cin>>K;
   pi s[K],des[K];
   for (int k=0; k<K; k++){
      int x,y; cin>>x>>y;
   }
   for (int k=0; k<K; k++){
      int x,y; cin>>x>>y;
   }

   string res;
   for (int i=0; i<N-1; i++) res+='U';
   for (int j=0; j<M-1;j++)  res+='R';
   for (int n=0; n<N; n++){
      if(n%2==0) for (int j=0; j<M-1; j++) res+='L';
      else for (int j=0; j<M-1; j++) res+='R';
      if(n!=N-1) res+='D';
   }
   cout << sz(res)<< endl;
   cout << res << endl;
}
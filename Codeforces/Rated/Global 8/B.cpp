//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

int32_t main(){
   boost;
   int K; cin>>K;
   int x;
   for(int i=50; i>=1; i--) if((int)(pow(i,10)<=K)){
      x=i; break;
   }
   int t[10];
   for(int i=0;i<10; i++) t[i]=x;
   int xx=1; for(int i=0; i<10; i++) xx*=t[i];
   int idx=0;
   while(xx<K){
      xx/=t[idx];
      t[idx]++;
      xx*=t[idx];
      idx=(idx+1)%10;
   }

   str s="codeforces";
   for(int i=0; i<10; i++){
      for(int j=0; j<t[i]; j++) cout << s[i];
   }

   return 0;
}


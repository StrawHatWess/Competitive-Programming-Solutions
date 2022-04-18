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
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      int t[N];
      for(int i=0; i<N; i++) cin>>t[i];

      //int p=0;
      int st=-1;
      vi vec;
      for(int i=0; i<N; i++){
         if(i==N-1){
            vec.pb(t[i]);
            break;
         }
         if(st==-1){
            vec.pb(t[i]);
            if(t[i+1]<t[i]) st=0;
            else st=1;
         }
         else if(st==0 && t[i+1]>t[i]){
            vec.pb(t[i]);
            st=1;
         }
         else if(st==1 && t[i+1]<t[i]){
               vec.pb(t[i]); st=0;}
      }
      cout << sz(vec) << endl;
      for(auto x: vec) cout << x << ' ';
      cout << endl;
   }


   return 0;
}


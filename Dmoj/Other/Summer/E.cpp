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
   int N,K,C;
   cin>>N>>K>>C;
   int t[K][N];
   int sm=0;
   for(int i=0; i<N; i++){
      for(int j=0; j<K; j++) cin>>t[j][i];
   }
   for(int i=0; i<K; i++){
      sort(t[i],t[i]+K,greater<int>());
      sm+=t[i][0];
   }

   set <int> s;
   s.insert(sm);
   for(int i=0; i<K; i++)lim[i]=0;

   while(sz(s)<C){
      int mn=INF,idx;
      for(int i=0; i<K; i++){
         if(lim[i]<N-1 && t[i][lim[i]+1]-t[i][lim[i]]<mn){
            mn=t[i][lim[i]+1]-t[i][lim[i]];
            idx=i;
         }
      }
      lim[idx]++;
      for(int i=0; i<K; i++){
         if(i!=idx){
            for(int j=0; j<lim[i]; j++)fdsjkljkldsfsfdjklfdsqjklfdsjklsdfkjlsdfkljdsflkjfdsjlmfdsjkldsfjlkdsfjklmsdfjklsdfljk
         }
      }
   }

   auto it=s.begin();
   for(int i=0; i<C-1; i++) it++;
   cout << *(it) << endl;



   return 0;
}


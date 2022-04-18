//Never stop trying
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

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

int32_t main(){
   boost;
   IO();

   int N; cin>>N;
   str s; cin>>s;
   set <int> st;
   for(int i=0; i<N; i++) if(s[i]=='R') st.insert(i);

   int ans=0;
   for(int i=0; i<N && !st.empty(); i++){
      auto it=st.end(); it--;
      if(*it<i) break;
      if(s[i]=='W'){
      	swap(s[i],s[*it]);
      	ans++;
      	st.erase(it);
      }
   }

   cout << ans << endl;
   //cout << s << endl;

   return 0;
}


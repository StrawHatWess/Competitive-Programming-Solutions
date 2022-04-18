//We'll win this
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

void IO(string name){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	if(name.size()){
        char * input = new char[name.size() + 3];
        char * output = new char[name.size() + 4];
        string input0 = name + ".in";
        string output0 = name + ".out";

        copy(input0.begin() , input0.end() , input);
        copy(output0.begin() , output0.end() , output);

        freopen(input,"r",stdin);
        freopen(output,"w",stdout);

    }
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


int32_t main() {
    IO("");

    int t; cin>>t;
    while(t--){
    	int N,T; cin>>N>>T;
    	vi a(N+2,0);
    	a[0]=0;
    	FOR(i,1,N+1) cin>>a[i];

    	int l=0,ans=0;
    	FOR(i,0,N+1){
    		if(i==N || a[i+1]-a[i]>T){
    			ans+=a[i]+T-l;
    			if(i+1<=N) l=a[i+1];
    		}
    	}
    	cout << ans << endl;
    }

    
    


    return 0;
}
//Change your approach 
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




ll fac[1000005];

int n,m,k;
int N,M,K;
vi X(MX),Y(MX);
vpi vec;

ll power(ll a , ll b){
    ll res = 1;
    ll base = a;
    while(b){
        if(b & 1)res *= base;
        base = (base * base) % MOD;
        b >>= 1;
        res = (res % MOD);
    }
    return res;
}

ll modreverse(ll a){
    return power(a , MOD - 2);
}

ll ways(ll a , ll b){
    ll c = fac[a - 1] * fac[b-1];
  
    c%= MOD;
    return (fac[a + b - 2] * modreverse(c))%MOD;
}

int f(int i, int j){
	int a=abs(X[j]-X[i]+1), b=abs(Y[j]-Y[i]+1);
	return ways(a,b);
}

const int LOG=22;
int cnt(int x){
	int ans=0;
	FOR(i,0,LOG) if((x)&((1)<<(i))) ans++;
	return ans;
}

bool valid(int m){
	vpi v; 
	FOR(i,0,K)  if((m)&((1)<<(i))) v.pb(vec[i]);
	sort(all(v));

	FOR(i,1,sz(v)) if(v[i].se<v[i-1].se) return 0;
	return 1;
}

int solve(int m){
	V<pair<pi,int>> v; 
	FOR(i,0,K)  if((m)&((1)<<(i))) v.pb({vec[i],i});
	sort(all(v));

	int ans=1;
	if(!sz(v)){
		ans=f(K,K+1);
	}
	else{
		FOR(i,0,sz(v)-1){
			ans*=f(vec[i].se,vec[i+1].se); ans%=MOD;
		}
		ans*=f(K,vec[0].se); ans%=MOD;
		ans*=f(vec[sz(v)-1].se,K+1); ans%=MOD;
	}
	return ans;



}

int32_t main() {
    IO("");

 	
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2;i<=1000000;i++)fac[i] = (fac[i-1] * i)%MOD;

    int t;
    cin >> t;
    while(t--){

        cin >> n >> m >> k;
        tie(N,M)={n,m};
        K=k;

        cout << f(K,K+1) << endl;
        

        bool f=0;

        FOR(i,0,K){
        	int x,y; cin>>x>>y;
        	X[i]=x; Y[i]=y;
        	vec.eb(x,y);
        	if(x==1 && y==1) f=1;
        	else if(x==N && y==M) f=1;
        }
        X[k]=1; Y[k]=1;
        X[k+1]=n; Y[K+1]=m;

        if(f){
        	cout << 0 << endl;
        	continue;
        }

        int ans=0;
        FOR(m,0,(1)<<(K)){
        	if(valid(m)){
        		if(cnt(m)%2==0) ans+=solve(m),ans%=MOD;
        		else{
        			ans-=solve(m);
        			ans+=MOD;
        			ans%=MOD;
    			}
        	}
        }

        cout << ans << endl;

        
    }
    


    return 0;
}
//Change your approach 
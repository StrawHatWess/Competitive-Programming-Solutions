//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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
const ll INF = 1e9;
const int MX = 5e3 + 10;
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
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

#ifndef LOCAL
#include "rail.h"
#endif

int d[MX][MX];

#ifdef LOCAL
int getDistance(int u, int v){
	return 0;
}
#endif

void findLocation(int N, int first, int location[], int stype[]){
	FOR(i,0,N) FOR(j,i,N){
		if(i==j) d[i][j]=0;
		else{
			d[i][j]=d[j][i]=getDistance(i,j);
		}
	}

	stype[0]=1;
	location[0]=first;

	int cur=0,c=0;
	set<int>s; FOR(i,1,N) s.insert(i);

	while(sz(s)){
		int mn=INF,nxt;
		for(auto v: s) if(ckmin(mn,d[cur][v])) nxt=v;

		if(!c){
			location[nxt]=location[cur]+d[cur][nxt];
			stype[nxt]=2;
		}
		else{
			location[nxt]=location[cur]-d[cur][nxt];
			stype[nxt]=1;
		}

		c=1-c;
		cur=nxt;
		s.erase(cur);
	}


}

#ifdef LOCAL
int main(){
	IO();

}
#endif

//Change your approach 
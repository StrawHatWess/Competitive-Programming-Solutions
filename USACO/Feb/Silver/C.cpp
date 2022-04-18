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
const ll INF = 1e18;
const int MX = 500 + 10;
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

int N; 
int g[MX][MX],g2[MX][MX];

void precompute(){
	FOR(i,0,N) FOR(j,0,N){
		g2[i][j]=(g[i][j]==100);
		g[i][j]=(g[i][j]>=100);
	}

	FOR(i,0,N) FOR(j,0,N){
		if(i){
			g[i][j]+=g[i-1][j];
			g2[i][j]+=g2[i-1][j];
		}
		if(j){
			g[i][j]+=g[i][j-1];
			g2[i][j]+=g2[i][j-1];
		}
		if(i && j){
			g[i][j]-=g[i-1][j-1];
			g2[i][j]-=g2[i-1][j-1];
		}
	}
}

int sum(int x, int y, int xx, int yy){
	int ans=g[xx][yy];
	if(x) ans-=g[x-1][yy];
	if(y) ans-=g[xx][y-1];
	if(x&&y) ans+=g[x-1][y-1];
	return ans;
}
int sum2(int x, int y, int xx, int yy){
	int ans=g2[xx][yy];
	if(x) ans-=g2[x-1][yy];
	if(y) ans-=g2[xx][y-1];
	if(x&&y) ans+=g2[x-1][y-1];
	return ans;
}
int f(int x, int y, int xx, int yy){
	return (xx-x+1)*(yy-y+1);
}

int main() {
    boost; IO();
    
    cin>>N;
    FOR(i,0,N) FOR(j,0,N) cin>>g[i][j];

    precompute();

    int ans=0;
    FOR(x,0,N) FOR(xx,x,N) FOR(yy,0,N){
		if(sum(x,yy,xx,yy)==f(x,yy,xx,yy)){

			int l=0,r=yy,y=-1; 
			while(l<=r){
				int m=(l+r)/2;
				if(sum(x,m,xx,yy)==f(x,m,xx,yy)){
					y=m;
					r=m-1;
				}
				else l=m+1;
			}
			assert(y!=-1);

			if(!sum2(x,y,xx,yy)) continue;

			l=y,r=yy; int ym=-1;
			while(l<=r){
				int m=(l+r)/2;
				if(sum2(x,m,xx,yy)){
					ym=m;
					l=m+1;
				}
				else r=m-1;
			}
			assert(ym!=-1);

			ans+=ym-y+1;
		}
    } 

    cout << ans << endl;

    return 0;
}
//Change your approach 
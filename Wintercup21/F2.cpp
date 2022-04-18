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
const int MX = 50 + 10;
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

int N,M,K,Sx,Sy,Ex,Ey; 
str s; 
map<char,int>mp;
//right left down up
char g[MX][MX];


bool grid(int x, int y){
	return min(x,y)>=0 && x<N && y<M;

}

pi nxt(int x, int y, int m){
	int nwx=x+nx[m],nwy=y+ny[m];
	if(!grid(nwx,nwy)||g[nwx][nwy]=='#') return {x,y};
	return {nwx,nwy};
}


int32_t main() {
    IO("");

    mp['R']=0; mp['L']=1; 
    mp['D']=2; mp['U']=3;

    int t; cin>>t;
    while(t--){
    	cin>>N>>M;
    	FOR(i,0,N) FOR(j,0,M) {
    		cin>>g[i][j];
    		if(g[i][j]=='R') tie(Sx,Sy)={i,j},g[i][j]='.';
    		else if(g[i][j]=='E') tie(Ex,Ey)={i,j},g[i][j]='.';
    	}
    	cin>>s;
    	K=sz(s);

    	priority_queue<pair<pi,pi>,V<pair<pi,pi>>,greater<pair<pi,pi>>>q;
    	q.push({{0,0},{Sx,Sy}});
    	int dist[K+1][N][M];
    	FOR(i,0,K+1) FOR(j,0,N) FOR(k,0,M) dist[i][j][k]=INF;
    	dist[0][Sx][Sy]=0;

    	while(!q.empty()){
    		int x=q.top().se.fi,y=q.top().se.se,idx=q.top().fi.se,d=q.top().fi.fi;
    		q.pop();
    		if(d>dist[idx][x][y]) continue;

    		if(idx<K){
    			pi p=nxt(x,y,mp[s[idx]]);
    			int nwx=p.fi,nwy=p.se;
    			if(dist[idx+1][nwx][nwy]>d){
    				dist[idx+1][nwx][nwy]=d;
    				q.push({{d,idx+1},{nwx,nwy}});
    			}

    			if(dist[idx+1][x][y]>d+1){
    				dist[idx+1][x][y]=d+1;
    				q.push({{d+1,idx+1},{x,y}});
    			}
    		}

    		FOR(m,0,4){
    			pi p=nxt(x,y,m);
    			int nwx=p.fi,nwy=p.se;

    			if(dist[idx][nwx][nwy]>d+1){
    				dist[idx][nwx][nwy]=d+1;
    				q.push({{d+1,idx},{nwx,nwy}});
    			}
    		}


    	}


    	int ans=INF;
    	FOR(i,0,K+1) ckmin(ans,dist[i][Ex][Ey]);
    	cout << ans << endl;


    }

    
    


    return 0;
}
//Change your approach 

/*
1
2 4
R.#.
#..E
RRUUDDRRUUUU
*/

/*
1
4 4
R.##
#...
E.#.
#...
RUUDRRURDRDLLLURL

*/
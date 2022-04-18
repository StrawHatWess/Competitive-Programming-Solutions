#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define inf 1000000000
#define sz(x) (ll)x.size()
#define boost() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair< int , pii> piii;
typedef pair<int,bool> pib;
typedef vector<pii> vii;
typedef vector<pib> vib;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<string,string> pss;
typedef pair<ll , ll> pll;
typedef vector<pss> vss;
typedef pair<ld , ld> pdd;
typedef vector<ld> vd;
typedef vector<vector<pib>> vvib;
typedef vector<piii> viii;
typedef vector<viii> vviii;
typedef vector<bool> vb;
typedef pair<pii , bool> piib;
typedef vector<pair<pii , bool>> viib;
const int   MOD = 1e9 + 7; //998244353;
const int N = 500005;


int main() {
    boost();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a = (n >> 3) & 1;
        int b = (n >> 2) & 1;
        int c = (n >> 1) & 1;
        int d = (n >> 0) & 1;
        if(a)cout << "jump" << " ";
        if(b)cout << "double_blink" << " ";
        if(c)cout << "close_your_eyes" << " ";
        if(d)cout << "wink" << " ";
        cout << endl;

    }
}


//NEVER GIVE UP
//LONG LONGht
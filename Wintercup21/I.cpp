#include <bits/stdc++.h>
using namespace std;
void setIO(string name){
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
int main(){
	setIO("");
	int tt;
	cin>>tt;
	while(tt--){
		long long n,m;
		cin>>n>>m;
		long long sum = 0;
		for(int i=0;i<m;i++){
			long long x;cin>>x;
			sum += x;
		}
		cout << int(ceil(double(n)/sum)) << '\n';
	}
	return 0;
}
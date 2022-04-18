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
		string s;
		cin>>s;
		int m;
		cin>>m;
		bool rev = 0;
		deque<char> d;
		for(auto i:s)d.push_back(i);
		while(m--){
			int t;
			cin>>t;
			if(t == 1){
				rev = !rev;
			}else if(t == 2){
				char c;
				cin>>c;
				// beginning
				if(rev == 0){
					d.push_front(c);
				}else d.push_back(c);
			}else{
				char c;
				cin>>c;
				if(rev == 1){
					d.push_front(c);
				}else d.push_back(c);
			}
		}
		if(rev == 1)reverse(d.begin(),d.end());
		for(auto c:d)cout<<c;
			cout<<'\n';
	}
	return 0;
}
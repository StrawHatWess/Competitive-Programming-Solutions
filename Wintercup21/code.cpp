#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> piii;
const int M = 52;
// 					R
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0};
char maze[M][M];
int dist[M][M];
int n,m;
char toc(int i,int j){
	if(i == 0 && j == 1)return 'R';
	if(i == 0)return 'L';
	if(i == 1 && j == 0)return 'D';
	return 'U';
}
pii toi(char c){
	if(c == 'R')return {0,1};
	if(c == 'L')return {0,-1};
	if(c == 'D')return {1,0};
	return {-1,0};
}
int main(){
	setIO("");
	int tt;
	cin>>tt;
	while(tt--){
		cin>>n>>m;
		memset(dist,0x3f3f3f3f,sizeof(dist));
		pii st,en;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>maze[i][j];
				if(maze[i][j] == 'S')st = {i,j};
				else if(maze[i][j] == 'E')en = {i,j};
			}
		}
		string s;
		cin>>s;
		auto val = [&](int x,int y){
			if(x < 0 || x >= n || y < 0 || y >= m)return false;
			return maze[x][y] != '#';
		};
		auto valid = [&](pii pos,int ind){
			pii p = toi(s[ind]);
			return val(pos.first+p.first,pos.second+p.second);
		};
		priority_queue<piii,vector<piii>,greater<piii>> pq; // cost,index, position
		dist[st.first][st.second] = 0;
		pq.push({{0,0},st});
		while(!pq.empty()){
			pii p = pq.top().first;
			pii pos = pq.top().second;
			if(p.first != dist[pos.first][pos.second])continue;
			while(!valid(pos,p.second))p.second++;
			for(int d=0;d<4;d++){
				int xn = nx[d]+pos.first;
				int yn = ny[d]+pos.second;
				if(val(nx,ny)){
					char let = toc(nx[d],ny[d]);
					if(s[p.second] == let){
						
						pq.push({{p.first,ind+1},{xn,yn}});
					}
				}
			}
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	int srow, scol;cin >> srow >> scol;
	vector<pair<int, int>> ans;
	ans.push_back({srow, scol});
	for(int col = 1;col <= m;col++){
		if(col != scol)ans.push_back({srow, col});
	}
	bool up = true;
	for(int col = m;col >= 1;col--){
		if(up){
			for(int row = 1;row <= n;row++){
				if(row != srow)ans.push_back({row, col});
			}
		}
		else{
			for(int row = n;row >= 1;row--){
				if(row != srow)ans.push_back({row, col});
			}
		}
		up = !up;
	}
	for(auto p : ans)cout << p.first << ' ' << p.second << endl;
}

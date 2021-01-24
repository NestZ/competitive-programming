#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;cin >> n;
	int w = n;
	vector<int> x(n);
	vector<int> y(n);
	vector<int> h(n);
	vector<tuple<int, int, int>> ans;
	for(int i = 0;i < n;i++){
		cin >> x[i] >> y[i] >> h[i];
		if(h[i] == 0)w--;
	}
	for(int i = 0;i <= 100;i++){
		for(int j = 0;j <= 100;j++){
			map<int, int> m;
			for(int k = 0;k < n;k++){
				if(h[k] == 0)continue;
				int H = h[k] + abs(i - x[k]) + abs(j - y[k]);
				m[H]++;
			}
			for(auto p : m){
				if(p.second == w){
					ans.emplace_back(i, j, p.first);
				}
			}
		}
	}
	for(auto p : ans){
		bool v = true;
		for(int i = 0;i < n;i++){
			if(h[i] != max(0, get<2>(p) - abs(get<0>(p) - x[i]) - abs(get<1>(p) - y[i])))
				v = false;
		}
		if(v){
			cout << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << endl;
			return 0;
		}
	}
}

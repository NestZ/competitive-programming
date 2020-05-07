#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	auto f = [&](int n){
		for(int i = 2;i < n;i++)
			if(n % i == 0)return i;
		return 0;
	};

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<vector<int>> ans(1001);
		vector<int> res(1001);
		for(int i = 0;i < n;i++){
			int k;cin >> k;
			ans[f(k)].push_back(i);
		}
		int ret = 1;
		for(int i = 0;i < 1000;i++){
			if(ans[i].size()){
				for(int j : ans[i])res[j] = ret;
				ret++;
			}
		}
		cout << ret - 1<< endl;
		for(int i = 0;i < n;i++)cout << res[i] << ' ';
		cout << endl;
	}
}

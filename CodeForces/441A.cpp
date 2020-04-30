#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, v;cin >> n >> v;
	vector<int> ans;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		bool flag = false;
		for(int j = 0;j < t;j++){
			int k;cin >> k;
			if(v > k)flag = true;
		}
		if(flag)ans.push_back(i + 1);
	}
	cout << ans.size() << endl;
	for(int i : ans)cout << i << ' ';
}

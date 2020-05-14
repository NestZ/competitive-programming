#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t, c;cin >> n >> t >> c;
	vector<int> ans;
	int curr = 0;
	for(int i = 0;i < n;i++){
		int k;cin >> k;
		if(k <= t)curr++;
		else{
			if(curr > 0)ans.push_back(curr);
			curr = 0;
		}
	}
	if(curr > 0)ans.push_back(curr);
	int cnt = 0;
	int l = ans.size();
	for(int i = 0;i < l;i++){
		if(ans[i] >= c)cnt += ans[i] - c + 1;
	}
	cout << cnt;
}

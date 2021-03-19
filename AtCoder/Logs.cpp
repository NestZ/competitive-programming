#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int cl(int a, int b){
	return (a + b - 1) / b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;cin >> n >> k;
	int ans = INT_MAX;
	int mx = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	int l = 1;
	int r = mx;
	while(l <= r){
		int m = l + (r - l) / 2;
		bool valid = true;
		int rem = k;
		int cur_ans = 0;
		for(int i = 0;i < n;i++){
			if(arr[i] <= m){
				cur_ans = max(cur_ans, arr[i]);
				continue;
			}
			int cut = cl(arr[i], m) - 1;
			if(cut > rem){
				valid = false;
				break;
			}
			rem -= cut;
			int res = cl(arr[i], cut + 1);
			cur_ans = max(cur_ans, res);
		}
		if(valid){
			ans = min(ans, cur_ans);
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << ans << endl;
}

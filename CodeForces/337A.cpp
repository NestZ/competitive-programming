#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int k,n;cin >> k >> n;
	int ans = INT_MAX;
	vector<int> v(n);
	for(int i = 0;i < n;i++)cin >> v[i];
	sort(v.begin(), v.end());
	for(int i = 0;i <= n - k;i++){
		vector<int> arr;
		for(int j = i;j < i + k;j++)arr.push_back(v[j]);
		ans = min(ans, *max_element(arr.begin(),arr.end()) - *min_element(arr.begin(), arr.end()));
	}
	cout << ans;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	vector<int> arr(n + 1);
	vector<int> cnt;
	for(int i = 0;i < n;i++){
		int num;cin >> num;
		arr[num]++;
	}
	for(int i = 0;i <= n;i++){
		if(arr[i] != 0)cnt.push_back(arr[i]);
	}
	sort(cnt.begin(), cnt.end());
	int want = max(0, (int)cnt.size() - k);
	int ans = 0;
	for(int i = 0;i < want;i++)ans += cnt[i];
	cout << ans << endl;
}

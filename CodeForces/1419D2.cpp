#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	vector<int> ans(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int mn = 0;
	int mx = n - 1;
	for(int i = n / 2;i < n;i++){
		if(arr[i] > arr[0])mx = min(mx, i);
	}
	bool m = true;
	int i = 0;
	for(i = 0;i < n;i++){
		if(m){
			ans[i] = arr[mx];
			arr[mx] = -1;
			mx++;
		}
		else{
			ans[i] = arr[mn];
			arr[mn] = -1;
			mn++;
		}
		m = !m;
		if(mx >= n || arr[mn] == -1)break;
	}
	int curu = 0;
	for(int j = i + 1;j < n;j++){
		while(arr[curu] == -1)curu++;
		ans[j] = arr[curu++];
	}
	int cnt = 0;
	for(int j = 1;j < n - 1;j++){
		if(ans[j] < ans[j - 1] && ans[j] < ans[j + 1])cnt++;
	}
	cout << cnt << endl;
	for(int j = 0;j < n;j++)cout << ans[j] << ' ';
}

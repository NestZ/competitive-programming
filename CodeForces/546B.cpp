#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int ans = 0;
	for(int i = 1;i < n;i++){
		if(arr[i] <= arr[i - 1]){
			ans += arr[i - 1] - arr[i] + 1;
			arr[i] = arr[i - 1] + 1;
		}
	}
	cout << ans;
}

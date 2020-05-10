#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c;cin >> n >> c;
	int ans = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n - 1;i++){
		if(arr[i] > arr[i + 1]){
			ans = max(ans, arr[i] - arr[i + 1] - c);
		}
	}
	cout << max(0, ans);
}

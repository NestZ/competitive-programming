#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int ans = 0;
	for(int i = 1;i < n - 1;i++){
		if(arr[i] > arr[i + 1] && arr[i] > arr[i - 1])ans++;
		if(arr[i] < arr[i + 1] && arr[i] < arr[i - 1])ans++;
	}
	cout << ans;
}

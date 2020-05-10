#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		vector<int> arr(3);
		for(int i = 0;i < 3;i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		int ans = 0;
		if(arr[2] >= arr[0] + arr[1])ans = arr[0] + arr[1];
		else ans = (arr[0] + arr[1] + arr[2]) / 2;
		cout << ans << endl;
	}
}

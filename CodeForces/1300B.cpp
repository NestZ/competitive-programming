#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n * 2);
		for(int i = 0;i < 2 * n;i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		cout << arr[n] - arr[n - 1] << endl;
	}
}

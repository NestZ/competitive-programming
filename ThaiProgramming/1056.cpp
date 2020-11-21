#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int fst = n - 1;
	int ans = 0;
	while(fst > 0){
		ans += arr[fst];
		fst -= k;
	}
	cout << ans << endl;
}

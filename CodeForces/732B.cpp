#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, k;cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int ans = 0;
	int curr = arr[0];
	for(int i = 1;i < n;i++){
		if(arr[i] + curr < k){
			int t = k - (arr[i] + curr);
			arr[i] += t;
			ans += t;
		}
		curr = arr[i];
	}
	cout << ans << endl;
	for(int i : arr)cout << i << ' ';
}

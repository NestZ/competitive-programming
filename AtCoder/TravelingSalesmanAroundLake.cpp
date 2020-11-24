#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, n;cin >> k >> n;
	vector<int> arr(n);
	vector<int> diff;
	int sum = 0;
	int mxD = 0;
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 1;i < n;i++){
		diff.push_back(arr[i] - arr[i - 1]);
	}
	diff.push_back(k - arr[n - 1] + arr[0]);
	for(int i : diff){
		sum += i;
		mxD = max(mxD, i);
	}
	cout << sum - mxD << endl;
}

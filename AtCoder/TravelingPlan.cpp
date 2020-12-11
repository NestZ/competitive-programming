#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(1, 0);
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		arr.push_back(t);
	}
	arr.push_back(0);
	int all = 0;
	for(int i = 1;i < n + 2;i++){
		all += abs(arr[i] - arr[i - 1]);
	}
	for(int i = 1;i <= n;i++){
		int cur = all;
		cur -= abs(arr[i] - arr[i - 1]);
		cur -= abs(arr[i] - arr[i + 1]);
		cur += abs(arr[i + 1] - arr[i - 1]);
		cout << cur << endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> arr(5);
	for(int i = 0;i < 5;i++)cin >> arr[i];
	map<int, int> m;
	int ans = 0;
	int sum = 0;
	for(int i = 0;i < 5;i++){
		m[arr[i]]++;
		sum += arr[i];
		if(m[arr[i]] > 1 && m[arr[i]] <= 3)ans = max(ans, m[arr[i]] * arr[i]);
	}
	cout << sum - ans;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	if(n == 1 && arr[0] != 0 && arr[0] != 15)return cout << -1, 0;
	if(arr[n - 1] == 0)return cout << "UP", 0;
	if(arr[n - 1] == 15)return cout << "DOWN", 0;
	if(arr[n - 1] - arr[n - 2] < 0)cout << "DOWN";
	else cout << "UP";
}

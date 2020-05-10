#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int pos = -1;
	for(int i = 0;i < n - 1;i++){
		if(pos == -1 && arr[i] > arr[i + 1])pos = i;
		else if(arr[i] > arr[i + 1])return cout << -1, 0;
	}
	if(pos == -1)cout << 0;
	else if(arr[n - 1] <= arr[0])cout << n - pos - 1;
	else cout << -1;
}

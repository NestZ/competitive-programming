#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	int mx = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	int b = 0;
	int a = 0;
	for(int i = 0;i < n;i++){
		b += arr[i];
		a += mx - arr[i];
	}
	int want = max(0, b - a + 1);
	cout << mx + ((want + n - 1) / n);
}

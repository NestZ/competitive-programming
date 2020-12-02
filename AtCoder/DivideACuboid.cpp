#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<ll> arr(3);
	for(int i = 0;i < 3;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 0;i < 3;i++){
		if(arr[i] % 2 == 0)
			return cout << 0 << endl, 0;
	}
	cout << arr[0] * arr[1] << endl;
}

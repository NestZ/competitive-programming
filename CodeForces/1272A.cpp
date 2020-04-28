#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		vector<ll> arr(3);
		for(int i = 0;i < 3;i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		if(arr[0] < arr[2])arr[0]++;
		if(arr[2] > arr[0])arr[2]--;
		if(arr[1] > arr[0])arr[1]--;
		else if(arr[1] < arr[2])arr[1]++;
		cout << abs(arr[0] - arr[1]) + abs(arr[0] - arr[2]) + abs(arr[2] - arr[1]);
		cout << endl;
	}
}

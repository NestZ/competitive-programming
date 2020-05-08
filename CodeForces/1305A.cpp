#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		vector<int> arra(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		for(int i = 0;i < n;i++)cin >> arra[i];
		sort(arr.begin(), arr.end());
		sort(arra.begin(), arra.end());
		for(int i : arr)cout << i << ' ';
		cout << endl;
		for(int i : arra)cout << i << ' ';
		cout << endl;
	}
}

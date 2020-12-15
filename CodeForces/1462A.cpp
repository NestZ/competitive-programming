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
		for(int i = 0;i < n;i++)cin >> arr[i];
		bool left = true;
		int l = 0;
		int r = n - 1;
		while(l <= r){
			if(left)cout << arr[l++] << ' ';
			else cout << arr[r--] << ' ';
			left = !left;
		}
		cout << endl;
	}
}

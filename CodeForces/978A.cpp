#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	map<int, int> m;
	vector<int> arr(n);
	int ans = 0;
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = n - 1;i >= 0;i--){
		if(m[arr[i]] == 1)arr[i] = -1;
		else{
			m[arr[i]]++;
			ans++;
		}
	}
	cout << ans << endl;
	for(int i : arr)if(i != -1)cout << i << ' ';
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int ans = 0;
	while(arr.size() > 1){
		int mx = 0;
		int rmi = 0;
		for(int i = 1;i < arr.size();i++){
			if(abs(arr[i] - arr[i - 1]) > mx){
				mx = abs(arr[i] - arr[i - 1]);
				rmi = i - 1;
			}
		}
		ans += mx;
		arr.erase(arr.begin() + rmi);
		arr.erase(arr.begin() + rmi);
	}
	cout << ans << endl;
}

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
		int mx = -1, mn = -1;
		for(int i = 1;i < n;i++){
			if(abs(arr[i] - arr[i - 1]) > 1){
				mx = i;
				mn = i - 1;
			}
		}
		if(mx != -1){
			cout << "YES" << endl << ++mn << ' ' << ++mx << endl;
		}
		else cout << "NO" << endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	for(int q = 1;q <= t;q++){
		int n;cin >> n;
		int ans = 0;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		for(int i = 0;i < n - 1;i++){
			int mn = arr[i];
			int mni = i;
			for(int j = i;j < n;j++){
				if(arr[j] < mn){
					mn = arr[j];
					mni = j;
				}
			}
			reverse(arr.begin() + i, arr.begin() + mni + 1);
			ans += mni - i + 1;
		}
		cout << "Case #" << q << ": " << ans << endl;
	}
}

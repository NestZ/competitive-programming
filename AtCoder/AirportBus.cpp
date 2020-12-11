#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c, k;cin >> n >> c >> k;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int ans = 1;
	int cur = arr[n - 1] - k;
	int pas = 0;
	for(int i = n - 1;i >= 0;i--){
		if(arr[i] >= cur){
			if(pas + 1 <= c)pas++;
			else{
				pas = 1;
				ans++;
				cur = arr[i] - k;
			}
		}
		else{
			ans++;
			pas = 1;
			cur = arr[i] - k;
		}
	}
	cout << ans << endl;
}

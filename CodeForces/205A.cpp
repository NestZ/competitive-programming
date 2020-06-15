#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	int cnt = 0;
	for(int i = 0;i < n;i++)cin >> arr[i];
	int mn = *min_element(arr.begin(), arr.end());
	for(int i = 0;i < n;i++)if(arr[i] == mn)cnt++;
	if(cnt > 1)cout << "Still Rozdil";
	else cout << min_element(arr.begin(), arr.end()) - arr.begin() + 1;
}

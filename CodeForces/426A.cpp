#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, s;cin >> n >> s;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int sum = 0;
	for(int i = 0;i < n - 1;i++)sum += arr[i];
	if(sum <= s)cout << "YES";
	else cout << "NO";
}

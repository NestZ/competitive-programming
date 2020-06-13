#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	auto it = upper_bound(arr.begin(), arr.end(), arr[0]);
	if(it == arr.end())cout << "NO";
	else cout << *it;
}

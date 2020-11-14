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
	if(n < 3)return cout << "no" << endl, 0;
	if(arr[0] + arr[1] <= arr[n - 1])cout << "yes";
	else cout << "no";
	cout << endl;
}

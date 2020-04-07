#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, k;cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int ans = 0;
	for(int i : arr)if(i + k <= 5)ans++;
	cout << ans / 3;
}

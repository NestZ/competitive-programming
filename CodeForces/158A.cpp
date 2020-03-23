#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n,k;cin >> n >> k;
	int ans = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n;i++){
		if(arr[i] >= arr[k - 1] &&  arr[i] > 0)ans++;
		else break;
	}
	cout << ans;
}

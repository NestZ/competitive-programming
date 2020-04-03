#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n,l;cin >> n >> l;
	vector<int> arr(n);
	double ans = -1e9;
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 0;i < n;i++){
		if(i == 0)ans = (double)arr[i];
		ans = max(ans, (arr[i] - arr[i - 1]) / 2.0);
		if(i == n - 1)ans = max(ans, (l - arr[i]) * 1.0);
	}
	printf("%.10f", ans);
}

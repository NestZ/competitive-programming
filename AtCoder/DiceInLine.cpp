#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	vector<int> arr(n);
	vector<double> pre(n + 1);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n;i++){
		pre[i + 1] = (1 + arr[i]) / 2.0 + pre[i];
	}
	double ans = 0;
	for(int i = 0;i < n - k + 1;i++){
		ans = max(ans, pre[i + k] - pre[i]);
	}
	printf("%.9lf\n", ans);
}

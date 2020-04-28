#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		vector<int> arr(n);
		vector<int> pre(n + 1, 0);
		for(int i = 0;i < n;i++)cin >> arr[i];
		for(int i = 2;i < n;i++){
			if(arr[i - 1] > arr[i - 2] && arr[i - 1] > arr[i])
				pre[i]++;
			pre[i] += pre[i - 1];
		}
		pre[n] += pre[n - 1];
		int mx = 0;
		int d = 1;
		for(int i = 1;i <= n - k + 1;i++){
			if(pre[i + k - 2] - pre[i] > mx){
				mx = pre[i + k - 2] - pre[i];
				d = i;
			}
		}
		cout << mx + 1 << ' ' << d << endl;
	}
}

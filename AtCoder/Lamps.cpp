#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;cin >> n >> k;
	vector<int> arr(n);
	vector<int> sum(n + 1);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		int s = max(0, i - arr[i]);
		int e = min(n, i + arr[i] + 1);
		sum[s]++;
		sum[e]--;
	}
	for(int i = 0;i < k;i++){
		int cur = 0;
		int cnt = 0;
		for(int j = 0;j < n;j++){
			cur += sum[j];
			arr[j] = cur;
			sum[j] = 0;
			if(arr[j] == n)cnt++;
		}
		if(cnt == n)break;
		for(int j = 0;j < n;j++){
			int s = max(0, j - arr[j]);
			int e = min(n, j + arr[j] + 1);
			sum[s]++;
			sum[e]--;
		}
	}
	for(int i : arr)
		cout << i << ' ';
	cout << endl;
}

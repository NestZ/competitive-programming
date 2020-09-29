#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		vector<int> arr(n, -1);
		vector<int> ans(n);
		int mid = 0;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			if(arr[i] < k / 2)ans[i] = 0;
			else if(arr[i] > k / 2)ans[i] = 1;
			if(k % 2 == 0 && arr[i] == k / 2)mid++;
		}
		if(k % 2 == 0){
			int w = mid / 2;
			for(int j = 0;j < n;j++){
				if(w <= 0)break;
				if(arr[j] == k / 2){
					w--;
					ans[j] = 1;
				}
			}
		}
		for(int i : ans)cout << max(i, 0) << ' ';
		cout << endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool valid(int a, int b, int c){
	if(a < b + c && b < c + a && c < a + b)return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int ans = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 0;i < n - 2;i++){
		for(int j = i + 1;j < n - 1;j++){
			int a = arr[i];
			int b = arr[j];
			int c = INT_MIN;
			int l = j + 1;
			int r = n - 1;
			while(l <= r){
				int mid = l + (r - l) / 2;
				if(valid(a, b, arr[mid])){
					l = mid + 1;
					c = max(c, mid);
				}
				else r = mid - 1;
			}
			if(c != INT_MIN)ans += c - j;
		}
	}
	cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	if(n < 3)return cout << 0, 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int l = arr[0];
	int r = arr[n - 1];
	int pl = n - 1;
	int pr = 0;
	for(int i = 0;i < n;i++){
		if(arr[i] != l){
			pl = i;
			break;
		}
	}
	for(int i = n - 1;i >= 0;i--){
		if(arr[i] != r){
			pr = i;
			break;
		}
	}
	cout << max(0, pr - pl + 1);
}

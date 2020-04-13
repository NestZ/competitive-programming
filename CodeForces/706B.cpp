#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int q;cin >> q;
	for(int i = 0;i < q;i++){
		int t;cin >> t;
		int b = 0;
		for(int k = n / 2;k > 0;k /= 2){
			while(b + k < n && arr[b + k] <= t)b += k;
		}
		if(arr[b] > t)cout << 0 << endl;
		else cout << b + 1 << endl;
	}
}

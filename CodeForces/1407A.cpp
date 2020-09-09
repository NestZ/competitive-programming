#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;cin >> q;
	while(q--){
		int n;cin >> n;
		vector<int> arr(n);
		int cnt1 = 0;
		int cnt0 = 0;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			if(arr[i] == 1)cnt1++;
			else cnt0++;
		}
		int ans = 1;
		int num = n / 2;
		if(cnt0 >= cnt1)ans = 0;
		if(cnt0 < cnt1 && ((n / 2) & 1))num++;
		cout << num << endl;
		for(int i = 0;i < num;i++)cout << ans << ' ';
		cout << endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		vector<char> arr(k, '2');
		string s;cin >> s;
		bool flag = true;
		for(int i = 0;i < n;i++){
			if(s[i] == '?')continue;
			if(arr[i % k] != s[i] && arr[i % k] != '2')flag = false;
			else arr[i % k] = s[i];
		}
		int cnt0 = 0, cnt1 = 0;
		for(int i = 0;i < k;i++){
			if(arr[i] == '1')cnt1++;
			else if(arr[i] == '0')cnt0++;
		}
		if(cnt1 > k / 2 || cnt0 > k / 2)flag = false;
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}

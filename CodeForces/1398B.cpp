#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		string s;cin >> s;
		int n = s.length();
		vector<int> arr;
		int cur = 0;
		for(int i = 0;i < n;i++){
			if(s[i] == '1')cur++;
			else {
				if(cur > 0)arr.push_back(cur);
				cur = 0;
			}
		}
		if(cur > 0)arr.push_back(cur);
		int ans = 0;
		sort(arr.begin(), arr.end());
		for(int i = arr.size() - 1;i >= 0;i -= 2)ans += arr[i];
		cout << ans << endl;
	}
}

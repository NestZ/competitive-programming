#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool is(string s){
	int n = s.length();
	for(int i = 0;i < n / 2;i++){
		if(s[i] != s[n - i - 1])return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	set<string> s;
	string ans = "";
	vector<string> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n;i++){
		if(is(arr[i])){
			ans += arr[i];
			break;
		}
	}
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			string rev = arr[i];
			reverse(rev.begin(), rev.end());
			if(arr[j] == rev){
				ans.insert(ans.begin(), arr[i].begin(), arr[i].end());
				ans.insert(ans.end(), arr[j].begin(), arr[j].end());
			}
		}
	}
	cout << ans.length() << endl;
	cout << ans;
}

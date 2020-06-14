#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<string> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int len = arr[0].length();
	set<char> s[len];
	for(int i = 0;i < n;i++){
		string curr = arr[i];
		for(int j = 0;j < len;j++)s[j].insert(curr[j]);
	}
	int ans = 0;
	for(set<char> se : s){
		if(se.size() == 1)ans++;
		else break;
	}
	cout << ans;
}

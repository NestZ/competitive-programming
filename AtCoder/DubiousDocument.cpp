#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> cnt(26, INT_MAX);
	for(int i = 0;i < n;i++){
		string s;cin >> s;
		vector<int> cur(26, 0);
		for(char c : s)cur[c - 'a']++;
		for(int j = 0;j < 26;j++){
			cnt[j] = min(cnt[j], cur[j]);
		}
	}
	for(int i = 0;i < 26;i++){
		for(int j = 0;j < cnt[i];j++){
			cout << char('a' + i);
		}
	}
	cout << endl;
}

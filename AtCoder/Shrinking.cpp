#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	map<char, vector<int>> m;
	int ans = INT_MAX;
	for(int i = 0;i < n;i++){
		m[s[i]].push_back(i);
	}
	for(char c = 'a';c <= 'z';c++){
		if(m[c].size() == 0)continue;
		vector<int> cur_v = m[c];
		int len = cur_v.size();
		int last = n - cur_v[len - 1] - 1;
		int cur_ans = last;
		for(int i = 0;i < len;i++){
			int bef = cur_v[i];
			if(i > 0)
				bef = cur_v[i] - cur_v[i - 1] - 1; 
			cur_ans = max(cur_ans, bef);
		}
		ans = min(ans, cur_ans);
	}
	cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	vector<int> ans(n);
	int cntr = 0;
	for(int i = 0;i < n - 1;){
		if(s[i] == 'L'){
			i++;
			cntr = 0;
			continue;
		}
		if(s[i + 1] == 'R'){
			i++;
			cntr++;
			continue;
		}
		cntr++;
		int rodd = cntr / 2;
		int reven = (cntr + 1) / 2;
		int dis = 0;
		int lodd = 0;
		int leven = 0;
		for(int j = i + 1;j < n;j++){
			if(s[j] == 'R')break;
			if(dis % 2 == 0)leven++;
			else lodd++;
			dis++;
		}
		ans[i] = reven + lodd;
		ans[i + 1] = rodd + leven;
		i += dis + 1;
		cntr = 0;
	}
	for(int i : ans)cout << i << ' ';
	cout << endl;
}

/*
ID: nestz
LANG: C++14
TASK: dualpal
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

string to_base(int b, int num){
	string s = "";
	int div = num / b;
	int rem = num % b;
	if(rem < 10)s += to_string(rem);
	else s += 'A' + (rem - 10);
	while(div >= b){
		rem = div % b;
		div = div / b;
		if(rem < 10)s += to_string(rem);
		else s += 'A' + (rem - 10);
	}
	if(div != 0){
		if(div < 10)s += to_string(div);
		else s += 'A' + (div - 10);
	}
	reverse(s.begin(), s.end());
	return s;
}

bool is_palin(string s){
	int n = s.length();
	bool ans = true;
	for(int i = 0;i < n / 2;i++){
		if(s[i] != s[n - i - 1])ans = false;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("dualpal.out", "w", stdout);
	freopen("dualpal.in", "r", stdin);
	
	int n, s;cin >> n >> s;
	vector<int> ans;
	for(int i = s + 1;;i++){
		if(ans.size() == n)break;
		int cnt = 0;
		for(int b = 2;b <= 10;b++){
			string base = to_base(b, i);
			if(is_palin(base))cnt++;
		}
		if(cnt >= 2)ans.push_back(i);
	}
	for(int i : ans)cout << i << endl;
}

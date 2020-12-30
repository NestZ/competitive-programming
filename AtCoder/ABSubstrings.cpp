#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int cnt_ab(string &s){
	int cnt = 0;
	size_t pos = s.find("AB");
	while(pos != string::npos){
		cnt++;
		pos = s.find("AB", pos + 1);
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int end_a = 0;
	int start_b = 0;
	int both = 0;
	int ab = 0;
	for(int i = 0;i < n;i++){
		string s;cin >> s;
		int len = s.length();
		ab += cnt_ab(s);
		if(s[len - 1] == 'A' && s[0] == 'B')both++;
		else if(s[len - 1] == 'A')end_a++;
		else if(s[0] == 'B')start_b++;
	}
	int ans = ab;
	if(both > 0){
		if(start_b > 0 && end_a > 0){
			ans += both + 1;
			start_b--;
			end_a--;
			ans += min(start_b, end_a);
		}
		else if(start_b > 0 || end_a > 0)ans += both;
		else ans += both - 1;
	}
	else ans += min(start_b, end_a);
	cout << ans << endl;
}

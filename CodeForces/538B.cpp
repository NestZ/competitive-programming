#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	vector<string> ans;
	string t = "123456789";
	bool flag = s.find_first_of(t) != string::npos;
	while(flag){
		string a = "";
		bool h = false;
		for(int i = 0;i < n;i++){
			if(s[i] > '0'){
				a += '1';
				s[i] = '0' + (s[i] - '0' - 1);
				h = true;
			}
			else if(h)a += '0';
		}
		ans.push_back(a);
		flag = s.find_first_of(t) != string::npos;
	}
	cout << ans.size() << endl;
	for(string a : ans)cout << a << ' ';
}

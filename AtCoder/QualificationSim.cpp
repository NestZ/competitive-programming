#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;cin >> n >> a >> b;
	string s;cin >> s;
	int over_pass = 0;
	int over_cnt = 0;
	int pass = 0;
	for(char c : s){
		if(c == 'b')over_cnt++;
	}
	vector<bool> ans(n, false);
	for(int i = 0;i < n;i++){
		if(s[i] == 'a'){
			if(pass < a + b){
				ans[i] = true;
				pass++;
			}
		}
		else if(s[i] == 'b'){
			if(pass < a + b && over_pass < b){
				ans[i] = true;
				pass++;
				over_pass++;
			}
		}
	}
	for(bool f : ans){
		if(f)cout << "Yes";
		else cout << "No";
		cout << endl;
	}
}

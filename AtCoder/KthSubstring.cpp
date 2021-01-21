#include<bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	int n = s.length();
	int k;cin >> k;
	set<string> all;
	for(int i = 1;i <= 5;i++){
		for(int j = 0;j <= n - i;j++){
			all.insert(s.substr(j, i));
		}
	}
	int cur = 1;
	for(string st : all){
		if(cur == k){
			cout << st << endl;
			break;
		}
		cur++;
	}
}

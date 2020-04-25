#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<int> ans;
void get(int c){
	if(c <= 1)return;
	if(c == 4){
		ans.push_back(3);
		ans.push_back(2);
		ans.push_back(2);
	}
	else if(c == 6){
		ans.push_back(5);
		ans.push_back(3);
	}
	else if(c == 8){
		ans.push_back(7);
		for(int i = 0;i < 3;i++)ans.push_back(2);
	}
	else if(c == 9){
		ans.push_back(7);
		ans.push_back(3);
		ans.push_back(3);
		ans.push_back(2);
	}
	else ans.push_back(c);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	for(int i = 0;i < n;i++){
		if(s[i] - '0' > 1)get(s[i] - '0');
	}
	sort(ans.rbegin(), ans.rend());
	for(int i : ans)cout << i;
}

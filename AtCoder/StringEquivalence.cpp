#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<string> ans;
int n;

void gen(string s, int cur, char mx){
	if(cur > n)ans.push_back(s);
	else{
		for(int i = 1;i <= cur;i++){
			if(cur == 1 || char('a' + i - 1) <= char(mx + 1))
				gen(s + char('a' + i - 1), cur + 1, max(mx, char('a' + i - 1)));
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	string t = "";
	gen(t, 1, 'a');
	for(string s : ans)cout << s << endl;
}

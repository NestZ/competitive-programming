#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int n;
vector<string> ans;
void fuck(int cur){
	if(cur == n){
		for(string s : ans)
			cout << s << endl;
		cout << "E\n";
	}
	else{
		ans.push_back("--");
		fuck(cur + 1);
		ans.pop_back();
		if(cur + 2 <= n){
			ans.push_back("||");
			fuck(cur + 2);
			ans.pop_back();
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	fuck(0);
}

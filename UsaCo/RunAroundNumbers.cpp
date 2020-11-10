/*
ID: nestz
LANG: C++14
TASK: runround
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool run_around(int n){
	string s = to_string(n);
	int len = s.length();
	//find false constraint
	if(s.find('0') != string::npos)return false;
	string t = s;
	sort(t.begin(), t.end());
	for(int i = 1;i < len;i++){
		if(t[i] == t[i - 1])return false;
	}

	set<int> st;
	int cur = int(s[0] - '0') % len;
	while(st.count(cur) == 0){
		st.insert(cur);
		cur = (cur + int(s[cur] - '0')) % len;
	}
	if((int)st.size() == len)return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("runround.out", "w", stdout);
	freopen("runround.in", "r", stdin);
	
	int n;cin >> n;
	for(int i = n + 1;;i++){
		if(run_around(i)){
			cout << i << endl;
			break;
		}
	}
}

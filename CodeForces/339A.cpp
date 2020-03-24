#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	vector<int> op;
	string s;cin >> s;
	int n = s.length();
	for(int i = 0;i < n;i++){
		if(s[i] != '+')op.push_back(s[i] - '0');
	}
	sort(op.begin(), op.end());
	cout << op[0];
	for(int i = 1;i < op.size();i++)cout << '+' << op[i];
}

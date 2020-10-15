#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

char minC(string s){
	int dep = 0;
	int n = s.length();
	int mn = 3;	
	char arr[] = {'+', '*', '^'};
	for(int i = 0;i < n;i++){
		if(s[i] == '(')dep++;
		else if(s[i] == ')')dep--;
		if(dep == 0){
			if(s[i] == '+')mn = 0;
			else if(s[i] == '*')mn = min(mn, 1);
			else if(s[i] == '^')mn = min(mn, 2);
		}
	}
	if(mn == 3)return '$';
	return arr[mn];
}

string solve(string e, int cur_op, vector<int> &op){
	if((int)op.size() == cur_op)return e;
	char mn = minC(e);
	if(mn == '$' && e[0] == '(' && e[e.size() - 1] == ')' && op[cur_op] == 1)
		return solve(e.substr(1, e.size() - 2), cur_op + 1, op);
	else if(mn == '$' && e[0] == '(' && e[e.size() - 1] == ')' && op[cur_op] != 1)
		return "null";
	int dep = 0;
	string new_e = "";
	vector<string> exp;
	for(char c : e){
		if(c == '(')dep++;
		else if(c == ')')dep--;
		if(c == mn && dep == 0){
			exp.push_back(new_e);
			new_e = "";
		}
		else new_e += c;
	}
	if(new_e.length() > 0)exp.push_back(new_e);
	if(int(exp.size()) < op[cur_op])return "null";
	return solve(exp[op[cur_op] - 1], cur_op + 1, op);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string e;cin >> e;
	int n;cin >> n;
	for(int i = 0;i < n;i++){
		vector<int> op;
		int in;cin >> in;
		while(in != 0){
			op.push_back(in);
			cin >> in;
		}
		for(int j = 0;j < int(op.size());j++){
			cout << "op(" << op[op.size() - j - 1] << ',';
		}
		cout << 'p';
		for(int j = 0;j < int(op.size());j++)cout << ')';
		cout << '=' << solve(e, 0, op) << endl;
	}
}

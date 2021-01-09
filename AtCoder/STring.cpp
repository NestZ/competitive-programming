#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	int n = s.length();
	stack<char> q;
	for(int i = 0;i < n;i++){
		if(q.empty())q.push(s[i]);
		else{
			if(q.top() == 'S' && s[i] == 'T')
				q.pop();
			else q.push(s[i]);
		}
	}
	cout << q.size() << endl;
}

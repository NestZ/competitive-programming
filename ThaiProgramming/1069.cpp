#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	stack<char> s;
	for(int i = 0;i < n;i++){
		char c;cin >> c;
		if(s.empty())s.push(c);
		else{
			if(c == s.top())s.pop();
			else s.push(c);
		}
	}
	cout << s.size() << endl;
	if(s.size() == 0)cout << "empty";
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

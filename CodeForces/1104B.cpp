#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	int cnt = 0;
	stack<char> st;
	for(int i = 0;i < n;i++){
		if(st.empty())st.push(s[i]);
		else{
			if(st.top() == s[i]){
				st.pop();
				cnt++;
			}
			else st.push(s[i]);
		}
	}
	if(cnt & 1)cout << "Yes";
	else cout << "No";
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	stack<int> s;
	for(int i = 0;i < n;i++){
		if(s.empty())s.push(1);
		else{
			int curr = 1;	
			while(!s.empty() && s.top() == curr){
				s.pop();
				curr++;
			}
			s.push(curr);
		}
	}
	vector<int> ans;
	while(!s.empty()){
		ans.push_back(s.top());
		s.pop();
	}
	reverse(ans.begin(), ans.end());
	for(int i : ans)cout << i << ' ';
}

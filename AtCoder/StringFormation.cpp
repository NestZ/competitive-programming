#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n;cin >> n;
	int flip = 0;
	deque<char> q;
	for(char c : s)q.push_back(c);
	for(int i = 0;i < n;i++){
		int op;cin >> op;
		if(op == 1)flip++;
		else{
			int f;cin >> f;
			f--;
			char c;cin >> c;
			if((flip & 1) ^ f)q.push_back(c);
			else q.push_front(c);
		}
	}
	while(!q.empty()){
		if(flip & 1){
			cout << q.back();
			q.pop_back();
		}
		else{
			cout << q.front();
			q.pop_front();
		}
	}
	cout << endl;
}

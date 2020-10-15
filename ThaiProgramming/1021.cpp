#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	priority_queue<ll> p;
	for(int i = 0;i < n;i++){
		char op;cin >> op;
		if(op == 'P'){
			ll num;cin >> num;
			p.push(num);
		}
		else{
			if(p.size() == 0)cout << -1 << endl;
			else{
				cout << p.top() << endl;
				p.pop();
			}
		}
	}
}

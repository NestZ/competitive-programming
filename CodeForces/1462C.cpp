#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int cur = 9;
		deque<int> q;
		bool ans = true;
		if(n > 45)ans = false;
		while(n > cur){
			n -= cur;
			q.push_front(cur--);
		}
		if(n > 0)q.push_front(n);
		if(ans){
			while(!q.empty()){
				cout << q.front();
				q.pop_front();
			}
		}
		else cout << -1;
		cout << endl;
	}
}

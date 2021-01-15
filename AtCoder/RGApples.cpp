#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y, a, b, c;cin >> x >> y >> a >> b >> c;
	ll ans = 0;
	priority_queue<int> red;
	priority_queue<int> green;
	priority_queue<int> no;
	for(int i = 0;i < a;i++){
		int t;cin >> t;
		red.push(-t);
	}
	for(int i = 0;i < b;i++){
		int t;cin >> t;
		green.push(-t);
	}
	for(int i = 0;i < c;i++){
		int t;cin >> t;
		no.push(t);
	}
	while((int)red.size() > x)red.pop();
	while((int)green.size() > y)green.pop();
	for(int i = 0;i < c;i++){
		if(no.top() > -red.top() || no.top() > -green.top()){
			if(-red.top() < -green.top()){
				red.pop();
				red.push(-no.top());
			}
			else{
				green.pop();
				green.push(-no.top());
			}
			no.pop();
		}
		else break;
	}
	while(!red.empty()){
		ans += -red.top();
		red.pop();
	}
	while(!green.empty()){
		ans += -green.top();
		green.pop();
	}
	cout << ans << endl;
}

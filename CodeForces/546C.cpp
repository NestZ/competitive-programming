#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;cin >> n;
	queue<int> q1;
	queue<int> q2;
	int a;cin >> a;
	for(int i = 0;i < a;i++){
		int t;cin >> t;
		q1.push(t);
	}
	int b;cin >> b;
	for(int i = 0;i < b;i++){
		int t;cin >> t;
		q2.push(t);
	}
	set<pair<queue<int>, queue<int>>> s;
	int cnt = 0;
	while(q1.size() > 0 && q2.size() > 0){
		cnt++;
		s.insert({q1, q2});
		int n1 = q1.front();q1.pop();
		int n2 = q2.front();q2.pop();
		if(n1 > n2){
			q1.push(n2);
			q1.push(n1);
		}
		else{
			q2.push(n1);
			q2.push(n2);
		}
		if(s.count({q1, q2}) > 0)return cout << -1, 0;
	}
	cout << cnt << ' ' << (q1.size() == 0 ? 2 : 1);
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	deque<ll> q;
	ll n;cin >> n;
	set<ll> s;
	for(int i = 0;i < n;i++){
		ll t;cin >> t;
		if(i == 0){
			q.push_back(t);
		}
		else s.insert(t);
	}
	bool flag = true;
	ll num = q.front();
	while(flag){
		if(s.count(num * 2LL) > 0){
			q.push_back(num * 2LL);
			s.erase(num * 2LL);
			num = num * 2LL;
		}
		else if(num % 3LL == 0 && s.count(num / 3LL) > 0){
			q.push_back(num / 3LL);
			s.erase(num / 3LL);
			num = num / 3LL;
		}
		else flag = false;
	}
	flag = true;
	num = q.front();
	while(flag){
		if(num % 2LL == 0 && s.count(num / 2LL) > 0){
			q.push_front(num / 2LL);
			s.erase(num / 2LL);
			num = num / 2LL;
		}
		else if(s.count(num * 3LL) > 0){
			q.push_front(num * 3LL);
			s.erase(num * 3LL);
			num = num * 3LL;
		}
		else flag = false;
	}
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop_front();
	}
}

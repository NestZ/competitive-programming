#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
set<int> vis;
queue<pair<int, int>> q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;cin >> a >> b;
	if(a >= b)cout << a - b << endl;
	else{
		q.push(make_pair(a, 0));
		while(!q.empty()){
			pair<int, int> cur = q.front();
			q.pop();
			int d = cur.second;
			int num = cur.first;
			if(num == b)return cout << d << endl, 0;
			if(num < b && vis.count(num * 2) == 0){
				q.push(make_pair(num * 2, d + 1));
				vis.insert(num * 2);
			}
			if(num > 1 && vis.count(num - 1) == 0){
				q.push(make_pair(num - 1, d + 1));
				vis.insert(num - 1);
			}
		}
	}
}

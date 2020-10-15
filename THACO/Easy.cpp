#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b;cin >> a >> b;
	deque<int> q;
	int rem = 0;
	int posa = a.length() - 1;
	int posb = b.length() - 1;
	while(posa >= 0 || posb >= 0){
		if(posa < 0){
			int curb = b[posb] - '0';
			int ans = (curb + rem) % 10;
			rem = (curb + rem) / 10;
			q.push_front(ans);
			posb--;
		}
		else if(posb < 0){
			int cura = a[posa] - '0';
			int ans = (cura + rem) % 10;
			rem = (cura + rem) / 10;
			q.push_front(ans);
			posa--;
		}
		else{
			int cura = a[posa] - '0';
			int curb = b[posb] - '0';
			int ans = (cura + curb + rem) % 10;
			rem = (cura + curb + rem) / 10;
			q.push_front(ans);
			posa--;posb--;
		}
	}
	if(rem != 0)q.push_front(rem);
	while(!q.empty()){
		cout << q.front();
		q.pop_front();
	}
}

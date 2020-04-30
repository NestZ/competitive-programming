#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	set<int> s;
	int l1 = 1;
	int l2 = 1;
	int curr = 0;
	s.insert(1);
	while(curr < 1000){
		curr = l1 + l2;
		l1 = l2;
		l2 = curr;
		s.insert(curr);
	}
	for(int i = 1;i <= n;i++){
		if(s.count(i) != 0)cout << 'O';
		else cout << 'o';
	}
}

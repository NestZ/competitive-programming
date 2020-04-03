#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	set<int> s;
	for(int i = 0;i < 4;i++){
		int t;cin >> t;
		s.insert(t);
	}
	cout << 4 - s.size();
}

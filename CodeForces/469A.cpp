#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	set<int> s;
	int a;cin >> a;
	while(a--){
		int t;cin >> t;
		s.insert(t);
	}
	cin >> a;
	while(a--){
		int t;cin >> t;
		s.insert(t);
	}
	cout << (s.size() == n ? "I become the guy." : "Oh, my keyboard!");
}

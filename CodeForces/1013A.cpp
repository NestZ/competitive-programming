#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int s1 = 0;
	int s2 = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		s1 += t;
	}
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		s2 += t;
	}
	if(s2 > s1)cout << "No";
	else cout << "Yes";
}

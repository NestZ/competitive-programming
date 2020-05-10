#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	for(int i = 1;i <= n;i++){
		if(n % i == 0){
			reverse(s.begin(), s.begin() + i);
		}
	}
	cout << s;
}

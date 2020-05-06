#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s = "";
	int l = 0;
	for(int i = 1;i <= 1000;i++){
		if(i < 10)l++;
		else if(i < 100)l += 2;
		else l += 3;
		s += to_string(i);
		if(l >= n)break;
	}
	cout << s[n - 1];
}

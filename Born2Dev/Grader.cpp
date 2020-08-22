#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	if(n >= 80)cout << 'A';
	else if(n >= 70)cout << 'B';
	else if(n >= 60)cout << 'C';
	else if(n >= 50)cout << 'D';
	else cout << 'F';
}

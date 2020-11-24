#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;cin >> a >> b;
	int ans = 0;
	if(a <= 0 && b >= 0)ans = 0;
	else if(a == 0)ans = 0;
	else if(a < 0 && b < 0){
		if((abs(a - b) + 1) % 2 == 0)ans = 1;
		else ans = -1;
	}
	else ans = 1;
	if(ans == 0)cout << "Zero";
	else if(ans == 1)cout << "Positive";
	else cout << "Negative";
	cout << endl;
}

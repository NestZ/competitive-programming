#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;cin >> a >> b;
	if(a == 0 || b == 0)return cout << 0, 0;
	if(b * 2 <= a)return cout << b, 0;
	if(a * 2 <= b)return cout << a, 0;
	int t = a;
	int w = a * 2;
	while(w > b){
		t--;
		w -= 3;
	}
	cout << t;
}

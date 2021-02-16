#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	four = n / 15;
	n %= 15;
	if(n >= 10){
		four++;
		n = 0;
	}
	three = n / 5;
	n %= 5;
	if(n >= 4){
		three++;
		n = 0;
	}
	two = n / 2;
	n %= 2;
	one = n;
	cout << four * 3000 + three * 1500 + two * 800 + one * 500 << endl;
}

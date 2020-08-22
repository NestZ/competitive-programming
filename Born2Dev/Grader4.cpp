#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	if(n < 0)return cout << "Error : Value must be greater than or equal to 0.", 0;
	if(n > 100)return cout << "Error : Value must be less than or equal to 100.", 0;
	if(n >= 90)cout << 'A';
	else if(n >= 85)cout << "B+";
	else if(n >= 80)cout << 'B';
	else if(n >= 75)cout << "C+";
	else if(n >= 70)cout << 'C';
	else if(n >= 65)cout << "D+";
	else if(n >= 60)cout << 'D';
	else cout << 'F';
}

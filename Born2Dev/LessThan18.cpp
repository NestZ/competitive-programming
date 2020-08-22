#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string name;cin >> name;
	string lname;cin >> lname;
	int y;cin >> y;
	if(2020 - y < 18)cout << "You shall not pass!";
	else cout << "Welcome " << name << ' ' << lname << " to NongGipsy Pub";
}

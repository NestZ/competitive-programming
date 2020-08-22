#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	cout << "--Customers Information--\n";
	for(int i = 0;i < n;i++){
		string name, lname;cin >> name >> lname;
		int y;cin >> y;
		string gen;cin >> gen;
		printf("%s %s (age : %d)\n", name.c_str(), lname.c_str(), 2017 - y);
	}
}

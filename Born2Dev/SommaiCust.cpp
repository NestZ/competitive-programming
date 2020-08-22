#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string name;getline(cin, name);
	string lname;getline(cin, lname);
	string add;getline(cin, add);
	string gen;getline(cin, gen);
	string tel;getline(cin, tel);
	printf("--- Customer Detail ---\n");
	printf("Name : %s %s\n", name.c_str(), lname.c_str());
	printf("Address : %s\n", add.c_str());
	printf("Gender : %s\n", gen.c_str());
	printf("Tel : %s\n", tel.c_str());
}

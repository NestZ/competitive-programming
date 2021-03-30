#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	set<string> all;
	//0000
	all.insert("AKIHABARA");
	//0001
	all.insert("AKIHABAR");
	//0010
	all.insert("AKIHABRA");
	//0011
	all.insert("AKIHABR");
	//0100
	all.insert("AKIHBARA");
	//0101
	all.insert("AKIHBAR");
	//0110
	all.insert("AKIHBRA");
	//0111
	all.insert("AKIHBR");
	//1000
	all.insert("KIHABARA");
	//1001
	all.insert("KIHABAR");
	//1010
	all.insert("KIHBARA");
	//1011
	all.insert("KIHABR");
	//1100
	all.insert("KIHBARA");
	//1101
	all.insert("KIHBAR");
	//1110
	all.insert("KIHBRA");
	//1111
	all.insert("KIHBR");
	if(all.count(s))cout << "YES";
	else cout << "NO";
	cout << endl;
}

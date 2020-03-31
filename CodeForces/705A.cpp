#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	string s = "I hate ";
	for(int i = 1;i < n;i++){
		s += "that ";
		if(i & 1)s += "I love ";
		else s += "I hate ";
	}
	s += "it";
	cout << s;
}

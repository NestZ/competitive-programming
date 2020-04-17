#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int ans = 0;
	size_t q = s.find("Q");
	while(q != string::npos){
		size_t a = s.find("A", q + 1);
		while(a != string::npos){
			size_t q2 = s.find("Q", a + 1);
			while(q2 != string::npos){
				ans++;
				q2 = s.find("Q", q2 + 1);
			}
			a = s.find("A", a + 1);
		}
		q = s.find("Q", q + 1);
	}
	cout << ans;
}

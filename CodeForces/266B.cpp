#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int t;cin >> t;
	string s;cin >> s;
	for(int i = 0;i < t;i++){
		for(int j = 1;j < n;j++){
			if(s[j] == 'G' && s[j - 1] == 'B'){
				s[j] = 'B';
				s[j - 1] = 'G';
				j++;
			}
		}
	}
	cout << s;
}

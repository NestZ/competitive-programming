#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	vector<char> arr;
	int lst = 0;
	bool f = false;
	for(int i = 0;i < n;i++){
		if(s[i] == '.'){
			int lst = i;
			if(s[i - 1] == '9')return cout << "GOTO Vasilisa.", 0;
			else if(s[i + 1] >= '5')f = true;
			break;
		}
		else arr.push_back(s[i]);
	}
	if(f)arr[arr.size() - 1] += 1;
	for(char c : arr)cout << c;
}

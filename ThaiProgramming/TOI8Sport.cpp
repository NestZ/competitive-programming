#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int k;
vector<char> res;
void fuck(int a, int b){
	if(a == k || b == k){
		for(char c : res)
			cout << c << ' ';
		cout << endl;
		return;
	}
	res.push_back('W');
	fuck(a + 1, b);
	res.pop_back();
	res.push_back('L');
	fuck(a, b + 1);
	res.pop_back();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;cin >> k >> a >> b;
	fuck(a, b);
}

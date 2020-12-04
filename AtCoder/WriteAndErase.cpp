#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	set<int> s;
	for(int i = 0;i < n;i++){
		int num;cin >> num;
		if(s.count(num))s.erase(num);
		else s.insert(num);
	}
	cout << s.size() << endl;
}

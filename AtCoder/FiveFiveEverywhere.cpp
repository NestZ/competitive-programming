#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int N = 5555500;
	vector<int> lp(N + 1);
	vector<bool> pr(N + 1, false);
	vector<int> lim_p;
	vector<int> prime;
	for(int i = 2;i <= N;i++){
		if(lp[i] == 0){
			lp[i] = i;
			pr[i] = true;
			prime.push_back(i);
			if(i <= 55555)lim_p.push_back(i);
		}
		for(int j = 0;j <(int)prime.size() && prime[j] <= lp[i] && i * prime[j] <= N;j++)
			lp[i * prime[j]] = prime[j];
	}
	int n;cin >> n;
	for(int i : prime){
		if(i % 5 == 1){
			cout << i << ' ';
			n--;
			if(n == 0)break;
		}
	}
	cout << endl;
}

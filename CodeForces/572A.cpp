#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int na, nb;cin >> na >> nb;
	int k, m;cin >> k >> m;
	vector<int> arra(na);
	vector<int> arrb(nb);
	for(int i = 0;i < na;i++)cin >> arra[i];
	for(int i = 0;i < nb;i++)cin >> arrb[i];
	if(arra[k - 1] < arrb[nb - m])cout << "YES";
	else cout << "NO";
}

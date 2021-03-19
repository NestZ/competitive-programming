#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, d, e, f;cin >> a >> b >> c >> d >> e >> f;
	int sugar = 0;
	int water = a * 100;
	for(int A = 0;A <= 100;A++){
		for(int B = 0;B <= 100;B++){
			if(a * 100 * A + 100 * b * B > f)continue;
			int mx_sugar = (a * 100 * A + b * 100 * B) / 100 * e;
			for(int C = 0;C <= 100;C++){
				for(int D = 0;D <= 100;D++){
					int cur_sugar = c * C + d * D;
					int cur_water = a * 100 * A + b * 100 * B;
					int cur_sub = cur_sugar + cur_water;
					if(cur_sugar > mx_sugar)continue;
					if(cur_sub > f)continue;
					if(cur_sugar == 0)continue;
					if(cur_sub * sugar < cur_sugar * water){
						sugar = cur_sugar;
						water = cur_sub;
					}
				}
			}
		}
	}
	cout << water << ' ' << sugar << endl;
}

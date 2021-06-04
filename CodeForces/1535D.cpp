#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

vector<char> arr(2000010);
vector<int> sum(2000010);
ll team;

void update(int k){
  if(k == 0)return;
  if(arr[team - k] == '0')sum[k] = sum[2 * k + 1];
  else if(arr[team - k] == '1')sum[k] = sum[2 * k];
  else sum[k] = sum[2 * k] + sum[2 * k + 1];
  update(k / 2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll k, q;cin >> k;
  team = (1 << k);
  for(ll i = 1;i <= (1 << k) - 1;i++){
    cin >> arr[i];
  }
  for(ll i = team;i < 2 * team;i++)sum[i] = 1;
  for(ll i = team - 1;i >= 1;i--)update(i); 
  cin >> q;
  for(ll i = 0;i < q;i++){
    int p;cin >> p;
    char c;cin >> c;
    arr[p] = c;
    update(team - p);
    cout << sum[1] << endl;
  }
}

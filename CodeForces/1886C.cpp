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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--) {
    string s;cin >> s;
    ll pos;cin >> pos;

    ll n = s.length();
    ll N = n * (n + 1ll) / 2ll;

    ll fnd = N - pos + 1;
    ll ind = 1;

    for (ll i = 1;i <= n;i++) {
      if (fnd <= i * (i + 1ll) / 2ll) {
        ind = i;
        break;
      }
    }

    //cab ab a -> 6
    //fnd: 1, ind: 1, removed: 2, residue: 1

    //abcd abc ab a -> 9
    //fnd: 2, ind: 2, removed: 2, residue: 2

    //x -> 1
    //fnd: 1, ind: 1, removed: 0, residue: 1

    ll removed = n - ind;
    ll residue = ind * (ind + 1ll) / 2ll - fnd + 1;

    stack<char> st;
    for (ll i = 0;i < n;i++) {
      if (st.empty()) {
        st.push(s[i]);
      } else {
        while (!st.empty() && st.top() > s[i] && removed > 0) {
          st.pop();
          removed--;
        }
        st.push(s[i]);
      }
    }

    while (removed > 0) {
      st.pop();
      removed--;
    }

    vector<char> arr;
    while (!st.empty()) {
      arr.push_back(st.top());
      st.pop();
    }

    reverse(arr.begin(), arr.end());

    cout << arr[residue - 1];
  }
  cout << endl;
}

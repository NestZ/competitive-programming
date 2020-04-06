__gcd(int, int);
lcm = a * b / __gcd(a, b);

int gcd(int a, int b){
	return b ? gcd(a % b) : a;
}

#String constructor
string s (5, '1'); // "11111"

#Bitset constructor
bitset<10> b(s); // "00000sssss"

bool isPrime(int n){
   if(n <= 1)return false;
   if(n <= 3)return true;
   if(n % 2 == 0 || n % 3 == 0)return false;
   for(int i = 5;i * i <= n;i += 6){
		 if(n % i == 0 || n % (i + 2) == 0)return false;
   }
   return true;
}

int countSubString(string s, string temp){
   int ans = 0;
   size_t f = s.find(temp);
   while(f != string::npos){
		 ans++;
		 f = s.find(temp, f + 1);
   }
   return ans;
}

#Count leading & trailing zero of an integer bits
__builtin_clz(n);
__builtin_clzll(n);

#Count 1s bits of an integer
__builtin_popcount(n);
__builtin_popcountll(n);

#Error checking
assert(n == 3);

#Error Printing
cerr << "Some thing";

#binary exponentiation
long long binpow(long long a, long long b) {
 long long res = 1;
 while (b > 0) {
	 if (b & 1)
		 res = res * a;
	 a = a * a;
	 b >>= 1;
 }
 return res;
}

#prime factorization
vector<int> fac(int n){
	vector<int> ans;
	for(int i = 2;i * i <= n;i++){
		if(n % i == 0){
			ans.push_back(i);
			while(n % i == 0)n /= i;
		}
	}
	if(n > 1)ans.push_back(n);
	return ans;
}

#sieve of eratosthenes
vector<bool> sieve(int N){
	vector<bool> ans(N + 1, true);
	ans[0] = ans[1] = false;
	for(int i = 2;i * i <= N;i++){
		if(ans[i]){
			for(int j = i * i;j <= N;j += i)ans[j] = false;
		}
	}
	return ans;
}

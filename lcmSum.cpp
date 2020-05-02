#include <numeric>
#include<algorithm>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define MAX 1000000

typedef long long ll;

void eulerPhiFunction(ll *sieve, ll *partialRes) {
	for (int i = 2; i <= MAX; i++) {
		if (sieve[i] == i) {
			sieve[i] = i - 1;
			for (int j = 2 * i; j <= MAX; j += i) {
				sieve[j] = (sieve[j] * (i - 1)) / i;
			}
		}
	}
	for (int i = 1; i <= MAX; i++) {
		for (int j = i; j <= MAX; j += i) {
			partialRes[j] += sieve[i] * i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll *sieve = new ll[MAX + 1];
	rep(i, MAX + 1)
		sieve[i] = i;
	ll *partialRes = new ll[MAX + 1]();	
	eulerPhiFunction(sieve, partialRes);
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll sum = partialRes[n] + 1;
		sum = (sum * n) / 2;
		cout << sum << endl;
	}
	delete [] sieve;
	delete [] partialRes;
	return 0;
}



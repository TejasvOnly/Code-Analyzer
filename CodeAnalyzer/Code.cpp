#include<bits/stdc++.h>
using namespace std;

bool check(int n, int k) {
	if (k == 1)
		return true;
	double r = log((double) n) / log((double) k);
	if (r > 1 && ( floor(r) - r ) == 0)
		return true;
	return false;
}
int main() {
	int t;
	cin>>t;
	long long int n, k;
	while (t) {
		cin >> n >> k;
		if (check(n, k))
			cout << "NO";
		else
			cout << "YES";
		cout << endl;
		t--;
	}
	return 0;
}

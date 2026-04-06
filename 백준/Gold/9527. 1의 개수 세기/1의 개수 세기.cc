#include <iostream>

#define MAX 55

using namespace std;

long long power2[MAX];
long long A, B;

long long getOne(long long x) {
	long long ret = x & 1;

	for (int i = MAX - 1; i > 0; i--) 
		if (x & (1LL << i)) {
			ret += power2[i - 1] + (x - (1LL << i) + 1);
			x -= 1LL << i;
		}

	return ret;
}

int main() {
	cin >> A >> B;

	power2[0] = 1;
	for (int i = 1; i < MAX; i++) 
		power2[i] = 2 * power2[i - 1] + (1LL << i);

	cout << getOne(B) - getOne(A - 1);
}
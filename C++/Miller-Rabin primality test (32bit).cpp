#include <iostream>
#include <stdint.h>

bool isPrime(const uint32_t n);
inline uint32_t powmod(uint64_t a, uint32_t b, const uint32_t m);

int main(void) {
	uint32_t n;
	std::cin >> n;
	std::cout << isPrime(n);
	return 0;
}

bool isPrime(const uint32_t n) {
	// Limits the value of n to odd numbers more than 3
	if (n <= 1) return false;
	if (n == 2 || n == 3) return true;
	if (!(n & 1)) return false;

	// Write n as 2^r·d + 1 with d odd (by factoring out powers of 2 from n − 1)
	uint32_t r = 0, d = n - 1;
	while (!(d & 1)) {
		++r;
		d >>= 1;
	}

	const uint32_t aList[] = { 2, 7, 61 };
	for (const uint32_t a : aList) {
		// pick a integer a in the range [2, n − 2]
		if (a < 2 || n - 2 < a) break;

		uint32_t x = powmod(a, d, n);
		if (x == 1 || x == n - 1) continue;

		uint32_t j;
		for (j = 1; j < r; ++j) {
			x = powmod(x, 2, n);
			if (x == n - 1) break;
		}
		if (j >= r) return false;
	}
	return true;
}

inline uint32_t powmod(uint64_t a, uint32_t b, const uint32_t m) {
	uint32_t ret = 1;
	a %= m;

	while (b) {
		if (b & 1) ret = (ret * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}

	return ret;
}
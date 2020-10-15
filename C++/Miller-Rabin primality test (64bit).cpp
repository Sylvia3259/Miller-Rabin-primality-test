#include <iostream>
#include <cstdint>

#ifdef __SIZEOF_INT128__
typedef unsigned __int128 uint128_t;
#endif

bool isPrime(const uint64_t n);
#ifdef __SIZEOF_INT128__
inline uint64_t powmod(uint128_t a, uint64_t b, const uint64_t m);
#else
inline uint64_t powmod(uint64_t a, uint64_t b, const uint64_t m);
inline uint64_t mulmod(uint64_t a, uint64_t b, const uint64_t m);
#endif

int main() {
	uint64_t n;
	std::cin >> n;
	std::cout << isPrime(n);
	return 0;
}

bool isPrime(const uint64_t n) {
	// Limits the value of n to odd numbers more than 3
	if (n <= 1) return false;
	if (n == 2 || n == 3) return true;
	if (!(n & 1)) return false;

	// Write n as 2^r·d + 1 with d odd (by factoring out powers of 2 from n − 1)
	uint64_t r = 0, d = n - 1;
	while (!(d & 1)) {
		++r;
		d >>= 1;
	}

	const uint64_t aList[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
	for (const uint64_t a : aList) {
		// pick a integer a in the range [2, n − 2]
		if (a < 2 || n - 2 < a) break;

		uint64_t x = powmod(a, d, n);
		if (x == 1 || x == n - 1) continue;

		uint64_t j;
		for (j = 1; j < r; ++j) {
			x = powmod(x, 2, n);
			if (x == n - 1) break;
		}
		if (j >= r) return false;
	}
	return true;
}

#ifdef __SIZEOF_INT128__
inline uint64_t powmod(uint128_t a, uint64_t b, const uint64_t m) {
	uint64_t ret = 1;
	a %= m;

	while (b) {
		if (b & 1) ret = (ret * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}

	return ret;
}
#else
inline uint64_t powmod(uint64_t a, uint64_t b, const uint64_t m) {
	uint64_t ret = 1;
	a %= m;

	while (b) {
		if (b & 1) ret = mulmod(ret, a, m);
		a = mulmod(a, a, m);
		b >>= 1;
	}

	return ret;
}
#endif

#ifndef __SIZEOF_INT128__
inline uint64_t mulmod(uint64_t a, uint64_t b, const uint64_t m) {
	uint64_t ret = 0, tmp;
	b %= m;

	while (a) {
		if (a & 1) {
			if (b >= m - ret) ret -= m;
			ret += b;
		}
		a >>= 1;

		tmp = b;
		if (b >= m - b) tmp -= m;
		b += tmp;
	}

	return ret;
}
#endif
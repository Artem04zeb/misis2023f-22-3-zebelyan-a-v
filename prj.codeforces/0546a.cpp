#include <iostream>

int main() {
	int k, n, w;
	std::cin >> k >> n >> w;

	k = (k * w * (w + 1)) / 2;
	if (k - n <= 0) std::cout << 0;
	else std::cout << k - n;
	
	return 0;
}
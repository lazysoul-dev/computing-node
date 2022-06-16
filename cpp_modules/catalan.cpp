#include <iostream>

/**
 * Calculates nth catalan number.
 *
 * @param n Order number of catalan number.
 * @return Catalan number.
 */
double catalan(double n) {
  if (n <= 1) {
    return 1;
  }

  double res = 0;

  for (unsigned int i = 0; i < n; i++) {
    res += catalan(i) * catalan(n - i - 1);
  }

  return res;
}

int main() {
  double result = catalan(20);
  std::cout << "catalan(" << 20 << ") = " << result << std::endl;

  return 0;
}


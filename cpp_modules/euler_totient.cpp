#include <iostream>

/**
 * Calculates gcd.
 *
 * @param a A number.
 * @param b B number.
 * @return Gcd.
 */
int _gcd(int a, int b) {
  if (a == 0) {
    return b;
  }

  return _gcd(b % a, a);
}


/**
 * Calculates Euler totient.
 *
 * @param n Number.
 * @return Euler totient.
 */
double euler_totient(double n) {
  unsigned int result = 1;

  for (int i = 2; i < n; i++) {
    if (_gcd(i, n) == 1) {
      result++;
    }
  }

  return result;
}

int main() {
  double result = euler_totient(1000);
  std :: cout << "euler_totient(" << 1000 << ") = " << result << std:: endl;

  return 0;
}


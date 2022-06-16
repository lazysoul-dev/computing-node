#include <cmath>


/**
 * Calculates nth fibonnaci number.
 *
 * @param n Order number of fibonnaci number.
 * @return Fibonacci number.
 */
double fibonacci(double n) {
  if (n < 1) {
    return 1;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}


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


/**
 * Calculates binobial coefficent.
 *
 * @param n First number.
 * @param k Second number.
 * @return binobial coefficent.
 */
double binomial_coeff(double n, double k) {
  if (k > n) {
    return 0;
  }

  if (k == 0 || k == n) {
    return 1;
  }

  return binomial_coeff(n - 1, k - 1) + binomial_coeff(n - 1, k);
}


/**
 * Calculates nth Newman Conway sequence number.
 *
 * @param n Number.
 * @return Newman Conway sequence number.
 */
double newman_conway(double n) {
  if (n == 1 || n == 2) {
    return 1;
  }

  return newman_conway(newman_conway(n - 1))
    + newman_conway(n - newman_conway(n - 1));
}

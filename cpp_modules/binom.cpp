#include <iostream>

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

int main () {
  std::cout << "binomial_coef(100, 2) = " << binomial_coeff(100, 2) << std::endl;

  return 0;
}


#include <iostream>

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

int main () {
  double initial_number = 10;
  double result = fibonacci(initial_number);

  std::cout << initial_number << " Fibonacci number = " << result << std::endl;

  return 0;
}


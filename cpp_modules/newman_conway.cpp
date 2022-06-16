#include <iostream>

double newman_conway(double n) {
  if (n == 1 || n == 2) {
    return 1;
  }

  return newman_conway(newman_conway(n - 1))
    + newman_conway(n - newman_conway(n - 1));
}

int main() {
  std::cout << "newman_conway(20) = " << newman_conway(20) << std::endl;
  return 0;
}

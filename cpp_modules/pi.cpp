#include <cmath>
#include <iostream>


inline int __randall(unsigned int *p_seed) {
#ifdef _WIN32
  return rand();
#else
  return rand_r(p_seed);
#endif
}

double pi(double points) {
  double i = points;
  double inside = 0;
  unsigned int randseed = 1;

#ifdef _WIN32
  srand(randseed);
#endif

  unsigned int seed = __randall(&randseed);

#ifdef _WIN32
  srand(seed);
#endif

  while (i-- > 0) {
    double x = __randall(&seed) / static_cast<double>(RAND_MAX);
    double y = __randall(&seed) / static_cast<double>(RAND_MAX);

    if ((x * x) + (y * y) <= 1)
      inside++;
  }

  return (inside / points) * 4;
}

int main() {
  std::cout << "pi(1000) =" << pi(1000) << std::endl;

  return 0;
}

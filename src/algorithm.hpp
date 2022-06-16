#ifndef COMPUTING_NODE_ALGORITHM
#define COMPUTING_NODE_ALGORITHM


/**
 * Calculates nth fibonnaci number.
 *
 * @param n Order number of fibonnaci number.
 * @return Fibonacci number.
 */
double fibonacci(double n);


/**
 * Calculates nth catalan number.
 *
 * @param n Order number of catalan number.
 * @return Catalan number.
 */
double catalan(double n);


/**
 * Calculates Euler totient.
 *
 * @param n Number.
 * @return Euler totient.
 */
double euler_totient(double n);


/**
 * Calculates binobial coefficent.
 *
 * @param n First number.
 * @param k Second number.
 * @return binobial coefficent.
 */
double binomial_coeff(double n, double k);


/**
 * Calculates nth Newman Conway sequence number.
 *
 * @param n Number.
 * @return Newman Conway sequence number.
 */
double newman_conway(double n);


#endif


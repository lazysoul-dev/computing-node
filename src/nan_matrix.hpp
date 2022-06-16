#include "nan.h"


#ifndef COMPUTING_NODE_NAN_MATRIX
#define COMPUTING_NODE_NAN_MATRIX


/**
 * Calculates sum of provided matrices. Matrices must be of same dimension.
 *
 * At args[0] and args[1] must be a matrix provided from JavaScript.
 *
 * As return value returns new matrix which is sum.
 *
 * Throw an error if at args[0] or args[1] (argument from JavaScript) not an
 * array, nothing, or args.size() != 2
 *
 * @param args Standart Nan function arguments list.
 */
void nan_matrix_sum(const Nan::FunctionCallbackInfo<v8::Value>& args);


#endif


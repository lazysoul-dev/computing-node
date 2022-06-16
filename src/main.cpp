#include "nan.h"
#include "nan_algorithm.hpp"
#include "nan_matrix.hpp"
#include "nan_sorting.hpp"


void init_basic(v8::Local<v8::Object> target) {
  Nan::Set(
    target,
    Nan::New("newmanConway").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_newman_conway)
    ).ToLocalChecked()
  );

  Nan::Set(
    target,
    Nan::New("bubbleSort").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_bubble_sort)
    ).ToLocalChecked()
  );

  Nan::Set(
    target,
    Nan::New("fibonacci").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_fibonacci)
    ).ToLocalChecked()
  );

  Nan::Set(
    target,
    Nan::New("catalan").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_catalan)
    ).ToLocalChecked()
  );

  Nan::Set(
    target,
    Nan::New("eulerTotient").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_euler_totient)
    ).ToLocalChecked()
  );

  Nan::Set(
    target,
    Nan::New("binomialCoeff").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_binomial_coeff)
    ).ToLocalChecked()
  );

  Nan::Set(
    target,
    Nan::New("estimatePiNumber").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_estimate_pi_number)
    ).ToLocalChecked()
  );

  Nan::Set(
    target,
    Nan::New("matrixSum").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_matrix_sum)
    ).ToLocalChecked()
  );
}


NODE_MODULE(basic, init_basic)


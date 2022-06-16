#include <vector>
#include "nan.h"


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
void nan_matrix_sum(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  if (args.Length() != 2) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Must be provided 2 arguments").ToLocalChecked()
    ));

    return;
  }

  if (!args[0] -> IsArray() || !args[1] -> IsArray()) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided arguments must be arrays").ToLocalChecked()
    ));

    return;
  }

  v8::Local<v8::Array> v8_provided_matrix_a =
    v8::Local<v8::Array>::Cast(args[0]);

  v8::Local<v8::Array> v8_provided_matrix_b =
    v8::Local<v8::Array>::Cast(args[1]);


  unsigned int matrix_a_height = v8_provided_matrix_a -> Length();
  unsigned int matrix_b_height = v8_provided_matrix_b -> Length();

  if (matrix_a_height == 0 || matrix_b_height == 0) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided matrices height must be non 0").ToLocalChecked()
    ));

    return;
  }

  if (matrix_a_height != matrix_b_height) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided matrices must be the same height").ToLocalChecked()
    ));

    return;
  }

  Nan::MaybeLocal<v8::Value> v8_maybe_first_subarray_a =
    Nan::Get(v8_provided_matrix_a, 0);

  Nan::MaybeLocal<v8::Value> v8_maybe_first_subarray_b =
    Nan::Get(v8_provided_matrix_b, 0);

  if (
    v8_maybe_first_subarray_a.IsEmpty() || v8_maybe_first_subarray_a.IsEmpty()
  ) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided matrices must be array of arrays").ToLocalChecked()
    ));

    return;
  }

  v8::Local<v8::Value> v8_first_value_a =
    v8_maybe_first_subarray_a.ToLocalChecked();

  v8::Local<v8::Value> v8_first_value_b =
    v8_maybe_first_subarray_b.ToLocalChecked();

  if (!v8_first_value_a -> IsArray() || !v8_first_value_b -> IsArray()) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided matrices must be array of arrays").ToLocalChecked()
    ));

    return;
  }

  v8::Local<v8::Array> v8_first_subarray_a = v8_first_value_a.As<v8::Array>();
  v8::Local<v8::Array> v8_first_subarray_b = v8_first_value_b.As<v8::Array>();

  unsigned int matrix_a_width = v8_first_subarray_a -> Length();
  unsigned int matrix_b_width = v8_first_subarray_b -> Length();

  if (matrix_a_width == 0 || matrix_b_width == 0) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided matrices must be array of arrays").ToLocalChecked()
    ));

    return;
  }

  if (matrix_a_width != matrix_b_width) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided matrices must be same width").ToLocalChecked()
    ));

    return;
  }

  v8::Local<v8::Array> v8_result_matrix = Nan::New<v8::Array>(matrix_a_height);

  for (unsigned int i = 0; i < matrix_a_height; i++) {
    Nan::MaybeLocal<v8::Value> v8_maybe_array_a_value =
      Nan::Get(v8_provided_matrix_a, i);

    Nan::MaybeLocal<v8::Value> v8_maybe_array_b_value =
      Nan::Get(v8_provided_matrix_b, i);

    if (v8_maybe_array_a_value.IsEmpty() || v8_maybe_array_b_value.IsEmpty()) {
      isolate -> ThrowException(v8::Exception::TypeError(
        Nan::New("Provided matrices must be array of arrays").ToLocalChecked()
      ));

      return;
    }

    v8::Local<v8::Value> v8_array_a_value =
      v8_maybe_array_a_value.ToLocalChecked();

    v8::Local<v8::Value> v8_array_b_value =
      v8_maybe_array_b_value.ToLocalChecked();

    if (!v8_array_a_value -> IsArray() || !v8_array_b_value -> IsArray()) {
      isolate -> ThrowException(v8::Exception::TypeError(
        Nan::New("Provided matrices must be array of arrays").ToLocalChecked()
      ));

      return;
    }

    v8::Local<v8::Array> v8_a_subarray = v8_array_a_value.As<v8::Array>();
    v8::Local<v8::Array> v8_b_subarray = v8_array_b_value.As<v8::Array>();

    unsigned int v8_a_subarray_width = v8_a_subarray -> Length();
    unsigned int v8_b_subarray_width = v8_b_subarray -> Length();

    if (
      v8_a_subarray_width != matrix_a_width
      || v8_b_subarray_width != matrix_b_width
    ) {
      isolate -> ThrowException(v8::Exception::TypeError(
        Nan::New("Provided matrix subarray must be same width").ToLocalChecked()
      ));

      return;
    }

    v8::Local<v8::Array> v8_result_subarray =
      Nan::New<v8::Array>(matrix_a_width);

    for (unsigned int j = 0; j < matrix_a_width; j++) {
      Nan::MaybeLocal<v8::Value> v8_maybe_a_subarray_value =
        Nan::Get(v8_a_subarray, j);

      Nan::MaybeLocal<v8::Value> v8_maybe_b_subarray_value =
        Nan::Get(v8_b_subarray, j);

      if (
        v8_maybe_a_subarray_value.IsEmpty()
        || v8_maybe_b_subarray_value.IsEmpty()
      ) {
        isolate -> ThrowException(v8::Exception::TypeError(
          Nan::New("Provided matrix subarrays found empty value")
            .ToLocalChecked()
        ));

        return;
      }

      v8::Local<v8::Value> v8_a_subarray_value =
        v8_maybe_a_subarray_value.ToLocalChecked();

      v8::Local<v8::Value> v8_b_subarray_value =
        v8_maybe_b_subarray_value.ToLocalChecked();

      if (
        !v8_a_subarray_value -> IsNumber() || !v8_b_subarray_value -> IsNumber()
      ) {
        isolate -> ThrowException(v8::Exception::TypeError(
          Nan::New("Provided matrix subarrays must contain only numbers")
            .ToLocalChecked()
        ));

        return;
      }

      double a_subarray_value = Nan::To<double>(v8_a_subarray_value).FromJust();
      double b_subarray_value = Nan::To<double>(v8_b_subarray_value).FromJust();

      Nan::Set(
        v8_result_subarray,
        j,
        Nan::New(a_subarray_value + b_subarray_value)
      );
    }

    Nan::Set(v8_result_matrix, i, v8_result_subarray);
  }

  args.GetReturnValue().Set(v8_result_matrix);
}


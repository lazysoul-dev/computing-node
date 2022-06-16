#include <nan.h>


/**
 * Bubble sort algorithm implementation.
 *
 * @param args Standart Nan function arguments list.
 */
void nan_bubble_sort(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  if (args.Length() != 1) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Must be provided 1 argument").ToLocalChecked()
    ));

    return;
  }

  if (!args[0] -> IsArray()) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided argument must be an array").ToLocalChecked()
    ));

    return;
  }

  v8::Local<v8::Array> v8_vector = v8::Local<v8::Array>::Cast(args[0]);
  unsigned int size = v8_vector -> Length();

  double* vector = new double[size];

  for (unsigned int i = 0; i < size; i++) {
    vector[i] = Nan::To<double>(Nan::Get(v8_vector, i).ToLocalChecked()).FromJust();
  }

  for (unsigned int i = 0; i < size - 1; i ++) {
    bool swapped = false;

    for (unsigned int j = 0; j < size - i - 1; j++) {
      if (vector[j] > vector[j + 1]) {
        double temp = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = temp;
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }

  for (unsigned int i = 0; i < size; i++) {
    Nan::Set(v8_vector, i, Nan::New(vector[i]));
  }

  args.GetReturnValue().Set(v8_vector);
}
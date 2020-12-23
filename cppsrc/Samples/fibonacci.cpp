#include "fibonacci.h"

int fibonacci::get(int n ){
    if (n <= 1)
          return n;
   return get(n-1) + get(n-2);
}


Napi::Number fibonacci::GetWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    } 

    Napi::Number first = info[0].As<Napi::Number>();

    int returnValue = fibonacci::get(first.Int32Value());
    
    return Napi::Number::New(env, returnValue);
}

Napi::Object fibonacci::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("get", Napi::Function::New(env, fibonacci::GetWrapped));
    return exports;
}

#include <napi.h>

namespace fibonacci {
    int get(int n);
    Napi::Number GetWrapped(const Napi::CallbackInfo& info);

    Napi::Object Init(Napi::Env env, Napi::Object exports);
    
}

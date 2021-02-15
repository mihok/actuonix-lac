#include <string>
#include "napi.h"
#include "greeting.h"

// Native C++ function assigned to `greetHello` property on the `exports` object
Napi::String greetHello ( const Napi::CallbackInfo& info ) {
    Napi::Env env = info.Env();

    // Call `helloUser` function from `greeting.cpp` file
    // WARNING: We are passing hardcoded value `MIHO` for now
    std::string result = helloUser( "MIHO" );

    // return new `Napi::String` value
    return Napi::String::New(env, result);
}

// Callback method when module is registered with Node.js
Napi::Object Init(Napi::Env env, Napi::Object exports) {
    // Set a key on `exports` object
    exports.Set(
        Napi::String::New(env, "greetHello"), // Property name `greetHello`
        Napi::Function::New(env, greetHello)  // Property value for `greetHello`
    );

    // Return the `exports` object always.
    return exports;
}

NODE_API_MODULE(greet, Init)
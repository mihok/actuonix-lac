#include "napi.h"
// #include "mpusbapi.h"

class LACBoard : public Napi::ObjectWrap<LACBoard> {
    public:
        static Napi::Object Init (Napi::Env env, Napi::Object exports);
        LACBoard (const Napi::CallbackInfo &info);
        Napi::Value Open (const Napi::CallbackInfo& info);
        void Close (const Napi::CallbackInfo& info);
        // Read
        // Write
    private: 
        // HANDLE InHandle     = INVALID_HANDLE_VALUE;
        // HANDLE OutHandle    = INVALID_HANDLE_VALUE;

};

Napi::Object LACBoard::Init (Napi::Env env, Napi::Object exports) {

    Napi::Function func = DefineClass(env, "LACBoard", {
        InstanceMethod("open", &LACBoard::Open),
        InstanceMethod("close", &LACBoard::Close),
    });

    Napi::FunctionReference* constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(func);
    constructor->SuppressDestruct();

    exports.Set("LACBoard", func);

    return exports;
}

LACBoard::LACBoard (const Napi::CallbackInfo &info) : Napi::ObjectWrap<LACBoard>(info) {
    Napi::Env env = info.Env();
}

Napi::Value LACBoard::Open (const Napi::CallbackInfo &info) {
    Napi::Promise::Deferred deferred = Napi::Promise::Deferred::New(info.Env());

    // if(MPUSBGetDeviceCount(LAC_VID_PID)) {
    //     this->InHandle  = MPUSBOpen(0, LAC_VID_PID, "\\MCHP_EP1", MP_WRITE, 0);
    //     this->OutHandle = MPUSBOpen(0, LAC_VID_PID, "\\MCHP_EP1", MP_READ, 0);
    // 
    deferred.Resolve(Napi::String::New(info.Env(), "OK"));
    // } else {
    //     deferred.Reject(Napi::String::New(info.Env(), "FAIL"));
    // }

    return deferred.Promise();
}

void LACBoard::Close (const Napi::CallbackInfo &info) {
    // if (this->InHandle != INVALID_HANDLE_VALUE && MPUSBClose(this->InHandle)) {
    //     this->InHandle = INVALID_HANDLE_VALUE;
    // }

    // if (this->OutHandle != INVALID_HANDLE_VALUE && MPUSBClose(this->OutHandle)) {}
    //     this->OutHandle = INVALID_HANDLE_VALUE;
    // }
}

Napi::Object Init (Napi::Env env, Napi::Object exports) {
    LACBoard::Init(env, exports);

    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
#include <napi.h>

typedef struct TSLanguage TSLanguage;

extern "C" TSLanguage * tree_sitter_vb_dotnet();

// "tree-sitter", "language" hashed with BLAKE2
const napi_type_tag LANGUAGE_TYPE_TAG = {
    0x8AF2E5212AD58ABF, 0xD5006CAD83ABBA16
};

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    auto language = Napi::External<TSLanguage>::New(env, tree_sitter_vb_dotnet());
    language.TypeTag(&LANGUAGE_TYPE_TAG);
    exports["language"] = language;
    exports["name"] = Napi::String::New(env, "vb_dotnet");
    return exports;
}

NODE_API_MODULE(tree_sitter_vb_dotnet_binding, Init)

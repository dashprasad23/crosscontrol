#include <node_api.h>
#include "mouse.h"
#include <vector>
#include <string>

napi_value MoveMouse(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int32_t x, y;
    napi_get_value_int32(env, args[0], &x);
    napi_get_value_int32(env, args[1], &y);

    moveMouse(x, y);

    napi_value result;
    napi_get_undefined(env, &result);
    return result;
}


napi_value ClickMouse(napi_env env, napi_callback_info info) {
    clickMouse();

    napi_value result;
    napi_get_undefined(env, &result);
    return result;
}

napi_value GetMousePosition(napi_env env, napi_callback_info info) {
    int x, y;
    getMousePosition(x, y);

    napi_value result;
    napi_create_object(env, &result);

    napi_value nx, ny;
    napi_create_int32(env, x, &nx);
    napi_create_int32(env, y, &ny);

    napi_set_named_property(env, result, "x", nx);
    napi_set_named_property(env, result, "y", ny);

    return result;
}

// typeKey(key)
napi_value TypeKey(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    size_t str_size;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &str_size);
    char* buffer = new char[str_size + 1];
    napi_get_value_string_utf8(env, args[0], buffer, str_size + 1, &str_size);

    typeKey(buffer);  // <-- calls your native function
    delete[] buffer;

    napi_value result;
    napi_get_undefined(env, &result);
    return result;
}


napi_value TypeKeyWithState(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    size_t str_size;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &str_size);
    char* buffer = new char[str_size + 1];
    napi_get_value_string_utf8(env, args[0], buffer, str_size + 1, &str_size);

    bool isKeyDown;
    napi_get_value_bool(env, args[1], &isKeyDown);

    typeKey(buffer, isKeyDown);
    delete[] buffer;

    napi_value result;
    napi_get_undefined(env, &result);
    return result;
}

napi_value GetPixelColor(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int32_t x, y;
    napi_get_value_int32(env, args[0], &x);
    napi_get_value_int32(env, args[1], &y);

    int r, g, b;
    getPixelColor(x, y, r, g, b);

    napi_value result;
    napi_create_object(env, &result);
    napi_value nr, ng, nb;
    napi_create_int32(env, r, &nr);
    napi_create_int32(env, g, &ng);
    napi_create_int32(env, b, &nb);
    napi_set_named_property(env, result, "r", nr);
    napi_set_named_property(env, result, "g", ng);
    napi_set_named_property(env, result, "b", nb);

    return result;
}

napi_value RightClickMouse(napi_env env, napi_callback_info info) {
    rightClickMouse();
    napi_value result;
    napi_get_undefined(env, &result);
    return result;
}

napi_value MiddleClickMouse(napi_env env, napi_callback_info info) {
    middleClickMouse();
    napi_value result;
    napi_get_undefined(env, &result);
    return result;
}

napi_value TypeCombo(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    uint32_t length;
    napi_get_array_length(env, args[0], &length);

    std::vector<std::string> keyStrings;
    std::vector<const char*> keyPtrs;

    for (uint32_t i = 0; i < length; ++i) {
        napi_value elem;
        napi_get_element(env, args[0], i, &elem);

        size_t str_size;
        napi_get_value_string_utf8(env, elem, nullptr, 0, &str_size);
        std::string key(str_size, '\0');
        napi_get_value_string_utf8(env, elem, key.data(), str_size + 1, &str_size);
        keyStrings.push_back(std::move(key));
    }

    for (const auto& s : keyStrings) {
        keyPtrs.push_back(s.c_str());
    }

    typeCombo(keyPtrs.data(), static_cast<int>(keyPtrs.size()));

    napi_value result;
    napi_get_undefined(env, &result);
    return result;
}


napi_value Init(napi_env env, napi_value exports) {
    napi_value fn1, fn2, fn3, fn4, fn5, fn6, fn7, fn8, fn9;

    napi_create_function(env, nullptr, 0, MoveMouse, nullptr, &fn1);
    napi_create_function(env, nullptr, 0, ClickMouse, nullptr, &fn2);
    napi_create_function(env, nullptr, 0, GetMousePosition, nullptr, &fn3);
    napi_create_function(env, nullptr, 0, TypeKey, nullptr, &fn4);
    napi_create_function(env, nullptr, 0, TypeKeyWithState, nullptr, &fn5);
    napi_create_function(env, nullptr, 0, GetPixelColor, nullptr, &fn6);
    napi_create_function(env, nullptr, 0, RightClickMouse, nullptr, &fn7);
    napi_create_function(env, nullptr, 0, MiddleClickMouse, nullptr, &fn8);
    napi_create_function(env, nullptr, 0, TypeCombo, nullptr, &fn9);

    napi_set_named_property(env, exports, "moveMouse", fn1);
    napi_set_named_property(env, exports, "clickMouse", fn2);
    napi_set_named_property(env, exports, "getMousePosition", fn3);
    napi_set_named_property(env, exports, "typeKey", fn4);
    napi_set_named_property(env, exports, "typeKeyWithState", fn5);
    napi_set_named_property(env, exports, "getPixelColor", fn6);
    napi_set_named_property(env, exports, "rightClickMouse", fn7);
    napi_set_named_property(env, exports, "middleClickMouse", fn8);
    napi_set_named_property(env, exports, "typeCombo", fn9);

    return exports;
}


NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)

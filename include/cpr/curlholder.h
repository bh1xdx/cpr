#ifndef CPR_CURL_HOLDER_H
#define CPR_CURL_HOLDER_H

#include <memory>

#include <curl/curl.h>

#include "cpr/ns.h"

CPR_NS_BEGIN

struct CurlHolder {
    CurlHolder() {
        handle = nullptr;
        chunk = nullptr;
        formpost = nullptr;
    };

    CURL* handle;
    struct curl_slist* chunk;
    struct curl_httppost* formpost;
    char error[CURL_ERROR_SIZE];
};

CPR_NS_END

#endif

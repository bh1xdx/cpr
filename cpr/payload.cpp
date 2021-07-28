#include "cpr/payload.h"

#include <initializer_list>
#include <string>

#include "cpr/util.h"

CPR_NS_BEGIN

Payload::Payload(const std::initializer_list<Pair>& pairs) : Payload(begin(pairs), end(pairs)) {}

void Payload::AddPair(const Pair& pair) {
    if (!content.empty()) {
        content += "&";
    }
    auto escaped = util::urlEncode(pair.value);
    content += pair.key + "=" + escaped;
}

CPR_NS_END
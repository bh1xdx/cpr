#include "cpr/parameters.h"

#include <initializer_list>
#include <string>

#include "cpr/util.h"

CPR_NS_BEGIN

Parameters::Parameters(const std::initializer_list<Parameter>& parameters) {
    for (const auto& parameter : parameters) {
        AddParameter(parameter);
    }
}

void Parameters::AddParameter(const Parameter& parameter) {
    if (!content.empty()) {
        content += "&";
    }

    auto escapedKey = util::urlEncode(parameter.key);
    if (parameter.value.empty()) {
        content += escapedKey;
    } else {
        auto escapedValue = util::urlEncode(parameter.value);
        content += escapedKey + "=" + escapedValue;
    }
}

CPR_NS_END
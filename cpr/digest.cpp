#include "cpr/digest.h"

CPR_NS_BEGIN

const char* Digest::GetAuthString() const noexcept {
    return Authentication::GetAuthString();
}

CPR_NS_END
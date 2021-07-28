
#include "cpr/auth.h"

CPR_NS_BEGIN

const char* Authentication::GetAuthString() const noexcept {
    return auth_string_.data();
}

CPR_NS_END

#include "cpr/ssl_options.h"

CPR_NS_BEGIN

VerifySsl::VerifySsl(bool verify) : verify_{verify} {}

VerifySsl::operator bool() const {
    return verify_;
}

CPR_NS_END

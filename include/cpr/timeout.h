#ifndef CPR_TIMEOUT_H
#define CPR_TIMEOUT_H

#include <chrono>
#include <cstdint>

#include "cpr/ns.h"

CPR_NS_BEGIN

class Timeout {
  public:
    Timeout(const std::chrono::milliseconds& duration) : ms{duration} {}
    Timeout(const std::int32_t& milliseconds) : Timeout{std::chrono::milliseconds(milliseconds)} {}

    long Milliseconds() const;

    std::chrono::milliseconds ms;
};

CPR_NS_END

#endif

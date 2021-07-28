#ifndef CPR_MAX_REDIRECTS_H
#define CPR_MAX_REDIRECTS_H


#include <cstdint>

#include "cpr/ns.h"

CPR_NS_BEGIN

class MaxRedirects {
  public:
    explicit MaxRedirects(const std::int32_t number_of_redirects)
            : number_of_redirects(number_of_redirects) {}

    std::int32_t number_of_redirects;
};

CPR_NS_END

#endif

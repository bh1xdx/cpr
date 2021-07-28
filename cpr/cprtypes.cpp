#include "cpr/cprtypes.h"

#include <algorithm>
#include <cctype>

CPR_NS_BEGIN

bool CaseInsensitiveCompare::operator()(const std::string& a, const std::string& b) const noexcept {
    return std::lexicographical_compare(
            a.begin(), a.end(), b.begin(), b.end(),
            [](unsigned char ac, unsigned char bc) { return std::tolower(ac) < std::tolower(bc); });
}

CPR_NS_END

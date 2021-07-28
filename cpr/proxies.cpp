#include "cpr/proxies.h"

#include <initializer_list>
#include <map>
#include <string>
#include <utility>

CPR_NS_BEGIN

Proxies::Proxies(const std::initializer_list<std::pair<const std::string, std::string>>& hosts)
        : hosts_{hosts} {}

bool Proxies::has(const std::string& protocol) const {
    return hosts_.count(protocol) > 0;
}

const std::string& Proxies::operator[](const std::string& protocol) {
    return hosts_[protocol];
}

CPR_NS_END
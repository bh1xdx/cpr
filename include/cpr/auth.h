#ifndef CPR_AUTH_H
#define CPR_AUTH_H

#include <string>

#include "cpr/ns.h"
#include "cpr/defines.h"

CPR_NS_BEGIN

class Authentication {
  public:
    template <typename UserType, typename PassType>
    Authentication(UserType&& username, PassType&& password)
            : username_{CPR_FWD(username)}, password_{CPR_FWD(password)},
              auth_string_{username_ + ":" + password_} {}

    const char* GetAuthString() const noexcept;

  private:
    std::string username_;
    std::string password_;
    std::string auth_string_;
};

CPR_NS_END

#endif

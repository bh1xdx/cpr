#ifndef CPR_DIGEST_H
#define CPR_DIGEST_H

#include "cpr/ns.h"
#include "cpr/auth.h"
#include "cpr/defines.h"

CPR_NS_BEGIN

class Digest : public Authentication {
  public:
    template <typename UserType, typename PassType>
    Digest(UserType&& username, PassType&& password)
            : Authentication{CPR_FWD(username), CPR_FWD(password)} {}

    const char* GetAuthString() const noexcept;
};

CPR_NS_END

#endif

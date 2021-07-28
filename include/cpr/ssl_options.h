#ifndef CPR_SSLOPTIONS_H
#define CPR_SSLOPTIONS_H

#include "cpr/ns.h"

CPR_NS_BEGIN

class VerifySsl {
  public:
    VerifySsl() {}
    VerifySsl(bool verify);

    operator bool() const;

  private:
    bool verify_ = true;
};

CPR_NS_END

#endif

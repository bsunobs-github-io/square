#ifndef RESPARAM_H
#define RESPARAM_H

#include "NdbMF.h"

/* ============= NdbResParam ============== */
class NdbResParam : public NdbMF
{
protected:

public:
   NdbResParam()
      : NdbMF(2, "Resonance prameter data") {}
   ~NdbResParam() override {}

   ClassDefOverride(NdbResParam,1)
}; // NdbResParam

#endif

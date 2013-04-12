#pragma once

#include "GaudiKernel/IInterface.h"

/** @class IFastTrackSvc IFastTrackSvc.h FastTrackSvc/IFastTrackSvc.h
 * Base interface providing accelerated tracking algorithms.
 */
class IFastTrackSvc :
    public virtual IInterface {
  public:
    virtual ~IFastTrackSvc() {}

    virtual bool isPrime(int n) = 0;

    virtual void searchByPair(const std::vector<char> & tracks) = 0;

    DeclareInterfaceID(IFastTrackSvc, 1, 0);
};
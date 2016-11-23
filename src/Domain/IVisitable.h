
#ifndef GRIMWALL_IVISITABLE_H
#define GRIMWALL_IVISITABLE_H

#include "IVisitor.h"

class IVisitable {
public:
    virtual void accept(IVisitor &v) = 0;
};

#endif
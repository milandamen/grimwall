#ifndef ICALLBACK_H
#define ICALLBACK_H
 
class ICallback
{
public:
    virtual ~ICallback() {}
    virtual void execute() = 0;
    virtual void reset() = 0;
};

#endif
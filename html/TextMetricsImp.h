// Generated by esidl (r1745).
// This file is expected to be modified for the Web IDL interface
// implementation.  Permission to use, copy, modify and distribute
// this file in any software license is hereby granted.

#ifndef ORG_W3C_DOM_BOOTSTRAP_TEXTMETRICSIMP_H_INCLUDED
#define ORG_W3C_DOM_BOOTSTRAP_TEXTMETRICSIMP_H_INCLUDED

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <org/w3c/dom/html/TextMetrics.h>

namespace org
{
namespace w3c
{
namespace dom
{
namespace bootstrap
{
class TextMetricsImp : public ObjectMixin<TextMetricsImp>
{
public:
    // TextMetrics
    float getWidth();
    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv)
    {
        return html::TextMetrics::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData()
    {
        return html::TextMetrics::getMetaData();
    }
};

}
}
}
}

#endif  // ORG_W3C_DOM_BOOTSTRAP_TEXTMETRICSIMP_H_INCLUDED

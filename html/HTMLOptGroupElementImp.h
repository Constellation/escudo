// Generated by esidl (r1745).
// This file is expected to be modified for the Web IDL interface
// implementation.  Permission to use, copy, modify and distribute
// this file in any software license is hereby granted.

#ifndef ORG_W3C_DOM_BOOTSTRAP_HTMLOPTGROUPELEMENTIMP_H_INCLUDED
#define ORG_W3C_DOM_BOOTSTRAP_HTMLOPTGROUPELEMENTIMP_H_INCLUDED

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <org/w3c/dom/html/HTMLOptGroupElement.h>
#include "HTMLElementImp.h"

#include <org/w3c/dom/html/HTMLElement.h>

namespace org
{
namespace w3c
{
namespace dom
{
namespace bootstrap
{
class HTMLOptGroupElementImp : public ObjectMixin<HTMLOptGroupElementImp, HTMLElementImp>
{
public:
    // HTMLOptGroupElement
    bool getDisabled();
    void setDisabled(bool disabled);
    Nullable<std::u16string> getLabel();
    void setLabel(Nullable<std::u16string> label);
    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv)
    {
        return html::HTMLOptGroupElement::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData()
    {
        return html::HTMLOptGroupElement::getMetaData();
    }
    HTMLOptGroupElementImp(DocumentImp* ownerDocument) :
        ObjectMixin(ownerDocument, u"optgroup") {
    }
    HTMLOptGroupElementImp(HTMLOptGroupElementImp* org, bool deep) :
        ObjectMixin(org, deep) {
    }
};

}
}
}
}

#endif  // ORG_W3C_DOM_BOOTSTRAP_HTMLOPTGROUPELEMENTIMP_H_INCLUDED

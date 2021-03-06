/*
 * Copyright 2011-2013 Esrille Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "HTMLTableColElementImp.h"

#include "one_at_a_time.hpp"

constexpr auto Intern = &one_at_a_time::hash<char16_t>;

#include "utf.h"

#include "HTMLUtil.h"
#include "css/CSSTokenizer.h"

namespace org
{
namespace w3c
{
namespace dom
{
namespace bootstrap
{

void HTMLTableColElementImp::handleMutation(events::MutationEvent mutation)
{
    std::u16string value;
    css::CSSStyleDeclaration style(getStyle());

    switch (Intern(mutation.getAttrName().c_str())) {
    // Styles
    case Intern(u"width"):
        if (mapToDimension(value = mutation.getNewValue()))
            style.setProperty(u"width", value, u"non-css");
        break;
    default:
        HTMLElementImp::handleMutation(mutation);
        break;
    }
}

unsigned int HTMLTableColElementImp::getSpan()
{
    std::u16string value = getAttribute(u"span");
    if (value.empty())
        return 1;
    // TODO: Use the rules for parsing non-negative integers of HTML.
    stripLeadingAndTrailingWhitespace(value);
    unsigned int span = CSSTokenizer::parseInt(value.c_str(), value.length());
    if (span == 0)
        span = 1;
    return span;
}

void HTMLTableColElementImp::setSpan(unsigned int span)
{
    setAttribute(u"span", toString(span));
}

std::u16string HTMLTableColElementImp::getAlign()
{
    // TODO: implement me!
    return u"";
}

void HTMLTableColElementImp::setAlign(const std::u16string& align)
{
    // TODO: implement me!
}

std::u16string HTMLTableColElementImp::getCh()
{
    // TODO: implement me!
    return u"";
}

void HTMLTableColElementImp::setCh(const std::u16string& ch)
{
    // TODO: implement me!
}

std::u16string HTMLTableColElementImp::getChOff()
{
    // TODO: implement me!
    return u"";
}

void HTMLTableColElementImp::setChOff(const std::u16string& chOff)
{
    // TODO: implement me!
}

std::u16string HTMLTableColElementImp::getVAlign()
{
    // TODO: implement me!
    return u"";
}

void HTMLTableColElementImp::setVAlign(const std::u16string& vAlign)
{
    // TODO: implement me!
}

std::u16string HTMLTableColElementImp::getWidth()
{
    // TODO: implement me!
    return u"";
}

void HTMLTableColElementImp::setWidth(const std::u16string& width)
{
    // TODO: implement me!
}

}
}
}
}

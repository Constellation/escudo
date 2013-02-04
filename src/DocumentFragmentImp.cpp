/*
 * Copyright 2013 Esrille Inc.
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

#include "DocumentFragmentImp.h"

#include "NodeListImp.h"

namespace org
{
namespace w3c
{
namespace dom
{
namespace bootstrap
{

Element DocumentFragmentImp::querySelector(const std::u16string& selectors)
{
    // TODO: implement me!
    return static_cast<Object*>(0);
}

NodeList DocumentFragmentImp::querySelectorAll(const std::u16string& selectors)
{
    // TODO: implement me!
    return new(std::nothrow) NodeListImp;
}

}
}
}
}

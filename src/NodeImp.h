/*
 * Copyright 2010-2013 Esrille Inc.
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

#ifndef ORG_W3C_DOM_BOOTSTRAP_NODEIMP_H_INCLUDED
#define ORG_W3C_DOM_BOOTSTRAP_NODEIMP_H_INCLUDED

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <org/w3c/dom/Node.h>

#include <org/w3c/dom/events/Event.h>
#include <org/w3c/dom/events/EventListener.h>
#include <org/w3c/dom/DOMException.h>
#include <org/w3c/dom/Document.h>
#include <org/w3c/dom/Element.h>
#include <org/w3c/dom/NodeList.h>

#include "EventTargetImp.h"

#include <list>

namespace org { namespace w3c { namespace dom { namespace bootstrap {

class DocumentImp;

class NodeImp : public ObjectMixin<NodeImp, EventTargetImp>
{
    friend class NodeListImp;
    friend class ElementImp;
    friend class EventTargetImp;
    friend class HTMLElementImp;  // for focus

    DocumentImp* ownerDocument;
    NodeImp* parentNode;
    NodeImp* firstChild;
    NodeImp* lastChild;
    NodeImp* previousSibling;
    NodeImp* nextSibling;
    unsigned int childCount;

    NodeImp* removeChild(NodeImp* item);
    NodeImp* appendChild(NodeImp* item);
    NodeImp* insertBefore(NodeImp* item, NodeImp* after);

protected:
    std::u16string nodeName;

public:
    NodeImp(DocumentImp* ownerDocument);
    NodeImp(NodeImp* org, bool deep);
    ~NodeImp();

    // Returns true if this is an ancestor of the node
    bool isAncestorOf(NodeImp* node) {
        for (NodeImp* parent = node->parentNode; parent; parent = parent->parentNode) {
            if (this == parent)
                return true;
        }
        return false;
    }

    DocumentImp* getOwnerDocumentImp() const {
        return ownerDocument;
    }
    void setOwnerDocument(DocumentImp* document);

    unsigned int getChildCount() const {
        return childCount;
    }

    void setParentNode(NodeImp* node) {
        parentNode = node;
    }

    // Node
    virtual unsigned short getNodeType();
    virtual std::u16string getNodeName();
    virtual Nullable<std::u16string> getBaseURI();
    virtual Document getOwnerDocument();
    virtual Node getParentNode();
    virtual Element getParentElement();
    virtual bool hasChildNodes();
    virtual NodeList getChildNodes();
    virtual Node getFirstChild();
    virtual Node getLastChild();
    virtual Node getPreviousSibling();
    virtual Node getNextSibling();
    virtual Nullable<std::u16string> getNodeValue();
    virtual void setNodeValue(const Nullable<std::u16string>& nodeValue);
    virtual Nullable<std::u16string> getTextContent();
    virtual void setTextContent(const Nullable<std::u16string>& textContent);
    virtual Node insertBefore(Node node, Node child);
    virtual Node appendChild(Node node, bool clone = false);
    virtual Node replaceChild(Node node, Node child);
    virtual Node removeChild(Node child);
    virtual void normalize();
    virtual Node cloneNode(bool deep = true);
    virtual bool isSameNode(Node other);
    virtual bool isEqualNode(Node node);
    virtual unsigned short compareDocumentPosition(Node other);
    virtual bool contains(Node other);
    virtual Nullable<std::u16string> lookupPrefix(const Nullable<std::u16string>& _namespace);
    virtual Nullable<std::u16string> lookupNamespaceURI(const Nullable<std::u16string>& prefix);
    virtual bool isDefaultNamespace(const Nullable<std::u16string>& _namespace);

    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv) {
        return Node::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData() {
        return Node::getMetaData();
    }
};

}}}}  // org::w3c::dom::bootstrap

#endif  // ORG_W3C_DOM_BOOTSTRAP_NODEIMP_H_INCLUDED

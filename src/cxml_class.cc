#include "cxml_class.hpp"
namespace cxml
{
CXMLNode_attr::CXMLNode_attr()
{
    next = perv = nullptr;
    nums = 0;
}

CXMLNode::CXMLNode()
{
    name = content = "";
    parent = nullptr;
    perv = next = nullptr;
    attr = nullptr;
}

CXMLNode_text::CXMLNode_text()
{
    perv = next = nullptr;
    lens = 0;
}
std::string CXMLNode::get_name() const
{
    std::string ret = "";
    ret = this->name;
    return ret;
}
std::string CXMLNode::get_text() const
{
    std::string ret = "";
    CXMLNode_text *child = this->text;
    ret = child->content;
    return ret;
}
std::map<std::string, std::string> CXMLNode::get_attrs() const
{
    std::map<std::string, std::string> ret;
    CXMLNode_attr *child = this->attr;
    ret = child->attributes;
    return ret;
}
CXMLNode *CXMLNode::get_parent() const
{
    CXMLNode *ret;
    ret = this->parent;
    return ret;
}
CXMLNode *CXMLNode::get_child() const
{
    CXMLNode *ret;
    ret = this->children.back();
    return ret;
}
std::vector<CXMLNode *> CXMLNode::get_children() const
{
    std::vector<CXMLNode *> ret;
    ret = this->children;
    return ret;
}
CXMLNode_result::CXMLNode_result()
{
    element = nullptr;
}
}
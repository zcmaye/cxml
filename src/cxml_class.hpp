#ifndef __CXMLCLASS__H_
#define __CXMLCLASS__H_
#include <string>
#include <iostream>
#include <map>
#include <vector>

namespace cxml
{

class Node
{
public:
    std::string name; //节点名称
    Node *next;  //前节点指针
    Node *perv;  //后节点指针
//    std::string getName()
//    {
//        return name;
//    }
};
//每个节点的属性
class CXMLNode_attr : public Node
{
public:
    std::map<std::string, std::string> attributes;
    int nums;

public:
    CXMLNode_attr();
};
//节点

class CXMLNode_text : public Node
{
public:
    std::string content;  //文本数组
    int lens;        //多少组文本
    CXMLNode_text(); //构造函数
};
class CXMLNode : public Node
{
public:
    std::string content;              //节点注释
    CXMLNode *parent;            //节点的父节点指针
    std::vector<CXMLNode *> children; //节点的子节点指针
    CXMLNode_attr *attr;         //包含子节点的指针
    CXMLNode_text *text;         //文本节点
public:
    CXMLNode();
    //获取节点名字
    std::string get_name() const;
    //获取节点文字
    std::string get_text() const;
    //获取节点属性
    std::map<std::string, std::string> get_attrs() const;
    //获取父节点
    CXMLNode *get_parent() const;
    //获取一个子节点
    CXMLNode *get_child() const;
    //获取所有子节点
    std::vector<CXMLNode *> get_children() const;
    //获取子节点数量
//    int get_children_size() const;
};
//xpath解析结果
class CXMLNode_result
{
public:
    CXMLNode *element;           //一个节点
    std::vector<CXMLNode *> elements; //多个节点
    std::string text;                 //结果文本
    CXMLNode_result();
};
}
#endif
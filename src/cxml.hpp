#ifndef __CXML__H_
#define __CXML__H_

#define CXML_PARSER_SUCCESS 0
#define CXML_CONTENT_EMPTY -1
#define CXML_SYNTAX_ERROR -2

#define CXML_SYN_HTML 0
#define CXML_SYN_STRICT 1

#define maxLength 1000000

#include "cxml_class.hpp"
#include <stack>
#include <algorithm>

bool is_blank(char c);
void strip(std::string &str);
bool is_open(std::string name);
CXMLNode *parse_node_element_text(const std::string cxml, CXMLNode *root);
CXMLNode *parse_node_element_attr(const std::string cxml, CXMLNode *root);
CXMLNode *parse_node_element_name(const std::string cxml, CXMLNode *root);
CXMLNode *parse_node(const std::string cxml, CXMLNode *root);
CXMLNode *parse_from_string(const std::string cxml);
CXMLNode *search(const std::string target, CXMLNode *root);

#endif
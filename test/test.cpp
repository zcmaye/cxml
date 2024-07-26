#include "src/parser.hpp"
#include "src/xpath.hpp"
#include <time.h>
extern int CXML_PARSER_STATUS; //解析状态
extern int XPATH_PARSE_STATUE;
int main()
{
    using std::cout;
    using std::endl;
    clock_t start, end;
    start = clock();
    CXMLNode *root = parse_from_std::string("\
        <bookstore company=\"codecat\" boss=\"man\">\n\
            <book category=\"CHILDREN\">\n\
                <title>Harry Potter</title>\n\
                <author>J K.Rowlingk</author>\n\
                <year>2005</year><br>\n\
                <price>29.99 </price>\n\
            </book>\n\
            <book category=\"WEB\">\n\
                <title>Learning XML</title>\n\
                <author>Erik T.Ray</author>\n\
                <year>2003 </year>\n\
                <price>39.95 </price>\n\
            </book>\n\
        </bookstore>");
    //std::cout << root->children.size() << std::endl;
    if (CXML_PARSER_STATUS == CXML_SYNTAX_ERROR)
    {
        std::puts(">xml解析异常");
        return 0;
    }
    else
    {
        std::puts(">xml解析成功");
    }

    const CXMLNode_result *result1 = xpath("/bookstore/book[@category=CHILDREN]//text()", root);
    const CXMLNode_result *result2 = xpath("/bookstore/book/title/../price/text()", root);
    if (XPATH_PARSE_STATUE == XPATH_SYNTAX_ERROR)
    {
        std::puts(">xpath解析异常");
        return 0;
    }
    else
    {
        std::puts(">xpath解析成功");
    }
    std::cout << "测试样例1:" << result1->text << std::endl;
    std::cout << "测试样例2:" << result2->text << std::endl;

    end = clock();
    std::cout << "\n函数运行花费:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
    // CXMLNode *result = search("book", root);
    // std::cout << result->children.size() << std::endl;
    // using std::puts;
    // puts("解析到的属性:");
    // if (result->attr != nullptr)
    // {
    //     for (auto m : result->attr->attributes)
    //     {
    //         //属性
    //         std::cout << "key:" << m.first << " value:" << m.second << std::endl;
    //     }
    // }
    // //
    // puts("解析子节点 及节点值");
    // for (auto m : result->children)
    // {
    //     //节点名称
    //     std::cout << m->name << ":" << m->text->content << std::endl;
    // }
    return 0;
}

#ifndef VIEW_H
#define VIEW_H

#include <htmlcxx/html/ParserDom.h>
#include <ostream>

using namespace std;
using namespace htmlcxx;

namespace calassomys {

class View
{
    HTML::ParserDom html;
    map<string, tree<HTML::Node> > mapIdContent;
public:
    View();
    void setContent(string fileNameHtml);
    void setContentId(string id, string fileNameContent);
    void write(std::ostream& out, const tree<htmlcxx::HTML::Node>& dom);
    const tree<HTML::Node>& getDom();


};

}
std::ostream& operator<<(std::ostream &stream, calassomys::View &view);

#endif // VIEW_H

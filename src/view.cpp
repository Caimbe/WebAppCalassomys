#include "include/view.h"
#include <fstream>
#include <sstream>

namespace calassomys
{

View::View()
{
}

void View::setContent(string fileNameHtml)
{
    ifstream file(fileNameHtml);
    stringstream ss;
    ss << file.rdbuf();
    html.parse(ss.str());
}

void View::setContentId(string id, string fileNameContent)
{
    ifstream file(fileNameContent);
    stringstream ss;
    ss << file.rdbuf();
    HTML::ParserDom dom;
    dom.parse(ss.str());
    mapIdContent[id] = dom.getTree();
}

const tree<HTML::Node>& View::getDom()
{
    return html.getTree();
}

void View::write(std::ostream& out, const tree<htmlcxx::HTML::Node>& dom)
{
    tree<htmlcxx::HTML::Node>::iterator it = dom.begin();

    out << it->text();
    for ( unsigned i=0; i<dom.number_of_children(it); i++ )
    {
        write(out, dom.child(it,i) );
    }

    it->parseAttributes();
    auto atrr = it->attribute("id");
    if(atrr.first)
    {
        auto content = mapIdContent.find(atrr.second);
        if(content != mapIdContent.end())
        {
            write(out, content->second);
        }
    }
    out << it->closingText();
}

}

std::ostream& operator<<(std::ostream &stream, calassomys::View &view)
{
    view.write(stream, view.getDom());
}

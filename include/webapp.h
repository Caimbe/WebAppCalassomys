#ifndef WEBAPP_H
#define WEBAPP_H
#include <memory>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>

using namespace std;
using namespace cppcms;

namespace calassomys {

class WebApp : public cppcms::application
{
protected:
    static cppcms::json::value config;
public:
    WebApp(cppcms::service& service, cppcms::json::value& cfg);
    WebApp(cppcms::service& service);
    virtual ~WebApp();

    static json::value getConfig();

    void attach(WebApp* webapp, string url="")
    {
        string name = typeid(*webapp).name()+1;
        if(url.length())
            url = url;
        else{
            url = "/";
            url += name;
        }
        cppcms::application::attach(webapp,
        name,
        url+"{1}", // mapping
        url+"(/(.*))?", 1);   // dispatching
    }

};
typedef WebApp* WebAppPtr;

}

#endif // WEBAPP_H

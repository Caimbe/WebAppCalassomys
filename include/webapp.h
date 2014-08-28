#ifndef WEBAPP_H
#define WEBAPP_H
#include <memory>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>

using namespace std;

namespace calassomys {

class WebApp : public cppcms::application
{
public:
    WebApp(cppcms::service& service);
    virtual ~WebApp();

    void attach(WebApp* webapp, string url="")
    {
        const char* name = typeid(*webapp).name()+1;
        url = url.length()?url:name;
        cppcms::application::attach(webapp,
        name,
        url+"{1}", // mapping
        url+"(/(.*))?", 1);   // dispatching
    }

};
typedef WebApp* WebAppPtr;

}

extern "C" calassomys::WebAppPtr create(cppcms::service& srv, std::string& name);

#define WEBCONTENT "WebContent"


#endif // WEBAPP_H

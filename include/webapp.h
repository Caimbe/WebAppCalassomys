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

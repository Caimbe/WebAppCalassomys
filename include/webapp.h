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

};
typedef WebApp* WebAppPtr;

}

extern "C" calassomys::WebAppPtr create(cppcms::service& srv);


#endif // WEBAPP_H

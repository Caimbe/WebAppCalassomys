#ifndef WEBAPP_H
#define WEBAPP_H
#include <memory>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include "iwebappconfig.h"

class WebApp : public cppcms::application
{
public:
    WebApp(cppcms::service& srv);
    template<typename func>
    void map_dispatcher(std::string path, func)
    {

    }
};


#endif // WEBAPP_H

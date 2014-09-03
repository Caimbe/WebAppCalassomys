#ifndef LOADWEBAPP_H
#define LOADWEBAPP_H

#include <webapp.h>
#include <cppcms/json.h>

namespace calassomys {

class LoadWebApp : public WebApp
{
    cppcms::json::value settings;
public:
    LoadWebApp(cppcms::service &srv, std::string& nameWebApp);
    void serveFile(std::string file_name);
    void loader();
};

}

#define CREATE  extern "C" calassomys::WebAppPtr create(cppcms::service& srv, std::string& name) { \
    return calassomys::WebAppPtr(new calassomys::LoadWebApp(srv, name)); \
}

#endif // LOADWEBAPP_H

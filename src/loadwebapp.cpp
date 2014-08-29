#include "loadwebapp.h"
#include <cppcms/json.h>
#include <fstream>

namespace calassomys {

LoadWebApp::LoadWebApp(cppcms::service &srv, std::string& nome) : calassomys::WebApp(srv)
{
    nameWebApp = nome;
    loader();
    dispatcher().assign("/(.*)",&LoadWebApp::serveFile,this,1);
}


void LoadWebApp::serveFile(std::string file_name)
{
    file_name = file_name.length()?file_name:settings().get<string>("calassomys.index_page");
    const char* name = (settings().get<string>("calassomys.path_webapps")+"/"+nameWebApp + "/"+settings().get<string>("calassomys.webcontent")+"/" + file_name).c_str();
    std::ifstream f(name);
    if(!f) {
        response().status(404);
    }
    else {
        response().out() << f.rdbuf();
    }
}

}

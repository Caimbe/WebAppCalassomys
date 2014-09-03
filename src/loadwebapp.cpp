#include "loadwebapp.h"
#include <cppcms/json.h>
#include <fstream>

namespace calassomys {

LoadWebApp::LoadWebApp(cppcms::service &srv, std::string& nome) : calassomys::WebApp(srv)
{
    settings = cppcms::application::settings();
    string webContentPath = settings.get<string>("calassomys.path_webapps")+"/"+nome + "/"+settings.get<string>("calassomys.webcontent")+"/";
    settings.set("calassomys.webapp.web_content_path", webContentPath);
    settings.set("calassomys.webapp.name", nome);
    settings.set("calassomys.webapp.path", settings.get<string>("calassomys.path_webapps")+"/"+nome+"/" );

    loader();
    dispatcher().assign("/(.*)",&LoadWebApp::serveFile,this,1);
}


void LoadWebApp::serveFile(std::string file_name)
{
    file_name = file_name.length()?file_name:settings.get<string>("calassomys.index_page");
    const char* name = (settings.get<string>("calassomys.webapp.web_content_path")+file_name).c_str();
    std::ifstream f(name);
    if(!f) {
        response().status(404);
    }
    else {
        response().content_type( request().content_type() );
        response().out() << f.rdbuf();
    }
}

}

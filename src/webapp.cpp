#include "include/webapp.h"

namespace calassomys {

cppcms::json::value WebApp::config;

WebApp::WebApp(cppcms::service &srv, cppcms::json::value& cfg) : cppcms::application(srv)
{
    config = cfg;
}

WebApp::WebApp(cppcms::service &srv) : cppcms::application(srv)
{

}

WebApp::~WebApp()
{

}

json::value WebApp::getConfig()
{
    return config;
}

}

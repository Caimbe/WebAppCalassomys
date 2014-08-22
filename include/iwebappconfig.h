#ifndef IWEBAPPCONFIG_H
#define IWEBAPPCONFIG_H

#include <cppcms/service.h>
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>

typedef std::unique_ptr<cppcms::service> ServicePtr;

class iWebAppConfig
{
public:
    iWebAppConfig();
    virtual void configure(ServicePtr& service) = 0;
};
typedef std::shared_ptr<iWebAppConfig> WebAppConfigPtr;

extern "C" WebAppConfigPtr create();

#endif // IWEBAPPCONFIG_H

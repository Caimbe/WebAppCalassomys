#ifndef WEBAPP_H
#define WEBAPP_H
#include <memory>
#include <cppcms/service.h>
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>


class WebApp
{
public:
    WebApp();

    void configure();
};

typedef std::shared_ptr<WebApp>  WebAppPtr;
typedef std::unique_ptr<cppcms::service> ServicePtr;

#define IMPL_CLASS(classe) _Impl##classe

#define _WebApp(path,classe) \
    class classe ; \
    class IMPL_CLASS(classe) : public classe, public cppcms::application { \
        std::string strPath = path; \
        public: \
        IMPL_CLASS(classe)(cppcms::service& srv) :cppcms::application(srv){\
        }\
    };\
    class AppManager { \
        void configure(ServicePtr& srv){ \
            srv->applications_pool().mount(cppcms::applications_factory< IMPL_CLASS(classe) >()); \
        } \
    };

#endif // WEBAPP_H

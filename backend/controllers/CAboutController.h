#pragma once
#include "main.h"




namespace NSBackend
{
namespace NSControllers
{




class CAboutController final : public drogon::HttpController<CAboutController>
{
private:
    /* data */




protected:
    /* data */




public:
    CAboutController(/* args */);
    ~CAboutController();


    METHOD_LIST_BEGIN


    ADD_METHOD_TO(CAboutController::callback_aboutContent,
                    "/about",
                    drogon::Get,
                    "CBaseFilter");


    METHOD_LIST_END


    void callback_aboutContent(const drogon::HttpRequestPtr& ptrReq, std::function<void(const drogon::HttpResponsePtr&)>&& callback);
}; // class CAboutController




} // namespace NSControllers
} // namespace NSBackend

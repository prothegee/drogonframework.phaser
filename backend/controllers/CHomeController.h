#pragma once
#include "main.h"




namespace NSBackend
{
namespace NSControllers
{




class CHomeController final : public drogon::HttpController<CHomeController>
{
private:
    /* data */




protected:
    /* data */




public:
    CHomeController(/* args */);
    ~CHomeController();


    METHOD_LIST_BEGIN


    ADD_METHOD_TO(CHomeController::callback_homeContent,
                    "/",
                    drogon::Get,
                    "CBaseFilter");


    METHOD_LIST_END


    void callback_homeContent(const drogon::HttpRequestPtr& ptrReq, std::function<void(const drogon::HttpResponsePtr&)>&& callback);
}; // class CHomeController




} // namespace NSControllers
} // namespace NSBackend

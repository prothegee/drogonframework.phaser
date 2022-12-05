#include "CHomeController.h"


using namespace NSBackend::NSControllers;




CHomeController::CHomeController(/* args */)
{
    #ifdef NDEBUG
    #else
    #endif
}
CHomeController::~CHomeController()
{
    #ifdef NDEBUG
    #else
    #endif
}








#pragma region private
#pragma endregion








#pragma region protected
#pragma endregion








#pragma region public
void CHomeController::callback_homeContent(const drogon::HttpRequestPtr& ptrReq, std::function<void(const drogon::HttpResponsePtr&)>&& callback)
{
    drogon::HttpResponsePtr ptrResp;


    ptrResp = drogon::HttpResponse::newHttpViewResponse("home.csp");
    ptrResp->setContentTypeCode(drogon::CT_TEXT_HTML);
    ptrResp->setStatusCode(drogon::k200OK);


    callback(ptrResp);
}
#pragma endregion

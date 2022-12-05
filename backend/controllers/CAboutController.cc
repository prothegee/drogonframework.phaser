#include "CAboutController.h"


using namespace NSBackend::NSControllers;




CAboutController::CAboutController(/* args */)
{
    #ifdef NDEBUG
    #else
    #endif
}
CAboutController::~CAboutController()
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
void CAboutController::callback_aboutContent(const drogon::HttpRequestPtr& ptrReq, std::function<void(const drogon::HttpResponsePtr&)>&& callback)
{
    drogon::HttpResponsePtr ptrResp;


    ptrResp = drogon::HttpResponse::newHttpViewResponse("about.csp");
    ptrResp->setContentTypeCode(drogon::CT_TEXT_HTML);
    ptrResp->setStatusCode(drogon::k200OK);


    callback(ptrResp);
}
#pragma endregion

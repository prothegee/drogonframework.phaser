/**
 *
 *  CBaseFilter.cc
 *
 */

#include "CBaseFilter.h"


using namespace drogon;
using namespace NSBackend;


void CBaseFilter::doFilter(const HttpRequestPtr &req,
                         FilterCallback &&fcb,
                         FilterChainCallback &&fccb)
{
    // headers
    const std::string _header_accept = "*/*";
    const std::string _header_STS = "max-age=518400; always";
    const std::string _header_xFrameOptions = "SAMEORIGIN";
    const std::string _header_contentEncoding = "gzip, compress, deflate, br";
    // const std::string _header_accessControlAllowOrigin = "*";


    if (1)
    {
        CMain::LogInfo("CBaseFilter::doFilter");

        
        // headers
        req->addHeader("Accept", _header_accept);
        req->addHeader("Strict-Transport-Security", _header_STS);
        req->addHeader("X-Frame-Options", _header_xFrameOptions);
        req->addHeader("Content-Encoding", _header_contentEncoding);
        // req->addHeader("Access-Control-Allow-Origin", _header_accessControlAllowOrigin);

        fccb();
        return;
    }


    auto res = drogon::HttpResponse::newHttpResponse();
    res->setStatusCode(k500InternalServerError);
    fcb(res);
}

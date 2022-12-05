/**
 *
 *  CBaseFilter.h
 *
 */

#pragma once
#include "main.h"
#include <drogon/HttpFilter.h>


using namespace drogon;


class CBaseFilter : public HttpFilter<CBaseFilter>
{
public:
    CBaseFilter() {}
    void doFilter(const HttpRequestPtr &req,
                  FilterCallback &&fcb,
                  FilterChainCallback &&fccb) override;
};


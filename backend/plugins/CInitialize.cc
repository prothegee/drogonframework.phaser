/**
 *
 *  CInitialize.cc
 *
 */

#include "CInitialize.h"


using namespace drogon;
using namespace NSBackend;


void CInitialize::initAndStart(const Json::Value &config)
{
    /// Initialize and start the plugin
    CMain::LogInfo("CInitialize::initAndStart");
}




void CInitialize::shutdown() 
{
    /// Shutdown the plugin
    CMain::LogInfo("CInitialize::shutdown");
}

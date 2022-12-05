/**
 *
 *  CInitialize.h
 *
 */

#pragma once
#include "main.h"
#include <drogon/plugins/Plugin.h>


class CInitialize : public drogon::Plugin<CInitialize>
{
public:
    CInitialize() {}
    /// This method must be called by drogon to initialize and start the plugin.
    /// It must be implemented by the user.
    void initAndStart(const Json::Value &config) override;


    /// This method must be called by drogon to shutdown the plugin.
    /// It must be implemented by the user.
    void shutdown() override;
};


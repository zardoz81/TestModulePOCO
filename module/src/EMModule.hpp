//
// Created by Sersoftin on 20.11.2022.
//

#ifndef NFCORE_TMMODULE_HPP
#define NFCORE_TMMODULE_HPP

#include <Poco/Manifest.h>
#include <Poco/ClassLibrary.h>

#include "../../sdk/BaseModule.hpp"

class EMModule : public modules::BaseModule {
public:
    explicit EMModule();

    void handleStart() override;

    void handleRun() override;

    void handleStop() override;

    void handleLogonUser(std::string username) override;

    void handleLogoffUser(std::string username) override;

    ~EMModule() override;
};

POCO_BEGIN_MANIFEST(modules::AbstractModule)
    POCO_EXPORT_CLASS(EMModule)
POCO_END_MANIFEST

#endif //NFCORE_TMMODULE_HPP

//
// Created by Sersoftin on 20.11.2022.
//

#include "EMModule.hpp"

EMModule::EMModule() : modules::BaseModule("EMModule") {
//    logger()->information("!!! Constructor called");
    std::cout << "Constructor" << std::endl;
}

void EMModule::handleStart() {
    this->data()->set("test", "start");

//    logger()->information("Test module start. Instance id: %u", getInstanceId());
}

void EMModule::handleRun() {
//    logger()->information("Test module run");
    while (!mustStop()) {
        // do work
        auto service_id = getInstanceId();
//        logger()->information("I have much work... Service id: %u", service_id);

        Poco::Thread::sleep(200);
    }
}

void EMModule::handleStop() {
//    logger()->information("Test module stop");
}

void EMModule::handleLogonUser(std::string username) {
//    logger()->information("User %s logged on!", username);
}

void EMModule::handleLogoffUser(std::string username) {
//    logger()->information("User %s logged off!", username);
}

EMModule::~EMModule() {
    std::cout << "Destructor" << std::endl;
//    logger()->information("!!! Destructor called");
}

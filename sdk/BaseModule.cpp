//
// Created by Sersoftin on 12.11.2022.
//

#include "BaseModule.hpp"

namespace modules {
    const std::string &BaseModule::getName() const {
        return name_;
    }

    BaseModule::BaseModule(const std::string &name)
            : name_(name),
              thread_(name),
              context_data_(Poco::makeShared<Poco::JSON::Object>()),
//              logger_(&Poco::Logger::root()),
              config_(new Poco::Util::LayeredConfiguration()) {}

    void BaseModule::setConfig(Poco::Util::LayeredConfiguration::Ptr config) {
        config_ = std::move(config);
    }

    void BaseModule::start() {
        handleStart();

        stopped_ = false;

        thread_.start(*this);
    }

    void BaseModule::run() {
        handleRun();

        stopped_ = true;
    }

    void BaseModule::stop() {
        stopped_ = true;

        thread_.join();
        handleStop();
    }

    Poco::Util::LayeredConfiguration &BaseModule::config() const {
        return *const_cast<Poco::Util::LayeredConfiguration *>(config_.get());
    }

    void BaseModule::setLogger(Poco::Logger &logger) {
//        logger_ = &logger;
    }

//    Poco::Logger::Ptr BaseModule::logger() const {
//        return logger_;
//    }

    void BaseModule::logonUser(std::string username) {
        handleLogonUser(std::move(username));
    }

    void BaseModule::logoffUser(std::string username) {
        handleLogoffUser(std::move(username));
    }

    uint32_t BaseModule::getInstanceId() const {
        return instance_id_;
    }

    void BaseModule::setInstanceId(uint32_t instance_id) {
        instance_id_ = instance_id;
    }

    void BaseModule::setData(Poco::JSON::Object* data) {
        context_data_ = data;
    }

    bool BaseModule::mustStop() const {
        return stopped_;
    }

    Poco::JSON::Object* BaseModule::data() {
        return context_data_;
    }

    std::string BaseModule::getData() {
        std::ostringstream ss;

        context_data_->stringify(ss);

        return ss.str();
    }
}

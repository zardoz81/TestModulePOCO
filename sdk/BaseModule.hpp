//
// Created by Sersoftin on 12.11.2022.
//

#ifndef NFCORE_BASEMODULE_HPP
#define NFCORE_BASEMODULE_HPP

#include <cstdint>

#include <Poco/Logger.h>
#include <Poco/Thread.h>
#include <Poco/Event.h>
#include <Poco/RWLock.h>
#include <Poco/ScopedLock.h>
#include <Poco/Runnable.h>
#include <Poco/JSON/Object.h>
#include <Poco/Util/LayeredConfiguration.h>
#include <Poco/Util/JSONConfiguration.h>

#include <atomic>

#include "AbstractModule.hpp"

namespace modules {
    class BaseModule : public AbstractModule, public Poco::Runnable {
    public:
        using Ptr = Poco::AutoPtr<BaseModule>;

        explicit BaseModule(const std::string &name);

        void setInstanceId(uint32_t instance_id) override;

        void setConfig(Poco::Util::LayeredConfiguration::Ptr config) override;

        void setLogger(Poco::Logger &logger) override;

        void start() override;

        void run() override;

        void stop() override;

        void logonUser(std::string username) override;

        void logoffUser(std::string username) override;

        void setData(Poco::JSON::Object* data) override;

        std::string getData() override;

        const std::string &getName() const override;

        ~BaseModule() override = default;

    protected:
        virtual void handleLogonUser(std::string username) = 0;

        virtual void handleLogoffUser(std::string username) = 0;

        virtual void handleStart() = 0;

        virtual void handleRun() = 0;

        virtual void handleStop() = 0;

        bool mustStop() const;

        uint32_t getInstanceId() const;

        Poco::JSON::Object* data();

        Poco::Util::LayeredConfiguration &config() const;

//        Poco::Logger::Ptr logger() const;

    private:
        std::string name_{};
        uint32_t instance_id_{};

//        Poco::Logger::Ptr logger_{nullptr};
        Poco::Util::LayeredConfiguration::Ptr config_{nullptr};
        Poco::JSON::Object* context_data_{};

        Poco::Thread thread_;
        std::atomic<bool> stopped_{true};
    };
}

#endif //NFCORE_BASEMODULE_HPP

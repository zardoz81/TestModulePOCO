//
// Created by Sersoftin on 15.12.2022.
//

#ifndef NFCORE_ABSTRACTMODULE_HPP
#define NFCORE_ABSTRACTMODULE_HPP

#include <string>
#include <Poco/Logger.h>
#include <Poco/JSON/Object.h>
#include <Poco/Util/LayeredConfiguration.h>

namespace modules {
    class AbstractModule {
    public:
        AbstractModule() = default;

        virtual void setInstanceId(uint32_t instance_id) = 0;

        virtual void setConfig(Poco::Util::LayeredConfiguration::Ptr config) = 0;

        virtual void setLogger(Poco::Logger &logger) = 0;

        virtual void start() = 0;

        virtual void stop() = 0;

        virtual void logonUser(std::string username) = 0;

        virtual void logoffUser(std::string username) = 0;

        virtual void setData(Poco::JSON::Object* data) = 0;

        virtual std::string getData() = 0;

        [[nodiscard]] virtual const std::string &getName() const = 0;

        virtual ~AbstractModule() = default;
    };
}

#endif //NFCORE_ABSTRACTMODULE_HPP

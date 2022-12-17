//
// Created by Sersoftin on 16.12.2022.
//

#include <iostream>
#include <Poco/ClassLoader.h>
#include "../../sdk/AbstractModule.hpp"

using ModuleLoader = Poco::ClassLoader<modules::AbstractModule>;

int main() {
    std::string lib = "ExampleModule";

    ModuleLoader module_loader_;

    module_loader_.loadLibrary(lib);

    auto data_object = Poco::makeShared<Poco::JSON::Object>();
    data_object->set("current_interface", "installed from main");

    {
        auto instance = module_loader_.create("EMModule");
        module_loader_.classFor("EMModule").autoDelete(instance);

//        instance->setLogger(Poco::Logger::get(instance->getName()));

        instance->setData(data_object.get());

        instance->start();

        Poco::Thread::sleep(1000);

        instance->stop();

        module_loader_.destroy("EMModule", instance);
    }

    data_object->stringify(std::cout);

    module_loader_.unloadLibrary(lib);

    return 0;
}

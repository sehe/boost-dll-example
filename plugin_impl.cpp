#include <boost/config.hpp> // for BOOST_SYMBOL_EXPORT
#include "my_plugin_api.hpp"
#include <iostream>

namespace my_namespace {

    class my_plugin_sum : public my_plugin_api {
      public:
        my_plugin_sum() {
            std::cout << "Constructing my_plugin_sum" << std::endl;
        }

        std::string name() const { return "sum"; }

        float calculate(float x, float y) { return x + y; }

        ~my_plugin_sum() {
            std::cout << "Destructing my_plugin_sum ;o)" << std::endl;
        }
    };

    // Exporting `my_namespace::plugin` variable with alias name `plugin`
    // (Has the same effect as `BOOST_DLL_ALIAS(my_namespace::plugin, plugin)`)

    extern "C" BOOST_SYMBOL_EXPORT my_plugin_sum plugin;
#if 0
    extern "C" __attribute__((__visibility__("default"))) my_plugin_sum plugin;
#endif
    my_plugin_sum plugin;

} // namespace my_namespace

//Lovely
#include <lovely.hpp>
// Love header
#include <common/config.h>
#include <modules/system/System.h>
#include <modules/system/sdl/System.h>
// Love implementation
#include <modules/system/System.cpp>
#include <modules/system/sdl/System.cpp>
// Love alias
using namespace love;
using namespace love::system;
#define instance() (Module::getInstance<System>(Module::M_SYSTEM))

extern void add_system_module(py::module& module)
{
	//Add module
	Module::registerInstance(new sdl::System());
	//power state
	py::enum_<System::PowerState>(module, "PowerState")
		.value("POWER_BATTERY",    System::PowerState::POWER_BATTERY)
		.value("POWER_NO_BATTERY", System::PowerState::POWER_NO_BATTERY)
		.value("POWER_CHARGED",    System::PowerState::POWER_CHARGED)
		.value("POWER_CHARGING",   System::PowerState::POWER_CHARGING)
		.value("POWER_UNKNOWN",    System::PowerState::POWER_UNKNOWN)
		.value("POWER_MAX_ENUM",   System::PowerState::POWER_MAX_ENUM)
		.export_values();
	//Wrapper
	module.def("getOS",            []()->std::string                { return instance()->getOS();             });
	module.def("getProcessorCount",[]()->int                        { return instance()->getProcessorCount(); });
	module.def("openURL",          [](const std::string& url)->bool { return instance()->openURL(url);        });
	module.def("vibrate",          [](double secs)                  { instance()->vibrate(secs);              });
	module.def("getClipboardText", []()-> std::string               { return instance()->getClipboardText();  });
	module.def("setClipboardText", [](const std::string& text)      { instance()->setClipboardText(text);     });
	module.def("getPowerInfo",	   [](){ 
		int secs = 0, perc = 0; 
		System::PowerState info = instance()->getPowerInfo(secs, perc);
		return std::make_tuple(info, secs, perc);
	}); 
}
//Lovely
#include <lovely.hpp>
// Love header
#include <common/config.h>
#include <modules/window/Window.h>
#include <modules/window/sdl/Window.h>
// Love implementation
#include <modules/window/Window.cpp>
#include <modules/window/sdl/Window.cpp>
// Love alias
using namespace love;
using namespace love::window;
#define instance() (Module::getInstance<Window>(Module::M_WINDOW))

extern void add_window_module(py::module& module)
{
	//Add module
	Module::registerInstance(new sdl::Window());
	//power state
	py::enum_<Window::Setting>(module, "Setting")
		.value("SETTING_FULLSCREEN", Window::Setting::SETTING_FULLSCREEN)
		.value("SETTING_FULLSCREEN_TYPE", Window::Setting::SETTING_FULLSCREEN_TYPE)
		.value("SETTING_VSYNC", Window::Setting::SETTING_VSYNC)
		.value("SETTING_MSAA", Window::Setting::SETTING_MSAA)
		.value("SETTING_RESIZABLE", Window::Setting::SETTING_RESIZABLE)
		.value("SETTING_MIN_WIDTH", Window::Setting::SETTING_MIN_WIDTH)
		.value("SETTING_MIN_HEIGHT", Window::Setting::SETTING_MIN_HEIGHT)
		.value("SETTING_BORDERLESS", Window::Setting::SETTING_BORDERLESS)
		.value("SETTING_CENTERED", Window::Setting::SETTING_CENTERED)
		.value("SETTING_DISPLAY", Window::Setting::SETTING_DISPLAY)
		.value("SETTING_HIGHDPI", Window::Setting::SETTING_HIGHDPI)
		.value("SETTING_REFRESHRATE", Window::Setting::SETTING_REFRESHRATE)
		.value("SETTING_X", Window::Setting::SETTING_X)
		.value("SETTING_Y", Window::Setting::SETTING_Y)
		.value("SETTING_MAX_ENUM", Window::Setting::SETTING_MAX_ENUM)
		.export_values();

	py::enum_<Window::FullscreenType>(module, "FullscreenType")
		.value("FULLSCREEN_DESKTOP", Window::FullscreenType::FULLSCREEN_DESKTOP)
		.value("FULLSCREEN_EXCLUSIVE", Window::FullscreenType::FULLSCREEN_EXCLUSIVE)
		.value("SETTING_VSYNC", Window::FullscreenType::FULLSCREEN_MAX_ENUM)
		.export_values();

	py::enum_<Window::MessageBoxType>(module, "MessageBoxType")
		.value("MESSAGEBOX_ERROR", Window::MessageBoxType::MESSAGEBOX_ERROR)
		.value("MESSAGEBOX_WARNING", Window::MessageBoxType::MESSAGEBOX_WARNING)
		.value("MESSAGEBOX_INFO", Window::MessageBoxType::MESSAGEBOX_INFO)
		.value("MESSAGEBOX_MAX_ENUM", Window::MessageBoxType::MESSAGEBOX_MAX_ENUM)
		.export_values();


	py::class_<WindowSettings>(module, "WindowSettings")
		.def(py::init<>())
		.def_readwrite("fullscreen", &WindowSettings::fullscreen)
		.def_readwrite("fstype", &WindowSettings::fstype)
		.def_readwrite("vsync", &WindowSettings::vsync)
		.def_readwrite("msaa", &WindowSettings::msaa)
		.def_readwrite("resizable", &WindowSettings::resizable)
		.def_readwrite("minwidth", &WindowSettings::minwidth)
		.def_readwrite("minheight", &WindowSettings::minheight)
		.def_readwrite("borderless", &WindowSettings::borderless)
		.def_readwrite("centered", &WindowSettings::centered)
		.def_readwrite("display", &WindowSettings::display)
		.def_readwrite("highdpi", &WindowSettings::highdpi)
		.def_readwrite("refreshrate", &WindowSettings::refreshrate)
		.def_readwrite("useposition", &WindowSettings::useposition)
		.def_readwrite("x", &WindowSettings::x)
		.def_readwrite("y", &WindowSettings::y)
	;
	//Wrapper
	module.def("close", []() { instance()->close(); });
	module.def("setMode", [](int width, int height, WindowSettings& settings) {
		instance()->setWindow(width, height, &settings);
	});
	module.def("setMode", [](int width, int height) {
		instance()->setWindow(width, height, nullptr);
	});
	module.def("isOpen", []() -> bool {
		return instance()->isOpen();
	});
}
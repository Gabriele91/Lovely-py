//
//  lovely.cpp
//  lovely
//
//  Created by Gabriele Di Bari on 03/05/17.
//  Copyright © 2017 Gabriele Di Bari. All rights reserved.
//
#define PYBIND11_EXPORT
#define PYBIND11_CPP_STANDARD
#define PYBIND11_PYTHON_VERSION 3.6
#include <pybind11/pybind11.h>
//#include <lovely.hpp>
//#include <modules/system/System.h>
//alias
namespace py = pybind11;

const char * libname()
{
    return "lovely";
}
const char * version()
{
    return "0.0.1";
}

void add_system_module(py::module& module)
{
    #if 0
    using namespace love::system;
    py::class_<System>(module, "Object")
        .def("getOS", &System::getOS)
        .def("openURL", &System::openURL)
        .def("vibrate", &System::vibrate);
    #endif
}

PYBIND11_PLUGIN(lovely) 
{
    //module
    py::module lovely("lovely", "lovely plugin");
    //lib
    lovely.def("libname", &libname, "That function return the name of library");
    lovely.def("version", &version, "That function return the version of library");
    //sub module objs
    auto love_system = lovely.def_submodule("system");
    auto love_math   = lovely.def_submodule("math");
    auto love_font   = lovely.def_submodule("font");
    //love system
    add_system_module(love_system);
    //return
    return lovely.ptr();
}

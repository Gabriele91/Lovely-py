//
//  lovely.cpp
//  lovely
//
//  Created by Gabriele Di Bari on 03/05/17.
//  Copyright © 2017 Gabriele Di Bari. All rights reserved.
//
#include <lovely.hpp>
#include <modules/system/System.h>

const char * libname()
{
    return "lovely";
}
const char * version()
{
    return "0.0.1";
}

PYBIND11_PLUGIN(lovely) 
{
    //module
    py::module lovely("lovely", "lovely plugin");
    //lib
    lovely.def("libname", &libname, "That function return the name of library");
    lovely.def("version", &version, "That function return the version of library");
    //sub module objs
	{ auto love_system = lovely.def_submodule("system"); add_system_module(love_system); }
	{ auto love_window = lovely.def_submodule("window"); add_window_module(love_window); }
    //return
    return lovely.ptr();
}

//
//  lovely.cpp
//  lovely
//
//  Created by Gabriele Di Bari on 03/05/17.
//  Copyright © 2017 Gabriele Di Bari. All rights reserved.
//

#include <lovely.hpp>
#include <modules/system/System.h>
#include <pybind11/pybind11.h>
//ref

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
    //alias
    namespace py = pybind11;
    //module
    py::module lovely("lovely", "lovely plugin");
    //lib
    lovely.def("libname", &libname, "That function return the name of library");
    lovely.def("version", &version, "That function return the version of library");
    //love system
    {
        using namespace love::system;
        py::class_<System>(lovely, "Object")
            .def("getOS", &System::getOS)
            .def("openURL", &System::openURL)
            .def("vibrate", &System::vibrate);
    }
    //return
    return lovely.ptr();
}
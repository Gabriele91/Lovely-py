//
//  lovely.cpp
//  lovely
//
//  Created by Gabriele Di Bari on 03/05/17.
//  Copyright © 2017 Gabriele Di Bari. All rights reserved.
//

#include <lovely.hpp>
#include <boost/python.hpp>
#include <modules/system/System.h>


const char * libname()
{
    return "lovely";
}
const char * version()
{
    return "0.0.1";
}

BOOST_PYTHON_MODULE(lovely)
{
    using namespace boost::python;
    def("libname", libname);
    def("version", version);
    
    using namespace love::system;
    
    class_<System>("System")
        .def("getOS",&System::getOS);
}

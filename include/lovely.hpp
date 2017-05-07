//
//  lovely.hpp
//  lovely
//
//  Created by Gabriele Di Bari on 03/05/17.
//  Copyright © 2017 Gabriele Di Bari. All rights reserved.
//

#ifndef lovely_hpp
#define lovely_hpp
//pybind
#include <pybind11/pybind11.h>
namespace py = pybind11;

extern void add_system_module(py::module& module);
extern void add_filesystem_module(py::module& module);
extern void add_window_module(py::module& module);
extern void add_math_module(py::module& module);
extern void add_font_module(py::module& module);

#endif /* lovely_hpp */

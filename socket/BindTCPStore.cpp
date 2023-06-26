//
// Created by 李成杰 on 2023/6/25.
//
#pragma once

#include "Store.hpp"
#include "TCPStore.hpp"

#include <pybind11/chrono.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

namespace xoscar {
PYBIND11_MODULE(example_bind, m) {
    py::class_<TCPStoreOptions>(m, "TCPStoreOptions")
        .def(py::init())
        .def_readwrite("port", &TCPStoreOptions::port)
        .def_readwrite("isServer", &TCPStoreOptions::isServer)
        .def_readwrite("numWorkers", &TCPStoreOptions::numWorkers)
        .def_readwrite("waitWorkers", &TCPStoreOptions::waitWorkers)
        .def_readwrite("timeout", &TCPStoreOptions::timeout)
        .def_readwrite("multiTenant", &TCPStoreOptions::multiTenant);

    py::class_<Store>(m, "Store");

    py::class_<TCPStore, Store>(m, "TCPStore")
        .def(py::init<std::string, const TCPStoreOptions &>())
        .def("wait",
             py::overload_cast<const std::vector<std::string> &>(
                 &TCPStore::wait))
        .def("wait",
             py::overload_cast<const std::vector<std::string> &,
                               const std::chrono::milliseconds &>(
                 &TCPStore::wait))
        .def("set",
             [](TCPStore &self, const std::string &key, py::bytes &bytes) {
                 const py::buffer_info info(py::buffer(bytes).request());
                 const char *data = reinterpret_cast<const char *>(info.ptr);
                 auto length = static_cast<size_t>(info.size);
                 self.set(key, std::vector<uint8_t>(data, data + length));
             })
        .def("get", [](TCPStore &self, const std::string &key) {
            auto result = self.get(key);
            const std::string str_result(result.begin(), result.end());
            return py::bytes(str_result);
        });
}
}  // namespace xoscar

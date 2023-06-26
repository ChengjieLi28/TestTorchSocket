#include "TCPStore.hpp"

#include <chrono>
#include <iostream>
#include <thread>

int main() {
    std::cout << "Simple example C++ compiled correctly and ran." << std::endl;
    std::cout << "Just a test for socket" << std::endl;

    auto store = xoscar::TCPStore("127.0.0.1", 25001, 2, false);
    std::cout << store.getHost() + ", " << store.getPort() << std::endl;

    std::cout << "After waiting for workers." << std::endl;
    std::cout << "This is worker." << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    std::string value1 = "This is value 1";
    store.set("test1", std::vector<uint8_t>(value1.begin(), value1.end()));
    auto v = store.get("test1");
    std::cout << "Value of key test1 is: " << std::string(v.begin(), v.end())
              << std::endl;

    return 0;
}

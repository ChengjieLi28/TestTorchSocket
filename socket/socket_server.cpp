#include "TCPStore.hpp"

#include <chrono>
#include <iostream>
#include <thread>

int main() {
    std::cout << "Simple example C++ compiled correctly and ran." << std::endl;
    std::cout << "Just a test for socket" << std::endl;

    auto store = xoscar::TCPStore("127.0.0.1", 25001, 2, true);
    std::cout << store.getHost() + ", " << store.getPort() << std::endl;

    std::cout << "After waiting for workers." << std::endl;
    std::cout << "This is server." << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(20000));

    return 0;
}

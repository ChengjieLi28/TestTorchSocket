#include <iostream>
#include "TCPStore.hpp"

int main() {

    std::cout << "Simple example C++ compiled correctly and ran." << std::endl;
    std::cout << "Just a test for socket" << std::endl;

    auto store = c10d::TCPStore(
            "127.0.0.1", 25001, 2, true
    );
    std::cout << store.getHost() + ", " << store.getPort() << std::endl;

    std::cout << "After waiting for workers." << std::endl;

    return 0;
}
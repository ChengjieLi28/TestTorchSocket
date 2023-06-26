#pragma once

#include "Utils.hpp"

#include <sys/poll.h>
#include <vector>

namespace xoscar::tcputil {

#define CONNECT_SOCKET_OFFSET 2

inline int poll(struct pollfd *fds, unsigned long nfds, int timeout) {
    return ::poll(fds, nfds, timeout);
}

inline void
addPollfd(std::vector<struct pollfd> &fds, int socket, short events) {
    fds.push_back({.fd = socket, .events = events});
}

inline struct ::pollfd getPollfd(int socket, short events) {
    struct ::pollfd res = {.fd = socket, .events = events};
    return res;
}

}  // namespace xoscar::tcputil

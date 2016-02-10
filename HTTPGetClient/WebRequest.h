/*
 * WebRequest
 */

#ifndef WEBREQUEST_H
#define WEBREQUEST_H

#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio::ip;

class WebRequest{
public:
    tcp::iostream* HttpGet(string url, string resource, long timeout = 60, string protocol = "http");
};

#endif /* WEBREQUEST_H */


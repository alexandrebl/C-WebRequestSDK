/*
 * WebRequest
 */

#ifndef WEBREQUEST_H
#define WEBREQUEST_H

#include <boost/asio.hpp>

//Define namespace
using namespace std;
//Define namespace
using namespace boost::asio::ip;

//Request Manager
class WebRequest{
public:
    //Execute Get Web Resquest
    tcp::iostream* HttpGet(string url, string resource, long timeout = 60, string protocol = "http");
    
    //Execute Post Web Resquest
    tcp::iostream* HttpPost(string url, string resource, char *buf, long bufSize, long timeout = 60, string protocol = "http");
};

#endif /* WEBREQUEST_H */


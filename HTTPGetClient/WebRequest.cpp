#include "WebRequest.h"

tcp::iostream* WebRequest::HttpGet(string url, string resource, long timeout, string protocol){
    
    tcp::iostream *stream = new tcp::iostream();
    
    stream->expires_from_now(boost::posix_time::seconds(timeout));
    stream->connect(url, protocol);
    
    *stream << "GET " << resource << " HTTP/1.0\r\n";
    *stream << "Host: " << url << "\r\n";
    *stream << "Accept: */*\r\n";
    *stream << "Connection: close\r\n\r\n";
    
    stream->flush();
    
    return stream;
}
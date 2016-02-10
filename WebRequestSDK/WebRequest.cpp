#include <ios>

//WebRequest Library
#include "WebRequest.h"

//Execute Get Web Resquest
tcp::iostream* WebRequest::HttpGet(string url, string resource, long timeout, string protocol){
    //Create stream
    tcp::iostream *stream = new tcp::iostream();
    
    //Define timeout
    stream->expires_from_now(boost::posix_time::seconds(timeout));
    //Connect
    stream->connect(url, protocol);
    
    //Define headers
    *stream << "GET " << resource << " HTTP/1.0\r\n";
    *stream << "Host: " << url << "\r\n";
    *stream << "Accept: */*\r\n";
    *stream << "Connection: close\r\n\r\n";
    
    //Flush data
    stream->flush();
    
    //Return
    return stream;
}

//Execute Post Web Resquest
tcp::iostream* WebRequest::HttpPost(string url, string resource, char *buf, long bufSize, long timeout, string protocol){
     //Create stream
    tcp::iostream *stream = new tcp::iostream();
    
    //Define timeout
    stream->expires_from_now(boost::posix_time::seconds(timeout));
    //Connect
    stream->connect(url, protocol);
    
    //Define headers
    *stream << "POST " << resource << " HTTP/1.0\r\n";
    *stream << "Host: " << url << "\r\n";
    *stream << "Accept: */*\r\n";
    *stream << "Connection: close\r\n";
    *stream << "Content-Length: " << bufSize << "\r\n";    
    
    //Define Raw Data
    *stream << "\r\n" << buf;
    
     //Flush data
    stream->flush();
    
    //Return
    return stream;
}
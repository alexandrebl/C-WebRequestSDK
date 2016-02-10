#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <ios>
#include "WebRequest.h"

int main(void) {
    
    WebRequest *webRequest = new WebRequest();
    
    tcp::iostream *stream = webRequest->HttpGet("www.google.com", "/");
    
    cout << stream->rdbuf();
    
    delete stream;
    delete webRequest;
    
    cout << endl << "---------------------------" << endl;
    cout << "Finished" << endl;

    return 0;
}





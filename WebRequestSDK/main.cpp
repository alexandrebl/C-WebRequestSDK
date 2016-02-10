#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <ios>
#include "WebRequest.h"

//Test HTTP Get Request
void TestHttpGet();
//Test HTTP Post Request
void TestHttpPost();

//Main method
int main(void) {

    //Execute Get Request
    TestHttpGet();
    //Execute Port Request    
    TestHttpPost();
    
    //Return    
    return 0;
}

//Test HTTP Get Request
void TestHttpGet(){
    //Initialize Web Request Manager
    WebRequest *webRequest = new WebRequest();
    
    //Execute Get Request
    tcp::iostream *stream = webRequest->HttpGet("www.google.com", "/");
    
    //Console message
    cout << "----------------------------------\r\n";           
    //Console message
    cout << "HTTP Response data:\r\n";           
    //Response data
    cout << stream->rdbuf();
    
    //Destroy stream object    
    delete stream;    
    //Destroy web request object
    delete webRequest;
}

//Test HTTP Post Request
void TestHttpPost(){
    //Initialize Web Request Manager
    WebRequest *webRequest = new WebRequest();
    
    //Data to send
    char data[] = "Testing Post Method";
    
    //Execute Post Request
    tcp::iostream *stream = webRequest->HttpPost("requestb.in", "/st92m7st", data, 19);
    
    //Console message
    cout << "----------------------------------\r\n";
    //Console message
    cout << "HTTP Response data:\r\n";         
    //Response data
    cout << stream->rdbuf();
    
    //Destroy stream object    
    delete stream;    
    //Destroy web request object
    delete webRequest;
}





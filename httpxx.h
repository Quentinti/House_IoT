#ifndef HTTPXX_H_INCLUDED
#define HTTPXX_H_INCLUDED

#include <winsock2.h>
#include <map>
#include <cstdlib>
#include "jsonxx.h"
#include <stdio.h>
#include <iostream>

using namespace jsonxx;
using namespace std;

const int E_SUCCESS      =  0;
const int E_WSASTARTUP   = -1;
const int E_CONNECTION   = -2;

namespace http {
    const char* HTTP_METHOD[] = {"GET", "POST"};

    typedef enum  {
        GET = 0,
        POST = 1,
    } Method;

    typedef struct  {
        string Host;
        int Port;
        string Resource;
        map<string, string> Headers;
        string Body;
    }Request;

    typedef struct  {
        string StatusText;
        int StatusCode;
        map<string, string> Headers;
        string Body;
    }Response;

    int doRequest(Method method, Request req, Response & resp) {
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
            return E_WSASTARTUP;

        SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        struct hostent *host;
        host = gethostbyname(req.Host.c_str());

        SOCKADDR_IN SockAddr;
        SockAddr.sin_port = htons(req.Port);
        SockAddr.sin_family = AF_INET;
        SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
        if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0)
            return E_CONNECTION;

        string buffer = HTTP_METHOD[method];
        buffer.append(" /"); buffer.append(req.Resource);
        buffer.append(" HTTP/1.1\r\n");
        buffer.append("Host: ");
        buffer.append(req.Host);
        buffer.append("\r\n");
        for (map<string,string>::iterator it=req.Headers.begin(); it!=req.Headers.end(); ++it) {
            buffer.append(it->first);
            buffer.append(": ");
            buffer.append(it->second);
            buffer.append("\r\n");
        }
        buffer.append("\r\n");

        if (method == POST){
            buffer.append(req.Body);
        }
        send(Socket, buffer.c_str(), buffer.length(), 0);

        const int BUFFER_SIZE = 128;
        char buff[BUFFER_SIZE+1];
        string responseBuffer = "";
        int nDataLength;
        do {
            nDataLength = recv(Socket, buff, BUFFER_SIZE, 0);
            buff[nDataLength] = 0;
            responseBuffer.append(buff);
            if (nDataLength < BUFFER_SIZE)
                break;
        }
        while (nDataLength > 0);
        closesocket(Socket);
        WSACleanup();

        int max_idx = responseBuffer.find("\r\n\r\n");
        resp.Body = responseBuffer.substr(max_idx+4, responseBuffer.length()-max_idx-4);
        int idx1 = responseBuffer.find(" ", 0) +1 ;
        resp.StatusCode = atoi(responseBuffer.substr(idx1, 3).c_str());
        idx1+= 4;
        int idx2 = responseBuffer.find("\r\n", idx1);
        resp.StatusText = responseBuffer.substr(idx1, idx2-idx1).c_str();
        int idx3;
        do {
            idx1 = responseBuffer.find(":", idx2);
            if (idx1 < max_idx && idx1 != -1) {
                idx3 = responseBuffer.find("\r\n", idx1);

                resp.Headers.insert(pair<string, string>(responseBuffer.substr(idx2+2, idx1-idx2-2),
                                                         responseBuffer.substr(idx1+2, idx3-idx1-2)));

               //cout << responseBuffer.substr(idx2+2, idx1-idx2-2) << "=" <<responseBuffer.substr(idx1+2, idx3-idx1-2) << endl;
            }
            else break;
            idx2 = idx3;
        } while (true);

        return E_SUCCESS;
    }
}

#endif // HTTPXX_H_INCLUDED

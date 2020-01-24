#ifndef IOTXX_H_INCLUDED
#define IOTXX_H_INCLUDED

#include "httpxx.h"
using namespace http;

namespace iot {

const int RESULT_OK = 0;
const int BAD_REQUEST   = -400;
const int FORBIDDEN     = -403;
const int NOT_FOUND     = -404;
const int SERVER_ERROR  = -500;


const char HOST[] = "127.0.0.1";
const int PORT = 8080;



int lire_capteur(char* nomCapteur, float & valeurCapteur) {
    int ret = E_SUCCESS;

    string path = "~/in-cse/in-name/";
    path.append(nomCapteur);
    path.append("/DATA/la");

    Request aRequest = {"127.0.0.1", 8080, path, map<string,string>()};
    aRequest.Headers.insert(pair<string, string>("X-M2M-Origin","admin:admin"));
    aRequest.Headers.insert(pair<string, string>("Accept","application/json"));
    aRequest.Headers.insert(pair<string, string>("Connection","close"));
    Response aResponse;

    ret = doRequest(GET, aRequest, aResponse);

    if (ret == E_SUCCESS) {
        Object obj;
        obj.parse(aResponse.Body);
        string con = obj.get<Object>("m2m:cin").get<String>("con");

        int idx_start = con.find("val");
        int idx_end = con.find("/>");
        string val = con.substr(idx_start+5, idx_end-idx_start-7);
        valeurCapteur = atof(val.c_str());

        if (aResponse.StatusCode != 200)
            ret = - aResponse.StatusCode;
    }
    return ret;
}

int commander_actionneur(char* nomActionneur, char* nomCommand) {
    int ret = E_SUCCESS;

    string path = "~/in-cse/in-name/";
    path.append(nomActionneur);
    path.append("/COMMAND");

    Request aRequest = {"127.0.0.1", 8080, path, map<string,string>()};
    aRequest.Headers.insert(pair<string, string>("X-M2M-Origin","admin:admin"));
    aRequest.Headers.insert(pair<string, string>("Accept","application/json"));
    aRequest.Headers.insert(pair<string, string>("Content-Type","application/xml;ty=4"));
    //aRequest.Headers.insert(pair<string, string>("Connection","close"));

    aRequest.Body = "<m2m:cin xmlns:m2m=\"http://www.onem2m.org/xml/protocols\"><con>";
    aRequest.Body.append(nomCommand);
    aRequest.Body.append("</con></m2m:cin>\r\n");

    char bodyLength[16];
    sprintf(bodyLength,"%u",  aRequest.Body.length());
    aRequest.Headers.insert(pair<string, string>("Content-Length", bodyLength));

    Response aResponse;
    ret = doRequest(POST, aRequest, aResponse);

    if (ret == E_SUCCESS) {
        if (aResponse.StatusCode <200 || aResponse.StatusCode >= 300)
            ret = - aResponse.StatusCode;
    }
    return ret;
}

}

#endif // IOTXX_H_INCLUDED

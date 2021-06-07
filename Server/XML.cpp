//
// Created by sormocs on 6/6/21.
//

#include "XML.h"

XML* XML::instance = nullptr;

XML *XML::GetInstance() {
    if (instance == nullptr){
        instance = new XML;
    }
    return instance;
}

void XML::Builder() {

    std::string info = "HOLA";
    std::string towrite =
            "<?xml version\"1.0\"?>"
            "<ROOT>"
            "<GEN>"  +info+ "</GEN>"
            "</ROOT>";

    static const char* xml = towrite.c_str();
    doc.Parse(xml);
    doc.SaveFile(("../XML Files/GEN"+std::to_string(gennum)+".xml").c_str());
    gennum ++;

}

void XML::SetList(List *list) {

    genList = list;

}

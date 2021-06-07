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

std::string XML::GenBuilder(const std::string& info) {

    std::string towrite =
            "<GEN" + std::to_string(gennum) + ">"
            +info+
            "</GEN" + std::to_string(gennum) + ">";
    return towrite;
}

void XML::SetList(GenList *list) {

    genList = list;

}

std::string XML::infoMaker() {
    std::string genInfo = std::string();

    for (int i = 0; i < genList->At(gennum)->Length(); ++i) {
        genInfo +=
                "<SPEC" + std::to_string(i) + ">";
        for (int j = 0; j < genList->At(gennum)->At(i)->positions->Length(); ++j) {
            genInfo += std::to_string(genList->At(gennum)->At(i)->positions->At(j)->value) + " ";
        }
        genInfo +=
                "</SPEC" + std::to_string(i) + ">";
    }

    return genInfo;
}

void XML::Build() {
    std::string towrite = "<?xml version\"1.0\"?>"
                          "<ROOT>";

    while(gennum < genList->Length()){

        towrite += GenBuilder(infoMaker());

        gennum ++;
    }

    towrite +=
            "</ROOT>";

    printf("towrite %s", towrite.c_str());

    static const char* xml = towrite.c_str();
    doc.Parse(xml);
    doc.SaveFile(("../XML Files/GEN"+std::to_string(gennum)+".xml").c_str());
}

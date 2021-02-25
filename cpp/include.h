//
// Created by Mark Truluck on 1/9/21.
//

#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>

using namespace std;


class Attr {
public:

    Attr(string name, string type, bool owned, void* pvAttr)
            : name(name), type(type), owned(owned), pvAttr(pvAttr) {}

    virtual ~Attr() {
        if (!owned) return;

        if (type == "int") delete (int*) pvAttr;
        else if (type == "string") delete(string*) pvAttr;
        else throw string("Trying to delete unknown attribute type.");
    }

public:

    string name;
    string type;
    bool owned;
    void* pvAttr;
};

//typedef map<string, Attr*> FrameAttrs;

class FrameAttrs {
public:

    virtual ~FrameAttrs() {
        for (std::pair<std::string, Attr*> element : attribs) {
            delete element.second;
        }
    }

public:

    void add(string name, string type, bool owned, void* pvArg) {
        attribs.insert(std::pair<string,Attr*>(name,new Attr(name,type,owned,pvArg)));
    }

    void* get(string name) {
        std::map<string,Attr*>::iterator it;
        it = attribs.find(name);
        return it->second->pvAttr;
    }

    bool set(string name,void* pvNew) {
        std::map<string,Attr*>::iterator it;
        it = attribs.find(name);
        if (it == attribs.end()) {
            return false;
        }
        Attr* pAttr = it->second;
        assign(pAttr->type,it->second->pvAttr,pvNew);
        return true;
    }

    void assign(string type,void* pvTarget, void* pvSource) {
        if (type == "int") {
            *((int*) pvTarget) = *((int*) pvSource);
        } else if (type == "string") {
            *((string*) pvTarget) = *((string*) pvSource);
        }
    }

private:
    map<string, Attr*> attribs;
};

class FrameEvent {

public:

    FrameEvent(string msg, FrameAttrs* pParams)
        : msg(msg), pParams(pParams) {
    }

    string msg;
    FrameAttrs* pParams;
    void* ret;
};

#endif //INCLUDE_H

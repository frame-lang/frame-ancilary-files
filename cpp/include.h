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

class StateContext {

public:
    StateContext(FrameState state) : state(state), onStateStack(false) {

    }

    virtual ~StateContext() {
//            for (std::pair<std::string, Attr*> element : stateArgs) {
//                delete element.second;
//            }
    };

    FrameAttrs* getStateArgs() {
        return &stateArgs;
    }

    void addStateArg(string name, string type, bool owned, void* pvArg) {
        stateArgs.add(name,type,owned,pvArg);
    }

    void* getStateArg(string name) {
        return stateArgs.get(name);
    }

    bool setStateArg(string name,void* pvNew) {
        return stateArgs.set(name, pvNew);
    }

    FrameAttrs* getStateVars() {
        return &stateVars;
    }

    void addStateVar(string name, string type, bool owned, void* pvArg) {
        stateVars.add(name,type,owned,pvArg);
    }

    void* getStateVar(string name) {
        stateVars.get(name);
    }

    bool setStateVar(string name,void* pvNew) {
        return stateVars.set(name,pvNew);
    }

    FrameAttrs* getEnterArgs() {
        return &enterArgs;
    }

    void addEnterArg(string name, string type, bool owned, void* pvArg) {
        enterArgs.add(name,type,owned,pvArg);
    }

    bool setEnterArg(string name,void* pvNew) {
        return enterArgs.set(name,pvNew);
    }

    void* getEnterArg(string name) {
        enterArgs.get(name);
    }


    void setOnStateStack(bool val) {
        onStateStack = val;
    }

    bool isOnStateStack() {
        return onStateStack;
    }

public:

    FrameState state;

private:
    bool onStateStack;

    FrameAttrs stateArgs;
    FrameAttrs stateVars;
    FrameAttrs enterArgs;

};

#endif //INCLUDE_H

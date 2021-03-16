 var FrameEvent = function(message, parameters) {

    var that = {};

    that._message = message;
    that._parameters = parameters;
    that._return = null;

    return that;
};

var StateContext = function(state) {
	let that = {};

    let stateArgs = {};
    let stateVars = {};
    let enterArgs = {};

    that.addStateArg = function(name,value) {
        stateArgs[name] = value;
    }

    that.setStateArg = function(name,value) {
        stateArgs[name] = value;
    }

    that.getStateArg = function(name) {
        return stateArgs[name];
    }

    that.addStateVar = function(name,value) {
        stateVars[name] = value;
    }

    that.setStateVar = function(name,value) {
        stateVars[name] = value;
    }

    that.getStateVar = function(name) {
        return stateVars[name];
    }
  
    that.addEnterArg = function(name,value) {
        enterArgs[name] = value;
    }

    that.setEnterArg = function(name,value) {
        enterArgs[name] = value;
    }

    that.getEnterArg = function(name) {
        return enterArgs[name];
    }

    that.getEnterArgs = function(name) {
        return enterArgs;
    }

    return that;
};

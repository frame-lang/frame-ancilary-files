# ----------------------------------------- #

class FrameEvent:

    def __init__(self, message, parameters):
        self._message = message
        self._parameters = parameters
        self._return = None
        
# ----------------------------------------- #


class StateContext:

    def __init__(self, state):
        self.state = state
        self.stateArgs = {}
        self.stateVars = {}
        self.enterArgs = {}

    def addStateArg(self, name, value):
        self.stateArgs[name] = value

    def setStateArg(self, name, value):
        self.stateArgs[name] = value

    def getStateArg(self, name):
        return self.stateArgs[name]

    def addStateVar(self, name, value):
        self.stateVars[name] = value

    def setStateVar(self, name, value):
        self.stateVars[name] = value

    def getStateVar(self, name):
        return self.stateVars[name]

    def addEnterArg(self, name, value):
        self.enterArgs[name] = value

    def setEnterArg(self, name, value):
        self.enterArgs[name] = value

    def getEnterArg(self, name):
        return self.enterArgs[name]

    def getEnterArgs(self):
        return self.enterArgs
 

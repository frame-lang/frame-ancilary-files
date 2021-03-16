# ----------------------------------------- #

# -- FrameEvent.gd -- #

func _init(message, params):
	self.message = message
	self.params = params
	self.ret = null
	
var message = null
var params = null
var ret = null


        
# ----------------------------------------- #


# -- StateContext.gd -- #


func _init(state):
    self.state = state
    self.stateArgs = {}
    self.stateVars = {}
    self.enterArgs = {}

func addStateArg(name, value):
    self.stateArgs[name] = value

func setStateArg(name, value):
    self.stateArgs[name] = value

func getStateArg(name):
    return self.stateArgs[name]

func addStateVar(name, value):
    self.stateVars[name] = value

func setStateVar(name, value):
    self.stateVars[name] = value

func getStateVar(name):
    return self.stateVars[name]

func addEnterArg(name, value):
    self.enterArgs[name] = value

func setEnterArg(name, value):
    self.enterArgs[name] = value

func getEnterArg(name):
    return self.enterArgs[name]

func getEnterArgs():
    return self.enterArgs

interface FrameState { 
    void call(FrameEvent e); 
}
    
class FrameEvent {
    FrameEvent(String message, HashMap<String,Object> params) {
        this.message = message;
        this.params = params;
    }
    
    String message;
    HashMap params;
    Object ret;
}
    

class StateContext {
	public StateContext(FrameState state) {
		this.state = state;
	}

	public void addStateArg(String name, Object value) {
		stateArgs.put(name,value);
	}

	public void setStateArg(String name, Object value) {
		stateArgs.put(name,value);
	}
	
	public Object getStateArg(String name) {
		return stateArgs.get(name);
	}
	
	public void addStateVar(String name, Object value) {
		stateVars.put(name,value);
	}

	public void setStateVar(String name, Object value) {
		stateVars.put(name,value);
	}
	
	public Object getStateVar(String name) {
		return stateVars.get(name);
	}

	public void addEnterArg(String name, Object value) {
		enterArgs.put(name,value);
	}

	public void setEnterArg(String name, Object value) {
		enterArgs.put(name,value);
	}
	
	public Object getEnterArg(String name) {
		return enterArgs.get(name);
	}
	
	public HashMap<String,Object> getEnterArgs() {
		return enterArgs;
	}

	HashMap<String,Object> stateArgs = new HashMap<String,Object>();
	HashMap<String,Object> stateVars = new HashMap<String,Object>();
	HashMap<String,Object> enterArgs = new HashMap<String,Object>();
	public FrameState state;

}

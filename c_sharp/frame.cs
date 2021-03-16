
public class FrameEvent {
	public FrameEvent(string message, Dictionary<string,object> parameters) {
		this._message = message;
		this._parameters = parameters;
	}
	public string _message;
	public Dictionary<string,Object> _parameters;
	public Object _return;
}

public delegate void FrameState(FrameEvent e);

public class StateContext {
	public StateContext(FrameState state) {
		this.state = state;
	}

	public void addStateArg(string name, object value) {
		stateArgs.Add(name,value);
	}

	public void setStateArg(string name, object value) {
		stateArgs[name] = value;
	}
	
	public object getStateArg(string name) {
		return stateArgs[name];
	}
	
	public void addStateVar(string name, object value) {
		stateVars.Add(name,value);
	}

	public void setStateVar(string name, object value) {
		stateVars[name] = value;
	}
	
	public object getStateVar(string name) {
		return stateVars[name];
	}

	public void addEnterArg(string name, object value) {
		enterArgs.Add(name,value);
	}

	public void setEnterArg(string name, object value) {
		enterArgs[name] = value;
	}
	
	public object getEnterArg(string name) {
		return enterArgs[name];
	}
	
	public Dictionary<string,object> getEnterArgs() {
		return enterArgs;
	}

	Dictionary<string,object> stateArgs = new Dictionary<string, object>();
	Dictionary<string,object> stateVars = new Dictionary<string, object>();
	Dictionary<string,object> enterArgs = new Dictionary<string, object>();
	public FrameState state;

}

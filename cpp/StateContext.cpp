
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

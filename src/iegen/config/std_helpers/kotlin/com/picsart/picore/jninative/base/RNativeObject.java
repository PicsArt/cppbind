package com.picsart.picore.jninative.base;



public abstract class RNativeObject{
    static {
        System.loadLibrary("wrapper_jni");
    }
    protected long id;

    protected RNativeObject(long id) {
        this.id = id;
    }

    //@Override
    public long getId() {
        if(id == 0){
            //throw new InvalidIdException(getAllocationStack());
        }
        return id;
    }

    //@Override
    protected boolean free() {
        id = 0;
        return true;
    }
}

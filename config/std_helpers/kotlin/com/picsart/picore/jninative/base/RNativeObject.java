package com.picsart.picore.jninative.base;
public class StringArray extends Array<String> {}



public abstract class RNativeObject{
	protected long id;

	protected RNativeObject(long id=0) {
		this.id = id;
	}

	@Override
	public long getId() {
		if(id == 0){
			//throw new InvalidIdException(getAllocationStack());
		}
		return id;
	}

	@Override
	protected boolean free() {
		id = 0;
		return true;
	}
}

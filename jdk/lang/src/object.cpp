/**************************************************
* File: object.cc.
* Desc: Implementation of the native calls for the lang_Object class.
* Module: AkraLog : JavaKit.
* Rev: 20 aout 1996 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <native/nativity.h>
#include <vm/jmachine.h>
#include <vm/execFrame.h>
#include <vm/jvInstance.h>
#include <vm/stacks.h>
#include <vm/valueTypes.h>
#include <threader/synchro.h>


// Function declarations.
Define_JavaNative(lang, Object, getClass);
Define_JavaNative(lang, Object, hashCode);
Define_JavaNative(lang, Object, clone);
Define_JavaNative(lang, Object, notify);
Define_JavaNative(lang, Object, notifyAll);
Define_JavaNative(lang, Object, wait);


//    public final native Class getClass();
Implement_JavaNative(lang, Object, getClass)
{
    JVInstance *mySelf= NULL, *anInstance= NULL;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	mySelf= tmpValue->extractInstance();
    }

    if (mySelf != NULL) {
	anInstance= mySelf->category()->getJavaEquivalent(machine);
    }

    if (anInstance == NULL) {
	callFrame->returnInstance(JVInstance::globalNullObject());
    }
    else {
	callFrame->returnInstance(anInstance);
    }
    return 0;
}


//    public native int hashCode();
Implement_JavaNative(lang, Object, hashCode)
{
    JVInstance *self;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
     }

    callFrame->returnInteger((unsigned int)self);
    return 0;
}


//    protected native Object clone() throws CloneNotSupportedException;
Implement_JavaNative(lang, Object, clone)
{
    return 0;
}

//    public final native void notify();
Implement_JavaNative(lang, Object, notify)
{
    JVInstance *self;
    JVRunValue *tmpValue;
    JVSynchronizer *theSynchro;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
     }

    if ((theSynchro= self->getSynchronizer()) != NULL) {
	theSynchro->declareSatisfied();
    }
    return 0;
}


//    public final native void notifyAll();
Implement_JavaNative(lang, Object, notifyAll)
{
    JVInstance *self;
    JVRunValue *tmpValue;
    JVSynchronizer *theSynchro;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
     }

    if ((theSynchro= self->getSynchronizer()) != NULL) {
	theSynchro->declareSatisfiedToAll();
    }
    return 0;
}

//    public final native void wait(long timeout) throws InterruptedException;
Implement_JavaNative(lang, Object, wait)
{
    JVInstance *self;
    JVRunValue *tmpValue;
    JVSynchronizer *theSynchro;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
     }

    if ((theSynchro= self->getSynchronizer()) == NULL) {
	theSynchro= machine->addSynchroTo(self);
    }

    if (theSynchro != NULL) {
	unsigned long lowWord, highWord;

	tmpValue= callFrame->getLocalValue(1);
	if (tmpValue != NULL) {
	    highWord= tmpValue->extractInteger();
	}
	tmpValue= callFrame->getLocalValue(2);
	if (tmpValue != NULL) {
	    lowWord= tmpValue->extractInteger();
	}
	// ATTN-971111 [HD]: Must use a real 'long' value !
	theSynchro->waitWithTimeout(lowWord);
    }
    return 0;
}


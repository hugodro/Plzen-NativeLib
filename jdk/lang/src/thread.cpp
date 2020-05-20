/**************************************************
* File: thread.cc.
* Desc: Implementation of the native calls for the lang_Thread class.
* Module: AkraLog : JavaKit.
* Rev: 18 novembre 1996 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <native/nativity.h>
#include <vm/jvInstance.h>
#include <vm/machineSupport.h>
#include <vm/jmachine.h>
#include <vm/execFrame.h>
#include <vm/jvThread.h>


static JVVariable *privateInfo= NULL;

// final static fields definitions:
enum j_l_Thread_Finals { MIN_PRIORITY= 1, NORM_PRIORITY= 5, MAX_PRIORITY= 10};

// Function declarations.
Define_JavaNative(lang, Thread, currentThread);
Define_JavaNative(lang, Thread, yield);
Define_JavaNative(lang, Thread, sleep);
Define_JavaNative(lang, Thread, start);
Define_JavaNative(lang, Thread, isAlive);
Define_JavaNative(lang, Thread, countStackFrames);
Define_JavaNative(lang, Thread, setPriority0);
Define_JavaNative(lang, Thread, stop0);
Define_JavaNative(lang, Thread, suspend0);
Define_JavaNative(lang, Thread, resume0);

// ATTN: All JVAbstractThread have been casted to JVThread, just until there is a real
// implementation of JVThread.

//     public static native Thread currentThread()
// Must send an ID to the current executing thread.
Implement_JavaNative(lang, Thread, currentThread)
{
    JVThread *aThread;
    JVInstance *anInstance= NULL;
    unsigned int threadID;

    aThread= (JVThread *)machine->getActiveThread();
    if (aThread != NULL) {
	anInstance= aThread->getJavaDual();
    }
    callFrame->returnInstance((anInstance != NULL) ? anInstance : machine->theNullObject());
    return 0;
}


//	    public static native void yield();
Implement_JavaNative(lang, Thread, yield)
{
    JVThread *aThread;

    aThread= (JVThread *)machine->getActiveThread();
    aThread->yield();

    return 0;
}


//	public static native void sleep(long millis) throws InterruptedException;
Implement_JavaNative(lang, Thread, sleep)
{
    JVThread *aThread;
    JVRunValue *tmpValue;
    long millis;

    aThread= (JVThread *)machine->getActiveThread();
    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	millis= tmpValue->extractInteger();
     }

    aThread->sleep(millis);

    return 0;
}


/* Start assigns a stopped, free JVThread to a java_lang_Thread instance, making the necessary
* setup of the JVThread.   It then does a runMachine in a system thread.  */

//     public synchronized native void start().
Implement_JavaNative(lang, Thread, start)
{
    JVInstance *self;
    JVThread *newThread;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
     }

    if (privateInfo == NULL) {
	privateInfo= machine->getFieldOfClass(self->category(), "PrivateInfo");
    }
    if (privateInfo != NULL) {
	JVThread *aThread;

	aThread= (JVThread *)machine->getThreadForID((unsigned int)self->getField(privateInfo));

	if (aThread == NULL) {
	    // No internal thread exists already.  This should not happen in the normal
	    // implementation of java.lang.Thread.init (that calls setPriority0 at
	    // creation).  For now, we act like if it is ok, and create a new thread.

	    JVRunValue *ioValue= new JVRunValue(TYPE_BASIC);

		// TMPTMP: Get the thread through the JVMachine.
	    aThread= (JVThread *)machine->getFreeThread();
	    if (aThread != NULL) {
		ioValue->setValue((void *)aThread->getID());
		self->putField(*ioValue, privateInfo);
		aThread->setJavaDual(self);
		aThread->start();
	    }
	}
	else {
	    aThread->start();
	}
    }
    return 0;
}


//    public final native boolean isAlive();
Implement_JavaNative(lang, Thread, isAlive)
{
    JVThread *aThread;
    JVInstance *self;
    JVRunValue *tmpValue;
    bool result;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
     }
    if (privateInfo == NULL) {
	privateInfo= machine->getFieldOfClass(self->category(), "PrivateInfo");
    }
    if (privateInfo != NULL) {
	aThread= (JVThread *)machine->getThreadForID((unsigned int)self->getField(privateInfo));
	if (aThread != NULL) {
	    result= aThread->isAlive();
	}
    }
    callFrame->returnInteger((unsigned int)result);
    return 0;
}


//    public native int countStackFrames();
Implement_JavaNative(lang, Thread, countStackFrames)
{
    // For now, a thread has only one stack.
    callFrame->returnInteger(1);
    return 0;
}


//    private native void setPriority0(int newPriority);
Implement_JavaNative(lang, Thread, setPriority0)
{
    JVThread *aThread;
    JVInstance *self;
    JVRunValue *tmpValue;
    unsigned int newPriority;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	newPriority= tmpValue->extractInteger();
    }

    if (privateInfo == NULL) {
	privateInfo= machine->getFieldOfClass(self->category(), "PrivateInfo");
    }
    if (privateInfo != NULL) {
	aThread= (JVThread *)machine->getThreadForID((unsigned int)self->getField(privateInfo));
	if (aThread != NULL) {
	    aThread->setPriority(newPriority);
	}
	else {
	    // No internal thread exists already.  This happens the first time setPriority0 is called,
	    // from java.lang.Thread.init.
	    JVRunValue *ioValue= new JVRunValue(TYPE_BASIC);

		// TMPTMP: Get the thread through the JVMachine.
	    aThread= (JVThread *)machine->getFreeThread();
	    if (aThread != NULL) {
		ioValue->setValue((void *)aThread->getID());
		self->putField(*ioValue, privateInfo);
		aThread->setJavaDual(self);
		aThread->setPriority(newPriority);
	    }
	}
    }
    return 0;
}


//    private native void stop0(Object o);
Implement_JavaNative(lang, Thread, stop0)
{
    JVThread *aThread;
    JVInstance *self, *raisedObject;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	raisedObject= tmpValue->extractInstance();
    }

    if (privateInfo == NULL) {
	privateInfo= machine->getFieldOfClass(self->category(), "PrivateInfo");
    }
    if (privateInfo != NULL) {
	aThread= (JVThread *)machine->getThreadForID((unsigned int)self->getField(privateInfo));
	if (aThread != NULL) {
	    // ATTENTION: What is the raised object used for ?
	    aThread->exit();
	}
    }
   return 0;
}


//    private native void suspend0();
Implement_JavaNative(lang, Thread, suspend0)
{
    JVThread *aThread;
    JVInstance *self, *raisedObject;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	raisedObject= tmpValue->extractInstance();
    }

    if (privateInfo == NULL) {
	privateInfo= machine->getFieldOfClass(self->category(), "PrivateInfo");
    }
    if (privateInfo != NULL) {
	aThread= (JVThread *)machine->getThreadForID((unsigned int)self->getField(privateInfo));
	if (aThread != NULL) {
	    aThread->suspend();
	}
    }
    return 0;	    // MOD-970520 [HD]: Was missing, pour NT.
}


//    private native void resume0();
Implement_JavaNative(lang, Thread, resume0)
{
    JVThread *aThread;
    JVInstance *self, *raisedObject;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	raisedObject= tmpValue->extractInstance();
    }

    if (privateInfo == NULL) {
	privateInfo= machine->getFieldOfClass(self->category(), "PrivateInfo");
    }
    if (privateInfo != NULL) {
	aThread= (JVThread *)machine->getThreadForID((unsigned int)self->getField(privateInfo));
	if (aThread != NULL) {
	    aThread->resume();
	}
    }
    return 0;	    // MOD-970520 [HD]: Was missing, pour NT.
}



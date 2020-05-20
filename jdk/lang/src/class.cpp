/**************************************************
* File: class.cc.
* Desc: Implementation of the native calls for the java.lang.Class class.
* Module: AkraLog : JavaKit.
* Rev: 4 novembre 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#if defined(_WIN32) || defined(__linux__)
// #include <string.h>
#include <string>
#endif
#include <native/nativity.h>
#include <vm/jmachine.h>
#include <vm/execFrame.h>
#include <vm/jvInstance.h>
#include <vm/stacks.h>
#include <vm/stringSupport.h>
#include <vm/classManager.h>
#include <vm/runtimeDefs.h>



// Function declarations.
//    JDK 1.0:
Define_JavaNative(lang, Class, forName);
Define_JavaNative(lang, Class, newInstance);
Define_JavaNative(lang, Class, getName);
Define_JavaNative(lang, Class, getSuperclass);
Define_JavaNative(lang, Class, getInterfaces);
Define_JavaNative(lang, Class, getClassLoader);
Define_JavaNative(lang, Class, isInterface);
//    JDK 1.1:
Define_JavaNative(lang, Class, isInstance);
Define_JavaNative(lang, Class, isAssignableFrom);
Define_JavaNative(lang, Class, isArray);
Define_JavaNative(lang, Class, isPrimitive);
Define_JavaNative(lang, Class, getComponentType);
Define_JavaNative(lang, Class, getModifiers);
Define_JavaNative(lang, Class, getSigners);
Define_JavaNative(lang, Class, setSigners);
Define_JavaNative(lang, Class, getPrimitiveClass);
Define_JavaNative(lang, Class, getFields0);
Define_JavaNative(lang, Class, getMethods0);
Define_JavaNative(lang, Class, getConstructors0);
Define_JavaNative(lang, Class, getField0);
Define_JavaNative(lang, Class, getMethod0);
Define_JavaNative(lang, Class, getConstructor0);


// Function implementations.
//    public static native Class forName(String className) throws ClassNotFoundException;
Implement_JavaNative(lang, Class, forName)
{   
    JVInstance *className;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	className= tmpValue->extractInstance();
     }

    if (className != JVInstance::globalNullObject()) {
	ClassFile *aClass;
	unsigned int nameLength, i;
	char *nameBuffer;

	StringSupport::mapStringToNarrowArray(className, &nameBuffer);
	if (nameBuffer != NULL) {
	    nameLength= strlen(nameBuffer);
	    for (i= 0; i < nameLength; i++) {
		if (nameBuffer[i] == '.') nameBuffer[i]= FILE_SEPARATOR;
	    }
    
		// Find the class by its name.
	    if ((aClass= machine->getClassFile(nameBuffer)) != NULL) {
		    // If it is found, get its java equivalent instance.
		callFrame->returnInstance(aClass->getJavaEquivalent(machine));
		delete[] nameBuffer;
		return 0;	// Warning: quick exit.
	    }
	    delete[] nameBuffer;
	}
    }
    callFrame->returnInstance(JVInstance::globalNullObject());
    return 0;
}


//    public native Object newInstance() 
Implement_JavaNative(lang, Class, newInstance)
{
    JVInstance *mySelf= NULL, *anInstance;
    JVRunValue *tmpValue;
    ClassManager *classManager;
    ClassFile *realClass;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	mySelf= tmpValue->extractInstance();
    }

    if (mySelf != NULL) {
	classManager= machine->getClassManager();
	if ((realClass= classManager->findClassByJavaEquiv(mySelf)) != NULL) {
	    JVMethod *initMethod;
	    char aBuffer[1024];

	    anInstance= machine->createObject(realClass);

	    realClass->getName(aBuffer);
	    initMethod= machine->getMethodInClass("<init>", "()V", aBuffer);
	
	    if (initMethod != NULL) {
		machine->runMethodWithArguments(anInstance, initMethod, 0, NULL);
	    }
	}
	else anInstance= JVInstance::globalNullObject();
    }
    else anInstance= JVInstance::globalNullObject();

    callFrame->returnInstance(anInstance);
    return 0;
}


//    public native String getName();
Implement_JavaNative(lang, Class, getName)
{
    JVInstance *mySelf= NULL, *className;
    JVRunValue *tmpValue;
    ClassManager *classManager;
    ClassFile *realClass;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	mySelf= tmpValue->extractInstance();
    }

    if (mySelf != NULL) {
	classManager= machine->getClassManager();
	if ((realClass= classManager->findClassByJavaEquiv(mySelf)) != NULL) {
	    unsigned int nameLength, i;
	    char aBuffer[1024];

	    realClass->getName(aBuffer);
	    nameLength= strlen(aBuffer);
	    for (i= 0; i < nameLength; i++) {
		if (aBuffer[i] == '/') aBuffer[i]= '.';
	    }
	    className= machine->createStringFromNarrowArray(aBuffer);
	}
	else className= JVInstance::globalNullObject();
    }

    callFrame->returnInstance(className);
    return 0;
}


//    public native Class getSuperclass();
Implement_JavaNative(lang, Class, getSuperclass)
{
    JVInstance *mySelf= NULL, *anInstance= NULL;
    JVRunValue *tmpValue;
    ClassManager *classManager;
    ClassFile *realClass, *superClass;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	mySelf= tmpValue->extractInstance();
    }

    if (mySelf != NULL) {
	classManager= machine->getClassManager();
	if ((realClass= classManager->findClassByJavaEquiv(mySelf)) != NULL) {
	    if ((superClass= realClass->getSuperClass()) != NULL) {
		anInstance= superClass->getJavaEquivalent(machine);
	    }
	}
    }
    if (anInstance == NULL) {
	callFrame->returnInstance(JVInstance::globalNullObject());
    }
    else {
	callFrame->returnInstance(anInstance);
    }
    return 0;
}


//    public native Class getInterfaces()[];
Implement_JavaNative(lang, Class, getInterfaces)
{
// TODO.
    return 0;
}


//    public native ClassLoader getClassLoader();
Implement_JavaNative(lang, Class, getClassLoader)
{
// TODO.
    return 0;
}


//    public native boolean isInterface();
Implement_JavaNative(lang, Class, isInterface)
{
// TODO.
    return 0;
}



// Natives from JDK 1.1.

//    public native boolean isInstance(Object obj);
Implement_JavaNative(lang, Class, isInstance)
{
// TODO.
    return 0;
}


//    public native boolean isAssignableFrom(Class cls);
Implement_JavaNative(lang, Class, isAssignableFrom)
{
// TODO.
    return 0;
}


//    public native boolean isArray();
Implement_JavaNative(lang, Class, isArray)
{
// TODO.
    return 0;
}


//    public native boolean isPrimitive();
Implement_JavaNative(lang, Class, isPrimitive)
{
// TODO.
    return 0;
}


//    public native Class getComponentType();
Implement_JavaNative(lang, Class, getComponentType)
{
// TODO.
    return 0;
}


//    public native int getModifiers();
Implement_JavaNative(lang, Class, getModifiers)
{
// TODO.
    return 0;
}


//    public native Object[] getSigners();
Implement_JavaNative(lang, Class, getSigners)
{
// TODO.
    return 0;
}


//    native void setSigners(Object[] signers);
Implement_JavaNative(lang, Class, setSigners)
{
// TODO.
    return 0;
}


//    static native Class getPrimitiveClass(String name);
Implement_JavaNative(lang, Class, getPrimitiveClass)
{
// TODO.
    return 0;
}


//    private native Field[] getFields0(int which);
Implement_JavaNative(lang, Class, getFields0)
{
// TODO.
    return 0;
}


//    private native Method[] getMethods0(int which);
Implement_JavaNative(lang, Class, getMethods0)
{
// TODO.
    return 0;
}


//    private native Constructor[] getConstructors0(int which);
Implement_JavaNative(lang, Class, getConstructors0)
{
// TODO.
    return 0;
}


//    private native Field getField0(String name, int which);
Implement_JavaNative(lang, Class, getField0)
{
// TODO.
    return 0;
}


//    private native Method getMethod0(String name, Class[] parameterTypes, int which);
Implement_JavaNative(lang, Class, getMethod0)
{
// TODO.
    return 0;
}


//    private native Constructor getConstructor0(Class[] parameterTypes, int which);
Implement_JavaNative(lang, Class, getConstructor0)
{
// TODO.
    return 0;
}



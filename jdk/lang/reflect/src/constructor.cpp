/**************************************************
* File: constructor.cc.
* Desc: Implementation of the java.lang.reflect.Constructor native methods.
* Module: Plzen : NativeLib.
* Rev: 15 janvier 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <native/nativity.h>
#include "constructor.h"


JVVariable *java_lang_reflect_Constructor::clazzField;
JVVariable *java_lang_reflect_Constructor::slotField;
boolean java_lang_reflect_Constructor::mustFetchDict= true;

boolean java_lang_reflect_Constructor::fetchDictionary(JVMachine *aMachine, ClassFile *aClass)
{
    if (mustFetchDict) {
	clazzField= aMachine->getFieldOfClass(aClass, "clazz");
	slotField= aMachine->getFieldOfClass(aClass, "slot");
	mustFetchDict= false;
    }

    return ((clazzField != NULL) && (slotField != NULL));
}


java_lang_reflect_Constructor::java_lang_reflect_Constructor(JVInstance *anInstance, JVMachine *aMachine)
{
    javaEquiv= anInstance;
    if (mustFetchDict) {
	if (!fetchDictionary(aMachine, javaEquiv->category())) {
	    // ATTN: Must throw an error.
	}
    }
}


JVInstance *java_lang_reflect_Constructor::get_this(void)
{
    return javaEquiv;
}


JVInstance *java_lang_reflect_Constructor::get_clazz(void)
{
    return (JVInstance *)javaEquiv->getField(clazzField);
}


int java_lang_reflect_Constructor::get_slot(void)
{
    return (int)javaEquiv->getField(slotField);
}


// Function declarations.
Define_JavaNative(lang_reflect, Constructor, getModifiers);
Define_JavaNative(lang_reflect, Constructor, newInstance);

//    public native int getModifiers();
Implement_JavaNative(lang_reflect, Constructor, getModifiers)
{
    JVRunValue *tmpValue;
    unsigned int result= 0;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	ClassFile *realClass;
	java_lang_reflect_Constructor constructor(tmpValue->extractInstance(), machine);

	if ((realClass= machine->getClassManager->findClassByJavaEquiv(constructor.get_clazz())) != NULL) {
	    unsigned int slot= constructor.get_slot();
	    if (slot < realClass->nbrMethods()) {
		result= realClass->getMethod(slot)->getAccessFlags();
	    }
	}
    }
    callFrame->returnInteger(result);

    return 0;
}


//    public native Object newInstance(Object[] initargs)
Implement_JavaNative(lang_reflect, Constructor, newInstance)
{
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	ClassFile *realClass;
	JVInstanceArray *argsArray;
	java_lang_reflect_Constructor constructor(tmpValue->extractInstance(), machine);

	if ((realClass= machine->getClassManager->findClassByJavaEquiv(constructor.get_clazz())) != NULL) {
	    if (!realClass->isAbstract()) {
		MethodInfo *methodInfo= NULL;
		unsigned int slot= constructor.get_slot();

		if (slot < realClass->nbrMethods()) {
		    methodInfo= realClass->getMethod(slot)->getAccessFlags();
		}
		else {
		    // ATTN: Throw some internal error.
		}

		// ATTN: Check for access rights, throw IllegalAccessException if can't use it.

		tmpValue= callFrame->getLocalValue(1);
		if (tmpValue != NULL) {
		    argsArray= (JVInstanceArray *)tmpValue->extractInstance();
		}
		if ((realMethod= methodInfo->resolve(machine->getClassManager())) != NULL) {
		    if (argsArray->nbrElements == realMethod->argumentCount()) {
			// RENDU ICI.			
		    }
		    else {
			// ATTN: Throw an IllegalArgumentException.
		    }
		}
		else {
		    // ATTN: Throw an internal error: NoSuchMethod.
		}

/*
A new instance of the constructor's declaring class is created, and its fields are initialized to their default initial values.

For each actual parameter in the supplied initargs array:

If the corresponding formal parameter has a primitive type, an unwrapping conversion is attempted to convert the object value to a value of the primitive type. If this attempt fails, the creation throws an IllegalArgumentException.

If, after possible unwrapping, the parameter value cannot be converted to the corresponding formal parameter type by an identity or widening conversion, the creation throws an IllegalArgumentException.

Control transfers to the underlying constructor to initialize the new instance. If the constructor completes abruptly by throwing an exception, the exception is placed in an InvocationTargetException and thrown in turn to the caller of newInstance.

If the constructor completes normally, returns the newly created and initialized instance.

Throws: _IllegalAccessException_ if the underlying constructor is inaccessible.
Throws: _IllegalArgumentException_ if the number of actual and formal parameters differ, or if an unwrapping conversion fails.
Throws: _InstantiationException_ if the class that declares the underlying constructor represents an abstract class.
Throws: _InvocationTargetException_ if the underlying constructor throws an exception.
*/
	    }
	    else {
		// ATTN: Throw an InstantiationException.
	    }
	}
    }

    return 0;
}


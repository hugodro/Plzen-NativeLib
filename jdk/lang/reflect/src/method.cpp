/**************************************************
* File: method.cc.
* Desc: Implementation of the java.lang.reflect.Method native methods.
* Module: Plzen : NativeLib.
* Rev: 15 janvier 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <native/nativity.h>
#include "method.h"

JVVariable *java_lang_reflect_Method::clazzField;
JVVariable *java_lang_reflect_Method::slotField;
boolean java_lang_reflect_Method::mustFetchDict= true;

boolean java_lang_reflect_Method::fetchDictionary(JVMachine *aMachine, ClassFile *aClass)
{
    if (mustFetchDict) {
	clazzField= aMachine->getFieldOfClass(aClass, "clazz");
	slotField= aMachine->getFieldOfClass(aClass, "slot");
	mustFetchDict= false;
    }

    return ((clazzField != NULL) && (slotField != NULL));
}


java_lang_reflect_Method::java_lang_reflect_Method(JVInstance *anInstance, JVMachine *aMachine)
{
    javaEquiv= anInstance;
    if (mustFetchDict) {
	if (!fetchDictionary(aMachine, javaEquiv->category())) {
	    // ATTN: Must throw an error.
	}
    }
}


JVInstance *java_lang_reflect_Method::get_this(void)
{
    return javaEquiv;
}


JVInstance *java_lang_reflect_Method::get_clazz(void)
{
    return (JVInstance *)javaEquiv->getField(clazzField);
}


int java_lang_reflect_Method::get_slot(void)
{
    return (int)javaEquiv->getField(slotField);
}


// Function declarations.
Define_JavaNative(lang_reflect, Method, getModifiers);
Define_JavaNative(lang_reflect, Method, invoke);


//    public native int getModifiers();
Implement_JavaNative(lang_reflect, Method, getModifiers)
{
    JVRunValue *tmpValue;
    unsigned int result= 0;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	ClassFile *realClass;
	java_lang_reflect_Method method(tmpValue->extractInstance(), machine);

	if ((realClass= machine->getClassManager->findClassByJavaEquiv(method.get_clazz())) != NULL) {
	    unsigned int slot= method.get_slot();
	    if (slot < realClass->nbrMethods()) {
		result= realClass->getMethod(slot)->getAccessFlags();
	    }
	}
    }
    callFrame->returnInteger(result);

    return 0;
}


//    public native Object invoke(Object obj, Object[] args)
Implement_JavaNative(lang_reflect, Method, invoke)
{
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	ClassFile *realClass;
	JVInstanceArray *argsArray;
	java_lang_reflect_Method method(tmpValue->extractInstance(), machine);

	if ((realClass= machine->getClassManager->findClassByJavaEquiv(method.get_clazz())) != NULL) {
	    if (!realClass->isAbstract()) {
		MethodInfo *methodInfo= NULL;

		if (method.get_slot() < realClass->nbrMethods()) {
		    methodInfo= realClass->getMethod(method.get_slot())->getAccessFlags();
		}
		else {
		    // ATTN: Throw some internal error.
		}

		// ATTN: Check for access rights, throw IllegalAccessException if can't use it.

		if ((realMethod= methodInfo->resolve(machine->getClassManager())) != NULL) {
		    tmpValue= callFrame->getLocalValue(2);
		    if (tmpValue != NULL) {
			argsArray= (JVInstanceArray *)tmpValue->extractInstance();
		    }

		    if (argsArray->nbrElements == realMethod->argumentCount()) {
			void *argBlock;
			unsigned int totalArgsInBlock;
			
			totalArgsInBlock= argsArray->nbrElements + ((realMethod->isStatic()) ? 0 : 1)

			if (totalArgsInBlock > 0) {
			    argBlock= new void*[totalArgsInBlock];
			    if (argsArray->nbrElements > 0) {
				JVTypeDefinition **methodTyping;
				unsigned int i;

	// RENDU ICI.
				methodTyping= realMethod->getTyping();
				for (i= 0; i < argsArray->nbrElements; i++) {
				    if (methodTyping[i+1]->metaType() == TYPE_BASIC) {
					anArg= argsArray->getElement(i);
					if (anArg->vectorialType() == TYPE_INSTANCE) {
					    // Must check if the class object is one of the primitive types.
					}
					else break;
				    }
				    else if (methodTyping[i+1]->metaType() == TYPE_CLASS) {
				    }
				    else if (methodTyping[i+1]->metaType() == TYPE_ARRAY) {
				    }
				}
				if (i != argsArray->nbrElements) {
				    // ATTN: Throw an IllegalArgumentException.
				}
			    }
			}


			if (realMethod->isStatic()) {
			}
			else {
			    JVInstance *receiver;

			    tmpValue= callFrame->getLocalValue(1);
			    if (tmpValue != NULL) {
				receiver= tmpValue->extractInstance();
			    }

			}

		    }
		    else {
			// ATTN: Throw an IllegalArgumentException.
		    }
		}
		else {
		    // ATTN: Throw an internal error: NoSuchMethod.
		}
	    }
	    else {
		// ATTN: Throw an InstantiationException.
	    }
	}
    }

    return 0;
}


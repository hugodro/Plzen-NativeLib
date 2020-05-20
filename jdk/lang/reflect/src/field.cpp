/**************************************************
* File: field.cc.
* Desc: Implementation of the java.lang.reflect.Field native methods.
* Module: Plzen : NativeLib.
* Rev: 15 janvier 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <native/nativity.h>
#include "field.h"

JVVariable *java_lang_reflect_Field::clazzField;
JVVariable *java_lang_reflect_Field::slotField;
boolean java_lang_reflect_Field::mustFetchDict= true;

boolean java_lang_reflect_Field::fetchDictionary(JVMachine *aMachine, ClassFile *aClass)
{
    if (mustFetchDict) {
	clazzField= aMachine->getFieldOfClass(aClass, "clazz");
	slotField= aMachine->getFieldOfClass(aClass, "slot");
	mustFetchDict= false;
    }

    return ((clazzField != NULL) && (slotField != NULL));
}


java_lang_reflect_Field::java_lang_reflect_Field(JVInstance *anInstance, JVMachine *aMachine)
{
    javaEquiv= anInstance;
    if (mustFetchDict) {
	if (!fetchDictionary(aMachine, javaEquiv->category())) {
	    // ATTN: Must throw an error.
	}
    }
}


JVInstance *java_lang_reflect_Field::get_this(void)
{
    return javaEquiv;
}


JVInstance *java_lang_reflect_Field::get_clazz(void)
{
    return (JVInstance *)javaEquiv->getField(clazzField);
}


int java_lang_reflect_Field::get_slot(void)
{
    return (int)javaEquiv->getField(slotField);
}



// Function declarations.
Define_JavaNative(lang_reflect, Field, getModifiers);
Define_JavaNative(lang_reflect, Field, get);
Define_JavaNative(lang_reflect, Field, getBoolean);
Define_JavaNative(lang_reflect, Field, getByte);
Define_JavaNative(lang_reflect, Field, getShort);
Define_JavaNative(lang_reflect, Field, getInt);
Define_JavaNative(lang_reflect, Field, getLong);
Define_JavaNative(lang_reflect, Field, getFloat);
Define_JavaNative(lang_reflect, Field, getDouble);
Define_JavaNative(lang_reflect, Field, set);
Define_JavaNative(lang_reflect, Field, setBoolean);
Define_JavaNative(lang_reflect, Field, setByte);
Define_JavaNative(lang_reflect, Field, setChar);
Define_JavaNative(lang_reflect, Field, setShort);
Define_JavaNative(lang_reflect, Field, setInt);
Define_JavaNative(lang_reflect, Field, setLong);
Define_JavaNative(lang_reflect, Field, setFloat);
Define_JavaNative(lang_reflect, Field, setDouble);


//    public native int getModifiers();
Implement_JavaNative(lang_reflect, Field, getModifiers)
{
    JVRunValue *tmpValue;
    unsigned int result= 0;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	ClassFile *realClass;
	java_lang_reflect_Field field(tmpValue->extractInstance(), machine);

	if ((realClass= machine->getClassManager->findClassByJavaEquiv(field.get_clazz())) != NULL) {
	    unsigned int slot= field.get_slot();
	    if (slot < realClass->nbrMethods()) {
		result= realClass->getMethod(slot)->getAccessFlags();
	    }
	}
    }
    callFrame->returnInteger(result);

    return 0;
}


//    public native Object get(Object obj)
Implement_JavaNative(lang_reflect, Field, get)
{
    JVRunValue *tmpValue;
    unsigned int result= 0;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	ClassFile *realClass;
	java_lang_reflect_Field field(tmpValue->extractInstance(), machine);

	if ((realClass= machine->getClassManager->findClassByJavaEquiv(field.get_clazz())) != NULL) {
	    unsigned int slot= field.get_slot();
	    if (slot < realClass->nbrMethods()) {
		result= realClass->getMethod(slot)->getAccessFlags();
	    }
	}
    }
    callFrame->returnInteger(result);

    return 0;
}


//    public native boolean getBoolean(Object obj)
Implement_JavaNative(lang_reflect, Field, getBoolean)
{
// TODO.
    return 0;
}


//    public native byte getByte(Object obj)
Implement_JavaNative(lang_reflect, Field, getByte)
{
// TODO.
    return 0;
}


//    public native char getChar(Object obj)
Implement_JavaNative(lang_reflect, Field, getChar)
{
// TODO.
    return 0;
}


//    public native short getShort(Object obj)
Implement_JavaNative(lang_reflect, Field, getShort)
{
// TODO.
    return 0;
}


//    public native int getInt(Object obj)
Implement_JavaNative(lang_reflect, Field, getInt)
{
// TODO.
    return 0;
}


//    public native long getLong(Object obj)
Implement_JavaNative(lang_reflect, Field, getLong)
{
// TODO.
    return 0;
}


//    public native float getFloat(Object obj)
Implement_JavaNative(lang_reflect, Field, getFloat)
{
// TODO.
    return 0;
}


//    public native double getDouble(Object obj)
Implement_JavaNative(lang_reflect, Field, getDouble)
{
// TODO.
    return 0;
}


//    public native void set(Object obj, Object value)
Implement_JavaNative(lang_reflect, Field, set)
{
// TODO.
    return 0;
}


//    public native void setBoolean(Object obj, boolean z)
Implement_JavaNative(lang_reflect, Field, setBoolean)
{
// TODO.
    return 0;
}


//    public native void setByte(Object obj, byte b)
Implement_JavaNative(lang_reflect, Field, setByte)
{
// TODO.
    return 0;
}


//    public native void setChar(Object obj, char c)
Implement_JavaNative(lang_reflect, Field, setChar)
{
// TODO.
    return 0;
}


//    public native void setShort(Object obj, short s)
Implement_JavaNative(lang_reflect, Field, setShort)
{
// TODO.
    return 0;
}


//    public native void setInt(Object obj, int i)
Implement_JavaNative(lang_reflect, Field, setInt)
{
// TODO.
    return 0;
}


//    public native void setLong(Object obj, long l)
Implement_JavaNative(lang_reflect, Field, setLong)
{
// TODO.
    return 0;
}


//    public native void setFloat(Object obj, float f)
Implement_JavaNative(lang_reflect, Field, setFloat)
{
// TODO.
    return 0;
}


//    public native void setDouble(Object obj, double d)
Implement_JavaNative(lang_reflect, Field, setDouble)
{
// TODO.
    return 0;
}


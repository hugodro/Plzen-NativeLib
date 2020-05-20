/**************************************************
* File: array.cc.
* Desc: Implementation of the java.lang.reflect.Array native methods.
* Module: Plzen : NativeLib.
* Rev: 15 janvier 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <native/nativity.h>
#include <vm/jmachine.h>

// Function declarations.
Define_JavaNative(lang_reflect, Array, getLength);
Define_JavaNative(lang_reflect, Array, get);
Define_JavaNative(lang_reflect, Array, getBoolean);
Define_JavaNative(lang_reflect, Array, getByte);
Define_JavaNative(lang_reflect, Array, getChar);
Define_JavaNative(lang_reflect, Array, getShort);
Define_JavaNative(lang_reflect, Array, getInt);
Define_JavaNative(lang_reflect, Array, getLong);
Define_JavaNative(lang_reflect, Array, getFloat);
Define_JavaNative(lang_reflect, Array, getDouble);
Define_JavaNative(lang_reflect, Array, set);
Define_JavaNative(lang_reflect, Array, setBoolean);
Define_JavaNative(lang_reflect, Array, setByte);
Define_JavaNative(lang_reflect, Array, setChar);
Define_JavaNative(lang_reflect, Array, setShort);
Define_JavaNative(lang_reflect, Array, setInt);
Define_JavaNative(lang_reflect, Array, setLong);
Define_JavaNative(lang_reflect, Array, setFloat);
Define_JavaNative(lang_reflect, Array, setDouble);
Define_JavaNative(lang_reflect, Array, newArray);
Define_JavaNative(lang_reflect, Array, multiNewArray);

/* ATTN-980318 [HD]: No checking is enforced on the parameter to see
* if it is really an array of the right type.
*/

//    public static native int getLength(Object array)
Implement_JavaNative(lang_reflect, Array, getLength)
{
    JVInstance *arg0= NULL;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	arg0= tmpValue->extractInstance();
    }
    if (arg0 != NULL) {
	callFrame->returnInteger(((JVArrayInstance *)arg0)->nbrElements);
    }
    else {
	callFrame->returnInteger(0);
    }

    return 0;
}


//    public static native Object get(Object array, int index)
Implement_JavaNative(lang_reflect, Array, get)
{
    JVAbstractArray *arg0= NULL;
    JVRunValue *tmpValue;
    int eleIndex;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	arg0= (JVAbstractArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }

    if (arg0 != NULL) {
	if (arg0->vectorialType() & TYPE_INST_ARRAY) {
	    callFrame->returnInstance(((JVInstanceArray *)arg0)->getElement(eleIndex));
	}
	else if (arg0->vectorialType() & TYPE_ARRAY_ARRAY) {
	    callFrame->returnInstance((JVInstance *)((JVArrayArray *)arg0)->getElement(eleIndex));
	}
	else {
	    callFrame->returnInstance(JVAbstractInstance::globalNullObject());
	}
    }
    else {
	callFrame->returnInstance(JVAbstractInstance::globalNullObject());
    }
    return 0;
}


//    public static native boolean getBoolean(Object array, int index)
Implement_JavaNative(lang_reflect, Array, getBoolean)
{
    JVBasicArray *arg0= NULL;
    JVRunValue *tmpValue;
    int eleIndex;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	arg0= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }

    if (arg0 != NULL) {
	callFrame->returnInteger((unsigned int)arg0->getElement(eleIndex));
    }
    else callFrame->returnInteger(0);
    return 0;
}


//    public static native byte getByte(Object array, int index)
Implement_JavaNative(lang_reflect, Array, getByte)
{
    JVBasicArray *arg0= NULL;
    JVRunValue *tmpValue;
    int eleIndex;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	arg0= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }

    if (arg0 != NULL) {
	callFrame->returnInteger((unsigned int)arg0->getElement(eleIndex));
    }
    else callFrame->returnInteger(0);
    return 0;
}


//    public static native char getChar(Object array, int index)
Implement_JavaNative(lang_reflect, Array, getChar)
{
    JVBasicArray *arg0= NULL;
    JVRunValue *tmpValue;
    int eleIndex;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	arg0= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }

    if (arg0 != NULL) {
	callFrame->returnInteger((unsigned int)arg0->getElement(eleIndex));
    }
    else callFrame->returnInteger(0);
    return 0;
}


//    public static native short getShort(Object array, int index)
Implement_JavaNative(lang_reflect, Array, getShort)
{
    JVBasicArray *arg0= NULL;
    JVRunValue *tmpValue;
    int eleIndex;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	arg0= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }

    if (arg0 != NULL) {
	callFrame->returnInteger((unsigned int)arg0->getElement(eleIndex));
    }
    else callFrame->returnInteger(0);
    return 0;
}


//    public static native int getInt(Object array, int index)
Implement_JavaNative(lang_reflect, Array, getInt)
{
    JVBasicArray *arg0= NULL;
    JVRunValue *tmpValue;
    int eleIndex;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	arg0= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }

    if (arg0 != NULL) {
	callFrame->returnInteger((unsigned int)arg0->getElement(eleIndex));
    }
    else callFrame->returnInteger(0);
    return 0;
}


//    public static native long getLong(Object array, int index)
Implement_JavaNative(lang_reflect, Array, getLong)
{
    JVBasicArray *arg0= NULL;
    JVRunValue *tmpValue;
    int eleIndex;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	arg0= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }

    if (arg0 != NULL) {
	callFrame->returnLong((Value64Bits *)arg0->getElement(eleIndex));
    }
    else callFrame->returnInteger(0);
    return 0;
}


//    public static native float getFloat(Object array, int index)
Implement_JavaNative(lang_reflect, Array, getFloat)
{
    JVBasicArray *arg0= NULL;
    JVRunValue *tmpValue;
    int eleIndex;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	arg0= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }

    if (arg0 != NULL) {
	callFrame->returnInteger((unsigned int)arg0->getElement(eleIndex));
    }
    else callFrame->returnInteger(0);
    return 0;
}


//    public static native double getDouble(Object array, int index)
Implement_JavaNative(lang_reflect, Array, getDouble)
{
    JVBasicArray *arg0= NULL;
    JVRunValue *tmpValue;
    int eleIndex;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	arg0= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }

    if (arg0 != NULL) {
	callFrame->returnLong((Value64Bits *)arg0->getElement(eleIndex));
    }
    else callFrame->returnInteger(0);
    return 0;
}


//    public static native void set(Object array, int index, Object value)
Implement_JavaNative(lang_reflect, Array, set)
{
    JVAbstractArray *arg0= NULL;
    JVInstance *aValue;
    JVRunValue *tmpValue;
    int eleIndex;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	arg0= (JVAbstractArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	aValue= tmpValue->extractInstance();
    }

    if (arg0 != NULL) {
	if (arg0->vectorialType() & TYPE_INST_ARRAY) {
	    ((JVInstanceArray *)arg0)->setElement(eleIndex, aValue));
	}
	else if (arg0->vectorialType() & TYPE_ARRAY_ARRAY) {
	    ((JVArrayArray *)arg0)->setElement(eleIndex, aValue));
	}
    }
    return 0;
}


//    public static native void setBoolean(Object array, int index, boolean z)
Implement_JavaNative(lang_reflect, Array, setBoolean)
{
    JVBasicArray *array= NULL;
    JVRunValue *tmpValue;
    int eleIndex;
    int aBoolean;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	array= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	aBoolean= tmpValue->extractInteger();
    }

    if (array != NULL) {
	if (array->vectorialType() & TYPE_BASIC_ARRAY) {
	    array->setElement(eleIndex, aBoolean);
	}
    }
    return 0;
}


//    public static native void setByte(Object array, int index, byte b)
Implement_JavaNative(lang_reflect, Array, setByte)
{
    JVBasicArray *array= NULL;
    JVRunValue *tmpValue;
    int eleIndex;
    int aByte;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	array= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	aByte= tmpValue->extractInteger();
    }

    if (array != NULL) {
	if (array->vectorialType() & TYPE_BASIC_ARRAY) {
	    array->setElement(eleIndex, aByte);
	}
    }
    return 0;
}


//    public static native void setChar(Object array, int index, char c)
Implement_JavaNative(lang_reflect, Array, setChar)
{
    JVBasicArray *array= NULL;
    JVRunValue *tmpValue;
    int eleIndex;
    int aChar;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	array= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	aChar= tmpValue->extractInteger();
    }

    if (array != NULL) {
	if (array->vectorialType() & TYPE_BASIC_ARRAY) {
	    array->setElement(eleIndex, aChar);
	}
    }
    return 0;
}


//    public static native void setShort(Object array, int index, short s)
Implement_JavaNative(lang_reflect, Array, setShort)
{
    JVBasicArray *array= NULL;
    JVRunValue *tmpValue;
    int eleIndex;
    int aShort;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	array= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	aShort= tmpValue->extractInteger();
    }

    if (array != NULL) {
	if (array->vectorialType() & TYPE_BASIC_ARRAY) {
	    array->setElement(eleIndex, aShort);
	}
    }
    return 0;
}


//    public static native void setInt(Object array, int index, int i)
Implement_JavaNative(lang_reflect, Array, setInt)
{
    JVBasicArray *array= NULL;
    JVRunValue *tmpValue;
    int eleIndex;
    int anInt;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	array= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	anInt= tmpValue->extractInteger();
    }

    if (array != NULL) {
	if (array->vectorialType() & TYPE_BASIC_ARRAY) {
	    array->setElement(eleIndex, anInt);
	}
    }
    return 0;
}


//    public static native void setLong(Object array, int index, long l)
Implement_JavaNative(lang_reflect, Array, setLong)
{
    JVBasicArray *array= NULL;
    JVRunValue *tmpValue;
    int eleIndex;
    Value64Bits *aLong;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	array= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	aLong= (Value64Bits *)tmpValue->extractInteger();
    }

    if (array != NULL) {
	if (array->vectorialType() & TYPE_BASIC_ARRAY) {
	    array->setElement(eleIndex, aLong);
	}
    }
    return 0;
}


//    public static native void setFloat(Object array, int index, float f)
Implement_JavaNative(lang_reflect, Array, setFloat)
{
    JVBasicArray *array= NULL;
    JVRunValue *tmpValue;
    int eleIndex;
    int aFloat;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	array= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	aFloat= (Value64Bits *)tmpValue->extractInteger();
    }

    if (array != NULL) {
	if (array->vectorialType() & TYPE_BASIC_ARRAY) {
	    array->setElement(eleIndex, aFloat);
	}
    }
    return 0;
}


//    public static native void setDouble(Object array, int index, double d)
Implement_JavaNative(lang_reflect, Array, setDouble)
{
    JVBasicArray *array= NULL;
    JVRunValue *tmpValue;
    int eleIndex;
    Value64Bits *aDouble;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	array= (JVBasicArray *)tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	eleIndex= tmpValue->extractInteger();
    }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	aDouble= (Value64Bits *)tmpValue->extractInteger();
    }

    if (array != NULL) {
	if (array->vectorialType() & TYPE_BASIC_ARRAY) {
	    array->setElement(eleIndex, aDouble);
	}
    }
    return 0;
}


//    private static native Object newArray(Class componentType, int length)
Implement_JavaNative(lang_reflect, Array, newArray)
{
    JVInstance *theClass= NULL;
    JVAbstractInstance *theResult= NULL;
    JVRunValue *tmpValue;
    int arrayLength;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	theClass= tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	arrayLength= tmpValue->extractInteger();
    }

    if (arrayLength < 0) {
	// ATTN: Must throw a j.l.NegativeArraySizeException.
    }

    if (theClass != NULL) {
	ClassFile *realClass;

	if ((realClass= machine->getClassManager()->findClassByJavaEquiv(theClass)) != NULL) {
	    if (realClass->isPrimitiveCover()) {	// Equiv NEWARRAY.
		unsigned char javaTypeSigna;

		javaTypeSigna= ClassManager::translateClassToPrimitiveByte(realClass);
		if ((javaTypeSigna != JVM_TYPE_VOID) && (javaTypeSigna != '\0')) {
		    theResult= machine->getPoolManager()->getBasicArray(javaTypeSigna, arrayLength);
		}
	    }
	    else if (realClass->isArrayClass()) {	// Equiv ANEWARRAY.
		 theResult= machine->getPoolManager()->getInstanceArray(realClass, arrayLength);
	    }
	    else {							// Equiv ANEWARRAY.
		 theResult= machine->getPoolManager()->getArrayArray(realClass, &arrayLength, 1);
	    }
	}
	else {
	    // ATTN: Must throw a NullPointerException.
	}
    }
    else {
	// ATTN: Must throw a NullPointerException.
    }

    if (theResult == NULL) {
	theResult= JVInstance::globalNullObject();
    }
    callFrame->returnInstance((JVInstance *)theResult);

    return 0;
}


//    private static native Object multiNewArray(Class componentType, int[] dimensions)
Implement_JavaNative(lang_reflect, Array, multiNewArray)
{
    JVInstance *theClass= NULL;
    JVAbstractInstance *theResult= NULL;
    JVBasicArray *theDims;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	theClass= tmpValue->extractInstance();
    }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	theDims= (JVBasicArray *)tmpValue->extractInstance();
    }

    if (theDims->nbrElements == 0) {
	// ATTN: Should throw an IllegalArgumentException.
    }

    if (theClass != NULL) {
	ClassFile *realClass;

	if ((realClass= machine->getClassManager()->findClassByJavaEquiv(theClass)) != NULL) {
	    unsigned int *integerDims;
	    
	    integerDims= (unsigned int *)theDims->elements;
	    if (realClass->isPrimitiveCover()) {	// Equiv NEWARRAY.
		unsigned char javaTypeSigna;

		javaTypeSigna= ClassManager::translateClassToPrimitiveByte(realClass);
		if ((javaTypeSigna != JVM_TYPE_VOID) && (javaTypeSigna != '\0')) {
		    if (theDims->nbrElements == 1) {
			theResult= machine->getPoolManager()->getBasicArray(javaTypeSigna, integerDims[0]);
		    }
		    else {
			ArrayClassFile *arrayClass;
			    // ATTN-980318 [HD]: arrayClass is 'lost' (kept only in theResult, until it is released).
			arrayClass= new ArrayClassFile(javaTypeSigna, theDims->nbrElements);
			theResult= machine->getPoolManager()->getArrayArray(arrayClass, integerDims, theDims->nbrElements);
		    }
		}
	    }
	    else if (realClass->isArrayClass()) {
		// ATTN: TODO !!
	    }
	    else {
		ArrayClassFile *arrayClass;

		arrayClass= new ArrayClassFile(realClass, theDims->nbrElements);
		 theResult= machine->getPoolManager()->getArrayArray(arrayClass, integerDims, theDims->nbrElements);
	    }
	}
	else {
	    // ATTN: Must throw a NullPointerException.
	}
    }
    else {
	// ATTN: Must throw a NullPointerException.
    }

    if (theResult == NULL) {
	theResult= JVInstance::globalNullObject();
    }
    callFrame->returnInstance((JVInstance *)theResult);

    return 0;
}


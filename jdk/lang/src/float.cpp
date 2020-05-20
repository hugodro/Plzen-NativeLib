/**************************************************
* File: float.cc.
* Desc: Implementation of the native calls for the java.lang.Float class.
* Module: AkraLog : JavaKit.
* Rev: 4 novembre 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#if defined(MSDOS)
#include <native~1/nativity.h>
#include <runtime/jmachine.h>
#include <runtime/execFr~1.h>
#include <runtime/jvinst~1.h>
#include <runtime/stacks.h>
#else
#include <native/nativity.h>
#include <vm/jmachine.h>
#include <vm/execFrame.h>
#include <vm/jvInstance.h>
#include <vm/stacks.h>
#endif


// Function declarations.
Define_JavaNative(lang, Float, toString);
Define_JavaNative(lang, Float, valueOf);
Define_JavaNative(lang, Float, doubleToLongBits);
Define_JavaNative(lang, Float, longBitsToFloat);


// Function implementations.
//    public static native String toString(float f);
Implement_JavaNative(lang, Float, toString)
{
// TODO.
    return 0;
}


//    public static native Float valueOf(String s) throws NumberFormatException;
Implement_JavaNative(lang, Float, valueOf)
{
// TODO.
    return 0;
}


//    public static native int doubleToLongBits(float value);
Implement_JavaNative(lang, Float, doubleToLongBits)
{
// TODO.
    return 0;
}


//    public static native float longBitsToFloat(long bits);
Implement_JavaNative(lang, Float, longBitsToFloat)
{
// TODO.
    return 0;
}



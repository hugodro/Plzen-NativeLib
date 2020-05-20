/**************************************************
* File: double.cc.
* Desc: Implementation of the native calls for the java.lang.Double class.
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
Define_JavaNative(lang, Double, toString);
Define_JavaNative(lang, Double, valueOf);
Define_JavaNative(lang, Double, doubleToLongBits);
Define_JavaNative(lang, Double, longBitsToDouble);


// Function implementations.
//    public static native String toString(double d);
Implement_JavaNative(lang, Double, toString)
{
// TODO.
    return 0;
}


//    public static native Double valueOf(String s) throws NumberFormatException;
Implement_JavaNative(lang, Double, valueOf)
{
// TODO.
    return 0;
}


//    public static native long doubleToLongBits(double value);
Implement_JavaNative(lang, Double, doubleToLongBits)
{
// TODO.
    return 0;
}


//    public static native double longBitsToDouble(long bits);
Implement_JavaNative(lang, Double, longBitsToDouble)
{
// TODO.
    return 0;
}




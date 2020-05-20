/**************************************************
* File: math.cc.
* Desc: Implementation of the native calls for the java.lang.Math class.
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
Define_JavaNative(lang, Math, sin);
Define_JavaNative(lang, Math, cos);
Define_JavaNative(lang, Math, tan);
Define_JavaNative(lang, Math, asin);
Define_JavaNative(lang, Math, acos);
Define_JavaNative(lang, Math, atan);
Define_JavaNative(lang, Math, exp);
Define_JavaNative(lang, Math, log);
Define_JavaNative(lang, Math, sqrt);
Define_JavaNative(lang, Math, IEEEremainder);
Define_JavaNative(lang, Math, ceil);
Define_JavaNative(lang, Math, floor);
Define_JavaNative(lang, Math, rint);
Define_JavaNative(lang, Math, atan2);
Define_JavaNative(lang, Math, pow);


// Function implementations.
//    public static native double sin(double a);
Implement_JavaNative(lang, Math, sin)
{
// TODO.
    return 0;
}


//    public static native double cos(double a);
Implement_JavaNative(lang, Math, cos)
{
// TODO.
    return 0;
}


//    public static native double tan(double a);
Implement_JavaNative(lang, Math, tan)
{
// TODO.
    return 0;
}


//    public static native double asin(double a);
Implement_JavaNative(lang, Math, asin)
{
// TODO.
    return 0;
}


//    public static native double acos(double a); 
Implement_JavaNative(lang, Math, acos)
{
// TODO.
    return 0;
}


//    public static native double atan(double a);
Implement_JavaNative(lang, Math, atan)
{
// TODO.
    return 0;
}


//    public static native double exp(double a);
Implement_JavaNative(lang, Math, exp)
{
// TODO.
    return 0;
}


//    public static native double log(double a) throws ArithmeticException;
Implement_JavaNative(lang, Math, log)
{
// TODO.
    return 0;
}


//    public static native double sqrt(double a) throws ArithmeticException;
Implement_JavaNative(lang, Math, sqrt)
{
// TODO.
    return 0;
}


//    public static native double IEEEremainder(double f1, double f2);
Implement_JavaNative(lang, Math, IEEEremainder)
{
// TODO.
    return 0;
}


//    public static native double ceil(double a);
Implement_JavaNative(lang, Math, ceil)
{
// TODO.
    return 0;
}


//    public static native double floor(double a);
Implement_JavaNative(lang, Math, floor)
{
// TODO.
    return 0;
}


//    public static native double rint(double a);
Implement_JavaNative(lang, Math, rint)
{
// TODO.
    return 0;
}


//    public static native double atan2(double a, double b);
Implement_JavaNative(lang, Math, atan2)
{
// TODO.
    return 0;
}


//    public static native double pow(double a, double b) throws ArithmeticException;
Implement_JavaNative(lang, Math, pow)
{
// TODO.
    return 0;
}



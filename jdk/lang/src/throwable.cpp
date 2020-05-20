/**************************************************
* File: throwable.cc.
* Desc: Implementation of the native calls for the java.lang.Throwable class.
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
Define_JavaNative(lang, Throwable, printStackTrace0);
Define_JavaNative(lang, Throwable, fillInStackTrace);

// Function implementations.
//    private native void printStackTrace0(java.io.PrintStream s);
Implement_JavaNative(lang, Throwable, printStackTrace0)
{
// TODO.
    return 0;
}


//    public native Throwable fillInStackTrace();
Implement_JavaNative(lang, Throwable, fillInStackTrace)
{
// TODO.
    return 0;
}



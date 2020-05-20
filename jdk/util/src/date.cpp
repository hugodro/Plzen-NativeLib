/**************************************************
* File: date.cc.
* Desc: Implementation of the native calls for the java.util.Date class.
* Module: AkraLog : JavaKit.
* Rev: 4 novembre 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <iostream.h>

#if defined(MSDOS)
#include <native~1/nativity.h>
#include <runtime/jmachine.h>
#include <runtime/execFr~1.h>
#include <runtime/jvinst~1.h>
#include <runtime/stacks.h>
#include <runtime/valuet~1.h>
#else
#include <native/nativity.h>
#include <vm/jmachine.h>
#include <vm/execFrame.h>
#include <vm/jvInstance.h>
#include <vm/stacks.h>
#include <vm/valueTypes.h>
#endif


// Function declarations
Define_JavaNative(util, Date, toString);
Define_JavaNative(util, Date, toLocaleString);
Define_JavaNative(util, Date, toGMTString);
Define_JavaNative(util, Date, expand);
Define_JavaNative(util, Date, computeValue);


// Function implementations.
//    public native String toString();
Implement_JavaNative(util, Date, toString)
{
// TODO.
    return 0;
}


//    public native String toLocaleString();
Implement_JavaNative(util, Date, toLocaleString)
{
// TODO.
    return 0;
}


//    public native String toGMTString();
Implement_JavaNative(util, Date, toGMTString)
{
// TODO.
    return 0;
}


//    private native void expand();
Implement_JavaNative(util, Date, expand)
{
// TODO.
    return 0;
}


//    private native void computeValue();
Implement_JavaNative(util, Date, computeValue)
{
// TODO.
    return 0;
}




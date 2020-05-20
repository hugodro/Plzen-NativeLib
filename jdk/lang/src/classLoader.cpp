/**************************************************
* File: classLoader.cc.
* Desc: Implementation of the native calls for the java.lang.ClassLoader class.
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
Define_JavaNative(lang, ClassLoader, defineClass);
Define_JavaNative(lang, ClassLoader, resolveClass);
Define_JavaNative(lang, ClassLoader, findSystemClass);
Define_JavaNative(lang, ClassLoader, init);


// Function implementations.
//    protected native final Class defineClass(byte data[], int offset, int length);
Implement_JavaNative(lang, ClassLoader, defineClass)
{
// TODO.
    return 0;
}


//    protected native final void resolveClass(Class c);
Implement_JavaNative(lang, ClassLoader, resolveClass)
{
// TODO.
    return 0;
}


//    protected native final Class findSystemClass(String name) throws ClassNotFoundException;
Implement_JavaNative(lang, ClassLoader, findSystemClass)
{
// TODO.
    return 0;
}


//    private native void init();
Implement_JavaNative(lang, ClassLoader, init)
{
// TODO.
    return 0;
}

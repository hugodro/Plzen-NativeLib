/**************************************************
* File: securityManager.cc.
* Desc: Implementation of the native calls for the java.lang.SecurityManager class.
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
Define_JavaNative(lang, SecurityManager, getClassContext);
Define_JavaNative(lang, SecurityManager, currentClassLoader);
Define_JavaNative(lang, SecurityManager, classDepth);
Define_JavaNative(lang, SecurityManager, classLoaderDepth);


// Function implementations.
//    protected native Class[] getClassContext();
Implement_JavaNative(lang, SecurityManager, getClassContext)
{
// TODO.
    return 0;
}


//    protected native ClassLoader currentClassLoader();
Implement_JavaNative(lang, SecurityManager, currentClassLoader)
{
// TODO.
    return 0;
}


//    protected native int classDepth(String name);
Implement_JavaNative(lang, SecurityManager, classDepth)
{
// TODO.
    return 0;
}


//    protected native int classLoaderDepth();
Implement_JavaNative(lang, SecurityManager, classLoaderDepth)
{
// TODO.
    return 0;
}



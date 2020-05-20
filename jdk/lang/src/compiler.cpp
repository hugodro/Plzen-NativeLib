/**************************************************
* File: compiler.cc.
* Desc: Implementation of the native calls for the java.lang.Compiler class.
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
Define_JavaNative(lang, Compiler, initialize);
Define_JavaNative(lang, Compiler, compileClass);
Define_JavaNative(lang, Compiler, compileClasses);
Define_JavaNative(lang, Compiler, command);
Define_JavaNative(lang, Compiler, enable);
Define_JavaNative(lang, Compiler, disable);


// Function implementations.
//    private static native void initialize();
Implement_JavaNative(lang, Compiler, initialize)
{
// TODO.
    return 0;
}


//    public static native boolean compileClass(Class clazz);
Implement_JavaNative(lang, Compiler, compileClass)
{
// TODO.
    return 0;
}


//    public static native boolean compileClasses(String string);
Implement_JavaNative(lang, Compiler, compileClasses)
{
// TODO.
    return 0;
}


//    public static native Object command(Object any);
Implement_JavaNative(lang, Compiler, command)
{
// TODO.
    return 0;
}


//    public static native void enable();
Implement_JavaNative(lang, Compiler, enable)
{
// TODO.
    return 0;
}


//    public static native void disable();
Implement_JavaNative(lang, Compiler, disable)
{
// TODO.
    return 0;
}



/**************************************************
* File: file.cc.
* Desc: Implementation of the native calls for the java.io.File class.
* Module: AkraLog : JavaKit.
* Rev: 4 novembre 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <iostream>

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
Define_JavaNative(io, File, exists0);
Define_JavaNative(io, File, canWrite0);
Define_JavaNative(io, File, canRead0);
Define_JavaNative(io, File, isFile0);
Define_JavaNative(io, File, isDirectory0);
Define_JavaNative(io, File, lastModified0);
Define_JavaNative(io, File, length0);
Define_JavaNative(io, File, mkdir0);
Define_JavaNative(io, File, renameTo0);
Define_JavaNative(io, File, delete0);
Define_JavaNative(io, File, list0);
Define_JavaNative(io, File, isAbsolute);


// Function implementations.
//    private native boolean exists0();
Implement_JavaNative(io, File, exists0)
{
// TODO.
    return 0;
}


//    private native boolean canWrite0();
Implement_JavaNative(io, File, canWrite0)
{
// TODO.
    return 0;
}


//    private native boolean canRead0();
Implement_JavaNative(io, File, canRead0)
{
// TODO.
    return 0;
}


//    private native boolean isFile0();
Implement_JavaNative(io, File, isFile0)
{
// TODO.
    return 0;
}


//    private native boolean isDirectory0();
Implement_JavaNative(io, File, isDirectory0)
{
// TODO.
    return 0;
}


//    private native long lastModified0();
Implement_JavaNative(io, File, lastModified0)
{
// TODO.
    return 0;
}


//    private native long length0();
Implement_JavaNative(io, File, length0)
{
// TODO.
    return 0;
}


//    private native boolean mkdir0();
Implement_JavaNative(io, File, mkdir0)
{
// TODO.
    return 0;
}


//    private native boolean renameTo0(File dest);
Implement_JavaNative(io, File, renameTo0)
{
// TODO.
    return 0;
}


//    private native boolean delete0();
Implement_JavaNative(io, File, delete0)
{
// TODO.
    return 0;
}


//    private native String[] list0();
Implement_JavaNative(io, File, list0)
{
// TODO.
    return 0;
}


//    public native boolean isAbsolute();
Implement_JavaNative(io, File, isAbsolute)
{
// TODO.
    return 0;
}





/**************************************************
* File: fileInputStream.cc.
* Desc: Implementation of the native calls for the java.io.FileInputStream class.
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
Define_JavaNative(io, FileInputStream, open);
Define_JavaNative(io, FileInputStream, read);
Define_JavaNative(io, FileInputStream, readBytes);
Define_JavaNative(io, FileInputStream, skip);
Define_JavaNative(io, FileInputStream, available);
Define_JavaNative(io, FileInputStream, close);


// Function implementations.
//    private native void open(String name) throws IOException;
Implement_JavaNative(io, FileInputStream, open)
{
// TODO.
    return 0;
}


//    public native int read() throws IOException;
Implement_JavaNative(io, FileInputStream, read)
{
// TODO.
    return 0;
}


//    private native int readBytes(byte b[], int off, int len) throws IOException;
Implement_JavaNative(io, FileInputStream, readBytes)
{
// TODO.
    return 0;
}


//    public native long skip(long n) throws IOException;
Implement_JavaNative(io, FileInputStream, skip)
{
// TODO.
    return 0;
}


//    public native int available() throws IOException;
Implement_JavaNative(io, FileInputStream, available)
{
// TODO.
    return 0;
}


//    public native void close() throws IOException;
Implement_JavaNative(io, FileInputStream, close)
{
// TODO.
    return 0;
}


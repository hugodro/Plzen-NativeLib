/**************************************************
* File: socketInputStream.cc.
* Desc: Implementation of the native calls for the java.net.SocketInputStream class.
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
Define_JavaNative(net, SocketInputStream, socketRead);

// Function implementations.
//    private native int socketRead(byte b[], int off, int len) throws IOException;
Implement_JavaNative(net, SocketInputStream, socketRead)
{
// TODO.
    return 0;
}



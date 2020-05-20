/**************************************************
* File: plainSocketImpl.cc.
* Desc: Implementation of the native calls for the java.net.PlainSocketImpl class.
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
Define_JavaNative(net, PlainSocketImpl, socketCreate);
Define_JavaNative(net, PlainSocketImpl, socketConnect);
Define_JavaNative(net, PlainSocketImpl, socketBind);
Define_JavaNative(net, PlainSocketImpl, socketListen);
Define_JavaNative(net, PlainSocketImpl, socketAccept);
Define_JavaNative(net, PlainSocketImpl, socketAvailable);
Define_JavaNative(net, PlainSocketImpl, socketClose);


// Function implementations.
//    private native void socketCreate(boolean stream) throws IOException;
Implement_JavaNative(net, PlainSocketImpl, socketCreate)
{
// TODO.
    return 0;
}


//    private native void socketConnect(PlainSocketImpl address, int port)
Implement_JavaNative(net, PlainSocketImpl, socketConnect)
{
// TODO.
    return 0;
}


//    private native void socketBind(PlainSocketImpl address, int port)
Implement_JavaNative(net, PlainSocketImpl, socketBind)
{
// TODO.
    return 0;
}


//    private native void socketListen(int count)
Implement_JavaNative(net, PlainSocketImpl, socketListen)
{
// TODO.
    return 0;
}


//    private native void socketAccept(SocketImpl s)
Implement_JavaNative(net, PlainSocketImpl, socketAccept)
{
// TODO.
    return 0;
}


//    private native int socketAvailable()
Implement_JavaNative(net, PlainSocketImpl, socketAvailable)
{
// TODO.
    return 0;
}


//    private native void socketClose()
Implement_JavaNative(net, PlainSocketImpl, socketClose)
{
// TODO.
    return 0;
}


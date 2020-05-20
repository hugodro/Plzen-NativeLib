/**************************************************
* File: datagramSocket.cc.
* Desc: Implementation of the native calls for the java.net.DatagramSocket class.
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
Define_JavaNative(net, DatagramSocket, datagramSocketCreate);
Define_JavaNative(net, DatagramSocket, datagramSocketBind);
Define_JavaNative(net, DatagramSocket, datagramSocketSend);
Define_JavaNative(net, DatagramSocket, datagramSocketPeek);
Define_JavaNative(net, DatagramSocket, datagramSocketReceive);
Define_JavaNative(net, DatagramSocket, datagramSocketClose);


// Function implementations.
//    private native void datagramSocketCreate();
Implement_JavaNative(net, DatagramSocket, datagramSocketCreate)
{
// TODO.
    return 0;
}


//    private native int  datagramSocketBind(int port);
Implement_JavaNative(net, DatagramSocket, datagramSocketBind)
{
// TODO.
    return 0;
}


//    private native void datagramSocketSend(DatagramPacket p);
Implement_JavaNative(net, DatagramSocket, datagramSocketSend)
{
// TODO.
    return 0;
}


//    private native int datagramSocketPeek(InetAddress i);
Implement_JavaNative(net, DatagramSocket, datagramSocketPeek)
{
// TODO.
    return 0;
}


//    private native void datagramSocketReceive(DatagramPacket p);
Implement_JavaNative(net, DatagramSocket, datagramSocketReceive)
{
// TODO.
    return 0;
}


//    private native void datagramSocketClose();
Implement_JavaNative(net, DatagramSocket, datagramSocketClose)
{
// TODO.
    return 0;
}



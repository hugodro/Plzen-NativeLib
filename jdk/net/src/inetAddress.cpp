/**************************************************
* File: inetAddress.cc.
* Desc: Implementation of the native calls for the java.net.InetAddress class.
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
Define_JavaNative(net, InetAddress, getLocalHostName);
Define_JavaNative(net, InetAddress, makeAnyLocalAddress);
Define_JavaNative(net, InetAddress, lookupHostAddr);
Define_JavaNative(net, InetAddress, lookupAllHostAddr);
Define_JavaNative(net, InetAddress, getHostByAddr);
Define_JavaNative(net, InetAddress, getInetFamily);


// Function implementations.
//    private static native String getLocalHostName() throws UnknownHostException;
Implement_JavaNative(net, InetAddress, getLocalHostName)
{
// TODO.
    return 0;
}


//    private static native void makeAnyLocalAddress(InetAddress addr);
Implement_JavaNative(net, InetAddress, makeAnyLocalAddress)
{
// TODO.
    return 0;
}


//    private static native byte[] lookupHostAddr(String hostname) throws UnknownHostException;
Implement_JavaNative(net, InetAddress, lookupHostAddr)
{
// TODO.
    return 0;
}


//    private static native byte[][] lookupAllHostAddr(String hostname) throws UnknownHostException;
Implement_JavaNative(net, InetAddress, lookupAllHostAddr)
{
// TODO.
    return 0;
}


//    private static native String getHostByAddr(int addr) throws UnknownHostException;
Implement_JavaNative(net, InetAddress, getHostByAddr)
{
// TODO.
    return 0;
}


//    private static native int getInetFamily();
Implement_JavaNative(net, InetAddress, getInetFamily)
{
// TODO.
    return 0;
}


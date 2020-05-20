/**************************************************
* File: fileOutputStream.cc.
* Desc: Implementation of the native calls for the io_FileOutputStream class.
* Module: AkraLog : JavaKit.
* Rev: 25 aout 1996 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <iostream>

#include <native/nativity.h>
#include <vm/jmachine.h>
#include <vm/execFrame.h>
#include <vm/jvInstance.h>
#include <vm/stacks.h>


static JVVariable *fdField= NULL;
static JVVariable *fdfdField= NULL;


// Function definitions.
Define_JavaNative(io, FileOutputStream, open);
Define_JavaNative(io, FileOutputStream, write);
Define_JavaNative(io, FileOutputStream, writeBytes);
Define_JavaNative(io, FileOutputStream, close);


// Definition: private native void open(String name) throws IOException.
Implement_JavaNative(io, FileOutputStream, open)
{
    JVInstance *mySelf, *fileName;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	mySelf= tmpValue->extractInstance();	// Contains the FileDescriptor 'fd'.
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	fileName= tmpValue->extractInstance();
     }

    // ATTN: TODO.
    return 0;
}

// Definition: public native void write(int b) throws IOException.
Implement_JavaNative(io, FileOutputStream, write)
{
    JVInstance *mySelf;
    JVRunValue *tmpValue;
    int byteToGo;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	mySelf= tmpValue->extractInstance();	// Contains the FileDescriptor 'fd'.
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	byteToGo= tmpValue->extractInteger();
     }

    // ATTN: To implement.
    return 0;
}


// Definition: private native void writeBytes(byte b[], int off, int len) throws IOException.
Implement_JavaNative(io, FileOutputStream, writeBytes)
{
    JVInstance *self;
    JVBasicArray *byteArray;
    JVRunValue *tmpValue;
    int offset, length;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();	// Contains the FileDescriptor 'fd'.
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	byteArray= (JVBasicArray *)tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	offset= tmpValue->extractInteger();
     }
    tmpValue= callFrame->getLocalValue(3);
    if (tmpValue != NULL) {
	length= tmpValue->extractInteger();
     }

    if (fdField == NULL) {
	fdField= machine->getFieldOfClass(self->category(), "fd");
    }
    if (fdField != NULL) {
	JVInstance *fileDescriptor= (JVInstance *)self->getField(fdField);

	if (fdfdField == NULL) {
	    fdfdField= machine->getFieldOfClass(fileDescriptor->category(), "fd");
	}
	if (fdfdField != NULL) {
		std::ostream *outStream;
	    outStream= (std::ostream *)fileDescriptor->getField(fdfdField);
// MOD-970414 [JST]: compilation issue on SGI.
	    outStream->write((const char *) byteArray->getElementPtrAt(offset), length);
	}
    }

    return 0;
}

// Definition: public native void close() throws IOException.
Implement_JavaNative(io, FileOutputStream, close)
{
    JVInstance *mySelf;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	mySelf= tmpValue->extractInstance();	// Contains the FileDescriptor 'fd'.
     }

    // ATTN: To implement.
    return 0;
}


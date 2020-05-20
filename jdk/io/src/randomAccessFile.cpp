/**************************************************
* File: randomAccessFile.cc.
* Desc: Implementation of the native calls for the io_RandomAccessFile class.
* Module: AkraLog : JavaKit.
* Rev: 20 aout 1996 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <fstream>

#include <native/nativity.h>
#include <vm/jmachine.h>
#include <vm/execFrame.h>
#include <vm/jvInstance.h>
#include <vm/stacks.h>
#include <vm/stringSupport.h>
#include <vm/valueTypes.h>


static JVVariable *fdField= NULL;
static JVVariable *fdfdField= NULL;
static JVVariable *stringValueField= NULL;

// Function declarations.
Define_JavaNative(io, RandomAccessFile, open);
Define_JavaNative(io, RandomAccessFile, read);
Define_JavaNative(io, RandomAccessFile, readBytes);
Define_JavaNative(io, RandomAccessFile, write);
Define_JavaNative(io, RandomAccessFile, writeBytes);
Define_JavaNative(io, RandomAccessFile, getFilePointer);
Define_JavaNative(io, RandomAccessFile, seek);
Define_JavaNative(io, RandomAccessFile, length);
Define_JavaNative(io, RandomAccessFile, close);


//     private native void open(String name, boolean writeable) throws IOException;
Implement_JavaNative(io, RandomAccessFile, open)
{
    JVInstance *self, *fileName;
    JVRunValue *tmpValue;
#if defined(_WIN32)
    std::fstream *fStream;
#else
    // fstreambase *fStream;
    std::ifstream *fStream;
#endif
    char *charFileName= NULL;
    bool writable;

    // Extract data from local value array.
    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	fileName= tmpValue->extractInstance();
	if (fileName) {
	    StringSupport::mapStringToNarrowArray(fileName, &charFileName);
	}
     }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	writable= (bool)tmpValue->extractInteger();
     }

    if (writable) {
	// fStream= new std::fstream(charFileName, std::ios::in | std::ios::out);
	fStream= new std::ifstream(charFileName, std::ios::in | std::ios::out);
    }
    else {
#if defined(_WIN32)
	fStream= new std::fstream(charFileName, std::ios::in);
#else
	// fStream= new std::ofstream(charFileName);
	fStream= new std::ifstream(charFileName);
#endif
    }
    if (fStream) {
	if (fdField == NULL) {
	    fdField= machine->getFieldOfClass(self->category(), "fd");
	}
	if (fdField != NULL) {
	    JVInstance *fileDescriptor= (JVInstance *)self->getField(fdField);

	    if (fdfdField == NULL) {
		fdfdField= machine->getFieldOfClass(fileDescriptor->category(), "fd");
	    }
	    if (fdfdField != NULL) {
		JVRunValue descValue(TYPE_BASIC, (void *)fStream);
		fileDescriptor->putField(descValue, fdfdField);
	    }
	}
    }
    else {
	// Must throw IOExection !
    }

    if (charFileName != NULL) delete[] charFileName;

    return 0;
}


//    public native int read() throws IOException;
Implement_JavaNative(io, RandomAccessFile, read)
{
    JVInstance *self;
    JVBasicArray *byteArray;
    JVRunValue *tmpValue, readValue;
    int offset, length;
    char aByte= -1;
    bool aFlag;

    // Extract data from local value array.
    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
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
		std::istream *inStream;
	    inStream= (std::istream *)fileDescriptor->getField(fdfdField);
	    inStream->get(aByte);
	    if (inStream->eof()) {
		aByte= -1;
	    }
	}
    }

    callFrame->returnInteger((unsigned int)aByte);
    return 0;
}

//     private native int readBytes(byte b[], int off, int len) throws IOException;
Implement_JavaNative(io, RandomAccessFile, readBytes)
{
    JVInstance *self;
    JVBasicArray *byteArray;
    JVRunValue *tmpValue, readValue;
    int offset, length, readBytes= 0;
    bool aFlag;

    // Extract data from local value array.
    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
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
		std::istream *inStream;
	    inStream= (std::istream *)fileDescriptor->getField(fdfdField);
	    inStream->read((char *) byteArray->getElementPtrAt(offset), length);
	    readBytes= inStream->gcount();
	}
    }

    callFrame->returnInteger(readBytes);
    return 0;
}


//    public native void write(int b) throws IOException;
Implement_JavaNative(io, RandomAccessFile, write)
{
    JVInstance *self;
    JVBasicArray *byteArray;
    JVRunValue *tmpValue;
    unsigned int aByte;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();	// Contains the FileDescriptor 'fd'.
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	aByte= tmpValue->extractInteger();
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
	    outStream->put((unsigned char)aByte);
	}
    }

    return 0;
}


//    private native void writeBytes(byte b[], int off, int len) throws IOException;
Implement_JavaNative(io, RandomAccessFile, writeBytes)
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
	    outStream->write((const char *) byteArray->getElementPtrAt(offset), length);
	}
    }

    return 0;
}


//    public native long getFilePointer() throws IOException;
Implement_JavaNative(io, RandomAccessFile, getFilePointer)
{
// ATTENTION: TO IMPLEMENT.
    return 0;
}


//     public native void seek(long pos) throws IOException;
Implement_JavaNative(io, RandomAccessFile, seek)
{
    return 0;
}


//    public native long length() throws IOException;
Implement_JavaNative(io, RandomAccessFile, length)
{
// ATTENTION: TO IMPLEMENT.
    return 0;
}


//    public native void close() throws IOException;
Implement_JavaNative(io, RandomAccessFile, close)
{
    JVInstance *self;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	self= tmpValue->extractInstance();
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
	    JVRunValue ioValue(TYPE_BASIC);
#if defined(_WIN32)
	    std::fstream *fStream= (std::fstream *)fileDescriptor->getField(fdfdField);
#else
	    // fstreambase *fStream= (fstreambase *)fileDescriptor->getField(fdfdField);
	    std::ifstream *fStream= (std::ifstream *)fileDescriptor->getField(fdfdField);
#endif

	    fStream->close();
	    fileDescriptor->putField(ioValue, fdfdField);
	}
    }

    return 0;
}



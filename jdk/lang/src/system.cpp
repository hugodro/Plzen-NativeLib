/**************************************************
* File: system.cc.
* Desc: Implementation of the native calls for the java.lang.System class.
* Module: AkraLog : JavaKit.
* Rev: 15 aout 1996 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

extern "C" {
#if defined(_WIN32)
#include <direct.h>
#include <windows.h>
#endif
#include <string.h>
#include <stdlib.h>
#if !defined(_WIN32)
#include <sys/time.h>
#endif
#if defined(NeXT)
#include <libc.h>
#endif

#if !defined(_WIN32)
    // For getuid, getpwuid.
#include <pwd.h>
#include <sys/types.h>
#endif

#if defined(__linux__) || defined(IRIX) || defined(MSDOS)
#include <unistd.h>
#endif

 }

#include <native/nativity.h>
#include <vm/execFrame.h>
#include <vm/jvInstance.h>
#include <vm/stacks.h>
#include <vm/valueTypes.h>
#include <vm/runtimeDefs.h>
#include <vm/machineSupport.h>
#include <vm/jmachine.h>
#include "system.h"

#if defined(TODO_UNAME)
#include <sys/utsname.h>			// For uname.
#endif


Define_JavaNative(lang, System, arraycopy);
Define_JavaNative(lang, System, initProperties);
Define_JavaNative(lang, System, currentTimeMillis);
Define_JavaNative(lang, System, setIn0);
Define_JavaNative(lang, System, setOut0);
Define_JavaNative(lang, System, setErr0);
Define_JavaNative(lang, System, identityHashCode);

static JVVariable *inField= NULL;
static JVVariable *outField= NULL;
static JVVariable *errField= NULL;

//    public static native void arraycopy(Object src, int src_position, Object dst, int dst_position, int length); 
Implement_JavaNative(lang, System, arraycopy)
{
    JVAbstractInstance *srcArray, *destArray;
    JVRunValue *tmpValue;
    unsigned int srcOffset, destOffset, length;
    unsigned int i;

    // Extract data from local value array.
    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	srcArray= tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	srcOffset= tmpValue->extractInteger();
     }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	destArray= tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(3);
    if (tmpValue != NULL) {
	destOffset= tmpValue->extractInteger();
     }
    tmpValue= callFrame->getLocalValue(4);
    if (tmpValue != NULL) {
	length= tmpValue->extractInteger();
     }

	// ATTN: Debut d'implantation.
    if ((srcArray->vectorialType() & TYPE_BASIC_ARRAY) && (destArray->vectorialType() & TYPE_BASIC_ARRAY)) {
	JVBasicArray *srcBasic, *destBasic;

	srcBasic= (JVBasicArray *)srcArray;
	destBasic= (JVBasicArray *)destArray;

	for (i= 0; i < length; i++) {
	    destBasic->setElement(destOffset+i, srcBasic->getElement(srcOffset+i));
	 }
     }
    else if ((srcArray->vectorialType() & TYPE_INST_ARRAY) && (destArray->vectorialType() & TYPE_INST_ARRAY)) {
	JVInstanceArray *srcBasic, *destBasic;

	srcBasic= (JVInstanceArray *)srcArray;
	destBasic= (JVInstanceArray *)destArray;

	for (i= 0; i < length; i++) {
	    destBasic->setElement(destOffset+i, srcBasic->getElement(srcOffset+i));
	 }
     }
    return 0;
}


/*********************************************************
 NOTE: System properties. The following properties are guaranteed to be defined:
1- java.version		Java version number
2- java.vendor		Java vendor specific string
3- java.vendor.url	Java vendor URL
4- java.home		Java installation directory
5- java.class.version	Java class version number
6- java.class.path	Java classpath
7- os.name			Operating System Name
8- os.arch			Operating System Architecture
9- os.version		Operating System Version
10- file.separator		File separator ("/" on Unix)
11- path.separator		Path separator (":" on Unix)
12- line.separator		Line separator ("\n" on Unix)
13- user.name		User account name
14- user.home		User home directory
15- user.dir			User's current working directory
// Akra perticulars.
16- awt.toolkit		Toolkit to use to show AWT things.
*********************************************************/
#define NBR_PROPERTIES		16

//    private static native Properties initProperties(Properties props);
Implement_JavaNative(lang, System, initProperties)
{
    JVRunValue *tmpValue;
    JVInstance *properties, *keyString, *valueString;
    static JVMethod *putMethod= NULL;
    static char *keys[NBR_PROPERTIES]= {
	"java.version", "java.vendor", "java.vendor.url",
	"java.home", "java.class.version", "java.class.path",
	"os.name", "os.arch", "os.version",
	"file.separator", "path.separator", "line.separator",
	"user.name", "user.home", "user.dir"
	, "awt.toolkit"
    };
    static char *values[NBR_PROPERTIES]= { NULL };
    char *tmpCharPtr;

    if (values[0] == NULL) {
	values[0]= "3.42";
	values[1]= "Akra Logique s.r.o.";
	values[2]= "http://www.akralog.cz";

	if ((values[3]= getenv(PLZEN_HOME)) == NULL) {
	    if ((values[3]= getenv(JAVA_HOME)) == NULL) {
		values[3]= ".";
	    }
	}
	values[4]= "1";
	if ((values[5]= getenv(CLASSPATH)) == NULL) {
	    values[5]= ".";
	}

#if defined(TODO_UNAME)
	{
	    struct utsname hostinfo;
	    if (uname(&hostinfo) > 0) {
		values[6]= new char[32];
		values[7]= new char[32];
		values[8]= new char[32];
		strcpy(values[6], hostinfo.sysname);
		strcpy(values[7], hostinfo.machine);
		strcpy(values[8], hostinfo.version);
	    }
	    else {
		values[6]= "Unknown";
		values[7]= "Unknown";
		values[8]= "Unknown";
	    }
	}
#else
	values[6]= "Unknown";
	values[7]= "Unknown";
	values[8]= "Unknown";
#endif

	values[9]= (tmpCharPtr= new char[8]);
	values[9][0]= FILE_SEPARATOR;
	values[9][1]= '\0';
	values[10]= tmpCharPtr + 2;
	values[10][0]= PATH_SEPARATOR;
	values[10][1]= '\0';
	values[11]= tmpCharPtr + 4;
#if defined(_WIN32)
	values[11][0]= '\r';
	values[11][1]= '\n';
	values[11][2]= '\0';
#else
	values[11][0]= '\n';
	values[11][1]= '\0';
#endif

#if !defined(_WIN32)
	{
	    struct passwd *passwdInfo;
	    if ((passwdInfo= getpwuid(getuid())) != NULL) {
		values[12]= new char[strlen(passwdInfo->pw_name) + 1];
		strcpy(values[12], passwdInfo->pw_name);
		values[13]= new char[strlen(passwdInfo->pw_dir) + 1];
		strcpy(values[13], passwdInfo->pw_dir);
	    }
	    else {
		values[12]= "Unknown";
		values[13]= "Unknown";
	    }
	}
#else
	values[12]= "Unknown";
	values[13]= "Unknown";
#endif

	values[14]= new char[1024];
#if defined(NeXT)
	if (getwd(values[14]) == NULL) {
	    strcpy(values[14], ".");
	}
#else
	if (getcwd(values[14], 1024) == NULL) {
	    strcpy(values[14], ".");
	}
#endif
	values[15]= "akralog.awt.GenericToolkit";
    };


    // Extract data from local value array.
    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	properties= tmpValue->extractInstance();
     }

    if (putMethod == NULL) {
	putMethod= machine->getMethodInClass("put",
				"(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;",
				"java/util/Properties");
    }

    if (putMethod != NULL) {
	void *argBlock[2];
	for (unsigned int i= 0; i < NBR_PROPERTIES; i++) {
	    argBlock[0]= machine->createStringFromNarrowArray(keys[i]);
	    argBlock[1]= machine->createStringFromNarrowArray(values[i]);
	    machine->runMethodWithArguments(properties, putMethod, 2, argBlock);
	    machine->operStack->popVoid();
	}
    }

    callFrame->returnInstance(properties);
    return 0;
}


//    public static native long currentTimeMillis();
Implement_JavaNative(lang, System, currentTimeMillis)
{
    Value64Bits result;

#if defined(_WIN32)
    FILETIME fileSysTime;
    SYSTEMTIME localTime, baseTime;

    GetLocalTime(&localTime);
    SystemTimeToFileTime(&localTime, &fileSysTime);
    Value64Bits winTime(fileSysTime.dwHighDateTime, fileSysTime.dwLowDateTime);
    localTime.wYear= 1601;
    localTime.wMonth= 1;
    localTime.wDay= 1;
    localTime.wHour= 0;
    localTime.wMinute= 0;
    localTime.wSecond= 0;
    localTime.wMilliseconds= 1;
    SystemTimeToFileTime(&localTime, &fileSysTime);
    Value64Bits offset(fileSysTime.dwHighDateTime, fileSysTime.dwLowDateTime);
    Value64Bits::isub(&result, &winTime, &offset);
	// TMP: Divide by 8192 instead of 10000, good enough approx.
    result.data.lint.lowWord>>= 13;
    result.data.lint.lowWord|= (result.data.lint.highWord & 0x0FF) << 19;
    result.data.lint.highWord>>= 13;

#else
    struct timeval tp;
    struct timezone tzp;

    gettimeofday(&tp, &tzp);
    Value64Bits currentTime(0, tp.tv_sec), operand(0, 1000);
    Value64Bits::imult(&result, &currentTime, &operand);
    operand.data.lint.lowWord= tp.tv_usec / 1000;
    currentTime= result;
    Value64Bits::iadd(&result, &currentTime, &operand);
#endif
    callFrame->returnLong(&result);
    return 0;
}


//    private static native void setIn0(InputStream in);
Implement_JavaNative(lang, System, setIn0)
{
    JVInstance *streamInstance;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	streamInstance= tmpValue->extractInstance();
     }

    if (inField == NULL) {
	inField= machine->getFieldOfClass(streamInstance->category(), "in");
    }
    if (inField != NULL) {
	inField->setStaticValue(streamInstance);
    }

    return 0;
}


//    private static native void setOut0(PrintStream out);
Implement_JavaNative(lang, System, setOut0)
{
    JVInstance *streamInstance;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	streamInstance= tmpValue->extractInstance();
     }

    if (outField == NULL) {
	outField= machine->getFieldOfClass(streamInstance->category(), "out");
    }
    if (outField != NULL) {
	outField->setStaticValue(streamInstance);
    }

    return 0;
}


//    private static native void setErr0(PrintStream err);
Implement_JavaNative(lang, System, setErr0)
{
    JVInstance *streamInstance;
    JVRunValue *tmpValue;

    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	streamInstance= tmpValue->extractInstance();
     }

    if (errField == NULL) {
	errField= machine->getFieldOfClass(streamInstance->category(), "err");
    }
    if (errField != NULL) {
	errField->setStaticValue(streamInstance);
    }
    return 0;
}


//    public static native int identityHashCode(Object x);
Implement_JavaNative(lang, System, identityHashCode)
{
// TODO.
    callFrame->returnInteger(0);
    return 0;
}


// TMP: Test of a native implemented as a method of a C++ class.

unsigned int System::arraycopy(JVInstance *src, unsigned int srcOffset, JVInstance *dest, unsigned int destOffset, unsigned int length)
{
    return 0;
}

/**************************************************
* File: runtime.cc.
* Desc: Implementation of the native calls for the runtime class.
* Module: AkraLog : JavaKit.
* Rev: 7 mai 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <stdlib.h>
#if defined(IRIX) || defined(_WIN32) || defined(__linux__)
// #include <string.h>
#include <string>
#endif

#include <native/nativity.h>
#include <vm/execFrame.h>
#include <vm/jvInstance.h>
#include <vm/stacks.h>
#include <vm/valueTypes.h>
#include <vm/stringSupport.h>
#include <vm/classManager.h>
#include <vm/jmachine.h>
#include <vm/runtimeDefs.h>
#include <vm/jvcup.h>

#include "runtime.h"


Define_JavaNative(lang, Runtime, exitInternal);
Define_JavaNative(lang, Runtime, execInternal);
Define_JavaNative(lang, Runtime, freeMemory);
Define_JavaNative(lang, Runtime, totalMemory);
Define_JavaNative(lang, Runtime, gc);
Define_JavaNative(lang, Runtime, runFinalization);
Define_JavaNative(lang, Runtime, traceInstructions);
Define_JavaNative(lang, Runtime, traceMethodCalls);
Define_JavaNative(lang, Runtime, initializeLinkerInternal);
Define_JavaNative(lang, Runtime, buildLibName);
Define_JavaNative(lang, Runtime, loadFileInternal);


// Declaration: private native void exitInternal(int status);
Implement_JavaNative(lang, Runtime, exitInternal)
{
// TODO.
    return 0;
}


// Declaration: private native Process execInternal(String cmdarray[], String envp[]) throws IOException
Implement_JavaNative(lang, Runtime, execInternal)
{
// TODO.
    return 0;
}


// Declaration: public native long freeMemory();
Implement_JavaNative(lang, Runtime, freeMemory)
{
// TODO.
    return 0;
}


// Declaration: public native long totalMemory();
Implement_JavaNative(lang, Runtime, totalMemory)
{
// TODO.
    return 0;
}


// Declaration: public native void gc();
Implement_JavaNative(lang, Runtime, gc)
{
// TODO.
    return 0;
}


// Declaration: public native void runFinalization();
Implement_JavaNative(lang, Runtime, runFinalization)
{
// TODO.
    return 0;
}


// Declaration: public native void traceInstructions(boolean on);
Implement_JavaNative(lang, Runtime, traceInstructions)
{
// TODO.
    return 0;
}


// Declaration: public native void traceMethodCalls(boolean on);
Implement_JavaNative(lang, Runtime, traceMethodCalls)
{
// TODO.
    return 0;
}


// Declaration: private synchronized native String initializeLinkerInternal();
Implement_JavaNative(lang, Runtime, initializeLinkerInternal)
{
    JVAbstractInstance *receiver;
    JVInstance *aString;
    JVRunValue *tmpValue;
    char *dynLibPath;

    // Extract data from local value array.
    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	receiver= tmpValue->extractInstance();
     }

// TODO: Get the value from a property in the system dictionary.
// TMP: Use a system environment variable to locate dyn libs.

    if ((dynLibPath= getenv(DYNLIBPATH)) == NULL) dynLibPath= ".";

    aString= machine->createStringFromNarrowArray(dynLibPath);
    callFrame->returnInstance(aString);
    return 0;
}


// Declaration: private native String buildLibName(String pathname, String filename);
Implement_JavaNative(lang, Runtime, buildLibName)
{
    JVAbstractInstance *receiver;
    JVInstance *pathname, *filename, *aString;
    JVRunValue *tmpValue;
    unsigned int pathLength, libLength;
    char *path, *libShortName, fullPath[1024];

    // Extract data from local value array.
    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	receiver= tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	pathname= tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(2);
    if (tmpValue != NULL) {
	filename= tmpValue->extractInstance();
     }

    StringSupport::mapStringToNarrowArray(pathname, &path);
    StringSupport::mapStringToNarrowArray(filename, &libShortName);
    
    if (path != NULL) {
	pathLength= strlen(path);
	strcpy(fullPath, path);
	fullPath[pathLength]= FILE_SEPARATOR;
#if defined(_WIN32)
    // TMP: Cause une exception dans le HeapBlock.
//        if (pathLength > 4) delete[] path;
#else
	delete[] path;
#endif
    }
    if (libShortName != NULL) {
	strcpy(fullPath + pathLength + 1, libShortName);
	libLength= strlen(libShortName);
	strcpy(fullPath + pathLength + libLength + 1, DYNLIB_EXTENSION);
#if defined(_WIN32)
    // TMP: Cause une exception dans le HeapBlock.
//	if (libLength > 4) delete[] libShortName;
#else
	delete[] libShortName;
#endif
    }

    aString= machine->createStringFromNarrowArray(fullPath);
    callFrame->returnInstance(aString);
    return 0;
}


// Declaration: private native boolean loadFileInternal(String filename);
Implement_JavaNative(lang, Runtime, loadFileInternal)
{
    ClassManager *classManager;
    JVAbstractInstance *receiver;
    JVInstance *filename;
    JVRunValue *tmpValue;
    unsigned int loadResult= 0;
    char *charFileName= NULL;

    // Extract data from local value array.
    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	receiver= tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	filename= tmpValue->extractInstance();
     }

    StringSupport::mapStringToNarrowArray(filename, &charFileName);
    if ((charFileName != NULL) && ((classManager= machine->getClassManager()) != NULL)) {
	if (classManager->loadDynamicLibrary(charFileName)) loadResult= 1;
    }
#if defined(_WIN32)
    // TMP: Cause une exception dans le HeapBlock.
#else
    if (charFileName != NULL) delete[] charFileName;
#endif

    callFrame->returnInteger(loadResult);
    return 0;
}



#ifndef _NATIVITY_H_
#define _NATIVITY_H_
/**************************************************
* File: nativity.h.
* Desc: Definition of macros and constants for native methods implementation.
* Module: AkraLog : JavaKit.
* Rev: 26 aout 1996 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

// Native function stub (definition and implementation), as it will be seeked by the ClassManager.
#if defined(NeXT) || defined(__linux__) || defined(IRIX) || defined(MSDOS)
    // General native function, with single package name.
// use unsigned int vs void.
#define Define_Native(thePack, theClass, theMethod) \
  extern "C" unsigned int  thePack##_##theClass##_##theMethod(JVMachine *, JVExecFrame *)
	    
// use unsigned int vs void.
#define Implement_NativeV2(thePack, theClass, theMethod) \
    unsigned int thePack##_##theClass##_##theMethod(JVMachine *machine, JVExecFrame *callFrame)


    // Plzen native function, with single package name.
#define Define_PlzenNative(thePack, theClass, theMethod) \
  extern "C" unsigned int plzn_##thePack##_##theClass##_##theMethod(JVMachine *, JVExecFrame *)

#define Implement_PlzenNative(thePack, theClass, theMethod) \
    unsigned int plzn_##thePack##_##theClass##_##theMethod(JVMachine *machine, JVExecFrame *callFrame)


    // Java native function, with single package name.
#define Define_JavaNative(thePack, theClass, theMethod) \
  extern "C" unsigned int java_##thePack##_##theClass##_##theMethod(JVMachine *, JVExecFrame *) \


#define Implement_JavaNative(thePack, theClass, theMethod) \
    unsigned int java_##thePack##_##theClass##_##theMethod(JVMachine *machine, JVExecFrame *callFrame)

#elif defined(_WIN32)
    // General native function, with single package name.
#define Define_Native(thePack, theClass, theMethod) \
    __declspec(dllexport) unsigned int thePack##_##theClass##_##theMethod(JVMachine *, JVExecFrame *)

#define Implement_Native(thePack, theClass, theMethod) \
    __declspec(dllexport) unsigned int thePack##_##theClass##_##theMethod(JVMachine *machine, JVExecFrame *callFrame)


#define Define_PlzenNative(thePack, theClass, theMethod) \
    __declspec(dllexport) unsigned int plzn_##thePack##_##theClass##_##theMethod(JVMachine *, JVExecFrame *)

#define Implement_PlzenNative(thePack, theClass, theMethod) \
    __declspec(dllexport) unsigned int plzn_##thePack##_##theClass##_##theMethod(JVMachine *machine, JVExecFrame *callFrame)

#define Define_JavaNative(thePack, theClass, theMethod) \
    __declspec(dllexport) unsigned int java_##thePack##_##theClass##_##theMethod(JVMachine *, JVExecFrame *)

#define Implement_JavaNative(thePack, theClass, theMethod) \
    __declspec(dllexport) unsigned int java_##thePack##_##theClass##_##theMethod(JVMachine *machine, JVExecFrame *callFrame)

#elif	/* _WIN32 */
#error "No OS definition for native lib"
#endif

#endif		/* _NATIVITY_H_ */

/**************************************************
* File: fileDescriptor.cc.
* Desc: Implementation of the native calls for the io_FileDescriptor class.
* Module: AkraLog : JavaKit.
* Rev: 15 aout 1996 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <iostream>

#include <native/nativity.h>
#include <vm/jmachine.h>
#include <vm/execFrame.h>
#include <vm/jvInstance.h>
#include <vm/stacks.h>
#include <vm/valueTypes.h>


// Function declarations
Define_JavaNative(io, FileDescriptor, valid);
Define_JavaNative(io, FileDescriptor, initSystemFD);


// Function implementations.
Implement_JavaNative(io, FileDescriptor, valid)
{
	// Should return a boolean.
    callFrame->returnInteger(1);
    return 0;
}


Implement_JavaNative(io, FileDescriptor, initSystemFD)
{
    JVInstance *descriptor;
    JVRunValue *tmpValue;
    static JVVariable *fdField= NULL;
    unsigned int descID;

    // Extract data from local value array.
    tmpValue= callFrame->getLocalValue(0);
    if (tmpValue != NULL) {
	descriptor= tmpValue->extractInstance();
     }
    tmpValue= callFrame->getLocalValue(1);
    if (tmpValue != NULL) {
	descID= tmpValue->extractInteger();
     }

    if (fdField == NULL) {
	fdField= machine->getFieldOfClass(descriptor->category(), "fd");
    }
    if (fdField != NULL) {
	JVRunValue *ioValue= new JVRunValue(TYPE_BASIC);
/* MOD-970415 [HD]: Porting issue.
	JVRunValue ioValue(TYPE_BASIC); 
*/
	switch(descID) {
	    case 0:
/* MOD-970415 [HD]: Porting issue.
		ioValue.setValue((void *)&cin);
*/
	        ioValue->setValue((void *)&std::cin);
	        break;
	    case 2:
/* MOD-970415 [HD]: Porting issue.
		ioValue.setValue((void *)&cerr);
*/
	        ioValue->setValue((void *)&std::cerr);
	        break;
	    default:
/* MOD-970415 [HD]: Porting issue.
		ioValue.setValue((void *)&cout);
*/
	        ioValue->setValue((void *)&std::cout);

	        break;
	 }
	descriptor->putField(*ioValue, fdField);
     }
    callFrame->returnInstance(descriptor);
    return 0;
}



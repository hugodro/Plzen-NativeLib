#ifndef _JDK_L_R_CONSTRUCTOR_H_
#define _JDK_L_R_CONSTRUCTOR_H_
/**************************************************
* File: constructor.h.
* Desc: Definition of the java.lang.reflect.Constructor support class, in C++.
* Module: AkraLog : Plzen.
* Rev: 18 mars 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/AkObject.h>
#include <akra/portableDefs.h>


class JVMachine;
class ClassFile;
class JVInstance;
class JVVariable;

class java_lang_reflect_Constructor : public AkObject {
  protected:	// Class variables.
    static JVVariable *clazzField, *slotField;
    static boolean mustFetchDict;

  public:	// Class methods.
    static boolean fetchDictionary(JVMachine *aMachine, ClassFile *aClass);

  protected:	// Instance variables.
    JVInstance *javaEquiv;

  public:	// Instance methods.
    java_lang_reflect_Constructor(JVInstance *anInstance, JVMachine *aMachine);

	// Field accessors.
    JVInstance *get_this(void);
    JVInstance get_clazz(void);
    int get_slot(void);
};


#endif	/* _JDK_L_R_CONSTRUCTOR_H_ */

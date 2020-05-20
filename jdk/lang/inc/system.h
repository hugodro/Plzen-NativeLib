#ifndef _JAVA_LANG_SYSTEM_H_
#define _JAVA_LANG_SYSTEM_H_
/**************************************************
* File: system.h.
* Desc: Definition of the System class.
* Module: AkraLog : JavaKit.
* Rev: 19 aout 1996 : REV 0 : Hugo DesRosiers (creation).
**************************************************/

#include <akra/AkObject.h>

class JVInstance;


class System : public AkObject {
  protected:

  public:
    static unsigned int arraycopy(JVInstance *src, unsigned int srcOffset, JVInstance *dest, unsigned int destOffset, unsigned int length);
};


#endif		/* _JAVA_LANG_SYSTEM_H_ */

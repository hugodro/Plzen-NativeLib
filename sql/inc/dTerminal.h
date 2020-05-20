#ifndef _DATAPIPE_LOW_H_
#define _DATAPIPE_LOW_H_
/**************************************************
* File: dTerminal.h.
* Desc: Definition of the plzen.sql.DataTerminal and associated support classes, in C++.
* Module: AkraLog : PlzenSql.
* Rev: 23 mai 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/AkObject.h>
#include <akra/portableDefs.h>

class JVMachine;
class ClassFile;
class JVInstance;
class JVVariable;

class ClassExport plzen_sql_DataPipe : public AkObject {
  protected:	// Class variables.
    static JVVariable *llowField;
    static JVVariable *terminalField;
    static bool mustFetchDict;

  public:	// Class methods.
    static bool fetchDictionary(JVMachine *aMachine, ClassFile *aClass);

  protected:	// Instance variables.
    JVInstance *javaEquiv;

  public:	// Instance methods.
    plzen_sql_DataPipe(JVInstance *anInstance, JVMachine *aMachine);
    ~plzen_sql_DataPipe(void);

	// Field accessors.
    JVInstance *get_this(void);
    int get_linkLow(void);
    JVInstance *get_terminal(void);
};
#endif		/* _DATAPIPE_LOW_H_ */

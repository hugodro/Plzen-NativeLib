#ifndef _MYSQL_SUPPORT_H_
#define _MYSQL_SUPPORT_H_
/**************************************************
* File: mysqlSupport.h.
* Desc: Definition of the plzen.sql.MySqlTerminal and associated support classes, in C++.
* Module: AkraLog : PlzenSql.
* Rev: 19 juillet 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/AkObject.h>
#include <akra/portableDefs.h>

#include "dTerminal.h"


class JVMachine;
class ClassFile;
class JVInstance;
class JVVariable;


class plzen_sql_MySqlTerminal : public AkObject {
  protected:	// Class variables.
    static JVVariable *llowField;
    static bool mustFetchDict;

  public:	// Class methods.
    static bool fetchDictionary(JVMachine *aMachine, ClassFile *aClass);

  protected:	// Instance variables.
    JVInstance *javaEquiv;

  public:	// Instance methods.
    plzen_sql_MySqlTerminal(JVInstance *anInstance, JVMachine *aMachine);
    ~plzen_sql_MySqlTerminal(void);

	// Field accessors.
    JVInstance *get_this(void);
    int get_linkLow(void);
};


#endif		/* _MYSQL_SUPPORT_H_ */

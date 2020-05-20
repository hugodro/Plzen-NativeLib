#ifndef _MYSQL_DATAPIPE_H_
#define _MYSQL_DATAPIPE_H_
/**************************************************
* File: mysqlPipe.h.
* Desc: Definition of the MySqlPipe class.
* Module: AkraLog : SqlSupport.
* Rev: 14 juillet 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include "sqlDataPipe.h"

class TextSqlEngine;
class MySqlTerminal;
class TextOutputBuffer;
class MySqlEngine;

class MySqlPipe : public SqlDataPipe {
  protected:
    bool hasTransaction;
    char cursorName[9];
    MySqlEngine *engine;
    TextOutputBuffer *outputBuffer;
    MySqlTerminal *terminal;

  public:
    MySqlPipe(JVInstance *anInstance);
    virtual ~MySqlPipe(void);
    virtual int execute(SqlExecFrame *aFrame, void **values, unsigned int nbrValues);
    virtual void installOnTerminal(MySqlTerminal *aTerminal);
    virtual SqlReplyValue **makeReplyArray(unsigned int aSize);
};


#endif		/* _MYSQL_DATAPIPE_H_ */

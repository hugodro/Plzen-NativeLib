#ifndef _SQL_MYSQL_TERMINAL_H_
#define _SQL_MYSQL_TERMINAL_H_
/**************************************************
* File: mysqlTerminal.h.
* Desc: Definition of the MySqlTerminal class.
* Module: AkraLog : SqlSupport.
* Rev: 23 mai 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include "sqlTerminal.h"


class JVInstance;


class MySqlTerminal : public SqlDataTerminal {
  protected:
    JVInstance *dual;		// Our Java equivalent.
    MYSQL *connection;
    char *host;
    char *options;
    char *port;
    char *pgTty;
    char *database;

  public:
    MySqlTerminal(JVInstance *anInstance);
    virtual int connectToServer(char **arguments, unsigned int nbrArguments);
    virtual bool disconnect(void);
    virtual bool hasConnection(void);
    virtual SqlDataPipe *createPipe(void);
    virtual MYSQL *getConnection(void);
};

#endif		/* _SQL_MYSQL_TERMINAL_H_ */


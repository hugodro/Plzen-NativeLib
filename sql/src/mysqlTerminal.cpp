/**************************************************
* File: mysqlTerminal.cc.
* Desc: Definition of the MySqlTerminal class.
* Module: AkraLog : SqlSupport.
* Rev: 23 mai 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <stdio.h>
#if defined(_WIN32)
typedef unsigned char byte;
#endif
#include <mysql/mysql.h>

#include "sqlDataPipe.h"
#include "mysqlTerminal.h"


MySqlTerminal::MySqlTerminal(JVInstance *anInstance)
{
    connection= new MYSQL;
    dual= anInstance;
}


int MySqlTerminal::connectToServer(char **arguments, unsigned int nbrArguments)
{
	MYSQL *newConn;
    char *connArgs[5]= { NULL, NULL, NULL, NULL, NULL };

    for (unsigned int i= 0; (i < 5) && (i < nbrArguments); i++) {
	connArgs[i]= arguments[i];
    }

    connArgs[0]= "localhost";	// TMPTMP.

	// Format: OldConnection, host, user, passwd..
	mysql_init(connection);
    newConn= mysql_real_connect(connection, "208.166.33.105", NULL, NULL, NULL,
				   3306, NULL, 0);
//    connection= mysql_connect(NULL, connArgs[0], connArgs[1], connArgs[2]);
    if (newConn == 0) {
	return -1;		// Warning: quick exit (No connection).
    }
    else {
	host= mysql_get_host_info(connection);
	options= mysql_get_server_info(connection);
	mysql_select_db(connection, "test");	// TMPTMP !
    }

    return 0;
}


bool MySqlTerminal::disconnect(void)
{
    mysql_close(connection);
    connection= NULL;
    return true;			// No way to find out if it didn't disconnect ?
}


bool MySqlTerminal::hasConnection(void)
{
    return (connection != NULL);
}


SqlDataPipe *MySqlTerminal::createPipe(void)
{
    return new SqlDataPipe(NULL);
}


MYSQL *MySqlTerminal::getConnection(void)
{
    return connection;
}


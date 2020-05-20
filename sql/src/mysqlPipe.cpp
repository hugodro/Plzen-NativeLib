/**************************************************
* File: mysqlPipe.cc.
* Desc: Implementation of the MySqlPipe class.
* Module: AkraLog : SqlSupport.
* Rev: 14 juillet 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/


#include <iostream.h>

#if defined(_WIN32)
typedef unsigned char byte;
#include <string.h>
#endif
#include <mysql/mysql.h>

#include <Compiler/sql3Support.h>
#include "mysqlTerminal.h"
#include "sqlDataPipe.h"
#include "mysqlEngine.h"
#include "textOutputBuffer.h"
#include "execFrame.h"
#include "sqlStatement.h"
#include "mysqlReply.h"
#include "mysqlPipe.h"


/**************************************************
* Implementation: MySqlPipe.
**************************************************/

MySqlPipe::MySqlPipe(JVInstance *anInstance)
    : SqlDataPipe(anInstance)
{
    hasTransaction= false;
    strcpy(cursorName, "aaaaaaaa");
    outputBuffer= new TextOutputBuffer();
    engine= new MySqlEngine(outputBuffer);
    engine->registerCursorName(cursorName);
}


MySqlPipe::~MySqlPipe(void)
{
    delete engine;
    delete outputBuffer;
}


int MySqlPipe::execute(SqlExecFrame *aFrame, void **values, unsigned int nbrValues)
{
    int result= -1;
    char *tmpResult;

    engine->execute(aFrame, values);
    tmpResult= outputBuffer->getCompactOutput();
    if (terminal) {
	MYSQL *conn= terminal->getConnection();
	MYSQL_RES *cmdResult;
	MYSQL_ROW aRow;
	int errorCode;

	if (aFrame->getStatement()->getMainAction() == SELECT_SNG_DATA) {
	    errorCode= mysql_query(conn, tmpResult);
	    if (errorCode == 0) {
		if ((cmdResult= mysql_use_result(conn)) != NULL) {
		    if ((aRow= mysql_fetch_row(cmdResult)) != NULL) {
			if (mysql_eof(cmdResult) != 0) {
			    // Error: more than a single row select.
			    result= -2;
			}
			else {
			    int j, fieldSize, fieldLength, replyWidth;
			    int fieldType;
			    MYSQL_FIELD *aField;

			    replyWidth= mysql_num_fields(cmdResult);
			    aFrame->allocForReply(replyWidth, this);
			    for (j= 0; j < replyWidth; j++) {
				aField= mysql_fetch_field(cmdResult);
				fieldType= (int)aField->type;
				fieldSize= aField->max_length;
				fieldLength= aField->length;
				aFrame->loadReply(j, fieldType, fieldSize, fieldLength, (char *)aRow[j]);
			    }
			    result= 0;
				// Make sure the fetch is EOF.
			    mysql_fetch_row(cmdResult);
			}
		    }
		    else result= -2;    // Error: no data returned.
		    mysql_free_result(cmdResult);

		}
		else result= -2;    // Error: no data returned.
	    }
	    else {
		// Error: query did not work.
		result= -3;
	    }
	}
	else {
	    errorCode= mysql_query(conn, tmpResult);
	    if (errorCode == 0) {
		result= 0;
	    }
	    else {
		// Error: query did not work.
		result= -3;
	    }
	}
    }

    return result;
}


void MySqlPipe::installOnTerminal(MySqlTerminal *aTerminal)
{
    terminal= aTerminal;
}


SqlReplyValue **MySqlPipe::makeReplyArray(unsigned int aSize)
{
    MySqlReplyValue **tmpHolder;
    unsigned int i;

    tmpHolder= new MySqlReplyValue *[aSize];
    tmpHolder[0]= new MySqlReplyValue[aSize];
    for (i= 1; i < aSize; i++) {
	tmpHolder[i]= tmpHolder[i-1] + 1;
    }
    return (SqlReplyValue **)tmpHolder;
}


#ifndef _SQLDATAPIPE_H_
#define _SQLDATAPIPE_H_
/**************************************************
* File: sqlDataPipe.h.
* Desc: Definition of the SqlDataPipe class.
* Module: AkraLog : SqlSupport.
* Rev: 23 mai 1998 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/AkObject.h>
#include <akra/portableDefs.h>

#include <sqlsup/dataPipe.h>

class JVInstance;
class SqlExecFrame;
class SqlStatement;
class Sql92Frame;
class Sql3Frame;
class JVOperStack;
class SqlReplyValue;

class ClassExport SqlDataPipe : public DataPipeGen {
  public:
    enum SqlConstant {
	sql92, sql3
    };

  public:
    static SqlStatement *sql92StatementCreator(unsigned char aToken);
    static SqlStatement *sql3StatementCreator(unsigned char aToken);

  protected:    // Instance variables.
    JVInstance *dual;		// Our Java equivalent.
    unsigned int tmpKnownCount;		// TMPTMP: keep track of known token strings.
    JVInstance *tmpKnownStrings[256];	// TMPTMP: known token strings. 
    SqlExecFrame *tmpKnownFrames[256];    // TMPTMP: known frame equivalents.

  public:
    SqlDataPipe(JVInstance *anObject);
    virtual SqlExecFrame *parseTokens(unsigned char *charArray, unsigned int dataLength, JVInstance *source);
    virtual SqlStatement *parseSql92(Sql92Frame *frame, unsigned char *constantBytes, unsigned char *tokenBytes, unsigned int version, unsigned int dataLength);
    virtual SqlStatement *parseSql3(Sql3Frame *frame, unsigned char *constantBytes, unsigned char *tokenBytes, unsigned int version, unsigned int dataLength);
    virtual SqlStatement *newStatementForToken(unsigned char aToken, SqlConstant sqlVersion);
    virtual int execute(SqlExecFrame *aFrame, void **values, unsigned int nbrValues);
    virtual bool putReplyOnStack(JVOperStack *operStack, unsigned int nbrValues);
    virtual SqlReplyValue **makeReplyArray(unsigned int aSize);
};


#endif	/* _SQLDATAPIPE_H_ */

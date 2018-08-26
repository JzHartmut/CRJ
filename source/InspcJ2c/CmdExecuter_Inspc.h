/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __InspcJ2c_CmdExecuter_Inspc_h__
#define __InspcJ2c_CmdExecuter_Inspc_h__

#include "emC/MemC_emC.h"        //basic concept

#include "Jc/ObjectJc.h"        //basic concept

#include "Jc/StringJc.h"        //used often

   //basic concept


/* J2C: Forward declaration of struct ***********************************************/
struct CmdConsumer_ifc_Inspc_t;
struct CmdExecuter_Inspc_t;
struct Comm_Inspc_t;


/* J2C: includes *********************************************************/
#include "InspcJ2c/AnswerComm_ifc_Inspc.h"  //interface
#include "InspcJ2c/InspcDataExchangeAccess_Inspc.h"  //embedded type in class data


/*@CLASS_C CmdExecuter_Inspc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct CmdExecuter_Inspc_t
{ 
  union { ObjectJc object; AnswerComm_ifc_Inspc_s AnswerComm_ifc_Inspc;} base; 
  InspcDatagram_InspcDataExchangeAccess_Inspc_s datagramCmd;   /*@ java2c=simpleRef. */
  Inspcitem_InspcDataExchangeAccess_Inspc_s infoCmd;   /*@ java2c=simpleRef. */
  struct CmdConsumer_ifc_Inspc_t* cmdConsumer;   /**/
  int32 maxNrofAnswerBytes; 
  int32 nrofBytesAnswer; 
  int32 nrofSentBytes; 
  int32 ctFailedTelgPart; 
  struct Comm_Inspc_t* comm;   /**/
  int8 data_bufferAnswerData[1400];   /*Buffer for the answer telegram. It should be less then the max length of an UDP telegram.*/
  PtrVal_int8 bufferAnswerData;   /*This reference is used to refer the answer buffer. It is for C usage with the PtrVal type which contains the address and the size*/
  InspcDatagram_InspcDataExchangeAccess_Inspc_s myAnswerData; 
  bool useTelgHead;   /*true than the myAnswerdata is of type DataExchangeTelg_Inspc, */
} CmdExecuter_Inspc_s;
  

#define sizeof_CmdExecuter_Inspc_s sizeof(CmdExecuter_Inspc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef CmdExecuter_InspcREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define CmdExecuter_InspcREFDEF
  struct CmdExecuter_Inspc_t;
  typedef TYPE_EnhancedRefJc(CmdExecuter_Inspc);
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct CmdExecuter_Inspc_X_t { ObjectArrayJc head; CmdExecuter_InspcREF data[50]; } CmdExecuter_Inspc_X;
typedef struct CmdExecuter_Inspc_Y_t { ObjectArrayJc head; CmdExecuter_Inspc_s data[50]; } CmdExecuter_Inspc_Y;

 extern_C struct ClassJc_t const reflection_CmdExecuter_Inspc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_CmdExecuter_Inspc(OBJP) { CONST_ObjectJc(sizeof(CmdExecuter_Inspc_s), OBJP, &reflection_CmdExecuter_Inspc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_CmdExecuter_Inspc_F(ObjectJc* othis, ThCxt* _thCxt);


 extern StringJc version_CmdExecuter_Inspc;   /*Version, history and license.*/

//!!usage: static init code, invoke that one time in start of main.
void initStatic_CmdExecuter_Inspc();




METHOD_C struct CmdExecuter_Inspc_t* ctorO_CmdExecuter_Inspc(ObjectJc* othis, struct CmdConsumer_ifc_Inspc_t* commandConsumer, ThCxt* _thCxt);

typedef void MT_completeConstruction_CmdExecuter_Inspc(CmdExecuter_Inspc_s* thiz, struct Comm_Inspc_t* comm, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void completeConstruction_CmdExecuter_Inspc_F(CmdExecuter_Inspc_s* thiz, struct Comm_Inspc_t* comm, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void completeConstruction_CmdExecuter_Inspc(CmdExecuter_Inspc_s* thiz, struct Comm_Inspc_t* comm, ThCxt* _thCxt);

/**Executes the given command received with this datagram
*/
typedef bool MT_executeCmd_CmdExecuter_Inspc(CmdExecuter_Inspc_s* thiz, PtrVal_int8 buffer, int32 nrofBytesReceived, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C bool executeCmd_CmdExecuter_Inspc_F(CmdExecuter_Inspc_s* thiz, PtrVal_int8 buffer, int32 nrofBytesReceived, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C bool executeCmd_CmdExecuter_Inspc(CmdExecuter_Inspc_s* thiz, PtrVal_int8 buffer, int32 nrofBytesReceived, ThCxt* _thCxt);

/**Send the current answer datagram as answer. Firstly the {@link InspcDataExchangeAccess.InspcDatagram#incrAnswerNr()}
was invoked, therewith an answer starts with 1. That increment is important for more as one answer datagrams. 
The head is initialized only one time with the data from the request telegram, the answerNr is incremented always. 
The length of the datagram is set to the head using {@link InspcDataExchangeAccess.InspcDatagram#setLengthDatagram(int)}

@see org.vishia.inspectorTarget.AnswerComm_ifc#txAnswer(int, boolean)
*/
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 txAnswer_ib_CmdExecuter_Inspc_F(ObjectJc* ithis, int32 nrofAnswerBytesPart, bool bLastTelg, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 txAnswer_ib_CmdExecuter_Inspc(ObjectJc* ithis, int32 nrofAnswerBytesPart, bool bLastTelg, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_CmdExecuter_Inspc[]; //marker for methodTable check
typedef struct Mtbl_CmdExecuter_Inspc_t
{ MtblHeadJc head;
  MT_completeConstruction_CmdExecuter_Inspc* completeConstruction;
  MT_executeCmd_CmdExecuter_Inspc* executeCmd;
  Mtbl_ObjectJc ObjectJc;
  //Method table of interfaces:
  Mtbl_AnswerComm_ifc_Inspc AnswerComm_ifc_Inspc;
} Mtbl_CmdExecuter_Inspc;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class CmdExecuter_Inspc : private CmdExecuter_Inspc_s
{ public:

  virtual void completeConstruction(struct Comm_Inspc_t* comm){ completeConstruction_CmdExecuter_Inspc_F(this, comm,  null/*_thCxt*/); }

  CmdExecuter_Inspc(struct CmdConsumer_ifc_Inspc_t* commandConsumer){ init_ObjectJc(&this->base.object, sizeof(CmdExecuter_Inspc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_CmdExecuter_Inspc_s, 0); ctorO_CmdExecuter_Inspc(&this->base.object, commandConsumer,  null/*_thCxt*/); }

  virtual bool executeCmd(PtrVal_int8 buffer, int32 nrofBytesReceived){  return executeCmd_CmdExecuter_Inspc_F(this, buffer, nrofBytesReceived,  null/*_thCxt*/); }

  virtual int32 txAnswer(int32 nrofAnswerBytesPart, bool bLastTelg){  return txAnswer_ib_CmdExecuter_Inspc_F(&this->base.AnswerComm_ifc_Inspc.base.object, nrofAnswerBytesPart, bLastTelg,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__InspcJ2c_CmdExecuter_Inspc_h__

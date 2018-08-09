/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __InspcJ2c_Comm_Inspc_h__
#define __InspcJ2c_Comm_Inspc_h__

#include "emC/MemC.h"        //basic concept

#include "Jc/ObjectJc.h"        //basic concept

#include "Jc/StringJc.h"        //used often

#include "emC/Exception.h"   //basic concept


/* J2C: Forward declaration of struct ***********************************************/
struct Address_InterProcessComm_t;
struct CmdExecuter_Inspc_t;
struct Comm_Inspc_t;
struct InterProcessComm_t;
struct ThreadJc_t;


/* J2C: includes *********************************************************/
#include "Jc/ThreadJc.h"  //interface


/*@CLASS_C Comm_Inspc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct Comm_Inspc_t
{ 
  union { ObjectJc object; RunnableJc_s RunnableJc;} base; 
  struct CmdExecuter_Inspc_t* cmdExecuter;   /**/
  char state;   /*State of function.*/
  bool bEnablePrintfOnComm; 
  struct InterProcessComm_t* ipc;   /**/
  int32 ctErrorTelg; 
  struct ThreadJc_t* thread;   /**/
  int32 nrofBytesReceived[1];   /**/
  int8 data_rxBuffer[1500];   /*Use a static receive buffer. It is important for C-applications. */
  PtrVal_int8 rxBuffer;   /*For C: store the reference and length of the SimpleArray in the next structure. */
  struct Address_InterProcessComm_t* myAnswerAddress;   /**/
} Comm_Inspc_s;
  

#define sizeof_Comm_Inspc_s sizeof(Comm_Inspc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef Comm_InspcREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define Comm_InspcREFDEF
  struct Comm_Inspc_t;
  typedef TYPE_EnhancedRefJc(Comm_Inspc);
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct Comm_Inspc_X_t { ObjectArrayJc head; Comm_InspcREF data[50]; } Comm_Inspc_X;
typedef struct Comm_Inspc_Y_t { ObjectArrayJc head; Comm_Inspc_s data[50]; } Comm_Inspc_Y;

 extern_C struct ClassJc_t const reflection_Comm_Inspc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_Comm_Inspc(OBJP) { CONST_ObjectJc(sizeof(Comm_Inspc_s), OBJP, &reflection_Comm_Inspc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_Comm_Inspc_F(ObjectJc* othis, ThCxt* _thCxt);


#define version_Comm_Inspc 0x20111118  /*Version and history*/


/**Creates the communication for the inspector.
* The InterProcessComm interface implementation is got depending on
* <ul><li>the ownAddrIpc-string
* <li>the existing InterProcessComm-Implementation, which analyzes the address-string.
* <ul>
* It means, the communication is not determined from this implementation, it depends
* on the parameter of the ownAddrIpc and the possibilities. 
* */
METHOD_C struct Comm_Inspc_t* ctorO_Comm_Inspc(ObjectJc* othis, StringJc ownAddrIpc, struct CmdExecuter_Inspc_t* cmdExecuter, ThCxt* _thCxt);

METHOD_C void dtor_Comm_Inspc(Comm_Inspc_s* thiz, ThCxt* _thCxt);

METHOD_C bool openComm_Comm_Inspc(Comm_Inspc_s* thiz, bool blocking, ThCxt* _thCxt);

METHOD_C void start_Comm_Inspc(Comm_Inspc_s* thiz, ThCxt* _thCxt);

/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void run_Comm_Inspc_F(ObjectJc* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void run_Comm_Inspc(ObjectJc* ithis, ThCxt* _thCxt);

METHOD_C void receiveAndExecute_Comm_Inspc(Comm_Inspc_s* thiz, ThCxt* _thCxt);

/**Sends the answer telg to the sender of the received telegram. 
If the receiving process fails, the answer isn't send. This situation can occur only 
if the preparation of the answer runs in another thread.
*/
METHOD_C int32 sendAnswer_Comm_Inspc(Comm_Inspc_s* thiz, PtrVal_int8 bufferAnswerData, int32 nrofBytesAnswer, ThCxt* _thCxt);

/**Shutdown the communication, close the thread. This routine should be called 
either on shutdown of the whole system or on closing the inspector functionality.
The inspector functionality can be restarted calling {@link #start(Object)}.
*/
typedef void MT_shutdown_Comm_Inspc(Comm_Inspc_s* thiz, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void shutdown_Comm_Inspc_F(Comm_Inspc_s* thiz, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void shutdown_Comm_Inspc(Comm_Inspc_s* thiz, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_Comm_Inspc[]; //marker for methodTable check
typedef struct Mtbl_Comm_Inspc_t
{ MtblHeadJc head;
  MT_shutdown_Comm_Inspc* shutdown;
  Mtbl_ObjectJc ObjectJc;
  //Method table of interfaces:
  Mtbl_RunnableJc RunnableJc;
} Mtbl_Comm_Inspc;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class Comm_Inspc : private Comm_Inspc_s
{ public:

  Comm_Inspc(StringJcpp ownAddrIpc, struct CmdExecuter_Inspc_t* cmdExecuter){ init_ObjectJc(&this->base.object, sizeof(Comm_Inspc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_Comm_Inspc_s, 0); ctorO_Comm_Inspc(&this->base.object, ownAddrIpc, cmdExecuter,  null/*_thCxt*/); }

  bool openComm(bool blocking){  return openComm_Comm_Inspc(this, blocking,  null/*_thCxt*/); }

  void receiveAndExecute(){ receiveAndExecute_Comm_Inspc(this,  null/*_thCxt*/); }

  virtual void run(){ run_Comm_Inspc_F(&this->base.RunnableJc.base.object,  null/*_thCxt*/); }

  int32 sendAnswer(PtrVal_int8 bufferAnswerData, int32 nrofBytesAnswer){  return sendAnswer_Comm_Inspc(this, bufferAnswerData, nrofBytesAnswer,  null/*_thCxt*/); }

  virtual void shutdown(){ shutdown_Comm_Inspc_F(this,  null/*_thCxt*/); }

  void start(){ start_Comm_Inspc(this,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__InspcJ2c_Comm_Inspc_h__

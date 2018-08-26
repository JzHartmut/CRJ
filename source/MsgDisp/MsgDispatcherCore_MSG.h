/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __MsgDisp_MsgDispatcherCore_MSG_h__
#define __MsgDisp_MsgDispatcherCore_MSG_h__

#include "emC/MemC_emC.h"        //basic concept

#include "Jc/ObjectJc.h"        //basic concept

#include "Jc/StringJc.h"        //used often

   //basic concept


/* J2C: Forward declaration of struct ***********************************************/
struct ConcurrentLinkedQueueJc_t;
struct Entry_MsgDispatcherCore_MSG_t;
struct MsgDispatcherCore_MSG_t;
struct MsgText_ifc_MSG_t;
struct Output_MsgDispatcherCore_MSG_t;
struct RunnableJc_t;
struct TestCnt_MsgDispatcherCore_MSG_t;


/* J2C: Enhanced references *********************************************************
 * In this part all here used enhanced references are defined conditionally.
 * The inclusion of all that header files isn't necessary, to prevent circular inclusion.
 * It is adequate a struct pointer forward declaration.
 */
#ifndef LogMessageFWREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define LogMessageFWREFDEF
  struct LogMessageFW_t;
  typedef TYPE_EnhancedRefJc(LogMessageFW);
#endif
#ifndef MsgText_ifc_MSGREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define MsgText_ifc_MSGREFDEF
  struct MsgText_ifc_MSG_t;
  typedef TYPE_EnhancedRefJc(MsgText_ifc_MSG);
#endif
#ifndef RunnableJcREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define RunnableJcREFDEF
  struct RunnableJc_t;
  typedef TYPE_EnhancedRefJc(RunnableJc);
#endif


/* J2C: includes *********************************************************/
#include "emC/LogMessage.h"  //interface
#include "Jc/StringJc.h"  //embedded type in class data
#include "emC/VaArgBuffer.h"  //embedded type in class data
#include "os_time.h"  //embedded type in class data


/*@CLASS_C Entry_MsgDispatcherCore_MSG @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct Entry_MsgDispatcherCore_MSG_t
{ 
  int32 ident;   /*Bit31 is set if the state is coming, 0 if it is going. */
  int32 dst;   /*The bits of destination dispatching are ascertained already before it is taken in the queue. */
  char const* text;   /*The output and format controlling text. In C it should be a reference to a persistent,*/
  OS_TimeStamp timestamp;   /*The time stamp of the message. It is detected before the message is queued. */
  VaArgBuffer values;   /*Values from variable argument list. This is a special structure */
} Entry_MsgDispatcherCore_MSG_s;
  

#define sizeof_Entry_MsgDispatcherCore_MSG_s sizeof(Entry_MsgDispatcherCore_MSG_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef Entry_MsgDispatcherCore_MSGREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define Entry_MsgDispatcherCore_MSGREFDEF
  struct Entry_MsgDispatcherCore_MSG_t;
  typedef TYPE_EnhancedRefJc(Entry_MsgDispatcherCore_MSG);
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct Entry_MsgDispatcherCore_MSG_X_t { ObjectArrayJc head; Entry_MsgDispatcherCore_MSGREF data[50]; } Entry_MsgDispatcherCore_MSG_X;
typedef struct Entry_MsgDispatcherCore_MSG_Y_t { ObjectArrayJc head; Entry_MsgDispatcherCore_MSG_s data[50]; } Entry_MsgDispatcherCore_MSG_Y;

 extern_C struct ClassJc_t const reflection_Entry_MsgDispatcherCore_MSG_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_Entry_MsgDispatcherCore_MSG(OBJP) { CONST_ObjectJc(sizeof(Entry_MsgDispatcherCore_MSG_s), OBJP, &reflection_Entry_MsgDispatcherCore_MSG_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_Entry_MsgDispatcherCore_MSG_F(Entry_MsgDispatcherCore_MSG_s* thiz, ThCxt* _thCxt);




/**Default constructor. */
METHOD_C struct Entry_MsgDispatcherCore_MSG_t* ctorM_Entry_MsgDispatcherCore_MSG(MemC mthis, ThCxt* _thCxt);

METHOD_C int32 _sizeof_Entry_MsgDispatcherCore_MSG(/*J2C:static method*/ ThCxt* _thCxt);


#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class Entry_MsgDispatcherCore_MSG : private Entry_MsgDispatcherCore_MSG_s
{ public:

  int32 _sizeof(){  return _sizeof_Entry_MsgDispatcherCore_MSG( null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/



/*@CLASS_C TestCnt_MsgDispatcherCore_MSG @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct TestCnt_MsgDispatcherCore_MSG_t
{ 
  union { ObjectJc object; } base; 
  int32 noOutput; 
  int32 tomuchMsgPerThread; 
} TestCnt_MsgDispatcherCore_MSG_s;
  

#define sizeof_TestCnt_MsgDispatcherCore_MSG_s sizeof(TestCnt_MsgDispatcherCore_MSG_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef TestCnt_MsgDispatcherCore_MSGREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define TestCnt_MsgDispatcherCore_MSGREFDEF
  struct TestCnt_MsgDispatcherCore_MSG_t;
  typedef TYPE_EnhancedRefJc(TestCnt_MsgDispatcherCore_MSG);
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct TestCnt_MsgDispatcherCore_MSG_X_t { ObjectArrayJc head; TestCnt_MsgDispatcherCore_MSGREF data[50]; } TestCnt_MsgDispatcherCore_MSG_X;
typedef struct TestCnt_MsgDispatcherCore_MSG_Y_t { ObjectArrayJc head; TestCnt_MsgDispatcherCore_MSG_s data[50]; } TestCnt_MsgDispatcherCore_MSG_Y;

 extern_C struct ClassJc_t const reflection_TestCnt_MsgDispatcherCore_MSG_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_TestCnt_MsgDispatcherCore_MSG(OBJP) { CONST_ObjectJc(sizeof(TestCnt_MsgDispatcherCore_MSG_s), OBJP, &reflection_TestCnt_MsgDispatcherCore_MSG_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_TestCnt_MsgDispatcherCore_MSG_F(ObjectJc* othis, ThCxt* _thCxt);




/**Default constructor. */
METHOD_C struct TestCnt_MsgDispatcherCore_MSG_t* ctorO_TestCnt_MsgDispatcherCore_MSG(ObjectJc* othis, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_TestCnt_MsgDispatcherCore_MSG[]; //marker for methodTable check
typedef struct Mtbl_TestCnt_MsgDispatcherCore_MSG_t
{ MtblHeadJc head;
  Mtbl_ObjectJc ObjectJc;
} Mtbl_TestCnt_MsgDispatcherCore_MSG;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class TestCnt_MsgDispatcherCore_MSG : private TestCnt_MsgDispatcherCore_MSG_s
{ public:

  TestCnt_MsgDispatcherCore_MSG(){ init_ObjectJc(&this->base.object, sizeof(TestCnt_MsgDispatcherCore_MSG_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_TestCnt_MsgDispatcherCore_MSG_s, 0); ctorO_TestCnt_MsgDispatcherCore_MSG(&this->base.object,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/



/*@CLASS_C Output_MsgDispatcherCore_MSG @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct Output_MsgDispatcherCore_MSG_t
{ 
  StringJc name;   /*Short name of the destination, used for {@link #setOutputRange } or {@link #setOutputFromString }*/
  LogMessageFWREF outputIfc;   /*The output interface. */
  bool dstInDispatcherThread;   /*true if this output is processed in the dispatcher thread, */
  bool bUseText;   /*Bit which indicates that the text information field of {@link #sendMsgVaList(int, OS_TimeStamp, String, Va_list)} is used.*/
} Output_MsgDispatcherCore_MSG_s;
  

#define sizeof_Output_MsgDispatcherCore_MSG_s sizeof(Output_MsgDispatcherCore_MSG_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef Output_MsgDispatcherCore_MSGREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define Output_MsgDispatcherCore_MSGREFDEF
  struct Output_MsgDispatcherCore_MSG_t;
  typedef TYPE_EnhancedRefJc(Output_MsgDispatcherCore_MSG);
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct Output_MsgDispatcherCore_MSG_X_t { ObjectArrayJc head; Output_MsgDispatcherCore_MSGREF data[50]; } Output_MsgDispatcherCore_MSG_X;
typedef struct Output_MsgDispatcherCore_MSG_Y_t { ObjectArrayJc head; Output_MsgDispatcherCore_MSG_s data[50]; } Output_MsgDispatcherCore_MSG_Y;

 extern_C struct ClassJc_t const reflection_Output_MsgDispatcherCore_MSG_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_Output_MsgDispatcherCore_MSG(OBJP) { CONST_ObjectJc(sizeof(Output_MsgDispatcherCore_MSG_s), OBJP, &reflection_Output_MsgDispatcherCore_MSG_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_Output_MsgDispatcherCore_MSG_F(Output_MsgDispatcherCore_MSG_s* thiz, ThCxt* _thCxt);




/**Default constructor. */
METHOD_C struct Output_MsgDispatcherCore_MSG_t* ctorM_Output_MsgDispatcherCore_MSG(MemC mthis, ThCxt* _thCxt);


#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class Output_MsgDispatcherCore_MSG : private Output_MsgDispatcherCore_MSG_s
{ public:
};

#endif /*__CPLUSPLUSJcpp*/



/*@CLASS_C MsgDispatcherCore_MSG @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct MsgDispatcherCore_MSG_t
{ 
  union { ObjectJc object; LogMessageFW_s LogMessageFW;} base; 
  int32 nrofMixedOutputs;   /*Number of Bits in {@link mDispatchWithBits}, it is the number of destinations dispatched via bit mask. */
  int32 mDstMixedOutputs;   /*Calculated mask of bits which are able to mix. */
  int32 mDstOneOutput;   /*Calculated mask of bits which are one index. */
  int64 idThreadForDispatching; 
  TestCnt_MsgDispatcherCore_MSG_s testCnt; 
  struct ConcurrentLinkedQueueJc_t* listOrders;   /*List of messages to process in the dispatcher thread.*/
  struct ConcurrentLinkedQueueJc_t* freeOrders;   /*List of entries for messages to use. For C usage it is a List with a fix size.*/
  Entry_MsgDispatcherCore_MSG_s entryMsgBufferOverflow; 
  int32 actNrofListIdents;   /*List of idents, its current length. */
  int32_Y* listIdents;   /*List of idents, a array with lengthListIdents elements.*/
  int32_Y* listBitDst;   /*List of destination bits for the idents.*/
  Output_MsgDispatcherCore_MSG_Y* outputs;   /*up to 30 destinations for output.*/
  MsgText_ifc_MSGREF msgText;   /*Converter from the ident number to a text. Maybe null, then unused.*/
  RunnableJcREF runNoEntryMessage; 
  int32 ctLostMessages; 
} MsgDispatcherCore_MSG_s;
  

#define sizeof_MsgDispatcherCore_MSG_s sizeof(MsgDispatcherCore_MSG_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef MsgDispatcherCore_MSGREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define MsgDispatcherCore_MSGREFDEF
  struct MsgDispatcherCore_MSG_t;
  typedef TYPE_EnhancedRefJc(MsgDispatcherCore_MSG);
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct MsgDispatcherCore_MSG_X_t { ObjectArrayJc head; MsgDispatcherCore_MSGREF data[50]; } MsgDispatcherCore_MSG_X;
typedef struct MsgDispatcherCore_MSG_Y_t { ObjectArrayJc head; MsgDispatcherCore_MSG_s data[50]; } MsgDispatcherCore_MSG_Y;

 extern_C struct ClassJc_t const reflection_MsgDispatcherCore_MSG_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_MsgDispatcherCore_MSG(OBJP) { CONST_ObjectJc(sizeof(MsgDispatcherCore_MSG_s), OBJP, &reflection_MsgDispatcherCore_MSG_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_MsgDispatcherCore_MSG_F(ObjectJc* othis, ThCxt* _thCxt);


#define version_MsgDispatcherCore_MSG 20130302  /*version, history and license.*/
#define mDispatchInDispatcherThread_MsgDispatcherCore_MSG 0x80000000  /*If this bit is set in the bitmask for dispatching, the dispatching should be done */
#define mDispatchInCallingThread_MsgDispatcherCore_MSG 0x40000000  /*If this bit is set in the bitmask for dispatching, the dispatching should only be done */
#define mDispatchBits_MsgDispatcherCore_MSG 0x3fffffff  /*Only this bits are used to indicate the destination via some Bits*/
#define mConsole_MsgDispatcherCore_MSG 0x1  /*Mask for dispatch the message to console directly in the calling thread. */
#define mConsoleQueued_MsgDispatcherCore_MSG 0x2  /*queued Console output, it is a fix part of the Message dispatcher. */
#define mAdd_MsgDispatcherCore_MSG 0xcadd  /*Used for argument mode from {@link #setOutputRange(int, int, int, int, int)} to add an output.*/
#define mSet_MsgDispatcherCore_MSG 0xc5ed  /*Used for argument mode from {@link #setOutputRange(int, int, int, int, int)} to set an output.*/
#define mRemove_MsgDispatcherCore_MSG 0xcde1  /*Used for argument mode from {@link #setOutputRange(int, int, int, int, int)} to remove an output.*/


/**Initializes the instance.
*/
METHOD_C struct MsgDispatcherCore_MSG_t* ctorO_MsgDispatcherCore_MSG(ObjectJc* othis, int32 maxQueue, int32 nrofMixedOutputs, struct RunnableJc_t* runNoEntryMessage, ThCxt* _thCxt);

/**Sets the capability that messages which are create in the dispatcher thread are output immediately
though the output channel should be used in the dispatcher thread. The advantage of that capability
is given 
<ul>
<li>Especially on startup for messages of startup. Often the {@link #tickAndFlushOrClose()} is started
after continue the startup routine but in the same main thread. 
The startup messages should be seen without delay, especially on problems on startup.
<li>If some algorithm are done in a main thread, which dispatches the messages too. Then no ressources
to store message entries are necessary, and the messages comes out immediately, helpfull on debugging.
It may be typically that algorithm of calculation are executed in the same thread like dispatching.
</ul>     
*/
typedef void MT_setIdThreadForMsgDispatching_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, int64 idThread, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void setIdThreadForMsgDispatching_MsgDispatcherCore_MSG_F(MsgDispatcherCore_MSG_s* thiz, int64 idThread, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void setIdThreadForMsgDispatching_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, int64 idThread, ThCxt* _thCxt);

METHOD_C void setMsgTextConverter_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, struct MsgText_ifc_MSG_t* converter, ThCxt* _thCxt);

/**Searches and returns the bits where a message is dispatch to.
The return value describes what to do with the message.
*/
METHOD_C int32 searchDispatchBits_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, int32 ident, ThCxt* _thCxt);

/**Sends a message. See interface.  
*/
METHOD_C bool sendMsg_izv_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, int32 identNumber, char const* text, char const* args, ...);

/**Sends a message. See interface.  
*/
METHOD_C bool sendMsgTime_iDtzv_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, int32 identNumber, OS_TimeStamp creationTime, char const* text, char const* args, ...);

/**Sends a message. See interface.  
*/
METHOD_C bool sendMsgVaList_iDtzv_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, int32 identNumber, OS_TimeStamp creationTime, char const* text, Va_listFW args, ThCxt* _thCxt);

METHOD_C bool isOnline_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, ThCxt* _thCxt);

/**This routine may be overridden by the inherited class (usual {@link MsgDispatcher} to support closing.
@see org.vishia.msgDispatch.LogMessage#close()
*/
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void close_MsgDispatcherCore_MSG_F(LogMessageFW_s* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void close_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, ThCxt* _thCxt);

/**This routine may be overridden by the inherited class (usual {@link MsgDispatcher} to support flushing
all queued messages.
@see org.vishia.msgDispatch.LogMessage#close()
*/
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void flush_MsgDispatcherCore_MSG_F(LogMessageFW_s* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void flush_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, ThCxt* _thCxt);

/**Dispatches the queues messages, after them calls {@link LogMessage#flush()} for all queued outputs.
This method can be called in any user thread cyclically. 
As opposite the {@link DispatcherThread} can be instantiate and {@link DispatcherThread#start()}. 
That thread calls only this routine in its cycle. 
*/
METHOD_C void tickAndFlushOrClose_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, ThCxt* _thCxt);

/**Dispatches all messages, which are stored in the queue. 
This routine should be called in a user thread or maybe in the background loop respectively the main thread. 
This routine is called in {@link #tickAndFlushOrClose()} and in @ {@link #flush()} and link #close()}.
*/
METHOD_C int32 dispatchQueuedMsg_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, ThCxt* _thCxt);

/**Dispatches a message. This routine is called either in the calling thread of the message
or in the dispatcher thread. 
*/
METHOD_C int32 dispatchMsg_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, int32 dstBits, bool bDispatchInDispatcherThread, bool bDispatchAlways, int32 identNumber, OS_TimeStamp creationTime, char const* text, Va_listFW args, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_MsgDispatcherCore_MSG[]; //marker for methodTable check
typedef struct Mtbl_MsgDispatcherCore_MSG_t
{ MtblHeadJc head;
  MT_setIdThreadForMsgDispatching_MsgDispatcherCore_MSG* setIdThreadForMsgDispatching;
  Mtbl_ObjectJc ObjectJc;
  //Method table of interfaces:
  Mtbl_LogMessageFW LogMessageFW;
} Mtbl_MsgDispatcherCore_MSG;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class MsgDispatcherCore_MSG : private MsgDispatcherCore_MSG_s
{ public:

  virtual void close(){ close_MsgDispatcherCore_MSG_F(&this->base.LogMessageFW,  null/*_thCxt*/); }

  MsgDispatcherCore_MSG(int32 maxQueue, int32 nrofMixedOutputs, struct RunnableJc_t* runNoEntryMessage){ init_ObjectJc(&this->base.object, sizeof(MsgDispatcherCore_MSG_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_MsgDispatcherCore_MSG_s, 0); ctorO_MsgDispatcherCore_MSG(&this->base.object, maxQueue, nrofMixedOutputs, runNoEntryMessage,  null/*_thCxt*/); }

  int32 dispatchMsg(int32 dstBits, bool bDispatchInDispatcherThread, bool bDispatchAlways, int32 identNumber, OS_TimeStamp creationTime, char const* text, Va_listFW args){  return dispatchMsg_MsgDispatcherCore_MSG(this, dstBits, bDispatchInDispatcherThread, bDispatchAlways, identNumber, creationTime, text, args,  null/*_thCxt*/); }

  int32 dispatchQueuedMsg(){  return dispatchQueuedMsg_MsgDispatcherCore_MSG(this,  null/*_thCxt*/); }

  virtual void flush(){ flush_MsgDispatcherCore_MSG_F(&this->base.LogMessageFW,  null/*_thCxt*/); }

  bool isOnline(){  return isOnline_MsgDispatcherCore_MSG(&this->base.LogMessageFW,  null/*_thCxt*/); }

  int32 searchDispatchBits(int32 ident){  return searchDispatchBits_MsgDispatcherCore_MSG(this, ident,  null/*_thCxt*/); }

  bool sendMsgTime(int32 identNumber, OS_TimeStamp creationTime, char const* text, char const* args, ...){  return sendMsgTime_iDtzv_MsgDispatcherCore_MSG(&this->base.LogMessageFW, identNumber, creationTime, text, args); }

  bool sendMsgVaList(int32 identNumber, OS_TimeStamp creationTime, char const* text, Va_listFW args){  return sendMsgVaList_iDtzv_MsgDispatcherCore_MSG(&this->base.LogMessageFW, identNumber, creationTime, text, args,  null/*_thCxt*/); }

  bool sendMsg(int32 identNumber, char const* text, char const* args, ...){  return sendMsg_izv_MsgDispatcherCore_MSG(&this->base.LogMessageFW, identNumber, text, args); }

  virtual void setIdThreadForMsgDispatching(int64 idThread){ setIdThreadForMsgDispatching_MsgDispatcherCore_MSG_F(this, idThread,  null/*_thCxt*/); }

  void setMsgTextConverter(struct MsgText_ifc_MSG_t* converter){ setMsgTextConverter_MsgDispatcherCore_MSG(this, converter,  null/*_thCxt*/); }

  void tickAndFlushOrClose(){ tickAndFlushOrClose_MsgDispatcherCore_MSG(this,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__MsgDisp_MsgDispatcherCore_MSG_h__

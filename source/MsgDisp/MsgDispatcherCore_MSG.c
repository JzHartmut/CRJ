/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "MsgDisp/MsgDispatcherCore_MSG.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <emC/Exception.h>  //basic stacktrace concept
#include "emC/MemC.h"  //embedded type in class data
#include "Jc/ArraysJc.h"  //reference-association: ArraysJc
#include "Jc/ConcurrentLinkedQueueJc.h"  //new object
#include "Jc/ThreadJc.h"  //reference-association: ThreadJc_s
#include "MsgDisp/MsgText_ifc_MSG.h"  //reference-association: msgText


/* J2C: Forward declaration of struct ***********************************************/
struct LogMessageFW_t;
struct ThreadJc_t;

/**This is the core of the message dispatcher. It dispatches only. 
The dispatch table maybe filled with a simplest algorithm. 
This class is able to use in a simple environment.

@author Hartmut Schorrig

*/


const char sign_Mtbl_MsgDispatcherCore_MSG[] = "MsgDispatcherCore_MSG"; //to mark method tables of all implementations

typedef struct MtblDef_MsgDispatcherCore_MSG_t { Mtbl_MsgDispatcherCore_MSG mtbl; MtblHeadJc end; } MtblDef_MsgDispatcherCore_MSG;
 extern MtblDef_MsgDispatcherCore_MSG const mtblMsgDispatcherCore_MSG;

/*Constructor */
struct MsgDispatcherCore_MSG_t* ctorO_MsgDispatcherCore_MSG(ObjectJc* othis, int32 maxQueue, int32 nrofMixedOutputs, struct RunnableJc_t* runNoEntryMessage, ThCxt* _thCxt)
{ MsgDispatcherCore_MSG_s* thiz = (MsgDispatcherCore_MSG_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_MsgDispatcherCore_MSG");
  checkConsistence_ObjectJc(othis, sizeof(MsgDispatcherCore_MSG_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_MsgDispatcherCore_MSG_s, sizeof(MsgDispatcherCore_MSG_s));  
  //j2c: Initialize all class variables:
  {
    //J2C: constructor for embedded element-ObjectJc
      init_ObjectJc(&(thiz->testCnt.base.object), sizeof(thiz->testCnt), 0); 
      ctorO_TestCnt_MsgDispatcherCore_MSG(/*J2C:static method call*/&(thiz->testCnt.base.object), _thCxt);
    //J2C: constructor for embedded element-MemC
      ctorM_Entry_MsgDispatcherCore_MSG(/*J2C:static method call*/build_MemC(&thiz->entryMsgBufferOverflow, sizeof(thiz->entryMsgBufferOverflow)), _thCxt);
  }
  { 
    ObjectJc *newObj2_1=null, *newObj2_2=null; /*J2C: temporary Objects for new operations
    */
    SETREFJc(thiz->runNoEntryMessage, runNoEntryMessage, RunnableJc_s);
    thiz->nrofMixedOutputs = nrofMixedOutputs;
    if(nrofMixedOutputs < 0 || nrofMixedOutputs > 28) { throw_s0Jc(ident_IllegalArgumentExceptionJc, "max. nrofMixedOutputs", 0, &_thCxt->stacktrc, __LINE__); return 0; };
    thiz->mDstMixedOutputs = (1 << nrofMixedOutputs) - 1;
    thiz->mDstOneOutput = mDispatchBits_MsgDispatcherCore_MSG & ~thiz->mDstMixedOutputs;
    
    MemC  mNodes = alloc_MemC(/*J2C:static method call*/(maxQueue + 2) * sizeof(Entry_MsgDispatcherCore_MSG_s));
    thiz->freeOrders = ctorO_MemC_ConcurrentLinkedQueueJc(/*J2C:static method call*/(newObj2_1 = alloc_ObjectJc(sizeof_ConcurrentLinkedQueueJc_s, 0, _thCxt)), mNodes, _thCxt);
    thiz->listOrders = ctorO_Clq_ConcurrentLinkedQueueJc(/*J2C:static method call*/(newObj2_2 = alloc_ObjectJc(sizeof_ConcurrentLinkedQueueJc_s, 0, _thCxt)), thiz->freeOrders, _thCxt);
    activateGC_ObjectJc(newObj2_1, null, _thCxt);
    activateGC_ObjectJc(newObj2_2, null, _thCxt);
  }
  STACKTRC_LEAVE;
  return thiz;
}



/**Sets the capability that messages which are create in the dispatcher thread are output immediately*/
void setIdThreadForMsgDispatching_MsgDispatcherCore_MSG_F(MsgDispatcherCore_MSG_s* thiz, int64 idThread, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setIdThreadForMsgDispatching_MsgDispatcherCore_MSG_F");
  
  { 
    
    thiz->idThreadForDispatching = idThread;
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void setIdThreadForMsgDispatching_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, int64 idThread, ThCxt* _thCxt)
{ Mtbl_MsgDispatcherCore_MSG const* mtbl = (Mtbl_MsgDispatcherCore_MSG const*)getMtbl_ObjectJc(&thiz->base.object, sign_Mtbl_MsgDispatcherCore_MSG);
  mtbl->setIdThreadForMsgDispatching(thiz, idThread, _thCxt);
}

void setMsgTextConverter_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, struct MsgText_ifc_MSG_t* converter, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setMsgTextConverter_MsgDispatcherCore_MSG");
  
  { 
    
    SETREFJc(thiz->msgText, converter, MsgText_ifc_MSG_s);
  }
  STACKTRC_LEAVE;
}


/**Searches and returns the bits where a message is dispatch to.*/
int32 searchDispatchBits_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, int32 ident, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("searchDispatchBits_MsgDispatcherCore_MSG");
  
  { 
    
    
    int32  bitDst;/*no initvalue*/
    if(ident < 0) 
    { 
      
      /**a negative ident means: going state. The absolute value is to dispatch! */
      ident = -ident;
    }
    
    int32  idx = binarySearch_int_ii_ArraysJc(/*J2C:static method call*/thiz->listIdents/*J2C-error testAndChangeAccess: XY*/, 0, thiz->actNrofListIdents, ident, _thCxt);
    if(idx < 0) idx = -idx - 2;/*example: nr between idx=2 and 3 returns -4, converted to 2*/
    
    if(idx < 0) idx = 0;/*if nr before idx = 0, use properties of msg nr=0*/
    
    bitDst = thiz->listBitDst->data[idx];
    { STACKTRC_LEAVE;
      return bitDst;
    }
  }
  STACKTRC_LEAVE;
}


/**Sends a message. See interface.  */
bool sendMsg_izv_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, int32 identNumber, char const* text, char const* args, ...)
{ MsgDispatcherCore_MSG_s* thiz = (MsgDispatcherCore_MSG_s*)ithis;
  
  STACKTRC_ENTRY("sendMsg_izv_MsgDispatcherCore_MSG");
  
  { 
    
    
    Va_listFW  vaArgs;va_start(vaArgs.args, args); vaArgs.typeArgs = args;
    { STACKTRC_LEAVE;
      return sendMsgVaList_iDtzv_MsgDispatcherCore_MSG(& ((* (thiz)).base.LogMessageFW)/*J2cT1*/, identNumber, os_getDateTime(), text, vaArgs, _thCxt);
    }
  }
  STACKTRC_LEAVE;
}


/**Sends a message. See interface.  */
bool sendMsgTime_iDtzv_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, int32 identNumber, OS_TimeStamp creationTime, char const* text, char const* args, ...)
{ MsgDispatcherCore_MSG_s* thiz = (MsgDispatcherCore_MSG_s*)ithis;
  
  STACKTRC_ENTRY("sendMsgTime_iDtzv_MsgDispatcherCore_MSG");
  
  { 
    
    
    Va_listFW  vaArgs;va_start(vaArgs.args, args); vaArgs.typeArgs = args;
    { STACKTRC_LEAVE;
      return sendMsgVaList_iDtzv_MsgDispatcherCore_MSG(& ((* (thiz)).base.LogMessageFW)/*J2cT1*/, identNumber, creationTime, text, vaArgs, _thCxt);
    }
  }
  STACKTRC_LEAVE;
}


/**Sends a message. See interface.  */
bool sendMsgVaList_iDtzv_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, int32 identNumber, OS_TimeStamp creationTime, char const* text, Va_listFW args, ThCxt* _thCxt)
{ MsgDispatcherCore_MSG_s* thiz = (MsgDispatcherCore_MSG_s*)ithis;
  
  STACKTRC_TENTRY("sendMsgVaList_iDtzv_MsgDispatcherCore_MSG");
  
  { 
    
    
    int32  dstBits = searchDispatchBits_MsgDispatcherCore_MSG(thiz, identNumber, _thCxt);
    if(dstBits != 0) 
    { 
      struct ThreadJc_t* _temp3_1; /*J2C: temporary references for concatenation */
      
      
      int32  dstBitsForDispatcherThread;/*no initvalue*/
      
      bool  bDispatchAlways = thiz->idThreadForDispatching != 0 && 
        ( _temp3_1= currentThread_ThreadJc(/*J2C:static method call*/_thCxt)
        , getId_ThreadJc(_temp3_1)
        ) == thiz->idThreadForDispatching;
      if((dstBits & mDispatchInCallingThread_MsgDispatcherCore_MSG) != 0 || bDispatchAlways) 
      { 
        
        /**dispatch in this calling thread: */
        dstBitsForDispatcherThread = dispatchMsg_MsgDispatcherCore_MSG(thiz, dstBits, false, bDispatchAlways, identNumber, creationTime, text, args, _thCxt);
      }
      else 
      { 
        
        /**No destinations are to use in calling thread. */
        dstBitsForDispatcherThread = dstBits;
      }/*if((dstBits & mDispatchInDispatcherThread) != 0)*/
      
      if(dstBitsForDispatcherThread != 0) 
      { 
        
        
        struct Entry_MsgDispatcherCore_MSG_t*  entry = ((/*J2C:cast from void*/Entry_MsgDispatcherCore_MSG_s*)(poll_ConcurrentLinkedQueueJc(thiz->freeOrders, _thCxt)));
        if(entry == null) 
        { 
          
          /**queue overflow, no entries available. The message can't be displayed*/
          if(REFJc(thiz->runNoEntryMessage)!= null) /**queue overflow, no entries available. The message can't be displayed*/
          
          { 
            
            /**queue overflow, no entries available. The message can't be displayed*/
            run_RunnableJc(&((REFJc (thiz->runNoEntryMessage))->base.object), _thCxt);
          }
          if(++thiz->ctLostMessages == 0) 
          { 
            
            thiz->ctLostMessages = 1;
          }/*never reaches 0 after incrementation.*/
          
        }
        else 
        { 
          
          /**write the informations to the entry, store it. */
          entry->dst = dstBitsForDispatcherThread;
          entry->ident = identNumber;
          entry->text = text;
          set_OS_TimeStamp(entry->timestamp, creationTime);
          copyFrom_VaArgBuffer(& (entry->values), text, args, _thCxt);
          offer_ConcurrentLinkedQueueJc(thiz->listOrders, entry, _thCxt);
        }
      }
    }
    { STACKTRC_LEAVE;
      return true;
    }
  }
  STACKTRC_LEAVE;
}

bool isOnline_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, ThCxt* _thCxt)
{ MsgDispatcherCore_MSG_s* thiz = (MsgDispatcherCore_MSG_s*)ithis;
  
  STACKTRC_TENTRY("isOnline_MsgDispatcherCore_MSG");
  
  { 
    
    { STACKTRC_LEAVE;
      return true;
    }
  }
  STACKTRC_LEAVE;
}


/**This routine may be overridden by the inherited class (usual {@link MsgDispatcher} to support closing.*/
void close_MsgDispatcherCore_MSG_F(LogMessageFW_s* ithis, ThCxt* _thCxt)
{ MsgDispatcherCore_MSG_s* thiz = (MsgDispatcherCore_MSG_s*)ithis;
  
  STACKTRC_TENTRY("close_MsgDispatcherCore_MSG_F");
  
  { 
    
    
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void close_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, ThCxt* _thCxt)
{ Mtbl_LogMessageFW const* mtbl = (Mtbl_LogMessageFW const*)getMtbl_ObjectJc(&ithis->base.object, sign_Mtbl_LogMessageFW);
  mtbl->close((LogMessageFW_s*)ithis, _thCxt);
}


/**This routine may be overridden by the inherited class (usual {@link MsgDispatcher} to support flushing*/
void flush_MsgDispatcherCore_MSG_F(LogMessageFW_s* ithis, ThCxt* _thCxt)
{ MsgDispatcherCore_MSG_s* thiz = (MsgDispatcherCore_MSG_s*)ithis;
  
  STACKTRC_TENTRY("flush_MsgDispatcherCore_MSG_F");
  
  { 
    
    
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void flush_MsgDispatcherCore_MSG(LogMessageFW_s* ithis, ThCxt* _thCxt)
{ Mtbl_LogMessageFW const* mtbl = (Mtbl_LogMessageFW const*)getMtbl_ObjectJc(&ithis->base.object, sign_Mtbl_LogMessageFW);
  mtbl->flush((LogMessageFW_s*)ithis, _thCxt);
}


/**Dispatches the queues messages, after them calls {@link LogMessage#flush()} for all queued outputs.*/
void tickAndFlushOrClose_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("tickAndFlushOrClose_MsgDispatcherCore_MSG");
  
  { 
    
    dispatchQueuedMsg_MsgDispatcherCore_MSG(thiz, _thCxt);
    { int32 ix; 
      for(ix = 0; ix < thiz->outputs->head.length; ix++)
        { 
          
          
          struct Output_MsgDispatcherCore_MSG_t*  output = & (thiz->outputs->data[ix]);
          if(output->dstInDispatcherThread) 
          { 
            
            flush_LogMessageFW(REFJc (output->outputIfc), _thCxt);
          }
        }
    }
  }
  STACKTRC_LEAVE;
}


/**Dispatches all messages, which are stored in the queue. */
int32 dispatchQueuedMsg_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("dispatchQueuedMsg_MsgDispatcherCore_MSG");
  
  { 
    
    
    int32  nrofFoundMsg = 0;
    
    int32  cntDispatchedMsg = 100;
    
    bool  bCont;/*no initvalue*/
    
    struct Entry_MsgDispatcherCore_MSG_t*  firstNotSentMsg = null;
    do 
      { 
        
        
        struct Entry_MsgDispatcherCore_MSG_t*  entry = ((/*J2C:cast from void*/Entry_MsgDispatcherCore_MSG_s*)(poll_ConcurrentLinkedQueueJc(thiz->listOrders, _thCxt)));
        bCont = (entry != null && entry != firstNotSentMsg);
        if(bCont) 
        { 
          
          nrofFoundMsg += 1;
          dispatchMsg_MsgDispatcherCore_MSG(thiz, entry->dst, true, false, entry->ident, entry->timestamp, entry->text, get_va_list_VaArgBuffer(& (entry->values), _thCxt), _thCxt);
          clean_VaArgBuffer(& (entry->values), _thCxt);
          entry->ident = 0;
          offer_ConcurrentLinkedQueueJc(thiz->freeOrders, entry, _thCxt);
        }
      }while(bCont && (--cntDispatchedMsg) >= 0);/*The buffer is empty yet.*/
    
    if(thiz->ctLostMessages > 0) 
    { /*:dispatch the message about overflow of queued message.*/
      
      
      setArg_VaArgBuffer(& (thiz->entryMsgBufferOverflow.values), 0, thiz->ctLostMessages, _thCxt);/*Note: In this time after readout the queue till set ctLostMessage to 0 an newly overflow may be occurred.*/
      
      thiz->ctLostMessages = 0;
      
      int32  dstBits = searchDispatchBits_MsgDispatcherCore_MSG(thiz, thiz->entryMsgBufferOverflow.ident, _thCxt);
      set_OS_TimeStamp(thiz->entryMsgBufferOverflow.timestamp, os_getDateTime());/*/*/
      
      dispatchMsg_MsgDispatcherCore_MSG(thiz, dstBits, true, false, thiz->entryMsgBufferOverflow.ident, thiz->entryMsgBufferOverflow.timestamp, thiz->entryMsgBufferOverflow.text, get_va_list_VaArgBuffer(& (thiz->entryMsgBufferOverflow.values), _thCxt), _thCxt);
    }
    if(cntDispatchedMsg == 0) 
    { /*:printf("MsgDisp: WARNING to much messages in queue\n");*/
      
      
      /**Count this situation to enable to inspect it. */
      thiz->testCnt.tomuchMsgPerThread += 1;
    }
    { STACKTRC_LEAVE;
      return nrofFoundMsg;
    }
  }
  STACKTRC_LEAVE;
}


/**Dispatches a message. This routine is called either in the calling thread of the message*/
int32 dispatchMsg_MsgDispatcherCore_MSG(MsgDispatcherCore_MSG_s* thiz, int32 dstBits, bool bDispatchInDispatcherThread, bool bDispatchAlways, int32 identNumber, OS_TimeStamp creationTime, char const* text, Va_listFW args, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("dispatchMsg_MsgDispatcherCore_MSG");
  
  { /*:final boolean bDispatchInDispatcherThread = (dstBits & mDispatchInDispatcherThread)!=0;*/
    /*:assert, that dstBits is positive, because >>=1 and 0-test fails elsewhere.*/
    /*:The highest Bit has an extra meaning, also extract above.*/
    
    
    dstBits &= mDispatchBits_MsgDispatcherCore_MSG;
    
    int32  bitTest = 0x1;
    
    int32  idst = 0;
    
    char const*  sTextMsg = text;
    
    bool  bMsgTextGotten = false;
    
    while(dstBits != 0 && bitTest < mDispatchBits_MsgDispatcherCore_MSG)
      { 
        
        if((dstBits & bitTest) != 0 && (bDispatchAlways || (thiz->outputs->data[idst].dstInDispatcherThread && bDispatchInDispatcherThread) || (!thiz->outputs->data[idst].dstInDispatcherThread && !bDispatchInDispatcherThread))) 
        { 
          
          
          struct Output_MsgDispatcherCore_MSG_t*  channel = & (thiz->outputs->data[idst]);
          
          struct LogMessageFW_t*  out = REFJc (channel->outputIfc);
          if(out != null) 
          { 
            
            if(!bMsgTextGotten && REFJc(thiz->msgText)!= null && channel->bUseText) 
            { 
              
              bMsgTextGotten = true;
              sTextMsg = getMsgText_MsgText_ifc_MSG(&((REFJc (thiz->msgText))->base.object), identNumber, _thCxt);
              if(sTextMsg == null || isEmpty_s0_emC(sTextMsg)) 
              { 
                
                sTextMsg = text;/*replace the input text if a new one is found.*/
                
              }
            }
            
            bool  sent = ((/*J2C:cast% from void*/bool)(sendMsgVaList_LogMessageFW(out, identNumber, creationTime, sTextMsg, args, _thCxt)));
            if(sent) 
            { 
              
              dstBits &= ~bitTest;/*if sent, reset the associated bit.*/
              
            }
          }
          else 
          { 
            
            dstBits &= ~bitTest;/*reset the associated bit, send isn't possible*/
            
            thiz->testCnt.noOutput += 1;
          }
        }
        bitTest <<= 1;
        idst += 1;
      }
    { STACKTRC_LEAVE;
      return dstBits;
    }
  }
  STACKTRC_LEAVE;
}


void finalize_MsgDispatcherCore_MSG_F(ObjectJc* othis, ThCxt* _thCxt)
{ MsgDispatcherCore_MSG_s* thiz = (MsgDispatcherCore_MSG_s*)othis;  //upcasting to the real class.
 STACKTRC_TENTRY("finalize_MsgDispatcherCore_MSG_F");
  finalize_ObjectJc_F(&thiz->testCnt.base.object, _thCxt); //J2C: finalizing the embedded instance.
  CLEAR_REFJc(thiz->msgText);
  CLEAR_REFJc(thiz->runNoEntryMessage);
  finalize_ObjectJc_F(&thiz->base.object, _thCxt); //J2C: finalizing the superclass.
  STACKTRC_LEAVE;
}




/**J2C: Reflections and Method-table *************************************************/
const MtblDef_MsgDispatcherCore_MSG mtblMsgDispatcherCore_MSG = {
{ { sign_Mtbl_MsgDispatcherCore_MSG //J2C: Head of methodtable of MsgDispatcherCore_MSG
  , (struct Size_Mtbl_t*)((1 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
  }
  //J2C: Dynamic methods of the class :MsgDispatcherCore_MSG:
, setIdThreadForMsgDispatching_MsgDispatcherCore_MSG_F //setIdThreadForMsgDispatching
  //J2C: The superclass's methodtable: 
, { { sign_Mtbl_ObjectJc //J2C: Head of methodtable of ObjectJc
    , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
    }
    //J2C: Dynamic methods of the class :ObjectJc:
  , clone_ObjectJc_F //clone
  , equals_ObjectJc_F //equals
  , finalize_MsgDispatcherCore_MSG_F //finalize
  , hashCode_ObjectJc_F //hashCode
  , toString_ObjectJc_F //toString
  }
  //J2C: The interface's methodtable: 
  //J2C: Mtbl-interfaces of :MsgDispatcherCore_MSG: */
, { { sign_Mtbl_LogMessageFW //J2C: Head of methodtable of LogMessageFW
    , (struct Size_Mtbl_t*)((6 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
    }
    //J2C: Dynamic methods of the class :LogMessageFW:
  , sendMsgVaList_iDtzv_MsgDispatcherCore_MSG //sendMsgVaList
  , flush_MsgDispatcherCore_MSG_F //flush
  , close_MsgDispatcherCore_MSG_F //close
  , isOnline_MsgDispatcherCore_MSG //isOnline
  , sendMsg_izv_MsgDispatcherCore_MSG //sendMsg
  , sendMsgTime_iDtzv_MsgDispatcherCore_MSG //sendMsgTime
    //J2C: The superclass's methodtable: 
  , { { sign_Mtbl_ObjectJc //J2C: Head of methodtable of ObjectJc
      , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
      }
      //J2C: Dynamic methods of the class :ObjectJc:
    , clone_ObjectJc_F //clone
    , equals_ObjectJc_F //equals
    , finalize_MsgDispatcherCore_MSG_F //finalize
    , hashCode_ObjectJc_F //hashCode
    , toString_ObjectJc_F //toString
    }
  }
}, { signEnd_Mtbl_ObjectJc, null } }; //Mtbl


 extern_C struct ClassJc_t const reflection_ObjectJc;
 static struct superClasses_MsgDispatcherCore_MSG_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_MsgDispatcherCore_MSG_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_MsgDispatcherCore_MSG, ObjectJc) }
   }
 };

 extern_C struct ClassJc_t const reflection_LogMessageFW_s;
 static struct ifcClasses_MsgDispatcherCore_MSG_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }interfaces_MsgDispatcherCore_MSG_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
, { {&reflection_LogMessageFW_s, OFFSET_Mtbl(Mtbl_MsgDispatcherCore_MSG, LogMessageFW) }
  }
};

extern_C struct ClassJc_t const reflection_MsgDispatcherCore_MSG_s;
extern_C struct ClassJc_t const reflection_ConcurrentLinkedQueueJc_s;
extern_C struct ClassJc_t const reflection_Entry_MsgDispatcherCore_MSG_s;
extern_C struct ClassJc_t const reflection_MsgText_ifc_MSG_s;
extern_C struct ClassJc_t const reflection_Output_MsgDispatcherCore_MSG_s;
extern_C struct ClassJc_t const reflection_RunnableJc_s;
extern_C struct ClassJc_t const reflection_TestCnt_MsgDispatcherCore_MSG_s;
const struct Reflection_Fields_MsgDispatcherCore_MSG_s_t
{ ObjectArrayJc head; FieldJc data[15];
} reflection_Fields_MsgDispatcherCore_MSG_s =
{ CONST_ObjectArrayJc(FieldJc, 15, OBJTYPE_FieldJc, null, &reflection_Fields_MsgDispatcherCore_MSG_s)
, {
     { "nrofMixedOutputs"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->nrofMixedOutputs) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "mDstMixedOutputs"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->mDstMixedOutputs) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "mDstOneOutput"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->mDstOneOutput) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "idThreadForDispatching"
    , 0 //nrofArrayElements
    , REFLECTION_int64
    , 8 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->idThreadForDispatching) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "testCnt"
    , 0 //nrofArrayElements
    , &reflection_TestCnt_MsgDispatcherCore_MSG_s
    , kEmbedded_Modifier_reflectJc |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->testCnt) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "listOrders"
    , 0 //nrofArrayElements
    , &reflection_ConcurrentLinkedQueueJc_s
    , kReference_Modifier_reflectJc |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->listOrders) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "freeOrders"
    , 0 //nrofArrayElements
    , &reflection_ConcurrentLinkedQueueJc_s
    , kReference_Modifier_reflectJc |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->freeOrders) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "entryMsgBufferOverflow"
    , 0 //nrofArrayElements
    , &reflection_Entry_MsgDispatcherCore_MSG_s
    , kEmbedded_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->entryMsgBufferOverflow) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "actNrofListIdents"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->actNrofListIdents) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "listIdents"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc |kObjectArrayJc_Modifier_reflectJc |kReferencedContainer_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->listIdents) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "listBitDst"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc |kObjectArrayJc_Modifier_reflectJc |kReferencedContainer_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->listBitDst) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "outputs"
    , 0 //nrofArrayElements
    , &reflection_Output_MsgDispatcherCore_MSG_s
    , kEmbedded_Modifier_reflectJc |kObjectArrayJc_Modifier_reflectJc |kReferencedContainer_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->outputs) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "msgText"
    , 0 //nrofArrayElements
    , &reflection_MsgText_ifc_MSG_s
    , kEnhancedReference_Modifier_reflectJc /*@*/ |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->msgText) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "runNoEntryMessage"
    , 0 //nrofArrayElements
    , &reflection_RunnableJc_s
    , kEnhancedReference_Modifier_reflectJc /*@*/ |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->runNoEntryMessage) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
   , { "ctLostMessages"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->ctLostMessages) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgDispatcherCore_MSG_s
    }
} };
const ClassJc reflection_MsgDispatcherCore_MSG_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "MsgDispatcherCore_MSG_s"
, (int16)((int32)(&((MsgDispatcherCore_MSG_s*)(0x1000))->base.object) - (int32)(MsgDispatcherCore_MSG_s*)0x1000)
, sizeof(MsgDispatcherCore_MSG_s)
, (FieldJc_Y const*)&reflection_Fields_MsgDispatcherCore_MSG_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_MsgDispatcherCore_MSG_s //superclass
, (ClassOffset_idxMtblJcARRAY*)&interfaces_MsgDispatcherCore_MSG_s //interfaces
, mObjectJc_Modifier_reflectJc
, &mtblMsgDispatcherCore_MSG.mtbl.head
};

/**Stores all data of a message if the message is queued here. */


const char sign_Mtbl_Entry_MsgDispatcherCore_MSG[] = "Entry_MsgDispatcherCore_MSG"; //to mark method tables of all implementations


/*Constructor *//**J2C: autogenerated as default constructor. */
struct Entry_MsgDispatcherCore_MSG_t* ctorM_Entry_MsgDispatcherCore_MSG(MemC mthis, ThCxt* _thCxt)
{ Entry_MsgDispatcherCore_MSG_s* thiz = PTR_MemC(mthis, Entry_MsgDispatcherCore_MSG_s);  //reference casting to the real class.
  int sizeObj = size_MemC(mthis);
  STACKTRC_TENTRY("ctor_Entry_MsgDispatcherCore_MSG");
  if(sizeof(Entry_MsgDispatcherCore_MSG_s) > sizeObj) THROW_s0(IllegalArgumentException, "faut size", sizeObj);
  //j2c: Initialize all class variables:
  {
    //J2C: constructor for embedded element
      INIT_OS_TimeStamp(/*J2C:static method call*/thiz->timestamp);
    //J2C: constructor for embedded element-MemC
      ctorM_VaArgBuffer(/*J2C:static method call*/build_MemC(&thiz->values, sizeof(thiz->values)), 11, _thCxt);
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return thiz;
}


int32 _sizeof_Entry_MsgDispatcherCore_MSG(/*J2C:static method*/ ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("_sizeof_Entry_MsgDispatcherCore_MSG");
  
  { 
    
    { STACKTRC_LEAVE;
      return 1;
    }
  }
  STACKTRC_LEAVE;
}

extern_C struct ClassJc_t const reflection_Entry_MsgDispatcherCore_MSG_s;
extern_C struct ClassJc_t const reflection_OS_TimeStamp;
extern_C struct ClassJc_t const reflection_VaArgBuffer;
const struct Reflection_Fields_Entry_MsgDispatcherCore_MSG_s_t
{ ObjectArrayJc head; FieldJc data[5];
} reflection_Fields_Entry_MsgDispatcherCore_MSG_s =
{ CONST_ObjectArrayJc(FieldJc, 5, OBJTYPE_FieldJc, null, &reflection_Fields_Entry_MsgDispatcherCore_MSG_s)
, {
     { "ident"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Entry_MsgDispatcherCore_MSG_s*)(0x1000))->ident) - (int32)(Entry_MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Entry_MsgDispatcherCore_MSG_s
    }
   , { "dst"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Entry_MsgDispatcherCore_MSG_s*)(0x1000))->dst) - (int32)(Entry_MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Entry_MsgDispatcherCore_MSG_s
    }
   , { "text"
    , 0 //nrofArrayElements
    , REFLECTION_char
    , mReference_Modifier_reflectJc//bitModifiers
    , (int16)((int32)(&((Entry_MsgDispatcherCore_MSG_s*)(0x1000))->text) - (int32)(Entry_MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Entry_MsgDispatcherCore_MSG_s
    }
   , { "timestamp"
    , 0 //nrofArrayElements
    , &reflection_OS_TimeStamp
    , kEmbedded_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Entry_MsgDispatcherCore_MSG_s*)(0x1000))->timestamp) - (int32)(Entry_MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Entry_MsgDispatcherCore_MSG_s
    }
   , { "values"
    , 0 //nrofArrayElements
    , &reflection_VaArgBuffer
    , kEmbedded_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Entry_MsgDispatcherCore_MSG_s*)(0x1000))->values) - (int32)(Entry_MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Entry_MsgDispatcherCore_MSG_s
    }
} };
const ClassJc reflection_Entry_MsgDispatcherCore_MSG_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "Entry_MsgDispatche_ore_MSG_s"
,  0 //position of ObjectJc
, sizeof(Entry_MsgDispatcherCore_MSG_s)
, (FieldJc_Y const*)&reflection_Fields_Entry_MsgDispatcherCore_MSG_s
, null //method
, null //superclass
, null //interfaces
, 0    //modifiers
};

/**This class contains some test-counts for debugging. It is a own class because structuring of attributes. 
@xxxjava2c=noObject.  //NOTE: ctor without ObjectJc not implemented yet.
*/


const char sign_Mtbl_TestCnt_MsgDispatcherCore_MSG[] = "TestCnt_MsgDispatcherCore_MSG"; //to mark method tables of all implementations

typedef struct MtblDef_TestCnt_MsgDispatcherCore_MSG_t { Mtbl_TestCnt_MsgDispatcherCore_MSG mtbl; MtblHeadJc end; } MtblDef_TestCnt_MsgDispatcherCore_MSG;
 extern MtblDef_TestCnt_MsgDispatcherCore_MSG const mtblTestCnt_MsgDispatcherCore_MSG;

/*Constructor *//**J2C: autogenerated as default constructor. */
struct TestCnt_MsgDispatcherCore_MSG_t* ctorO_TestCnt_MsgDispatcherCore_MSG(ObjectJc* othis, ThCxt* _thCxt)
{ TestCnt_MsgDispatcherCore_MSG_s* thiz = (TestCnt_MsgDispatcherCore_MSG_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_TestCnt_MsgDispatcherCore_MSG");
  checkConsistence_ObjectJc(othis, sizeof(TestCnt_MsgDispatcherCore_MSG_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_TestCnt_MsgDispatcherCore_MSG_s, sizeof(TestCnt_MsgDispatcherCore_MSG_s));  
  //j2c: Initialize all class variables:
  {
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return thiz;
}




/**J2C: Reflections and Method-table *************************************************/
const MtblDef_TestCnt_MsgDispatcherCore_MSG mtblTestCnt_MsgDispatcherCore_MSG = {
{ { sign_Mtbl_TestCnt_MsgDispatcherCore_MSG //J2C: Head of methodtable of TestCnt_MsgDispatcherCore_MSG
  , (struct Size_Mtbl_t*)((0 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
  }
  //J2C: The superclass's methodtable: 
, { { sign_Mtbl_ObjectJc //J2C: Head of methodtable of ObjectJc
    , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
    }
    //J2C: Dynamic methods of the class :ObjectJc:
  , clone_ObjectJc_F //clone
  , equals_ObjectJc_F //equals
  , finalize_ObjectJc_F //finalize
  , hashCode_ObjectJc_F //hashCode
  , toString_ObjectJc_F //toString
  }
}, { signEnd_Mtbl_ObjectJc, null } }; //Mtbl


 extern_C struct ClassJc_t const reflection_ObjectJc;
 static struct superClasses_TestCnt_MsgDispatcherCore_MSG_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_TestCnt_MsgDispatcherCore_MSG_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_TestCnt_MsgDispatcherCore_MSG, ObjectJc) }
   }
 };

extern_C struct ClassJc_t const reflection_TestCnt_MsgDispatcherCore_MSG_s;
const struct Reflection_Fields_TestCnt_MsgDispatcherCore_MSG_s_t
{ ObjectArrayJc head; FieldJc data[2];
} reflection_Fields_TestCnt_MsgDispatcherCore_MSG_s =
{ CONST_ObjectArrayJc(FieldJc, 2, OBJTYPE_FieldJc, null, &reflection_Fields_TestCnt_MsgDispatcherCore_MSG_s)
, {
     { "noOutput"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestCnt_MsgDispatcherCore_MSG_s*)(0x1000))->noOutput) - (int32)(TestCnt_MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestCnt_MsgDispatcherCore_MSG_s
    }
   , { "tomuchMsgPerThread"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestCnt_MsgDispatcherCore_MSG_s*)(0x1000))->tomuchMsgPerThread) - (int32)(TestCnt_MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestCnt_MsgDispatcherCore_MSG_s
    }
} };
const ClassJc reflection_TestCnt_MsgDispatcherCore_MSG_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "TestCnt_MsgDispatc_ore_MSG_s"
,  0 //position of ObjectJc
, sizeof(TestCnt_MsgDispatcherCore_MSG_s)
, (FieldJc_Y const*)&reflection_Fields_TestCnt_MsgDispatcherCore_MSG_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_TestCnt_MsgDispatcherCore_MSG_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblTestCnt_MsgDispatcherCore_MSG.mtbl.head
};

/**This class contains all infomations for a output. There is an array of this type in MsgDispatcher. 
*/


const char sign_Mtbl_Output_MsgDispatcherCore_MSG[] = "Output_MsgDispatcherCore_MSG"; //to mark method tables of all implementations


/*Constructor *//**J2C: autogenerated as default constructor. */
struct Output_MsgDispatcherCore_MSG_t* ctorM_Output_MsgDispatcherCore_MSG(MemC mthis, ThCxt* _thCxt)
{ Output_MsgDispatcherCore_MSG_s* thiz = PTR_MemC(mthis, Output_MsgDispatcherCore_MSG_s);  //reference casting to the real class.
  int sizeObj = size_MemC(mthis);
  STACKTRC_TENTRY("ctor_Output_MsgDispatcherCore_MSG");
  if(sizeof(Output_MsgDispatcherCore_MSG_s) > sizeObj) THROW_s0(IllegalArgumentException, "faut size", sizeObj);
  //j2c: Initialize all class variables:
  {
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return thiz;
}



void finalize_Output_MsgDispatcherCore_MSG_F(Output_MsgDispatcherCore_MSG_s* thiz, ThCxt* _thCxt)
{ STACKTRC_TENTRY("finalize_Output_MsgDispatcherCore_MSG_F");
  CLEAR_REFJc(thiz->outputIfc);
  STACKTRC_LEAVE;
}


extern_C struct ClassJc_t const reflection_Output_MsgDispatcherCore_MSG_s;
extern_C struct ClassJc_t const reflection_LogMessageFW_s;
extern_C struct ClassJc_t const reflection_StringJc;
const struct Reflection_Fields_Output_MsgDispatcherCore_MSG_s_t
{ ObjectArrayJc head; FieldJc data[4];
} reflection_Fields_Output_MsgDispatcherCore_MSG_s =
{ CONST_ObjectArrayJc(FieldJc, 4, OBJTYPE_FieldJc, null, &reflection_Fields_Output_MsgDispatcherCore_MSG_s)
, {
     { "name"
    , 0 //nrofArrayElements
    , &reflection_StringJc
    , kEnhancedReference_Modifier_reflectJc /*t*/ //bitModifiers
    , (int16)((int32)(&((Output_MsgDispatcherCore_MSG_s*)(0x1000))->name) - (int32)(Output_MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Output_MsgDispatcherCore_MSG_s
    }
   , { "outputIfc"
    , 0 //nrofArrayElements
    , &reflection_LogMessageFW_s
    , kEnhancedReference_Modifier_reflectJc /*@*/ |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Output_MsgDispatcherCore_MSG_s*)(0x1000))->outputIfc) - (int32)(Output_MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Output_MsgDispatcherCore_MSG_s
    }
   , { "dstInDispatcherThread"
    , 0 //nrofArrayElements
    , REFLECTION_bool
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Output_MsgDispatcherCore_MSG_s*)(0x1000))->dstInDispatcherThread) - (int32)(Output_MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Output_MsgDispatcherCore_MSG_s
    }
   , { "bUseText"
    , 0 //nrofArrayElements
    , REFLECTION_bool
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Output_MsgDispatcherCore_MSG_s*)(0x1000))->bUseText) - (int32)(Output_MsgDispatcherCore_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Output_MsgDispatcherCore_MSG_s
    }
} };
const ClassJc reflection_Output_MsgDispatcherCore_MSG_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "Output_MsgDispatch_ore_MSG_s"
,  0 //position of ObjectJc
, sizeof(Output_MsgDispatcherCore_MSG_s)
, (FieldJc_Y const*)&reflection_Fields_Output_MsgDispatcherCore_MSG_s
, null //method
, null //superclass
, null //interfaces
, 0    //modifiers
};

/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "InspcJ2c/Comm_Inspc.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <emC/Exception.h>  //basic stacktrace concept
#include "emC/Exception.h"  //reference-association: ExceptionJc
#include "InspcJ2c/CmdExecuter_Inspc.h"  //reference-association: cmdExecuterMtbl
#include "Ipc/InterProcessComm.h"  //reference-association: InterProcessCommFactory_s
#include "Jc/AssertJc.h"  //reference-association: AssertJc_s
#include "Jc/PrintStreamJc.h"  //reference-association: out
#include "Jc/StringJc.h"  //embedded type in class data
#include "Jc/SystemJc.h"  //reference-association: SystemJc

#include <stdio.h>
FILE* ftest = null;

/* J2C: Forward declaration of struct ***********************************************/


/* J2C: Method-table-references *********************************************************/
#ifndef AnswerComm_ifc_InspcMTBDEF
  #define AnswerComm_ifc_InspcMTBDEF
  typedef struct AnswerComm_ifc_InspcMTB_t { struct Mtbl_AnswerComm_ifc_Inspc_t const* mtbl; struct AnswerComm_ifc_Inspc_t* ref; } AnswerComm_ifc_InspcMTB;
#endif

#ifndef CmdExecuter_InspcMTBDEF
  #define CmdExecuter_InspcMTBDEF
  typedef struct CmdExecuter_InspcMTB_t { struct Mtbl_CmdExecuter_Inspc_t const* mtbl; struct CmdExecuter_Inspc_t* ref; } CmdExecuter_InspcMTB;
#endif

#ifndef InterProcessCommMTBDEF
  #define InterProcessCommMTBDEF
  typedef struct InterProcessCommMTB_t { struct Mtbl_InterProcessComm_t const* mtbl; struct InterProcessComm_t* ref; } InterProcessCommMTB;
#endif

#ifndef InterProcessCommFactoryMTBDEF
  #define InterProcessCommFactoryMTBDEF
  typedef struct InterProcessCommFactoryMTB_t { struct Mtbl_InterProcessCommFactory_t const* mtbl; struct InterProcessCommFactory_t* ref; } InterProcessCommFactoryMTB;
#endif



const char sign_Mtbl_Comm_Inspc[] = "Comm_Inspc"; //to mark method tables of all implementations

typedef struct MtblDef_Comm_Inspc_t { Mtbl_Comm_Inspc mtbl; MtblHeadJc end; } MtblDef_Comm_Inspc;
 extern MtblDef_Comm_Inspc const mtblComm_Inspc;

/*Constructor */
struct Comm_Inspc_t* ctorO_Comm_Inspc(ObjectJc* othis, StringJc ownAddrIpc, struct CmdExecuter_Inspc_t* cmdExecuter, ThCxt* _thCxt)
{ Comm_Inspc_s* thiz = (Comm_Inspc_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_Comm_Inspc");
  checkConsistence_ObjectJc(othis, sizeof(Comm_Inspc_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_Comm_Inspc_s, sizeof(Comm_Inspc_s));  
  //PRINTX(0, "ctorO_Comm_Inspc\n");
  //j2c: Initialize all class variables:
  {
    init0_MemC(build_MemC(&thiz->nrofBytesReceived, 1 * sizeof(int32))); //J2C: init the embedded simple array;
    init0_MemC(build_MemC(&thiz->data_rxBuffer, 1500 * sizeof(int8))); //J2C: init the embedded simple array;
    thiz->rxBuffer.ref = & thiz->data_rxBuffer[0]; thiz->rxBuffer.val = sizeof( thiz->data_rxBuffer) / sizeof(thiz->data_rxBuffer[0]);
  }
  { 
    ObjectJc *newObj2_1=null; /*J2C: temporary Objects for new operations
    */
    thiz->cmdExecuter = cmdExecuter;
    if(startsWith_StringJc(ownAddrIpc, z_StringJc("UDP:"))) {
      InterProcessCommFactoryMTB ipcFactory ; SETMTBJc(ipcFactory, getInstance_InterProcessCommFactory(), InterProcessCommFactory);
    
      if(ipcFactory.ref !=null) {
        InterProcessCommMTB ipcMtbl ; SETMTBJc(ipcMtbl, ipcFactory.mtbl->create( (ipcFactory.ref), ownAddrIpc, _thCxt), InterProcessComm);
        thiz->myAnswerAddress = ipcMtbl.mtbl->createAddressEmpty(&(( (ipcMtbl.ref))->base.object));/*empty address for receiving and send back*/
        thiz->state = '0';  //not started yet.
        thiz->thread = ctorO_Runnable_s_ThreadJc(/*J2C:static method call*/(newObj2_1 = alloc_ObjectJc(sizeof_ThreadJc_s, 0, _thCxt)), & ((* (thiz)).base.RunnableJc), s0_StringJc("Inspc"), _thCxt);/*set it to class ref.*/
    
        thiz->ipc =  (ipcMtbl.ref);
        activateGC_ObjectJc(newObj2_1, null, _thCxt);
      }
    }
  }
  STACKTRC_LEAVE;
  return thiz;
}









bool openComm_Comm_Inspc(Comm_Inspc_s* thiz, bool blocking, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("openComm_Comm_Inspc");
  
  { 
    
    
    int32  ok;/*no initvalue*/
    
    InterProcessCommMTB ipcMtbl ; SETMTBJc(ipcMtbl, thiz->ipc, InterProcessComm);
    ok = ipcMtbl.mtbl->open(&(( (ipcMtbl.ref))->base.object), null, ((/*J2C:cast% from bool*/int32)(blocking)));
    thiz->state = (ok >= 0 ? 'o' : 'e');
    if(thiz->bEnablePrintfOnComm) 
    { /*:only for debug:*/
      
      
      if(ok >= 0) 
      { 
        
        print_z_PrintStreamJc(REFJc (out_SystemJc), "\nopen OBMA-Communication ok\n", _thCxt);
      }
      else 
      { 
        
        format_z_PrintStreamJc(REFJc (out_SystemJc), "\nopen OBMA-Communication error: %d\n", "I", -ok, _thCxt);
      }
    }
    { STACKTRC_LEAVE;
      return ok >= 0;
    }/*true if InterProcessComm.open() successfully*/
    
  }
  STACKTRC_LEAVE;
}

void start_Comm_Inspc(Comm_Inspc_s* thiz, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("start_Comm_Inspc");
  
  { 
    thiz->state = 'a';
    if(thiz->thread !=null) {
      start_ThreadJc(thiz->thread, -1, _thCxt);
    }
  }
  STACKTRC_LEAVE;
}

void run_Comm_Inspc_F(ObjectJc* ithis, ThCxt* _thCxt)
{ Comm_Inspc_s* thiz = (Comm_Inspc_s*)ithis;
  
  STACKTRC_TENTRY("run_Comm_Inspc_F");
  if(ftest) { fprintf(ftest, "run_Comm_Inspc_F\n"); fflush(ftest); } 
  { 
    
    
    while(thiz->state != 'x')
      { 
        
        openComm_Comm_Inspc(thiz, true, _thCxt);
        if(thiz->state == 'o') 
        { 
          sleep_ThreadJc(100, _thCxt); //delay, necessary for some op
          receiveAndExecute_Comm_Inspc(thiz, _thCxt);
        }
        else 
        { 
          
          if(ftest) { fprintf(ftest, "ErrorOpen_Comm_Inspc_F\n"); fflush(ftest); }  
          thiz->state = 'E';
          
          while(thiz->state == 'E')
            { 
              
              TRY
              { 
                
                sleep_ThreadJc(/*J2C:static method call*/1000, _thCxt);
              }_TRY
              CATCH(InterruptedException, exc)
              
                { 
                  
                  
                }
              END_TRY/*check state after a waiting time, repeat open.*/
              
            }
        }
      }
    
    synchronized_ObjectJc(& ((* (thiz)).base.RunnableJc.base.object)); {
      
      { 
        
        thiz->state = 'z';
        notify_ObjectJc(& ((* (thiz)).base.RunnableJc.base.object), _thCxt);
      }
    } endSynchronized_ObjectJc(& ((* (thiz)).base.RunnableJc.base.object));
  }
  STACKTRC_LEAVE;
}




/*J2C: dynamic call variant of the override-able method: */
void run_Comm_Inspc(ObjectJc* ithis, ThCxt* _thCxt)
{ Mtbl_RunnableJc const* mtbl = (Mtbl_RunnableJc const*)getMtbl_ObjectJc(ithis, sign_Mtbl_RunnableJc);
  mtbl->run(ithis, _thCxt);
}

void receiveAndExecute_Comm_Inspc(Comm_Inspc_s* thiz, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("receiveAndExecute_Comm_Inspc");
  
  { 
    
    
    AnswerComm_ifc_InspcMTB answerCommMtbl ; SETMTBJc(answerCommMtbl, & ((* (thiz->cmdExecuter)).base.AnswerComm_ifc_Inspc), AnswerComm_ifc_Inspc);
    
    CmdExecuter_InspcMTB cmdExecuterMtbl ; SETMTBJc(cmdExecuterMtbl, thiz->cmdExecuter, CmdExecuter_Inspc);
    
    InterProcessCommMTB ipcMtbl ; SETMTBJc(ipcMtbl, thiz->ipc, InterProcessComm);
    
    while(thiz->state != 'x')
      { /*:x to terminate*/
        /*:chgData_TestData_Inspc(ythis->testInspc);   //only for test.*/
        
        
        thiz->nrofBytesReceived[0] = 0;/*expected the nrof available data*/
        
        thiz->state = 'r';/*receive*/
        
        TRY
        { 
          
          ipcMtbl.mtbl->receiveData(&(( (ipcMtbl.ref))->base.object), &thiz->nrofBytesReceived[0], build_MemC(thiz->rxBuffer.ref, thiz->rxBuffer.val ), thiz->myAnswerAddress);
          if(thiz->state != 'x') 
          { 
            
            if(thiz->nrofBytesReceived[0] < 0) 
            { /*:error situation*/
              /*:it is possible that a send request has failed because the destination port is not*/
              /*:able to reach any more. Therefore wait a moment and listen new*/
              
              
              thiz->state = 'e';/*prevent send*/
              
              TRY
              { 
                
                sleep_ThreadJc(/*J2C:static method call*/50, _thCxt);
              }_TRY
              CATCH(InterruptedException, exc)
              
                { 
                  
                  
                }
              END_TRY
              thiz->state = 'r';/**/
              
            }
            else 
            { 
              
              cmdExecuterMtbl.mtbl->executeCmd( (cmdExecuterMtbl.ref), thiz->rxBuffer, thiz->nrofBytesReceived[0], _thCxt);/*unnecessary because usage receiveData: ipcMtbl.freeData(rxBuffer);*/
              
            }
          }
        }_TRY
        CATCH(ExceptionJc, exc)
        
          { 
            
            
            CharSeqJc msg ; msg = exceptionInfo_AssertJc(/*J2C:static method call*/"org.vishia.inspector.Comm - unexpected Exception; ", exc, 0, 7, _thCxt);
            println_c_PrintStreamJc(REFJc (err_SystemJc), msg/*J2C-error testAndChangeAccess: ct*/, _thCxt);
            printStackTrace_P_ExceptionJc(exc, REFJc (err_SystemJc), _thCxt);
          }
        END_TRY
      }/*while state !='x'*/
      
  }
  STACKTRC_LEAVE;
}


/**Sends the answer telg to the sender of the received telegram. */
int32 sendAnswer_Comm_Inspc(Comm_Inspc_s* thiz, PtrVal_int8 bufferAnswerData, int32 nrofBytesAnswer, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("sendAnswer_Comm_Inspc");
  
  { 
    
    
    int32  nrofSentBytes;/*no initvalue*/
    
    InterProcessCommMTB ipcMtbl ; SETMTBJc(ipcMtbl, thiz->ipc, InterProcessComm);
    nrofSentBytes = ipcMtbl.mtbl->send(&(( (ipcMtbl.ref))->base.object), build_MemC(bufferAnswerData.ref, bufferAnswerData.val ), nrofBytesAnswer, thiz->myAnswerAddress);
    if(nrofSentBytes < 0) 
    { 
      
      if(thiz->bEnablePrintfOnComm) 
      { /*:only for debug.*/
        
        
        print_z_PrintStreamJc(REFJc (out_SystemJc), "\nError InterProcessComm ", _thCxt);
      }
      nrofSentBytes = -2;
    }
    /**/
    if(thiz->bEnablePrintfOnComm) /**/
    
    { 
      
      /**/
      print_z_PrintStreamJc(REFJc (out_SystemJc), "<", _thCxt);
    }
    { STACKTRC_LEAVE;
      return nrofSentBytes;
    }
  }
  STACKTRC_LEAVE;
}


/**Shutdown the communication, close the thread. This routine should be called */
void shutdown_Comm_Inspc_F(Comm_Inspc_s* thiz, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("shutdown_Comm_Inspc_F");
  if(ftest) fclose(ftest);

  if(thiz->state !='0' && thiz->ipc !=null)  {  //do nothing if not started. 
    
    thiz->state = 'x';
    
    InterProcessCommMTB ipcMtbl ; SETMTBJc(ipcMtbl, thiz->ipc, InterProcessComm);
    ipcMtbl.mtbl->close(&(( (ipcMtbl.ref))->base.object));/*breaks waiting in receive socket*/
    
    
    while(thiz->state != 'z')
      { 
        
        
        synchronized_ObjectJc(& ((* (thiz)).base.RunnableJc.base.object)); {
          
          { 
            
            TRY
            { 
              
              wait_ObjectJc(& ((* (thiz)).base.RunnableJc.base.object), 100, _thCxt);
            }_TRY
            CATCH(InterruptedException, exc)
            
              { 
                
                
              }
            END_TRY
          }
        } endSynchronized_ObjectJc(& ((* (thiz)).base.RunnableJc.base.object));
      }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void shutdown_Comm_Inspc(Comm_Inspc_s* thiz, ThCxt* _thCxt)
{ ObjectJc* othiz = &thiz->base.object;
  Mtbl_Comm_Inspc const* mtbl = (Mtbl_Comm_Inspc const*)getMtbl_ObjectJc(&thiz->base.object, sign_Mtbl_Comm_Inspc);
  mtbl->shutdown(thiz, _thCxt);
}



void dtor_Comm_Inspc(Comm_Inspc_s* thiz, ThCxt* _thCxt) {
  if(ftest) { fprintf(ftest, "dtor\n "); fclose(ftest); }
}


/**J2C: Reflections and Method-table *************************************************/
const MtblDef_Comm_Inspc mtblComm_Inspc = {
{ { sign_Mtbl_Comm_Inspc //J2C: Head of methodtable of Comm_Inspc
  , (struct Size_Mtbl_t*)((1 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
  }
  //J2C: Dynamic methods of the class :Comm_Inspc:
, shutdown_Comm_Inspc_F //shutdown
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
  //J2C: The interface's methodtable: 
  //J2C: Mtbl-interfaces of :Comm_Inspc: */
, { { sign_Mtbl_RunnableJc //J2C: Head of methodtable of RunnableJc
    , (struct Size_Mtbl_t*)((1 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
    }
    //J2C: Dynamic methods of the class :RunnableJc:
  , run_Comm_Inspc_F //run
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
  }
}, { signEnd_Mtbl_ObjectJc, null } }; //Mtbl


 extern_C struct ClassJc_t const reflection_ObjectJc;
 static struct superClasses_Comm_Inspc_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_Comm_Inspc_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_Comm_Inspc, ObjectJc) }
   }
 };

 extern_C struct ClassJc_t const reflection_RunnableJc_s;
 static struct ifcClasses_Comm_Inspc_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }interfaces_Comm_Inspc_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
, { {&reflection_RunnableJc_s, OFFSET_Mtbl(Mtbl_Comm_Inspc, RunnableJc) }
  }
};

extern_C struct ClassJc_t const reflection_Comm_Inspc_s;
extern_C struct ClassJc_t const reflection_Address_InterProcessComm_s;
extern_C struct ClassJc_t const reflection_CmdExecuter_Inspc_s;
extern_C struct ClassJc_t const reflection_InterProcessComm_s;
extern_C struct ClassJc_t const reflection_ThreadJc_s;
const struct Reflection_Fields_Comm_Inspc_s_t
{ ObjectArrayJc head; FieldJc data[10];
} reflection_Fields_Comm_Inspc_s =
{ CONST_ObjectArrayJc(FieldJc, 10, OBJTYPE_FieldJc, null, &reflection_Fields_Comm_Inspc_s)
, {
     { "cmdExecuter"
    , 0 //nrofArrayElements
    , &reflection_CmdExecuter_Inspc_s
    , kReference_Modifier_reflectJc |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Comm_Inspc_s*)(0x1000))->cmdExecuter) - (int32)(Comm_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Comm_Inspc_s
    }
   , { "state"
    , 0 //nrofArrayElements
    , REFLECTION_char
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Comm_Inspc_s*)(0x1000))->state) - (int32)(Comm_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Comm_Inspc_s
    }
   , { "bEnablePrintfOnComm"
    , 0 //nrofArrayElements
    , REFLECTION_bool
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Comm_Inspc_s*)(0x1000))->bEnablePrintfOnComm) - (int32)(Comm_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Comm_Inspc_s
    }
   , { "ipc"
    , 0 //nrofArrayElements
    , &reflection_InterProcessComm_s
    , kReference_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Comm_Inspc_s*)(0x1000))->ipc) - (int32)(Comm_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Comm_Inspc_s
    }
   , { "ctErrorTelg"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Comm_Inspc_s*)(0x1000))->ctErrorTelg) - (int32)(Comm_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Comm_Inspc_s
    }
   , { "thread"
    , 0 //nrofArrayElements
    , &reflection_ThreadJc_s
    , kReference_Modifier_reflectJc |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Comm_Inspc_s*)(0x1000))->thread) - (int32)(Comm_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Comm_Inspc_s
    }
   , { "nrofBytesReceived"
    , 1 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc |kStaticArray_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Comm_Inspc_s*)(0x1000))->nrofBytesReceived) - (int32)(Comm_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Comm_Inspc_s
    }
   , { "data_rxBuffer"
    , 1500 //nrofArrayElements
    , REFLECTION_int8
    , 1 << kBitPrimitiv_Modifier_reflectJc |kStaticArray_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Comm_Inspc_s*)(0x1000))->data_rxBuffer) - (int32)(Comm_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Comm_Inspc_s
    }
   , { "rxBuffer"
    , 0 //nrofArrayElements
    , REFLECTION_int8
    , 1 << kBitPrimitiv_Modifier_reflectJc |kObjectArrayJc_Modifier_reflectJc |kPtrVal_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Comm_Inspc_s*)(0x1000))->rxBuffer) - (int32)(Comm_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Comm_Inspc_s
    }
   , { "myAnswerAddress"
    , 0 //nrofArrayElements
    , &reflection_Address_InterProcessComm_s
    , kReference_Modifier_reflectJc |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((Comm_Inspc_s*)(0x1000))->myAnswerAddress) - (int32)(Comm_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_Comm_Inspc_s
    }
} };
const ClassJc reflection_Comm_Inspc_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "Comm_Inspc_s"
, (int16)((int32)(&((Comm_Inspc_s*)(0x1000))->base.object) - (int32)(Comm_Inspc_s*)0x1000)
, sizeof(Comm_Inspc_s)
, (FieldJc_Y const*)&reflection_Fields_Comm_Inspc_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_Comm_Inspc_s //superclass
, (ClassOffset_idxMtblJcARRAY*)&interfaces_Comm_Inspc_s //interfaces
, mObjectJc_Modifier_reflectJc
, &mtblComm_Inspc.mtbl.head
};

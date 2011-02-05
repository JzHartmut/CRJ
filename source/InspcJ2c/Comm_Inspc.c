/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "InspcJ2c/Comm_Inspc.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <Fwc/fw_Exception.h>  //basic stacktrace concept
#include "InspcJ2c/CmdExecuter_Inspc.h"  //reference-association: cmdExecuterMtbl
#include "Ipc/InterProcessComm.h"  //reference-association: InterProcessCommFactoryAccessor
#include "Jc/PrintStreamJc.h"  //reference-association: out
#include "Jc/StringJc.h"  //embedded type in class data
#include "Jc/SystemJc.h"  //reference-association: SystemJc


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
{ Comm_Inspc_s* ythis = (Comm_Inspc_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_Comm_Inspc");
  checkConsistence_ObjectJc(othis, sizeof(Comm_Inspc_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_Comm_Inspc_s, sizeof(Comm_Inspc_s));  
  //j2c: Initialize all class variables:
  {
    init0_MemC(build_MemC(&ythis->nrofBytesReceived, 1 * sizeof(int32))); //J2C: init the embedded simple array;
    /*J2C: newArray*/
      init_ObjectJc(&ythis->rxBuffer.head.object, sizeof_ARRAYJc(int8, 1500), 0);   //J2C: ctor embedded array.
      ctorO_ObjectArrayJc(&ythis->rxBuffer.head.object, 1500, sizeof(int8), null, 0);//J2C: constructor for embedded array;
  }
  { 
    InterProcessCommFactoryMTB ipcFactory;   /*use the existent factory, it is determined by linker or classLoader, which it is.*/
    InterProcessCommMTB ipcMtbl;   /*The interProcessCommunication, depends from the factory and the own Address.*/
    
    ObjectJc *newObj1_1=null; //J2C: temporary Objects for new operations
    
    ythis->cmdExecuter = cmdExecuter;
    SETMTBJc(ipcFactory, getInstance_InterProcessCommFactoryAccessor(), InterProcessCommFactory);
    SETMTBJc(ipcMtbl, ipcFactory.mtbl->create(&(( (ipcFactory.ref))->base.object), ownAddrIpc, _thCxt), InterProcessComm);
    ythis->myAnswerAddress = ipcMtbl.mtbl->createAddressEmpty(&(( (ipcMtbl.ref))->base.object));//empty address for receiving and send back
    
    ythis->thread = ctorO_Runnable_s_ThreadJc(/*static*/(newObj1_1 = alloc_ObjectJc(sizeof_ThreadJc_s, 0, _thCxt)), & ((* (ythis)).base.RunnableJc), s0_StringJc("Inspc"), _thCxt);//set it to class ref.
    
    ythis->ipc =  (ipcMtbl.ref);
    activateGC_ObjectJc(newObj1_1, null, _thCxt);
  }
  STACKTRC_LEAVE;
  return ythis;
}


bool openComm_Comm_Inspc(Comm_Inspc_s* ythis, bool blocking, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("openComm_Comm_Inspc");
  
  { 
    int32 ok = 0; 
    InterProcessCommMTB ipcMtbl;   /**/
    
    
    /*no initvalue*/
    SETMTBJc(ipcMtbl, ythis->ipc, InterProcessComm);
    ok = ipcMtbl.mtbl->open(&(( (ipcMtbl.ref))->base.object), null, ((/*J2C:cast% from bool*/int32)(blocking)));
    ythis->state = (char)(ok >= 0 ? 'o' : 'e');
    if(ythis->bEnablePrintfOnComm) 
    { //:only for debug:
      
      
      if(ok >= 0) 
      { 
        
        print_z_PrintStreamJc(REFJc(out_SystemJc), "\nopen OBMA-Communication ok\n", _thCxt);
      }
      else 
      { 
        
        format_z_PrintStreamJc(REFJc(out_SystemJc), "\nopen OBMA-Communication error: %d\n", "I", -ok, _thCxt);
      }
    }
    { STACKTRC_LEAVE;
      return ok >= 0;
    }//true if InterProcessComm.open() successfully
    
  }
  STACKTRC_LEAVE;
}

void start_Comm_Inspc(Comm_Inspc_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("start_Comm_Inspc");
  
  { 
    
    start_ThreadJc(ythis->thread, -1, _thCxt);
  }
  STACKTRC_LEAVE;
}

void run_Comm_Inspc_F(ObjectJc* ithis, ThCxt* _thCxt)
{ Comm_Inspc_s* ythis = (Comm_Inspc_s*)ithis;
  
  STACKTRC_TENTRY("run_Comm_Inspc_F");
  
  { 
    
    
    while(ythis->state != 'x')
      { 
        
        openComm_Comm_Inspc(ythis, true, _thCxt);
        if(ythis->state == 'o') 
        { 
          
          receiveAndExecute_Comm_Inspc(ythis, _thCxt);
        }
        else 
        { 
          
          ythis->state = 'E';
          
          while(ythis->state == 'E')
            { 
              
              TRY
              { 
                
                sleep_ThreadJc(/*static*/1000, _thCxt);
              }_TRY
              CATCH(InterruptedException, exc)
              
                { 
                  
                  
                }
              END_TRY//check state after a waiting time, repeat open.
              
            }
        }
      }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void run_Comm_Inspc(ObjectJc* ithis, ThCxt* _thCxt)
{ Mtbl_RunnableJc const* mtbl = (Mtbl_RunnableJc const*)getMtbl_ObjectJc(ithis, sign_Mtbl_RunnableJc);
  mtbl->run(ithis, _thCxt);
}

void receiveAndExecute_Comm_Inspc(Comm_Inspc_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("receiveAndExecute_Comm_Inspc");
  
  { 
    AnswerComm_ifc_InspcMTB answerCommMtbl;   /*The interface for answer: It is implemented in cmdExecuter. */
    CmdExecuter_InspcMTB cmdExecuterMtbl;   /**/
    InterProcessCommMTB ipcMtbl;   /**/
    
    
    SETMTBJc(answerCommMtbl, & ((* (ythis->cmdExecuter)).base.AnswerComm_ifc_Inspc), AnswerComm_ifc_Inspc);
    SETMTBJc(cmdExecuterMtbl, ythis->cmdExecuter, CmdExecuter_Inspc);
    SETMTBJc(ipcMtbl, ythis->ipc, InterProcessComm);
    
    while(ythis->state != 'x')
      { //:x to terminate
        //:chgData_TestData_Inspc(ythis->testInspc);   //only for test.
        
        
        ythis->nrofBytesReceived[0] = 0;//expected the nrof available data
        
        ythis->state = 'r';//receive
        
        ipcMtbl.mtbl->receiveData(&(( (ipcMtbl.ref))->base.object), &ythis->nrofBytesReceived[0], buildFromArrayX_MemC(&((struct int8_Y_t*)(&( ythis->rxBuffer)))->head) , ythis->myAnswerAddress);
        if(ythis->nrofBytesReceived[0] > 0) 
        { }
        if(ythis->state == 'r') 
        { 
          bool bOk; 
          
          
          bOk = cmdExecuterMtbl.mtbl->executeCmd( (cmdExecuterMtbl.ref), (struct int8_Y_t*)(&( ythis->rxBuffer)), ythis->nrofBytesReceived[0], _thCxt);
        }
      }
  }
  STACKTRC_LEAVE;
}



/**J2C: Reflections and Method-table *************************************************/
const MtblDef_Comm_Inspc mtblComm_Inspc = {
{ { sign_Mtbl_Comm_Inspc//J2C: Head of methodtable.
  , (struct Size_Mtbl_t*)((0 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
  }
, { { sign_Mtbl_ObjectJc//J2C: Head of methodtable.
    , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
    }
  , clone_ObjectJc_F //clone
  , equals_ObjectJc_F //equals
  , finalize_ObjectJc_F //finalize
  , hashCode_ObjectJc_F //hashCode
  , toString_ObjectJc_F //toString
  }
  /**J2C: Mtbl-interfaces of Comm_Inspc: */
, { { sign_Mtbl_RunnableJc//J2C: Head of methodtable.
    , (struct Size_Mtbl_t*)((1 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
    }
  , run_Comm_Inspc_F //run
  , { { sign_Mtbl_ObjectJc//J2C: Head of methodtable.
      , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
      }
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
extern_C struct ClassJc_t const reflection_InterProcessComm_i;
extern_C struct ClassJc_t const reflection_ThreadJc_s;
const struct Reflection_Fields_Comm_Inspc_s_t
{ ObjectArrayJc head; FieldJc data[9];
} reflection_Fields_Comm_Inspc_s =
{ CONST_ObjectArrayJc(FieldJc, 9, OBJTYPE_FieldJc, null, &reflection_Fields_Comm_Inspc_s)
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
    , &reflection_InterProcessComm_i
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
   , { "rxBuffer"
    , 1500 //nrofArrayElements
    , REFLECTION_int8
    , 1 << kBitPrimitiv_Modifier_reflectJc |kStaticArray_Modifier_reflectJc |kEmbeddedContainer_Modifier_reflectJc //bitModifiers
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
, (FieldJcArray const*)&reflection_Fields_Comm_Inspc_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_Comm_Inspc_s //superclass
, (ClassOffset_idxMtblJcARRAY*)&interfaces_Comm_Inspc_s //interfaces
, mObjectJc_Modifier_reflectJc
, &mtblComm_Inspc.mtbl.head
};

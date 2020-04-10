/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "emC/Ipc2c/InterProcessCommRxExec_Ipc.h"
#include <string.h>  //because using memset()
#include <emC/Jc/ReflectionJc.h>   //Reflection concept 
  //basic stacktrace concept
#include "emC/Jc/PrintStreamJc.h"  //reference-association: out
#include "emC/Jc/SystemJc.h"  //reference-association: SystemJc


/* J2C: Forward declaration of struct ***********************************************/

/**This is a sample class for implementing the {@link InterProcessCommRx_ifc} especially for usage in C.
It is translated Java2C.

@author Hartmut Schorrig

*/


const char sign_Vtbl_InterProcessCommRxExec_Ipc[] = "InterProcessCommRxExec_Ipc"; //to mark method tables of all implementations

typedef struct VtblDef_InterProcessCommRxExec_Ipc_t { Vtbl_InterProcessCommRxExec_Ipc mtbl; VtblHeadJc end; } VtblDef_InterProcessCommRxExec_Ipc;
 extern VtblDef_InterProcessCommRxExec_Ipc const mtblInterProcessCommRxExec_Ipc;

/*Constructor *//**J2C: autogenerated as default constructor. */
struct InterProcessCommRxExec_Ipc_t* ctorO_InterProcessCommRxExec_Ipc(ObjectJc* othis, ThCxt* _thCxt)
{ InterProcessCommRxExec_Ipc_s* thiz = (InterProcessCommRxExec_Ipc_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_InterProcessCommRxExec_Ipc");
  checkConsistence_ObjectJc(othis, sizeof(InterProcessCommRxExec_Ipc_s), null, _thCxt);  
  //J2C:super Constructor
  ctorO_InterProcessCommRx_ifc_Ipc(/*J2C:static method call*/othis, _thCxt);
  setReflection_ObjectJc(othis, &reflection_InterProcessCommRxExec_Ipc_s, sizeof(InterProcessCommRxExec_Ipc_s));  
  //j2c: Initialize all class variables:
  {
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return thiz;
}


void execRxData_iYiAddrIpc_InterProcessCommRxExec_Ipc_F(InterProcessCommRx_ifc_Ipc_s* ithis, int8ARRAY buffer, int32 nrofBytesReceived, struct Address_InterProcessComm_t* sender, ThCxt* _thCxt)
{ InterProcessCommRxExec_Ipc_s* thiz = (InterProcessCommRxExec_Ipc_s*)ithis;
  
  STACKTRC_TENTRY("execRxData_iYiAddrIpc_InterProcessCommRxExec_Ipc_F");
  
  { 
    
    println_z_PrintStreamJc(REFJc (out_SystemJc), "Hello world - implementing of InterProcessCommRx_ifc", _thCxt);
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void execRxData_iYiAddrIpc_InterProcessCommRxExec_Ipc(InterProcessCommRx_ifc_Ipc_s* ithis, int8ARRAY buffer, int32 nrofBytesReceived, struct Address_InterProcessComm_t* sender, ThCxt* _thCxt)
{ Vtbl_InterProcessCommRx_ifc_Ipc const* mtbl = (Vtbl_InterProcessCommRx_ifc_Ipc const*)getVtbl_ObjectJc(&ithis->base.object, sign_Vtbl_InterProcessCommRx_ifc_Ipc);
  mtbl->execRxData((InterProcessCommRx_ifc_Ipc_s*)ithis, buffer, nrofBytesReceived, sender, _thCxt);
}



/**J2C: Reflections and Method-table *************************************************/
const VtblDef_InterProcessCommRxExec_Ipc mtblInterProcessCommRxExec_Ipc = {
{ { sign_Vtbl_InterProcessCommRxExec_Ipc //J2C: Head of methodtable of InterProcessCommRxExec_Ipc
  , (struct Size_Vtbl_t*)((0 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
  }
  //J2C: The superclass's methodtable: 
, { { sign_Vtbl_InterProcessCommRx_ifc_Ipc //J2C: Head of methodtable of InterProcessCommRx_ifc_Ipc
    , (struct Size_Vtbl_t*)((1 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
    }
    //J2C: Dynamic methods of the class :InterProcessCommRx_ifc_Ipc:
  , execRxData_iYiAddrIpc_InterProcessCommRxExec_Ipc_F //execRxData
    //J2C: The superclass's methodtable: 
  , { { sign_Vtbl_ObjectJc //J2C: Head of methodtable of ObjectJc
      , (struct Size_Vtbl_t*)((5 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
      }
      //J2C: Dynamic methods of the class :ObjectJc:
    , clone_ObjectJc_F //clone
    , equals_ObjectJc_F //equals
    , finalize_ObjectJc_F //finalize
    , hashCode_ObjectJc_F //hashCode
    , toString_ObjectJc_F //toString
    }
  }
}, { signEnd_Vtbl_ObjectJc, null } }; //Vtbl


 extern_C struct ClassJc_t const reflection_InterProcessCommRx_ifc_Ipc;
 static struct superClasses_InterProcessCommRxExec_Ipc_s_t
 { ObjectArrayJc head;
   ClassOffset_idxVtblJc data[1];
 }superclasses_InterProcessCommRxExec_Ipc_s =
 { CONST_ObjectArrayJc(ClassOffset_idxVtblJc, 1, OBJTYPE_ClassOffset_idxVtblJc, null, null)
 , { {&reflection_InterProcessCommRx_ifc_Ipc, OFFSET_Vtbl(Vtbl_InterProcessCommRxExec_Ipc, InterProcessCommRx_ifc_Ipc) }
   }
 };

const ClassJc reflection_InterProcessCommRxExec_Ipc_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "InterProcessCommRxExec_Ipc_s"
,  0 //position of ObjectJc
, sizeof(InterProcessCommRxExec_Ipc_s)
, null //attributes and associations
, null //method
, (ClassOffset_idxVtblJcARRAY*)&superclasses_InterProcessCommRxExec_Ipc_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblInterProcessCommRxExec_Ipc.mtbl.head
};

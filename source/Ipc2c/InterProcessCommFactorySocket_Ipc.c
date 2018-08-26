/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "Ipc2c/InterProcessCommFactorySocket_Ipc.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
  //basic stacktrace concept
#include "Ipc/InterProcessCommSocket.h"  //new object
#include "Jc/ObjectJc.h"  //reference-association: IntegerJc
#include "Jc/StringJc.h"  //embedded type in class data


/* J2C: Forward declaration of struct ***********************************************/
struct InterProcessCommSocket_t;

/*** @author Hartmut Schorrig
*
*/


const char sign_Mtbl_InterProcessCommFactorySocket_Ipc[] = "InterProcessCommFactorySocket_Ipc"; //to mark method tables of all implementations

typedef struct MtblDef_InterProcessCommFactorySocket_Ipc_t { Mtbl_InterProcessCommFactorySocket_Ipc mtbl; MtblHeadJc end; } MtblDef_InterProcessCommFactorySocket_Ipc;
 extern MtblDef_InterProcessCommFactorySocket_Ipc const mtblInterProcessCommFactorySocket_Ipc;

/*Constructor */
struct InterProcessCommFactorySocket_Ipc_t* ctorO_InterProcessCommFactorySocket_Ipc(ObjectJc* othis, ThCxt* _thCxt)
{ InterProcessCommFactorySocket_Ipc_s* thiz = (InterProcessCommFactorySocket_Ipc_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_InterProcessCommFactorySocket_Ipc");
  checkConsistence_ObjectJc(othis, sizeof(InterProcessCommFactorySocket_Ipc_s), null, _thCxt);  
  //J2C:super Constructor
  ctorO_InterProcessCommFactory(/*J2C:static method call*/othis, _thCxt);
  setReflection_ObjectJc(othis, &reflection_InterProcessCommFactorySocket_Ipc_s, sizeof(InterProcessCommFactorySocket_Ipc_s));  
  //j2c: Initialize all class variables:
  {
  }
  { 
    
    
  }
  STACKTRC_LEAVE;
  return thiz;
}


struct InterProcessComm_t* create_S_InterProcessCommFactorySocket_Ipc_F(InterProcessCommFactory_s* ithis, StringJc protocolAndOwnAddr, ThCxt* _thCxt)
{ InterProcessCommFactorySocket_Ipc_s* thiz = (InterProcessCommFactorySocket_Ipc_s*)ithis;
  Mtbl_InterProcessCommFactorySocket_Ipc const* mtthis = (Mtbl_InterProcessCommFactorySocket_Ipc const*)getMtbl_ObjectJc(&thiz->base.object, sign_Mtbl_InterProcessCommFactorySocket_Ipc);
  
  STACKTRC_TENTRY("create_S_InterProcessCommFactorySocket_Ipc_F");
  
  { 
    
    
    struct InterProcessComm_t*  obj = mtthis->InterProcessCommFactory.create_Port(& ((* (thiz)).base.super)/*J2cT1*/, protocolAndOwnAddr, -1, _thCxt);
    { STACKTRC_LEAVE;
      return obj;
    }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
struct InterProcessComm_t* create_S_InterProcessCommFactorySocket_Ipc(InterProcessCommFactory_s* ithis, StringJc protocolAndOwnAddr, ThCxt* _thCxt)
{ Mtbl_InterProcessCommFactory const* mtbl = (Mtbl_InterProcessCommFactory const*)getMtbl_ObjectJc(&ithis->base.object, sign_Mtbl_InterProcessCommFactory);
  return mtbl->create((InterProcessCommFactory_s*)ithis, protocolAndOwnAddr, _thCxt);
}


/**Creates a InterProcessComm from a parameter String. The type depends on this String.*/
struct InterProcessComm_t* create_Si_InterProcessCommFactorySocket_Ipc_F(InterProcessCommFactory_s* ithis, StringJc protocolAndOwnAddr, int32 nPort, ThCxt* _thCxt)
{ InterProcessCommFactorySocket_Ipc_s* thiz = (InterProcessCommFactorySocket_Ipc_s*)ithis;
  
  STACKTRC_TENTRY("create_Si_InterProcessCommFactorySocket_Ipc_F");
  
  { 
    
    
    struct InterProcessComm_t*  ipc;/*no initvalue*/
    
    int32  posSocketAddr = -1;
    if(startsWith_StringJc(protocolAndOwnAddr, s0_StringJc("UDP:"))) 
    { 
      
      posSocketAddr = 4;
    }
    else if(startsWith_StringJc(protocolAndOwnAddr, s0_StringJc("Socket:"))) 
    { 
      
      posSocketAddr = 7;
    }
    if(posSocketAddr >= 0) 
    { 
      ObjectJc *newObj3_1=null; /*J2C: temporary Objects for new operations
      */
      
      struct Address_InterProcessComm_t*  ownAddr = createAddressSocket_InterProcessCommFactorySocket_Ipc(/*J2C:static method call*/null_StringJc /*J2C: mem assignment*/, protocolAndOwnAddr, nPort, _thCxt);
      ipc = ((/*J2C:cast from InterProcessCommSocket_s*/InterProcessComm_s*)(ctorO_InterProcessCommSocket(/*J2C:static method call*/(newObj3_1 = alloc_ObjectJc(sizeof_InterProcessCommSocket_s, 0, _thCxt)), ((/*J2C:cast from Address_InterProcessComm_s*/Address_InterProcessComm_s*)(ownAddr)), _thCxt)));
      activateGC_ObjectJc(newObj3_1, null, _thCxt);
    }
    else 
    { 
      
      ipc = null;
    }
    { STACKTRC_LEAVE;
      return ipc;
    }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
struct InterProcessComm_t* create_Si_InterProcessCommFactorySocket_Ipc(InterProcessCommFactory_s* ithis, StringJc protocolAndOwnAddr, int32 nPort, ThCxt* _thCxt)
{ Mtbl_InterProcessCommFactory const* mtbl = (Mtbl_InterProcessCommFactory const*)getMtbl_ObjectJc(&ithis->base.object, sign_Mtbl_InterProcessCommFactory);
  return mtbl->create_Port((InterProcessCommFactory_s*)ithis, protocolAndOwnAddr, nPort, _thCxt);
}

struct InterProcessComm_t* create_AddrIpc_InterProcessCommFactorySocket_Ipc_F(InterProcessCommFactory_s* ithis, struct Address_InterProcessComm_t* addr, ThCxt* _thCxt)
{ InterProcessCommFactorySocket_Ipc_s* thiz = (InterProcessCommFactorySocket_Ipc_s*)ithis;
  
  STACKTRC_TENTRY("create_AddrIpc_InterProcessCommFactorySocket_Ipc_F");
  
  { 
    
    if( instanceof_ObjectJc(& ((* (addr)).base.object), &reflection_Address_InterProcessComm_s)) 
    { 
      ObjectJc *newObj3_1=null; /*J2C: temporary Objects for new operations
      */
      
      struct InterProcessCommSocket_t*  obj = ctorO_InterProcessCommSocket(/*J2C:static method call*/(newObj3_1 = alloc_ObjectJc(sizeof_InterProcessCommSocket_s, 0, _thCxt)), ((/*J2C:cast from Address_InterProcessComm_s*/Address_InterProcessComm_s*)(addr)), _thCxt);
      { STACKTRC_LEAVE;
        activateGC_ObjectJc(newObj3_1, obj, _thCxt);
        return ((/*J2C:cast from InterProcessCommSocket_s*/InterProcessComm_s*)(obj));
      }
    }
    else 
    { 
      
      { throw_s0Jc(ident_IllegalArgumentExceptionJc, "only Socket-Implementation, fault type of address:", 0, __LINE__, _thCxt); return 0; };
    }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
struct InterProcessComm_t* create_AddrIpc_InterProcessCommFactorySocket_Ipc(InterProcessCommFactory_s* ithis, struct Address_InterProcessComm_t* addr, ThCxt* _thCxt)
{ Mtbl_InterProcessCommFactory const* mtbl = (Mtbl_InterProcessCommFactory const*)getMtbl_ObjectJc(&ithis->base.object, sign_Mtbl_InterProcessCommFactory);
  return mtbl->create_Addr((InterProcessCommFactory_s*)ithis, addr, _thCxt);
}


/**Creates an address information for the InterProcessComm from a parameter String. */
struct Address_InterProcessComm_t* createAddress_Si_InterProcessCommFactorySocket_Ipc_F(InterProcessCommFactory_s* ithis, StringJc protocolAndOwnAddr, int32 nPort, ThCxt* _thCxt)
{ InterProcessCommFactorySocket_Ipc_s* thiz = (InterProcessCommFactorySocket_Ipc_s*)ithis;
  
  STACKTRC_TENTRY("createAddress_Si_InterProcessCommFactorySocket_Ipc_F");
  
  { 
    
    
    struct Address_InterProcessComm_t*  addr;/*no initvalue*/
    if(startsWith_StringJc(protocolAndOwnAddr, s0_StringJc("Socket:"))) 
    { 
      
      
      StringJc sAddr ; sAddr = substring_I_StringJc(protocolAndOwnAddr, 7, _thCxt)/*J2C:non-persistent*/;
      addr = createAddressSocket_InterProcessCommFactorySocket_Ipc(/*J2C:static method call*/null_StringJc /*J2C: mem assignment*/, protocolAndOwnAddr, nPort, _thCxt);
    }
    else if(startsWith_StringJc(protocolAndOwnAddr, s0_StringJc("UDP:"))) 
    { 
      
      
      StringJc sAddr ; sAddr = substring_I_StringJc(protocolAndOwnAddr, 4, _thCxt)/*J2C:non-persistent*/;
      addr = createAddressSocket_InterProcessCommFactorySocket_Ipc(/*J2C:static method call*/null_StringJc /*J2C: mem assignment*/, protocolAndOwnAddr, nPort, _thCxt);
    }
    else if(startsWith_StringJc(protocolAndOwnAddr, s0_StringJc("TCP:"))) 
    { 
      
      
      StringJc sAddr ; sAddr = substring_I_StringJc(protocolAndOwnAddr, 4, _thCxt)/*J2C:non-persistent*/;
      addr = createAddressSocket_InterProcessCommFactorySocket_Ipc(/*J2C:static method call*/null_StringJc /*J2C: mem assignment*/, protocolAndOwnAddr, nPort, _thCxt);
    }
    else 
    { 
      
      addr = null;
    }
    { STACKTRC_LEAVE;
      return addr;
    }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
struct Address_InterProcessComm_t* createAddress_Si_InterProcessCommFactorySocket_Ipc(InterProcessCommFactory_s* ithis, StringJc protocolAndOwnAddr, int32 nPort, ThCxt* _thCxt)
{ Mtbl_InterProcessCommFactory const* mtbl = (Mtbl_InterProcessCommFactory const*)getMtbl_ObjectJc(&ithis->base.object, sign_Mtbl_InterProcessCommFactory);
  return mtbl->createAddress_Port((InterProcessCommFactory_s*)ithis, protocolAndOwnAddr, nPort, _thCxt);
}


/**Creates an address for InterProcesscommunication with given description.*/
struct Address_InterProcessComm_t* createAddress_S_InterProcessCommFactorySocket_Ipc_F(InterProcessCommFactory_s* ithis, StringJc protocolAndAddr, ThCxt* _thCxt)
{ InterProcessCommFactorySocket_Ipc_s* thiz = (InterProcessCommFactorySocket_Ipc_s*)ithis;
  Mtbl_InterProcessCommFactorySocket_Ipc const* mtthis = (Mtbl_InterProcessCommFactorySocket_Ipc const*)getMtbl_ObjectJc(&thiz->base.object, sign_Mtbl_InterProcessCommFactorySocket_Ipc);
  
  STACKTRC_TENTRY("createAddress_S_InterProcessCommFactorySocket_Ipc_F");
  
  { 
    
    
    struct Address_InterProcessComm_t*  obj = mtthis->InterProcessCommFactory.createAddress_Port(& ((* (thiz)).base.super)/*J2cT1*/, protocolAndAddr, -1, _thCxt);
    { STACKTRC_LEAVE;
      return obj;
    }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
struct Address_InterProcessComm_t* createAddress_S_InterProcessCommFactorySocket_Ipc(InterProcessCommFactory_s* ithis, StringJc protocolAndAddr, ThCxt* _thCxt)
{ Mtbl_InterProcessCommFactory const* mtbl = (Mtbl_InterProcessCommFactory const*)getMtbl_ObjectJc(&ithis->base.object, sign_Mtbl_InterProcessCommFactory);
  return mtbl->createAddress((InterProcessCommFactory_s*)ithis, protocolAndAddr, _thCxt);
}

struct Address_InterProcessComm_t* createAddressSocket_InterProcessCommFactorySocket_Ipc(/*J2C:static method*/ StringJc type, StringJc addr, int32 nPort, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("createAddressSocket_InterProcessCommFactorySocket_Ipc");
  
  { 
    ObjectJc *newObj2_1=null; /*J2C: temporary Objects for new operations
    */
    if(type.ref== null) 
    { 
      
      
      int32  posAddr = indexOf_C_StringJc(addr, ':');
      type = substring_StringJc(addr, 0, posAddr, _thCxt)/*J2C:non-persistent*/;
      addr = substring_I_StringJc(addr, posAddr + 1, _thCxt)/*J2C:non-persistent*/;
    }
    ASSERTJc(/*J2C:static method call*/length_StringJc(addr) > 0);
    if(nPort <= 0) 
    { 
      StringJc _temp3_1; /*J2C: temporary references for concatenation */
      
      
      int32  posPort = indexOf_C_StringJc(addr, ':');
      if(posPort < 0) { throw_s0Jc(ident_IllegalArgumentExceptionJc, "param addr needs a port in form \"URL:port\" where port is a number or hexNumber with \"0x\"-prefix.", 0, __LINE__, _thCxt); return 0; };
      if(
        ( _temp3_1= substring_I_StringJc(addr, posPort + 1, _thCxt)
        , startsWith_StringJc(_temp3_1, s0_StringJc("0x"))
        )) 
      { 
        
        nPort = parseInt_radix_IntegerJc(/*J2C:static method call*/substring_I_StringJc(addr, posPort + 3, _thCxt), 16);
      }
      else 
      { 
        
        nPort = parseInt_IntegerJc(/*J2C:static method call*/substring_I_StringJc(addr, posPort + 1, _thCxt));
      }
      addr = substring_StringJc(addr, 0, posPort, _thCxt)/*J2C:non-persistent*/;
    }
    
    struct Address_InterProcessComm_t*  addrSocket = ctorO_ssI_Address_InterProcessComm(/*J2C:static method call*/(newObj2_1 = alloc_ObjectJc(sizeof_Address_InterProcessComm_s, 0, _thCxt)), type, addr, nPort, _thCxt);
    { STACKTRC_LEAVE;
      activateGC_ObjectJc(newObj2_1, addrSocket, _thCxt);
      return ((/*J2C:cast from Address_InterProcessComm_s*/Address_InterProcessComm_s*)(addrSocket));
    }
  }
  STACKTRC_LEAVE;
}



/**J2C: Reflections and Method-table *************************************************/
const MtblDef_InterProcessCommFactorySocket_Ipc mtblInterProcessCommFactorySocket_Ipc = {
{ { sign_Mtbl_InterProcessCommFactorySocket_Ipc //J2C: Head of methodtable of InterProcessCommFactorySocket_Ipc
  , (struct Size_Mtbl_t*)((0 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
  }
  //J2C: The superclass's methodtable: 
, { { sign_Mtbl_InterProcessCommFactory //J2C: Head of methodtable of InterProcessCommFactory
    , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //J2C:size. NOTE: all elements has the size of void*.
    }
    //J2C: Dynamic methods of the class :InterProcessCommFactory:
  , createAddress_S_InterProcessCommFactorySocket_Ipc_F //createAddress
  , createAddress_Si_InterProcessCommFactorySocket_Ipc_F //createAddress_Port
  , create_S_InterProcessCommFactorySocket_Ipc_F //create
  , create_Si_InterProcessCommFactorySocket_Ipc_F //create_Port
  , create_AddrIpc_InterProcessCommFactorySocket_Ipc_F //create_Addr
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


 extern_C struct ClassJc_t const reflection_InterProcessCommFactory_s;
 static struct superClasses_InterProcessCommFactorySocket_Ipc_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_InterProcessCommFactorySocket_Ipc_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_InterProcessCommFactory_s, OFFSET_Mtbl(Mtbl_InterProcessCommFactorySocket_Ipc, InterProcessCommFactory) }
   }
 };

const ClassJc reflection_InterProcessCommFactorySocket_Ipc_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "InterProcessCommFa_ket_Ipc_s"
,  0 //position of ObjectJc
, sizeof(InterProcessCommFactorySocket_Ipc_s)
, null //attributes and associations
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_InterProcessCommFactorySocket_Ipc_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblInterProcessCommFactorySocket_Ipc.mtbl.head
};

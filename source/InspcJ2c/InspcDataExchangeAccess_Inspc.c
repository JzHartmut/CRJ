/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "InspcJ2c/InspcDataExchangeAccess_Inspc.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <Fwc/fw_Exception.h>  //basic stacktrace concept
#include "Jc/ReflectionJc.h"  //reference-association: ClassJc


/* J2C: Forward declaration of struct ***********************************************/

/**This class supports preparing data for the Inspector-datagram-definition.
@author Hartmut Schorrig

*/


const char sign_Mtbl_InspcDataExchangeAccess_Inspc[] = "InspcDataExchangeAccess_Inspc"; //to mark method tables of all implementations

typedef struct MtblDef_InspcDataExchangeAccess_Inspc_t { Mtbl_InspcDataExchangeAccess_Inspc mtbl; MtblHeadJc end; } MtblDef_InspcDataExchangeAccess_Inspc;
 extern MtblDef_InspcDataExchangeAccess_Inspc const mtblInspcDataExchangeAccess_Inspc;

/*Constructor *//**J2C: autogenerated as default constructor. */
struct InspcDataExchangeAccess_Inspc_t* ctorO_InspcDataExchangeAccess_Inspc(ObjectJc* othis, ThCxt* _thCxt)
{ InspcDataExchangeAccess_Inspc_s* thiz = (InspcDataExchangeAccess_Inspc_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_InspcDataExchangeAccess_Inspc");
  checkConsistence_ObjectJc(othis, sizeof(InspcDataExchangeAccess_Inspc_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_InspcDataExchangeAccess_Inspc_s, sizeof(InspcDataExchangeAccess_Inspc_s));  
  //j2c: Initialize all class variables:
  {
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return thiz;
}




/**J2C: Reflections and Method-table *************************************************/
const MtblDef_InspcDataExchangeAccess_Inspc mtblInspcDataExchangeAccess_Inspc = {
{ { sign_Mtbl_InspcDataExchangeAccess_Inspc//J2C: Head of methodtable.
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
}, { signEnd_Mtbl_ObjectJc, null } }; //Mtbl


 extern_C struct ClassJc_t const reflection_ObjectJc;
 static struct superClasses_InspcDataExchangeAccess_Inspc_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_InspcDataExchangeAccess_Inspc_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_InspcDataExchangeAccess_Inspc, ObjectJc) }
   }
 };

const ClassJc reflection_InspcDataExchangeAccess_Inspc_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "InspcDataExchangeA_s_Inspc_s"
,  0 //position of ObjectJc
, sizeof(InspcDataExchangeAccess_Inspc_s)
, null //attributes and associations
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_InspcDataExchangeAccess_Inspc_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblInspcDataExchangeAccess_Inspc.mtbl.head
};

/**Preparing the header of a datagram.

*/


const char sign_Mtbl_InspcDatagram_InspcDataExchangeAccess_Inspc[] = "InspcDatagram_InspcDataExchangeAccess_Inspc"; //to mark method tables of all implementations


/*Constructor */
struct InspcDatagram_InspcDataExchangeAccess_Inspc_t* ctorM_iY_InspcDatagram_InspcDataExchangeAccess_Inspc(MemC mthis, PtrVal_int8 buffer, ThCxt* _thCxt)
{ InspcDatagram_InspcDataExchangeAccess_Inspc_s* thiz = PTR_MemC(mthis, InspcDatagram_InspcDataExchangeAccess_Inspc_s);  //reference casting to the real class.
  int sizeObj = size_MemC(mthis);
  STACKTRC_TENTRY("ctor_InspcDatagram_InspcDataExchangeAccess_Inspc");
  if(sizeof(InspcDatagram_InspcDataExchangeAccess_Inspc_s) > sizeObj) THROW_s0(IllegalArgumentException, "faut size", sizeObj);
  //J2C:super Constructor
  ctorM_i_ByteDataAccessBaseJc(/*static*/mthis, sizeofHead_InspcDatagram_InspcDataExchangeAccess_Inspc, _thCxt);
  //j2c: Initialize all class variables:
  {
  }
  { 
    
    assign_iYii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), buffer, -1, 0, _thCxt);
    setBigEndian_ByteDataAccessBaseJc((&thiz->base.super), true);
  }
  STACKTRC_LEAVE;
  return thiz;
}



/*Constructor */
struct InspcDatagram_InspcDataExchangeAccess_Inspc_t* ctorM_InspcDatagram_InspcDataExchangeAccess_Inspc(MemC mthis, ThCxt* _thCxt)
{ InspcDatagram_InspcDataExchangeAccess_Inspc_s* thiz = PTR_MemC(mthis, InspcDatagram_InspcDataExchangeAccess_Inspc_s);  //reference casting to the real class.
  int sizeObj = size_MemC(mthis);
  STACKTRC_TENTRY("ctor_InspcDatagram_InspcDataExchangeAccess_Inspc");
  if(sizeof(InspcDatagram_InspcDataExchangeAccess_Inspc_s) > sizeObj) THROW_s0(IllegalArgumentException, "faut size", sizeObj);
  //J2C:super Constructor
  ctorM_i_ByteDataAccessBaseJc(/*static*/mthis, sizeofHead_InspcDatagram_InspcDataExchangeAccess_Inspc, _thCxt);
  //j2c: Initialize all class variables:
  {
  }
  { 
    
    setBigEndian_ByteDataAccessBaseJc(& ((* (thiz)).base.super), true);
  }
  STACKTRC_LEAVE;
  return thiz;
}



/**Sets the head for an answer telegram*/
void setHeadRequest_InspcDatagram_InspcDataExchangeAccess_Inspc(InspcDatagram_InspcDataExchangeAccess_Inspc_s* thiz, int32 entrant, int32 seqNr, int32 encryption, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setHeadRequest_InspcDatagram_InspcDataExchangeAccess_Inspc");
  
  { 
    
    setInt16_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), knrofBytes_InspcDatagram_InspcDataExchangeAccess_Inspc, sizeofHead_InspcDatagram_InspcDataExchangeAccess_Inspc, _thCxt);
    setInt16_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), knEntrant_InspcDatagram_InspcDataExchangeAccess_Inspc, entrant, _thCxt);
    setInt32_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kseqnr_InspcDatagram_InspcDataExchangeAccess_Inspc, seqNr, _thCxt);
    setInt8_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kanswerNr_InspcDatagram_InspcDataExchangeAccess_Inspc, 0x0);
    setInt8_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kspare13_InspcDatagram_InspcDataExchangeAccess_Inspc, 0x0);
    setInt16_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kspare14_InspcDatagram_InspcDataExchangeAccess_Inspc, 0x0, _thCxt);/*int encryption = (int)(((0x10000 * Math.random())-0x8000) * 0x10000);*/
    
    setInt32_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kencryption_InspcDatagram_InspcDataExchangeAccess_Inspc, encryption, _thCxt);
  }
  STACKTRC_LEAVE;
}


/**Sets the head for an request telegram*/
void setHeadAnswer_InspcDatagram_InspcDataExchangeAccess_Inspc(InspcDatagram_InspcDataExchangeAccess_Inspc_s* thiz, int32 entrant, int32 seqNr, int32 encryption, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setHeadAnswer_InspcDatagram_InspcDataExchangeAccess_Inspc");
  
  { 
    
    setInt16_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), knrofBytes_InspcDatagram_InspcDataExchangeAccess_Inspc, sizeofHead_InspcDatagram_InspcDataExchangeAccess_Inspc, _thCxt);
    setInt16_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), knEntrant_InspcDatagram_InspcDataExchangeAccess_Inspc, entrant, _thCxt);
    setInt32_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kseqnr_InspcDatagram_InspcDataExchangeAccess_Inspc, seqNr, _thCxt);
    setInt8_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kanswerNr_InspcDatagram_InspcDataExchangeAccess_Inspc, 0x1);
    setInt8_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kspare13_InspcDatagram_InspcDataExchangeAccess_Inspc, 0x0);
    setInt16_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kspare14_InspcDatagram_InspcDataExchangeAccess_Inspc, 0x0, _thCxt);/*int encryption = (int)(((0x10000 * Math.random())-0x8000) * 0x10000);*/
    
    setInt32_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kencryption_InspcDatagram_InspcDataExchangeAccess_Inspc, encryption, _thCxt);
  }
  STACKTRC_LEAVE;
}


/**Mark the datagram as last answer. */
void markAnswerNrLast_InspcDatagram_InspcDataExchangeAccess_Inspc(InspcDatagram_InspcDataExchangeAccess_Inspc_s* thiz, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("markAnswerNrLast_InspcDatagram_InspcDataExchangeAccess_Inspc");
  
  { 
    int32 nr; 
    
    
    nr = getInt8_i_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kanswerNr_InspcDatagram_InspcDataExchangeAccess_Inspc, _thCxt);
    nr |= 0x80;
    setInt8_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kanswerNr_InspcDatagram_InspcDataExchangeAccess_Inspc, nr);
  }
  STACKTRC_LEAVE;
}


/**Increments the number for the answer datagram. */
void incrAnswerNr_InspcDatagram_InspcDataExchangeAccess_Inspc(InspcDatagram_InspcDataExchangeAccess_Inspc_s* thiz, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("incrAnswerNr_InspcDatagram_InspcDataExchangeAccess_Inspc");
  
  { 
    int32 nr; 
    
    
    nr = getInt8_i_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kanswerNr_InspcDatagram_InspcDataExchangeAccess_Inspc, _thCxt);
    nr = (nr & 0x7f) + 1;
    ASSERT(/*static*/(nr & 0x80) == 0);
    setInt8_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kanswerNr_InspcDatagram_InspcDataExchangeAccess_Inspc, nr);
  }
  STACKTRC_LEAVE;
}

 extern_C struct ClassJc_t const reflection_ByteDataAccessBaseJc_s;
 static struct superClasses_InspcDatagram_InspcDataExchangeAccess_Inspc_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_InspcDatagram_InspcDataExchangeAccess_Inspc_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ByteDataAccessBaseJc_s, 0 /*J2C: no Mtbl*/ }
   }
 };

const ClassJc reflection_InspcDatagram_InspcDataExchangeAccess_Inspc_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "InspcDatagram_Insp_s_Inspc_s"
,  0 //position of ObjectJc
, sizeof(InspcDatagram_InspcDataExchangeAccess_Inspc_s)
, null //attributes and associations
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_InspcDatagram_InspcDataExchangeAccess_Inspc_s //superclass
, null //interfaces
, 0    //modifiers
};

/**This is the header of an information entry.
<pre>
Inspcitem::= <@0+2#?SIZE> <@2+2#?cmd> <@4+4#?order> .
</pre>
An information entry contains this header and may be some childs.
The childs may be simple integer or String childs getting and setting
with the methodes to add
{@link ByteDataAccessBase#addChildInteger(int, long)} or {@link ByteDataAccessBase#addChildString(String)}.
and the methods to get
{@link ByteDataAccessBase#getChildInteger(int)} or {@link ByteDataAccessBase#getChildString(int)}.
The childs may be described by a named-here class, forex {@link InspcSetValue}
<br><br>
The structure of an information entry may be described with XML, where the XML is only
a medium to show the structures, for example:
<pre>
<Info bytes="16" order="345"><StringValue length="7">Example</StringValue></Info>
</pre>
In this case 8 Bytes are added after the head. The length stored in the head is 16.
The <StringValue...> consists of a length byte, following by ASCII-character.
*/


const char sign_Mtbl_Inspcitem_InspcDataExchangeAccess_Inspc[] = "Inspcitem_InspcDataExchangeAccess_Inspc"; //to mark method tables of all implementations


/*Constructor */
struct Inspcitem_InspcDataExchangeAccess_Inspc_t* ctorM_i_Inspcitem_InspcDataExchangeAccess_Inspc(MemC mthis, int32 sizeData, ThCxt* _thCxt)
{ Inspcitem_InspcDataExchangeAccess_Inspc_s* thiz = PTR_MemC(mthis, Inspcitem_InspcDataExchangeAccess_Inspc_s);  //reference casting to the real class.
  int sizeObj = size_MemC(mthis);
  STACKTRC_TENTRY("ctor_Inspcitem_InspcDataExchangeAccess_Inspc");
  if(sizeof(Inspcitem_InspcDataExchangeAccess_Inspc_s) > sizeObj) THROW_s0(IllegalArgumentException, "faut size", sizeObj);
  //J2C:super Constructor
  ctorM_ii_ByteDataAccessBaseJc(/*static*/mthis, sizeofHead_Inspcitem_InspcDataExchangeAccess_Inspc, sizeData, _thCxt);
  //j2c: Initialize all class variables:
  {
  }
  { 
    
    
  }
  STACKTRC_LEAVE;
  return thiz;
}



/*Constructor */
struct Inspcitem_InspcDataExchangeAccess_Inspc_t* ctorM_Inspcitem_InspcDataExchangeAccess_Inspc(MemC mthis, ThCxt* _thCxt)
{ Inspcitem_InspcDataExchangeAccess_Inspc_s* thiz = PTR_MemC(mthis, Inspcitem_InspcDataExchangeAccess_Inspc_s);  //reference casting to the real class.
  int sizeObj = size_MemC(mthis);
  STACKTRC_TENTRY("ctor_Inspcitem_InspcDataExchangeAccess_Inspc");
  if(sizeof(Inspcitem_InspcDataExchangeAccess_Inspc_s) > sizeObj) THROW_s0(IllegalArgumentException, "faut size", sizeObj);
  //J2C:super Constructor
  ctorM_i_ByteDataAccessBaseJc(/*static*/mthis, sizeofHead_Inspcitem_InspcDataExchangeAccess_Inspc, _thCxt);
  //j2c: Initialize all class variables:
  {
  }
  { 
    
    
  }
  STACKTRC_LEAVE;
  return thiz;
}



/**Sets the head data and sets the length of the ByteDataAccess-element.*/
void setInfoHead_Inspcitem_InspcDataExchangeAccess_Inspc(Inspcitem_InspcDataExchangeAccess_Inspc_s* thiz, int32 length, int32 cmd, int32 order, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setInfoHead_Inspcitem_InspcDataExchangeAccess_Inspc");
  
  { 
    int32 lengthInfo; 
    
    
    setInt16_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), 0, length, _thCxt);
    setInt16_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), 2, cmd, _thCxt);
    setInt32_ii_ByteDataAccessBaseJc(& ((* (thiz)).base.super), kbyteOrder_Inspcitem_InspcDataExchangeAccess_Inspc, order, _thCxt);
    lengthInfo = length >= sizeofHead_Inspcitem_InspcDataExchangeAccess_Inspc ? length : sizeofHead_Inspcitem_InspcDataExchangeAccess_Inspc;
    setLengthElement_ByteDataAccessBaseJc(& ((* (thiz)).base.super), lengthInfo);/*adjust the length in the access.*/
    
  }
  STACKTRC_LEAVE;
}

 extern_C struct ClassJc_t const reflection_ByteDataAccessBaseJc_s;
 static struct superClasses_Inspcitem_InspcDataExchangeAccess_Inspc_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_Inspcitem_InspcDataExchangeAccess_Inspc_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ByteDataAccessBaseJc_s, 0 /*J2C: no Mtbl*/ }
   }
 };

const ClassJc reflection_Inspcitem_InspcDataExchangeAccess_Inspc_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "Inspcitem_InspcDat_s_Inspc_s"
,  0 //position of ObjectJc
, sizeof(Inspcitem_InspcDataExchangeAccess_Inspc_s)
, null //attributes and associations
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_Inspcitem_InspcDataExchangeAccess_Inspc_s //superclass
, null //interfaces
, 0    //modifiers
};

/**ReflItem which contains a value.
<pre>
InspcSetValue::= <@0+6#?pwd> <@7+1#?type> [<@8+4 empty> <@12+4#?long> | ...].
</pre>

*/


const char sign_Mtbl_InspcSetValue_InspcDataExchangeAccess_Inspc[] = "InspcSetValue_InspcDataExchangeAccess_Inspc"; //to mark method tables of all implementations


/*Constructor */
struct InspcSetValue_InspcDataExchangeAccess_Inspc_t* ctorM_InspcSetValue_InspcDataExchangeAccess_Inspc(MemC mthis, ThCxt* _thCxt)
{ InspcSetValue_InspcDataExchangeAccess_Inspc_s* thiz = PTR_MemC(mthis, InspcSetValue_InspcDataExchangeAccess_Inspc_s);  //reference casting to the real class.
  int sizeObj = size_MemC(mthis);
  STACKTRC_TENTRY("ctor_InspcSetValue_InspcDataExchangeAccess_Inspc");
  if(sizeof(InspcSetValue_InspcDataExchangeAccess_Inspc_s) > sizeObj) THROW_s0(IllegalArgumentException, "faut size", sizeObj);
  //J2C:super Constructor
  ctorM_i_ByteDataAccessBaseJc(/*static*/mthis, sizeofElement_InspcSetValue_InspcDataExchangeAccess_Inspc, _thCxt);
  //j2c: Initialize all class variables:
  {
  }
  { 
    
    setBigEndian_ByteDataAccessBaseJc(& ((* (thiz)).base.super), true);
  }
  STACKTRC_LEAVE;
  return thiz;
}


 extern_C struct ClassJc_t const reflection_ByteDataAccessBaseJc_s;
 static struct superClasses_InspcSetValue_InspcDataExchangeAccess_Inspc_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_InspcSetValue_InspcDataExchangeAccess_Inspc_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ByteDataAccessBaseJc_s, 0 /*J2C: no Mtbl*/ }
   }
 };

const ClassJc reflection_InspcSetValue_InspcDataExchangeAccess_Inspc_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "InspcSetValue_Insp_s_Inspc_s"
,  0 //position of ObjectJc
, sizeof(InspcSetValue_InspcDataExchangeAccess_Inspc_s)
, null //attributes and associations
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_InspcSetValue_InspcDataExchangeAccess_Inspc_s //superclass
, null //interfaces
, 0    //modifiers
};

/**An item to set values with an index.
<pre>
InspcSetValueData::= <@0+8 Inspcitem> <@8+4#?address> <@12+4#?position> <@16 ReflSetValue>
</pre>
uses @{@link Inspcitem}, {@link InspcSetValue}
*/


const char sign_Mtbl_InspcSetValueData_InspcDataExchangeAccess_Inspc[] = "InspcSetValueData_InspcDataExchangeAccess_Inspc"; //to mark method tables of all implementations


/*Constructor */
struct InspcSetValueData_InspcDataExchangeAccess_Inspc_t* ctorM_InspcSetValueData_InspcDataExchangeAccess_Inspc(MemC mthis, ThCxt* _thCxt)
{ InspcSetValueData_InspcDataExchangeAccess_Inspc_s* thiz = PTR_MemC(mthis, InspcSetValueData_InspcDataExchangeAccess_Inspc_s);  //reference casting to the real class.
  int sizeObj = size_MemC(mthis);
  STACKTRC_TENTRY("ctor_InspcSetValueData_InspcDataExchangeAccess_Inspc");
  if(sizeof(InspcSetValueData_InspcDataExchangeAccess_Inspc_s) > sizeObj) THROW_s0(IllegalArgumentException, "faut size", sizeObj);
  //J2C:super Constructor
  ctorM_i_Inspcitem_InspcDataExchangeAccess_Inspc(/*static*/mthis, sizeofElement_InspcSetValueData_InspcDataExchangeAccess_Inspc, _thCxt);
  //j2c: Initialize all class variables:
  {
  }
  { 
    
    setBigEndian_ByteDataAccessBaseJc(& ((* (thiz)).base.super.base.super), true);
  }
  STACKTRC_LEAVE;
  return thiz;
}


void setBool_InspcSetValueData_InspcDataExchangeAccess_Inspc(InspcSetValueData_InspcDataExchangeAccess_Inspc_s* thiz, int32 value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setBool_InspcSetValueData_InspcDataExchangeAccess_Inspc");
  
  { 
    InspcSetValue_InspcDataExchangeAccess_Inspc_s setValue = { 0 }; 
    
    
    
    //J2C: constructor for embedded element-MemC
    ctorM_InspcSetValue_InspcDataExchangeAccess_Inspc(/*static*/build_MemC(&setValue, sizeof(setValue)), _thCxt);
    addChildAt_iXX_ByteDataAccessBaseJc(& ((* (thiz)).base.super.base.super), 16, & ((setValue).base.super), _thCxt);
    setBool_InspcSetValue_InspcDataExchangeAccess_Inspc(& (setValue), (int8)value);
  }
  STACKTRC_LEAVE;
}

void setShort_InspcSetValueData_InspcDataExchangeAccess_Inspc(InspcSetValueData_InspcDataExchangeAccess_Inspc_s* thiz, int32 value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setShort_InspcSetValueData_InspcDataExchangeAccess_Inspc");
  
  { 
    InspcSetValue_InspcDataExchangeAccess_Inspc_s setValue = { 0 }; 
    
    
    
    //J2C: constructor for embedded element-MemC
    ctorM_InspcSetValue_InspcDataExchangeAccess_Inspc(/*static*/build_MemC(&setValue, sizeof(setValue)), _thCxt);
    addChildAt_iXX_ByteDataAccessBaseJc(& ((* (thiz)).base.super.base.super), 16, & ((setValue).base.super), _thCxt);
    setShort_InspcSetValue_InspcDataExchangeAccess_Inspc(& (setValue), (int16)value);
  }
  STACKTRC_LEAVE;
}

void setByte_InspcSetValueData_InspcDataExchangeAccess_Inspc(InspcSetValueData_InspcDataExchangeAccess_Inspc_s* thiz, int32 value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setByte_InspcSetValueData_InspcDataExchangeAccess_Inspc");
  
  { 
    InspcSetValue_InspcDataExchangeAccess_Inspc_s setValue = { 0 }; 
    
    
    
    //J2C: constructor for embedded element-MemC
    ctorM_InspcSetValue_InspcDataExchangeAccess_Inspc(/*static*/build_MemC(&setValue, sizeof(setValue)), _thCxt);
    addChildAt_iXX_ByteDataAccessBaseJc(& ((* (thiz)).base.super.base.super), 16, & ((setValue).base.super), _thCxt);
    setByte_InspcSetValue_InspcDataExchangeAccess_Inspc(& (setValue), (int8)value);
  }
  STACKTRC_LEAVE;
}

void setInt_InspcSetValueData_InspcDataExchangeAccess_Inspc(InspcSetValueData_InspcDataExchangeAccess_Inspc_s* thiz, int32 value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setInt_InspcSetValueData_InspcDataExchangeAccess_Inspc");
  
  { 
    InspcSetValue_InspcDataExchangeAccess_Inspc_s setValue = { 0 }; 
    
    
    
    //J2C: constructor for embedded element-MemC
    ctorM_InspcSetValue_InspcDataExchangeAccess_Inspc(/*static*/build_MemC(&setValue, sizeof(setValue)), _thCxt);
    addChildAt_iXX_ByteDataAccessBaseJc(& ((* (thiz)).base.super.base.super), 16, & ((setValue).base.super), _thCxt);
    setInt_InspcSetValue_InspcDataExchangeAccess_Inspc(& (setValue), value);
  }
  STACKTRC_LEAVE;
}

void setFloat_InspcSetValueData_InspcDataExchangeAccess_Inspc(InspcSetValueData_InspcDataExchangeAccess_Inspc_s* thiz, float value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setFloat_InspcSetValueData_InspcDataExchangeAccess_Inspc");
  
  { 
    InspcSetValue_InspcDataExchangeAccess_Inspc_s setValue = { 0 }; 
    
    
    
    //J2C: constructor for embedded element-MemC
    ctorM_InspcSetValue_InspcDataExchangeAccess_Inspc(/*static*/build_MemC(&setValue, sizeof(setValue)), _thCxt);
    addChildAt_iXX_ByteDataAccessBaseJc(& ((* (thiz)).base.super.base.super), 16, & ((setValue).base.super), _thCxt);
    setFloat_InspcSetValue_InspcDataExchangeAccess_Inspc(& (setValue), value);
  }
  STACKTRC_LEAVE;
}

void setFloatIntImage_InspcSetValueData_InspcDataExchangeAccess_Inspc(InspcSetValueData_InspcDataExchangeAccess_Inspc_s* thiz, int32 value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setFloatIntImage_InspcSetValueData_InspcDataExchangeAccess_Inspc");
  
  { 
    InspcSetValue_InspcDataExchangeAccess_Inspc_s setValue = { 0 }; 
    
    
    
    //J2C: constructor for embedded element-MemC
    ctorM_InspcSetValue_InspcDataExchangeAccess_Inspc(/*static*/build_MemC(&setValue, sizeof(setValue)), _thCxt);
    addChildAt_iXX_ByteDataAccessBaseJc(& ((* (thiz)).base.super.base.super), 16, & ((setValue).base.super), _thCxt);
    setFloatIntImage_InspcSetValue_InspcDataExchangeAccess_Inspc(& (setValue), value);
  }
  STACKTRC_LEAVE;
}

void setDouble_InspcSetValueData_InspcDataExchangeAccess_Inspc(InspcSetValueData_InspcDataExchangeAccess_Inspc_s* thiz, double value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setDouble_InspcSetValueData_InspcDataExchangeAccess_Inspc");
  
  { 
    InspcSetValue_InspcDataExchangeAccess_Inspc_s setValue = { 0 }; 
    
    
    
    //J2C: constructor for embedded element-MemC
    ctorM_InspcSetValue_InspcDataExchangeAccess_Inspc(/*static*/build_MemC(&setValue, sizeof(setValue)), _thCxt);
    addChildAt_iXX_ByteDataAccessBaseJc(& ((* (thiz)).base.super.base.super), 16, & ((setValue).base.super), _thCxt);
    setDouble_InspcSetValue_InspcDataExchangeAccess_Inspc(& (setValue), value);
  }
  STACKTRC_LEAVE;
}

void setLong_InspcSetValueData_InspcDataExchangeAccess_Inspc(InspcSetValueData_InspcDataExchangeAccess_Inspc_s* thiz, int64 value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("setLong_InspcSetValueData_InspcDataExchangeAccess_Inspc");
  
  { 
    InspcSetValue_InspcDataExchangeAccess_Inspc_s setValue = { 0 }; 
    
    
    
    //J2C: constructor for embedded element-MemC
    ctorM_InspcSetValue_InspcDataExchangeAccess_Inspc(/*static*/build_MemC(&setValue, sizeof(setValue)), _thCxt);
    addChildAt_iXX_ByteDataAccessBaseJc(& ((* (thiz)).base.super.base.super), 16, & ((setValue).base.super), _thCxt);
    setLong_InspcSetValue_InspcDataExchangeAccess_Inspc(& (setValue), value);
  }
  STACKTRC_LEAVE;
}

 extern_C struct ClassJc_t const reflection_Inspcitem_InspcDataExchangeAccess_Inspc_s;
 static struct superClasses_InspcSetValueData_InspcDataExchangeAccess_Inspc_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_InspcSetValueData_InspcDataExchangeAccess_Inspc_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_Inspcitem_InspcDataExchangeAccess_Inspc_s, 0 /*J2C: no Mtbl*/ }
   }
 };

const ClassJc reflection_InspcSetValueData_InspcDataExchangeAccess_Inspc_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "InspcSetValueData__s_Inspc_s"
,  0 //position of ObjectJc
, sizeof(InspcSetValueData_InspcDataExchangeAccess_Inspc_s)
, null //attributes and associations
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_InspcSetValueData_InspcDataExchangeAccess_Inspc_s //superclass
, null //interfaces
, 0    //modifiers
};

/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "MsgDisp/MsgText_ifc_MSG.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <Fwc/fw_Exception.h>  //basic stacktrace concept


/* J2C: Forward declaration of struct ***********************************************/

/**Interface to get a text to a message number. */


const char sign_Mtbl_MsgText_ifc_MSG[] = "MsgText_ifc_MSG"; //to mark method tables of all implementations


/**Returns a message text to the given ident number*/
/*J2C: dynamic call variant of the override-able method: */
char const* getMsgText_MsgText_ifc_MSG(ObjectJc* ithis, int32 ident, ThCxt* _thCxt)
{ Mtbl_MsgText_ifc_MSG const* mtbl = (Mtbl_MsgText_ifc_MSG const*)getMtbl_ObjectJc(ithis, sign_Mtbl_MsgText_ifc_MSG);
  return mtbl->getMsgText(ithis, ident, _thCxt);
}

/*J2C: dynamic call variant of the override-able method: */
struct CollectionJc_t* getListItems_MsgText_ifc_MSG(ObjectJc* ithis, ThCxt* _thCxt)
{ Mtbl_MsgText_ifc_MSG const* mtbl = (Mtbl_MsgText_ifc_MSG const*)getMtbl_ObjectJc(ithis, sign_Mtbl_MsgText_ifc_MSG);
  return mtbl->getListItems(ithis, _thCxt);
}

 extern_C struct ClassJc_t const reflection_ObjectJc;
 static struct superClasses_MsgText_ifc_MSG_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_MsgText_ifc_MSG_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, 0 /*J2C: no Mtbl*/ }
   }
 };

extern_C struct ClassJc_t const reflection_MsgText_ifc_MSG_s;
const struct Reflection_Fields_MsgText_ifc_MSG_s_t
{ ObjectArrayJc head; FieldJc data[1];
} reflection_Fields_MsgText_ifc_MSG_s =
{ CONST_ObjectArrayJc(FieldJc, 1, OBJTYPE_FieldJc, null, &reflection_Fields_MsgText_ifc_MSG_s)
, {
     { "version"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgText_ifc_MSG_s*)(0x1000))->version) - (int32)(MsgText_ifc_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgText_ifc_MSG_s
    }
} };
const ClassJc reflection_MsgText_ifc_MSG_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "MsgText_ifc_MSG_s"
,  0 //position of ObjectJc
, sizeof(MsgText_ifc_MSG_s)
, (FieldJcArray const*)&reflection_Fields_MsgText_ifc_MSG_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_MsgText_ifc_MSG_s //superclass
, null //interfaces
, 0    //modifiers
};

/**One item for each message.
From Zbnf: This class is used as setting class for Zbnf2Java, therefore all is public. The identifiers have to be used
as semantic in the parser script.

*/


const char sign_Mtbl_MsgConfigItem_MsgText_ifc_MSG[] = "MsgConfigItem_MsgText_ifc_MSG"; //to mark method tables of all implementations

typedef struct MtblDef_MsgConfigItem_MsgText_ifc_MSG_t { Mtbl_MsgConfigItem_MsgText_ifc_MSG mtbl; MtblHeadJc end; } MtblDef_MsgConfigItem_MsgText_ifc_MSG;
 extern MtblDef_MsgConfigItem_MsgText_ifc_MSG const mtblMsgConfigItem_MsgText_ifc_MSG;
void set_type_MsgConfigItem_MsgText_ifc_MSG_F(MsgConfigItem_MsgText_ifc_MSG_s* thiz, StringJc src, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("set_type_MsgConfigItem_MsgText_ifc_MSG_F");
  
  { 
    
    thiz->type_ = charAt_StringJc(src, 0);
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void set_type_MsgConfigItem_MsgText_ifc_MSG(MsgConfigItem_MsgText_ifc_MSG_s* thiz, StringJc src, ThCxt* _thCxt)
{ Mtbl_MsgConfigItem_MsgText_ifc_MSG const* mtbl = (Mtbl_MsgConfigItem_MsgText_ifc_MSG const*)getMtbl_ObjectJc(&thiz->base.object, sign_Mtbl_MsgConfigItem_MsgText_ifc_MSG);
  mtbl->set_type(thiz, src, _thCxt);
}



/**J2C: Reflections and Method-table *************************************************/
const MtblDef_MsgConfigItem_MsgText_ifc_MSG mtblMsgConfigItem_MsgText_ifc_MSG = {
{ { sign_Mtbl_MsgConfigItem_MsgText_ifc_MSG//J2C: Head of methodtable.
  , (struct Size_Mtbl_t*)((1 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
  }
, set_type_MsgConfigItem_MsgText_ifc_MSG_F //set_type
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
 static struct superClasses_MsgConfigItem_MsgText_ifc_MSG_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_MsgConfigItem_MsgText_ifc_MSG_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_MsgConfigItem_MsgText_ifc_MSG, ObjectJc) }
   }
 };

extern_C struct ClassJc_t const reflection_MsgConfigItem_MsgText_ifc_MSG_s;
extern_C struct ClassJc_t const reflection_StringJc;
const struct Reflection_Fields_MsgConfigItem_MsgText_ifc_MSG_s_t
{ ObjectArrayJc head; FieldJc data[6];
} reflection_Fields_MsgConfigItem_MsgText_ifc_MSG_s =
{ CONST_ObjectArrayJc(FieldJc, 6, OBJTYPE_FieldJc, null, &reflection_Fields_MsgConfigItem_MsgText_ifc_MSG_s)
, {
     { "text"
    , 0 //nrofArrayElements
    , &reflection_StringJc
    , kEnhancedReference_Modifier_reflectJc /*t*/ //bitModifiers
    , (int16)((int32)(&((MsgConfigItem_MsgText_ifc_MSG_s*)(0x1000))->text) - (int32)(MsgConfigItem_MsgText_ifc_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgConfigItem_MsgText_ifc_MSG_s
    }
   , { "identText"
    , 0 //nrofArrayElements
    , &reflection_StringJc
    , kEnhancedReference_Modifier_reflectJc /*t*/ //bitModifiers
    , (int16)((int32)(&((MsgConfigItem_MsgText_ifc_MSG_s*)(0x1000))->identText) - (int32)(MsgConfigItem_MsgText_ifc_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgConfigItem_MsgText_ifc_MSG_s
    }
   , { "identNr"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgConfigItem_MsgText_ifc_MSG_s*)(0x1000))->identNr) - (int32)(MsgConfigItem_MsgText_ifc_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgConfigItem_MsgText_ifc_MSG_s
    }
   , { "identNrLast"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgConfigItem_MsgText_ifc_MSG_s*)(0x1000))->identNrLast) - (int32)(MsgConfigItem_MsgText_ifc_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgConfigItem_MsgText_ifc_MSG_s
    }
   , { "dst"
    , 0 //nrofArrayElements
    , &reflection_StringJc
    , kEnhancedReference_Modifier_reflectJc /*t*/ //bitModifiers
    , (int16)((int32)(&((MsgConfigItem_MsgText_ifc_MSG_s*)(0x1000))->dst) - (int32)(MsgConfigItem_MsgText_ifc_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgConfigItem_MsgText_ifc_MSG_s
    }
   , { "type_"
    , 0 //nrofArrayElements
    , REFLECTION_char
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((MsgConfigItem_MsgText_ifc_MSG_s*)(0x1000))->type_) - (int32)(MsgConfigItem_MsgText_ifc_MSG_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_MsgConfigItem_MsgText_ifc_MSG_s
    }
} };
const ClassJc reflection_MsgConfigItem_MsgText_ifc_MSG_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "MsgConfigItem_MsgT_ifc_MSG_s"
,  0 //position of ObjectJc
, sizeof(MsgConfigItem_MsgText_ifc_MSG_s)
, (FieldJcArray const*)&reflection_Fields_MsgConfigItem_MsgText_ifc_MSG_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_MsgConfigItem_MsgText_ifc_MSG_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblMsgConfigItem_MsgText_ifc_MSG.mtbl.head
};
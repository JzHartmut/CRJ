/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "InspcJ2c/SearchElement_Inspc.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <Fwc/fw_Exception.h>  //basic stacktrace concept
#include "Jc/ObjectJc.h"  //reference-association: IntegerJc
#include "Jc/ReflectionJc.h"  //reference-association: ClassJc
#include "Jc/StringJc.h"  //embedded type in class data


/* J2C: Forward declaration of struct ***********************************************/

/**It is a wrapper around the java.lang.Class with additional functionality.
@author Hartmut Schorrig
*/


const char sign_Mtbl_SearchElement_Inspc[] = "SearchElement_Inspc"; //to mark method tables of all implementations

typedef struct MtblDef_SearchElement_Inspc_t { Mtbl_SearchElement_Inspc mtbl; MtblHeadJc end; } MtblDef_SearchElement_Inspc;
 extern MtblDef_SearchElement_Inspc const mtblSearchElement_Inspc;
SearchTrc_SearchElement_Inspc_s searchTrc_SearchElement_Inspc[16];

/*Constructor *//**J2C: autogenerated as default constructor. */
struct SearchElement_Inspc_t* ctorO_SearchElement_Inspc(ObjectJc* othis, ThCxt* _thCxt)
{ SearchElement_Inspc_s* thiz = (SearchElement_Inspc_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_SearchElement_Inspc");
  checkConsistence_ObjectJc(othis, sizeof(SearchElement_Inspc_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_SearchElement_Inspc_s, sizeof(SearchElement_Inspc_s));  
  //j2c: Initialize all class variables:
  {
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return thiz;
}



/**Searches a Field in a Object with given path*/
MemSegmJc searchObject_SearchElement_Inspc(/*static*/ StringJc sPath, struct ObjectJc_t* startObj, struct FieldJc_t const** retField, int32* retIdx, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("searchObject_SearchElement_Inspc");
  
  { 
    MemSegmJc currentObj = { 0 }; 
    StringJc sName = NULL_StringJc; 
    StringJc sElement = NULL_StringJc; 
    struct ClassJc_t const* clazz; 
    MemSegmJc nextObj = { 0 };   /*@xx java2c=stackInstance */
    struct FieldJc_t const* field = null; 
    int32 idx = -1; 
    int32 posSep = 0; 
    int32 posStart = 0; 
    int32 idxSearchTrc = 0; 
    
    
    
    //J2C: constructor for embedded element
    INIT_MemSegmJc(/*static*/currentObj);
    sName = null_StringJc/*J2C:non-persistent*/;
    sElement = null_StringJc/*J2C:non-persistent*/;
    clazz = getClass_ClassJc(/*static*/startObj);
    
    //J2C: constructor for embedded element
    INIT_AddrSegm_MemSegmJc(/*static*/nextObj, startObj, 0);
    field = null;
    idx = -1;
    /*no initvalue*/
    posStart = 0;
    idxSearchTrc = 0;
    TRY
    { 
      
      do 
        { 
          int32 posEnd = 0; 
          
          
          /*no initvalue*/
          posSep = indexOf_CI_StringJc(sPath, '.', posStart);/*may be <0 if no '.' is found*/
          
          posEnd = posSep >= 0 ? posSep : length_StringJc(sPath);
          if(posEnd > posStart) 
          { /*:next loop to search:*/
            
            int32 posBracket = 0; 
            
            
            /*no initvalue*/
            set_MemSegmJc(currentObj, nextObj);
            idx = -1;
            sElement = substring_StringJc(sPath, posStart, posEnd, _thCxt)/*J2C:non-persistent*/;
            posBracket = indexOf_C_StringJc(sElement, '[');
            
            { 
              int32 posAngleBracket; 
              
              
              posAngleBracket = indexOf_C_StringJc(sElement, '<');
              if(posAngleBracket >= 0) 
              { 
                
                posBracket = posAngleBracket;/*may be also <0*/
                
              }
              if(posBracket >= 0) 
              { 
                int32 posBracketEnd; 
                
                
                posBracketEnd = indexOf_CI_StringJc(sElement, posAngleBracket >= 0 ? '>' : ']', posBracket + 1);
                if(posBracketEnd < 0) 
                { 
                  
                  posBracketEnd = length_StringJc(sElement);
                }/*if the ] is missing in the actual context*/
                /*get index:*/
                
                idx = parseInt_IntegerJc(/*static*/substring_StringJc(sElement, posBracket + 1, posBracketEnd, _thCxt));
                sName = substring_StringJc(sElement, 0, posBracket, _thCxt)/*J2C:non-persistent*/;
              }
              else 
              { 
                
                sName = sElement/*J2C:non-persistent*/;
              }
              sElement = null_StringJc/*J2C:non-persistent*/;/*clear_StringJc(&sElement);*/
              
              if(equals_StringJc(sName, s0_StringJc("super"))) 
              { 
                
                field = getSuperField_ClassJc(clazz);
              }
              else 
              { 
                
                field = getDeclaredField_ClassJc(clazz, sName);
              }
              sName = null_StringJc/*J2C:non-persistent*/;/*clear_StringJc(&sName);*/
              
              if(field != null && (posSep > 0 && length_StringJc(sPath) > (posSep + 1))) 
              { /*:a next loop may be necessary because a . is found:*/
                /*:access to the element because it is the base of next loop.*/
                /*:currentObj is the object where the field is searched.*/
                
                struct ClassJc_t const* retClazz[1];   /**/
                
                
                set_MemSegmJc(searchTrc_SearchElement_Inspc[idxSearchTrc].objWhereFieldIsFound, currentObj);
                searchTrc_SearchElement_Inspc[idxSearchTrc].clazzWhereFieldIsFound = clazz;
                searchTrc_SearchElement_Inspc[idxSearchTrc].field = field;
                
                set_MemSegmJc(nextObj, getObjAndClass_FieldJc(field, currentObj, &retClazz[0], "I", idx));
                clazz = retClazz[0];
                searchTrc_SearchElement_Inspc[idxSearchTrc].typeOfField = clazz;
                set_MemSegmJc(searchTrc_SearchElement_Inspc[idxSearchTrc].objOfField, nextObj);
                if(++idxSearchTrc >= ARRAYLEN(searchTrc_SearchElement_Inspc)) 
                { /*:prevent overflow. Its only a debug helper. The first entries are relevant.*/
                  
                  
                  idxSearchTrc = ARRAYLEN(searchTrc_SearchElement_Inspc) - 1;
                }/*nextObj is the object where the field is member of,*/
                /*nextObj is getted started from currentObj, +via offset in field, and access than.*/
                
              }
              else 
              { }/*the obj and field are found*/
              
              posStart = posSep + 1;
            }
          }
        }while(field != null && posSep > 0 && obj_MemSegmJc(nextObj) != null);
    }_TRY
    CATCH(NoSuchFieldException, exc)
    
      { 
        
        setNull_MemSegmJc(currentObj);
        field = null;
        idx = -1;
      }
    CATCH(ExceptionJc, exc)
    
      { 
        
        setNull_MemSegmJc(currentObj);
        field = null;
        idx = -1;
      }
    END_TRY
    retField[0] = field;
    retIdx[0] = idx;
    { STACKTRC_LEAVE;
      return currentObj;
    }
  }
  STACKTRC_LEAVE;
}



/**J2C: Reflections and Method-table *************************************************/
const MtblDef_SearchElement_Inspc mtblSearchElement_Inspc = {
{ { sign_Mtbl_SearchElement_Inspc//J2C: Head of methodtable.
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
 static struct superClasses_SearchElement_Inspc_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_SearchElement_Inspc_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_SearchElement_Inspc, ObjectJc) }
   }
 };

extern_C struct ClassJc_t const reflection_SearchElement_Inspc_s;
extern_C struct ClassJc_t const reflection_SearchTrc_SearchElement_Inspc_s;
const struct Reflection_Fields_SearchElement_Inspc_s_t
{ ObjectArrayJc head; FieldJc data[1];
} reflection_Fields_SearchElement_Inspc_s =
{ CONST_ObjectArrayJc(FieldJc, 1, OBJTYPE_FieldJc, null, &reflection_Fields_SearchElement_Inspc_s)
, {
     { "searchTrc"
    , 16 //nrofArrayElements
    , &reflection_SearchTrc_SearchElement_Inspc_s
    , kEmbedded_Modifier_reflectJc |kStaticArray_Modifier_reflectJc |mSTATIC_Modifier_reflectJc //bitModifiers
    , 0 //compiler problem, not a constant,TODO: (int16)(&searchTrc_SearchElement_Inspc) //lo part of memory address of static member
    , 0 //compiler problem, not a constant,TODO: (int16)((int32)(&searchTrc_SearchElement_Inspc)>>16) //hi part of memory address of static member instead offsetToObjectifcBase, TRICKY because compatibilty.
    , &reflection_SearchElement_Inspc_s
    }
} };
const ClassJc reflection_SearchElement_Inspc_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "SearchElement_Inspc_s"
,  0 //position of ObjectJc
, sizeof(SearchElement_Inspc_s)
, (FieldJcArray const*)&reflection_Fields_SearchElement_Inspc_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_SearchElement_Inspc_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblSearchElement_Inspc.mtbl.head
};

/**Only for debugging: Element to store the trace while searching any element.
* It is use-able if the algorithm itself are debugged.
* */


const char sign_Mtbl_SearchTrc_SearchElement_Inspc[] = "SearchTrc_SearchElement_Inspc"; //to mark method tables of all implementations


/*Constructor *//**J2C: autogenerated as default constructor. */
struct SearchTrc_SearchElement_Inspc_t* ctorM_SearchTrc_SearchElement_Inspc(MemC mthis, ThCxt* _thCxt)
{ SearchTrc_SearchElement_Inspc_s* thiz = PTR_MemC(mthis, SearchTrc_SearchElement_Inspc_s);  //reference casting to the real class.
  int sizeObj = size_MemC(mthis);
  STACKTRC_TENTRY("ctor_SearchTrc_SearchElement_Inspc");
  if(sizeof(SearchTrc_SearchElement_Inspc_s) > sizeObj) THROW_s0(IllegalArgumentException, "faut size", sizeObj);
  //j2c: Initialize all class variables:
  {
    //J2C: constructor for embedded element
      INIT_MemSegmJc(/*static*/thiz->objWhereFieldIsFound);
    //J2C: constructor for embedded element
      INIT_MemSegmJc(/*static*/thiz->objOfField);
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return thiz;
}


extern_C struct ClassJc_t const reflection_SearchTrc_SearchElement_Inspc_s;
extern_C struct ClassJc_t const reflection_ClassJc;
extern_C struct ClassJc_t const reflection_FieldJc;
extern_C struct ClassJc_t const reflection_MemSegmJc;
extern_C struct ClassJc_t const reflection_SearchTrc_SearchElement_Inspc_s;
const struct Reflection_Fields_SearchTrc_SearchElement_Inspc_s_t
{ ObjectArrayJc head; FieldJc data[5];
} reflection_Fields_SearchTrc_SearchElement_Inspc_s =
{ CONST_ObjectArrayJc(FieldJc, 5, OBJTYPE_FieldJc, null, &reflection_Fields_SearchTrc_SearchElement_Inspc_s)
, {
     { "objWhereFieldIsFound"
    , 0 //nrofArrayElements
    , &reflection_MemSegmJc
    , kEmbedded_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SearchTrc_SearchElement_Inspc_s*)(0x1000))->objWhereFieldIsFound) - (int32)(SearchTrc_SearchElement_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SearchTrc_SearchElement_Inspc_s
    }
   , { "clazzWhereFieldIsFound"
    , 0 //nrofArrayElements
    , &reflection_ClassJc
    , kReference_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SearchTrc_SearchElement_Inspc_s*)(0x1000))->clazzWhereFieldIsFound) - (int32)(SearchTrc_SearchElement_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SearchTrc_SearchElement_Inspc_s
    }
   , { "field"
    , 0 //nrofArrayElements
    , &reflection_FieldJc
    , kReference_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SearchTrc_SearchElement_Inspc_s*)(0x1000))->field) - (int32)(SearchTrc_SearchElement_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SearchTrc_SearchElement_Inspc_s
    }
   , { "typeOfField"
    , 0 //nrofArrayElements
    , &reflection_ClassJc
    , kReference_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SearchTrc_SearchElement_Inspc_s*)(0x1000))->typeOfField) - (int32)(SearchTrc_SearchElement_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SearchTrc_SearchElement_Inspc_s
    }
   , { "objOfField"
    , 0 //nrofArrayElements
    , &reflection_MemSegmJc
    , kEmbedded_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SearchTrc_SearchElement_Inspc_s*)(0x1000))->objOfField) - (int32)(SearchTrc_SearchElement_Inspc_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SearchTrc_SearchElement_Inspc_s
    }
} };
const ClassJc reflection_SearchTrc_SearchElement_Inspc_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "SearchTrc_SearchEl_t_Inspc_s"
,  0 //position of ObjectJc
, sizeof(SearchTrc_SearchElement_Inspc_s)
, (FieldJcArray const*)&reflection_Fields_SearchTrc_SearchElement_Inspc_s
, null //method
, null //superclass
, null //interfaces
, 0    //modifiers
};

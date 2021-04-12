/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __InspcJ2c_SearchElement_Inspc_h__
#define __InspcJ2c_SearchElement_Inspc_h__

#include "emC/Base/MemC_emC.h"        //basic concept

#include "emC/Jc/ObjectJc.h"        //basic concept

#include "emC/Jc/StringJc.h"        //used often

   //basic concept


/* J2C: Forward declaration of struct ***********************************************/
struct ClassJc_t;
struct FieldJc_t;
struct ObjectJc_t;
struct SearchElement_Inspc_t;
struct SearchTrc_SearchElement_Inspc_t;


/* J2C: includes *********************************************************/
#include "emC/Jc/ReflMemAccessJc.h"  //embedded type in class data


/*@CLASS_C SearchTrc_SearchElement_Inspc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct SearchTrc_SearchElement_Inspc_t
{ 
  MemSegmJc objWhereFieldIsFound; 
  struct ClassJc_t const* clazzWhereFieldIsFound;   /**/
  struct FieldJc_t const* field;   /**/
  struct ClassJc_t const* typeOfField;   /**/
  MemSegmJc objOfField; 
} SearchTrc_SearchElement_Inspc_s;
  

#define sizeof_SearchTrc_SearchElement_Inspc_s sizeof(SearchTrc_SearchElement_Inspc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef SearchTrc_SearchElement_InspcREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define SearchTrc_SearchElement_InspcREFDEF
  struct SearchTrc_SearchElement_Inspc_t;
  typedef TYPE_EnhancedRefJc(SearchTrc_SearchElement_Inspc);
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct SearchTrc_SearchElement_Inspc_X_t { ObjectArrayJc head; SearchTrc_SearchElement_InspcREF data[50]; } SearchTrc_SearchElement_Inspc_X;
typedef struct SearchTrc_SearchElement_Inspc_Y_t { ObjectArrayJc head; SearchTrc_SearchElement_Inspc_s data[50]; } SearchTrc_SearchElement_Inspc_Y;

 extern_C struct ClassJc_t const refl_SearchTrc_SearchElement_Inspc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_SearchTrc_SearchElement_Inspc(OBJP) { CONST_ObjectJc(sizeof(SearchTrc_SearchElement_Inspc_s), OBJP, &refl_SearchTrc_SearchElement_Inspc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_SearchTrc_SearchElement_Inspc_F(SearchTrc_SearchElement_Inspc_s* thiz, ThCxt* _thCxt);




/**Default constructor. */
METHOD_C struct SearchTrc_SearchElement_Inspc_t* ctorM_SearchTrc_SearchElement_Inspc(MemC mthis, ThCxt* _thCxt);


#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class SearchTrc_SearchElement_Inspc : private SearchTrc_SearchElement_Inspc_s
{ public:
};

#endif /*__CPLUSPLUSJcpp*/



/*@CLASS_C SearchElement_Inspc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct SearchElement_Inspc_t
{ 
  union { ObjectJc object; } base; 
} SearchElement_Inspc_s;
  

#define sizeof_SearchElement_Inspc_s sizeof(SearchElement_Inspc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef SearchElement_InspcREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define SearchElement_InspcREFDEF
  struct SearchElement_Inspc_t;
  typedef TYPE_EnhancedRefJc(SearchElement_Inspc);
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct SearchElement_Inspc_X_t { ObjectArrayJc head; SearchElement_InspcREF data[50]; } SearchElement_Inspc_X;
typedef struct SearchElement_Inspc_Y_t { ObjectArrayJc head; SearchElement_Inspc_s data[50]; } SearchElement_Inspc_Y;

 extern_C struct ClassJc_t const refl_SearchElement_Inspc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_SearchElement_Inspc(OBJP) { CONST_ObjectJc(sizeof(SearchElement_Inspc_s), OBJP, &refl_SearchElement_Inspc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_SearchElement_Inspc_F(ObjectJc* othis, ThCxt* _thCxt);


 extern StringJc version_SearchElement_Inspc;   /*Version, history and license.*/
 extern SearchTrc_SearchElement_Inspc_s searchTrc_SearchElement_Inspc[16];   /*Only for debugging: Stores the trace while searching any element.*/

//!!usage: static init code, invoke that one time in start of main.
void initStatic_SearchElement_Inspc();




/**Default constructor. */
METHOD_C struct SearchElement_Inspc_t* ctorO_SearchElement_Inspc(ObjectJc* othis, ThCxt* _thCxt);

#define kNoAccessRights_SearchElement_Inspc -2
#define kNullPointerInPath_SearchElement_Inspc -3
#define kFieldNotFound_SearchElement_Inspc -4
#define kAccessError_SearchElement_Inspc -5

/**Searches a Field in a Object with given path. It is the core routine to access data
 * with the inspector with the given path.
 * @param sPath the access path
 * @param startClazz If have to be matching with startAddr. It is separated because non-ObjectJc instances are supported as well as remote Adresses.
 * @param startAddr It is possible to search in an remote device, therefore uses an MemSegmJc. Use SETaddrSegm_MemSegJc(mem, addr, 0) for ordinary access to own addresses.
 * @param retField reference is set with the field last found field in the path. It is set to null if the field is not found because an access error 
 * @param retIdx 
 * -1 = the path has not an index on its end. >=0 for a given index. 
 * -2 = kNoAccessRights_SearchElement_Inspc if the access rights don't permit the access. Then the last field and instance which is accessible is returned.
 * -3 = kNullPointerInPath_SearchElement_Inspc if the path cannot be evaluated to its end because a null-pointer is found in the access path. 
 * -4 = kFieldNotFound_SearchElement_Inspc on field not found.
 * -5 = kAccessError_SearchElement_Inspc on any other error.
 * @return The Object where the retField is found or null
 * @throws never, except on fatal errors. It is  not necessary to use a TRY-environment for this routine. It uses TRY internally.
 */
METHOD_C MemSegmJc searchObject_SearchElement_Inspc(/*J2C:static method*/ StringJc sPath
, struct ClassJc_t const* startClazz, MemSegmJc startAddr
, struct FieldJc_t const** retField, int32* retIdx, ThCxt* _thCxt);


#ifdef DEF_ClassJc_Vtbl
/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Vtbl_SearchElement_Inspc[]; //marker for methodTable check
typedef struct Vtbl_SearchElement_Inspc_t
{ VtblHeadJc head;
  Vtbl_ObjectJc ObjectJc;
} Vtbl_SearchElement_Inspc;
#endif //def DEF_ClassJc_Vtbl



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class SearchElement_Inspc : private SearchElement_Inspc_s
{ public:

  SearchElement_Inspc(){ init_ObjectJc(&this->base.object, sizeof(SearchElement_Inspc_s), 0); setReflection_ObjectJc(&this->base.object, &refl_SearchElement_Inspc_s, 0); ctorO_SearchElement_Inspc(&this->base.object,  null/*_thCxt*/); }

  MemSegmJc searchObject(StringJcpp sPath, struct ObjectJc_t* startObj, struct FieldJc_t const** retField, int32* retIdx){  return searchObject_SearchElement_Inspc(sPath, startObj, retField, retIdx,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__InspcJ2c_SearchElement_Inspc_h__

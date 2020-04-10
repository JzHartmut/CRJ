/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __J1c_SpecialCharStringsJc_h__
#define __J1c_SpecialCharStringsJc_h__

#include "emC/Base/MemC_emC.h"        //basic concept

#include "emC/Jc/ObjectJc.h"        //basic concept

#include "emC/Jc/StringJc.h"        //used often

   //basic concept


/* J2C: Forward declaration of struct ***********************************************/
struct SpecialCharStringsJc_t;


/* J2C: includes *********************************************************/


/*@CLASS_C SpecialCharStringsJc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct SpecialCharStringsJc_t
{ 
  union { ObjectJc object; } base; 
} SpecialCharStringsJc_s;
  

#define sizeof_SpecialCharStringsJc_s sizeof(SpecialCharStringsJc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef SpecialCharStringsJcREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define SpecialCharStringsJcREFDEF
  struct SpecialCharStringsJc_t;
  typedef TYPE_EnhancedRefJc(SpecialCharStringsJc);
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct SpecialCharStringsJc_X_t { ObjectArrayJc head; SpecialCharStringsJcREF data[50]; } SpecialCharStringsJc_X;
typedef struct SpecialCharStringsJc_Y_t { ObjectArrayJc head; SpecialCharStringsJc_s data[50]; } SpecialCharStringsJc_Y;

 extern_C struct ClassJc_t const reflection_SpecialCharStringsJc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_SpecialCharStringsJc(OBJP) { CONST_ObjectJc(sizeof(SpecialCharStringsJc_s), OBJP, &reflection_SpecialCharStringsJc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_SpecialCharStringsJc_F(ObjectJc* othis, ThCxt* _thCxt);




/**Default constructor. */
METHOD_C struct SpecialCharStringsJc_t* ctorO_SpecialCharStringsJc(ObjectJc* othis, ThCxt* _thCxt);

/**Resolves the given String containing some switch chars in form of backslash 
to a string with the appropriate character codes.
In the result String all char-pairs beginning with backslash are replaced by
one char. If the String doesn't contain backslashes, the method returns the input string
in a as soon as possible calculation time.
<ul>
<li>\n\r\t\f\b will converted to the known control character codes:
<li>\n newline 0x0a
<li>etc TODO
<li>\s will converted to a single space. It is usefull in input situations
where a space will have another effect.
<li>\a will converted to the code 0x02, known in this class {@link cStartOfText}.
It is usefull wether a String may be contain a code for start of text.
<li>\e will converted to the code 0x03, known in this class {@link cEndOfText}.
<li>\x0123 Convert from given hex code TODO
<li>\\ is the backslash itself.
<li>All other chars after backslash will be converted to the same char, 
at example "\{" to "{". Don't use this feature for normal alphabetic chars
because some extensions in a future may be conflict with them. But this feature
may be usefull if an input text uses the special characters in a special way.
</ul> 
*/
METHOD_C CharSeqJc resolveCircumScription_SpecialCharStringsJc(/*J2C:static method*/ CharSeqJc src, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Vtbl_SpecialCharStringsJc[]; //marker for methodTable check
typedef struct Vtbl_SpecialCharStringsJc_t
{ VtblHeadJc head;
  Vtbl_ObjectJc ObjectJc;
} Vtbl_SpecialCharStringsJc;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class SpecialCharStringsJc : private SpecialCharStringsJc_s
{ public:

  SpecialCharStringsJc(){ iniz_ObjectJc(&this->base.object, sizeof(SpecialCharStringsJc_s), &reflection_SpecialCharStringsJc_s, 0); ctorO_SpecialCharStringsJc(&this->base.object,  null/*_thCxt*/); }

  CharSeqJc resolveCircumScription(CharSeqJc src){  return resolveCircumScription_SpecialCharStringsJc(src,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__J1c_SpecialCharStringsJc_h__

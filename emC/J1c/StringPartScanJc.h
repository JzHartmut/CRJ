/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __J1c_StringPartScanJc_h__
#define __J1c_StringPartScanJc_h__

#include "emC/Base/MemC_emC.h"        //basic concept

#include "emC/Jc/ObjectJc.h"        //basic concept

#include "emC/Jc/StringJc.h"        //used often

   //basic concept


/* J2C: Forward declaration of struct ***********************************************/
struct StringPartScanJc_t;


/* J2C: includes *********************************************************/
#include "emC/J1c/StringPartJc.h"  //superclass


/*@CLASS_C StringPartScanJc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct StringPartScanJc_t
{ 
  union { ObjectJc object; StringPartJc_s super;} base; 
  int32 beginScan;   /*Position of scanStart() or after scanOk() as begin of next scan operations. */
  struct nLastIntegerNumber_Y { ObjectArrayJc head; int64 data[5]; }nLastIntegerNumber;   /*Buffer for last scanned integer numbers.*/
  struct nLastIntegerSign_Y { ObjectArrayJc head; bool data[5]; }nLastIntegerSign;   /*Buffer for last scanned signs of integer numbers.*/
  int32 idxLastIntegerNumber;   /*current index of the last scanned integer number. -1=nothing scanned. 0..4=valid*/
  struct nLastFloatNumber_Y { ObjectArrayJc head; double data[5]; }nLastFloatNumber;   /*Last scanned float number*/
  int32 idxLastFloatNumber;   /*current index of the last scanned float number. -1=nothing scanned. 0..4=valid*/
  Part_StringPartJc_s sLastString;   /*Last scanned string. */
} StringPartScanJc_s;
  

#define sizeof_StringPartScanJc_s sizeof(StringPartScanJc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef StringPartScanJcREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define StringPartScanJcREFDEF
  struct StringPartScanJc_t;
  typedef TYPE_EnhancedRefJc(StringPartScanJc);
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct StringPartScanJc_X_t { ObjectArrayJc head; StringPartScanJcREF data[50]; } StringPartScanJc_X;
typedef struct StringPartScanJc_Y_t { ObjectArrayJc head; StringPartScanJc_s data[50]; } StringPartScanJc_Y;

 extern_C struct ClassJc_t const reflection_StringPartScanJc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_StringPartScanJc(OBJP) { CONST_ObjectJc(sizeof(StringPartScanJc_s), OBJP, &reflection_StringPartScanJc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_StringPartScanJc_F(ObjectJc* othis, ThCxt* _thCxt);


#define version_StringPartScanJc 20131027  /*Version, history and license.*/


METHOD_C struct StringPartScanJc_t* ctorO_Csii_StringPartScanJc(ObjectJc* othis, CharSeqJc src, int32 begin, int32 end, ThCxt* _thCxt);

METHOD_C struct StringPartScanJc_t* ctorO_Cs_StringPartScanJc(ObjectJc* othis, CharSeqJc src, ThCxt* _thCxt);

METHOD_C struct StringPartScanJc_t* ctorO_StringPartScanJc(ObjectJc* othis, ThCxt* _thCxt);

/**Skips over white spaces. It calls {@link StringPart#seekNoWhitespace()} and return this. */
METHOD_C struct StringPartScanJc_t* scanSkipSpace_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/**Skips over white spaces and comments. It calls {@link StringPart#seekNoWhitespaceOrComments()} and return this. */
METHOD_C struct StringPartScanJc_t* scanSkipComment_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/*** */
METHOD_C struct StringPartScanJc_t* scanStart_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/**Invocation of scan() for a {@link StringPart} is the same than scanStart().
@see org.vishia.util.StringPart#scan()
*/
METHOD_C struct StringPartScanJc_t* scan_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

METHOD_C bool scanEntry_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/**Test the result of scanning and set the scan Pos Ok, if current scanning was ok. If current scanning
was not ok, this method set the current scanning pos back to the position of the last call of scanOk()
or scanStart().
This method should only used in the user space to scan options. 
If it is not okay, the scan starts on the last position where it was okay, for the next option test:
<pre>
scanStart(); //call scanOk() independent of the last result. Set the scan start.
if(scanIdentifier().scanOk()) { //do something with the indentifier
} else if(scanFloat().scanOk()) { //a float is detected
} else if ....
</pre>
It is not yet possible for nested options.  
*/
METHOD_C bool scanOk_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/**scan next content, test the requested String.
new since 2008-09: if sTest contains cEndOfText, test whether this is the end.
skips over whitespaces and comments automatically, depends on the settings forced with
calling of {@link #seekNoWhitespaceOrComments()} .<br/>
See global description of scanning methods.
*/
METHOD_C struct StringPartScanJc_t* scan_Cs_StringPartScanJc(StringPartScanJc_s* thiz, CharSeqJc sTestP, ThCxt* _thCxt);

/*** */
METHOD_C struct StringPartScanJc_t* scanQuotion_CsSSY_StringPartScanJc(StringPartScanJc_s* thiz, CharSeqJc sQuotionmarkStart, StringJc sQuotionMarkEnd, StringJc_Y* sResult, ThCxt* _thCxt);

/*** */
METHOD_C struct StringPartScanJc_t* scanQuotion_CsSSYi_StringPartScanJc(StringPartScanJc_s* thiz, CharSeqJc sQuotionmarkStart, StringJc sQuotionMarkEnd, StringJc_Y* sResult, int32 maxToTest, ThCxt* _thCxt);

/**Scans if it is a integer number, contains exclusively of digits 0..9
*/
METHOD_C int64 scanDigits_StringPartScanJc(StringPartScanJc_s* thiz, bool bHex, int32 maxNrofChars, ThCxt* _thCxt);

/**Scanns a integer number as positiv value without sign. 
All digit character '0' to '9' will be proceed. 
The result as long value is stored internally
and have to be got calling {@link #getLastScannedIntegerNumber()}.
There can stored upto 5 numbers. If more as 5 numbers are stored yet,
an exception is thrown. 
*/
METHOD_C struct StringPartScanJc_t* scanPositivInteger_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/**Scans an integer expression with possible sign char '-' at first.
The result as long value is stored internally
and have to be got calling {@link #getLastScannedIntegerNumber()}.
There can stored upto 5 numbers. If more as 5 numbers are stored yet,
an exception is thrown. 
*/
METHOD_C struct StringPartScanJc_t* scanInteger_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/**Scans a float number. The result is stored internally
and have to be got calling {@link #getLastScannedFloatNumber()}.
There can stored upto 5 numbers. If more as 5 numbers are stored yet,
an exception is thrown.
*/
METHOD_C struct StringPartScanJc_t* scanFloatNumber_b_StringPartScanJc(StringPartScanJc_s* thiz, bool cleanBuffer, ThCxt* _thCxt);

/**Scans a float / double number. The result is stored internally
and have to be got calling {@link #getLastScannedFloatNumber()}.
There can stored upto 5 numbers. If more as 5 numbers are stored yet,
an exception is thrown. 
*/
METHOD_C struct StringPartScanJc_t* scanFloatNumber_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/**Scans the fractional part of a float / double number with given integer part and sign. 
The result is stored internally and have to be gotten calling {@link #getLastScannedFloatNumber()}.
<br><br>
Application-sample:
<pre>
if(spExpr.scanSkipSpace().scanInteger().scanOk()) {
Value value = new Value();
long longvalue = spExpr.getLastScannedIntegerNumber();
if(spExpr.scanFractionalNumber(longvalue).scanOk()) {
double dval = spExpr.getLastScannedFloatNumber();
if(spExpr.scan("F").scanOk()){
value.floatVal = (float)dval;
value.type = 'F';
} else {
value.doubleVal = dval;
value.type = 'D';
}
} else {
//no float, check range of integer
if(longvalue < 0x80000000L && longvalue >= -0x80000000L) {
value.intVal = (int)longvalue; value.type = 'I';
} else {
value.longVal = longvalue; value.type = 'L';
}
}
</pre>
*/
METHOD_C struct StringPartScanJc_t* scanFractionalNumber_StringPartScanJc(StringPartScanJc_s* thiz, int64 nInteger, bool bNegative, ThCxt* _thCxt);

/**Scans a sequence of hex chars a hex number. No '0x' or such should be present. 
See scanHexOrInt().
The result as long value is stored internally
and have to be got calling {@link #getLastScannedIntegerNumber()}.
There can stored upto 5 numbers. If more as 5 numbers are stored yet,
an exception is thrown. 
*/
METHOD_C struct StringPartScanJc_t* scanHex_StringPartScanJc(StringPartScanJc_s* thiz, int32 maxNrofChars, ThCxt* _thCxt);

/**Scans a integer number possible as hex, or decimal number.
If the number starts with 0x it is hexa. Otherwise it is a decimal number.
Octal numbers are not supported!  
The result as long value is stored internally
and have to be got calling {@link #getLastScannedIntegerNumber()}.
There can stored upto 5 numbers. If more as 5 numbers are stored yet,
an exception is thrown. 
*/
METHOD_C struct StringPartScanJc_t* scanHexOrDecimal_StringPartScanJc(StringPartScanJc_s* thiz, int32 maxNrofChars, ThCxt* _thCxt);

/**Scans an identifier with start characters A..Z, a..z, _ and all characters 0..9 inside.
If an identifier is not found, scanOk() returns false and the current position is preserved.
The identifier can be gotten with call of {@link #getLastScannedString()}.
*/
METHOD_C struct StringPartScanJc_t* scanIdentifier_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/**Scans an identifier with start characters A..Z, a..z, _ and all characters 0..9 inside,
and additional characters.
If an identifier is not found, scanOk() returns false and the current position is preserved.
The identifier can be gotten with call of {@link #getLastScannedString()}.
*/
METHOD_C struct StringPartScanJc_t* scanIdentifier_SS_StringPartScanJc(StringPartScanJc_s* thiz, StringJc additionalStartChars, StringJc additionalChars, ThCxt* _thCxt);

/**Returns the last scanned integer sign. It is the result of the methods
<ul><li>{@link #scanHex(int)}
<li>{@link #scanHexOrDecimal(int)}
<li>{@link #scanInteger()}
</ul>
This routine have to be called <b>before</b> the associated {@link #getLastScannedIntegerNumber()} is invoked.

*/
METHOD_C bool getLastScannedIntegerSign_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/**Returns the last scanned integer number. It is the result of the methods
<ul><li>{@link #scanHex(int)}
<li>{@link #scanHexOrDecimal(int)}
<li>{@link #scanInteger()}
</ul>
This routine can be called only one time for a scan result. After them the number, and its sign for {@link #getLastScannedIntegerSign()},
is removed.
*/
METHOD_C int64 getLastScannedIntegerNumber_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/**Returns the last scanned float number.
*/
METHOD_C double getLastScannedFloatNumber_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);

/**Returns the part of the last scanning yet only from {@link #scanIdentifier()}
*/
METHOD_C struct Part_StringPartJc_t* getLastScannedString_StringPartScanJc(StringPartScanJc_s* thiz, ThCxt* _thCxt);


/**Returns the last scanned part non persistently.
 * If the scanning continues with Strings, the returned instance is reused with the new scanning result.  
 * @param nr 1..5 for the last, pre-last etc. 
 */
METHOD_C struct Part_StringPartJc_t* getLastScannedPart_StringPartScanJc(StringPartScanJc_s* thiz, int nr, ThCxt* _thCxt);


/**Closes the work. This routine should be called if the StringPart is never used, 
but it may be kept because it is part of class data or part of a statement block which runs.
The associated String is released. It can be recycled by garbage collector.
If this method is overridden, it should used to close a associated file which is opened 
for this String processing. The overridden method should call super->close() too.
<br>
<br>
Note: if only this class is instantiated and the instance will be garbaged, close is not necessary.
A warning or error "Resource leak" can be switched off. Therefore the interface {@link java.io.Closeable} is not used here.
*/
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void close_StringPartScanJc_F(StringPartJc_s* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void close_StringPartScanJc(StringPartJc_s* ithis, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Vtbl_StringPartScanJc[]; //marker for methodTable check
typedef struct Vtbl_StringPartScanJc_t
{ VtblHeadJc head;
  Vtbl_StringPartJc StringPartJc;
} Vtbl_StringPartScanJc;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class StringPartScanJc : private StringPartScanJc_s
{ public:

  virtual void close(){ close_StringPartScanJc_F(&this->base.super,  null/*_thCxt*/); }

  StringPartScanJc(CharSeqJc src){ init_ObjectJc(&this->base.object, sizeof(StringPartScanJc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_StringPartScanJc_s, 0); ctorO_Cs_StringPartScanJc(&this->base.object, src,  null/*_thCxt*/); }

  StringPartScanJc(CharSeqJc src, int32 begin, int32 end){ init_ObjectJc(&this->base.object, sizeof(StringPartScanJc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_StringPartScanJc_s, 0); ctorO_Csii_StringPartScanJc(&this->base.object, src, begin, end,  null/*_thCxt*/); }

  StringPartScanJc(){ init_ObjectJc(&this->base.object, sizeof(StringPartScanJc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_StringPartScanJc_s, 0); ctorO_StringPartScanJc(&this->base.object,  null/*_thCxt*/); }

  double getLastScannedFloatNumber(){  return getLastScannedFloatNumber_StringPartScanJc(this,  null/*_thCxt*/); }

  int64 getLastScannedIntegerNumber(){  return getLastScannedIntegerNumber_StringPartScanJc(this,  null/*_thCxt*/); }

  bool getLastScannedIntegerSign(){  return getLastScannedIntegerSign_StringPartScanJc(this,  null/*_thCxt*/); }

  CharSeqJc getLastScannedString(){  return getLastScannedString_StringPartScanJc(this,  null/*_thCxt*/); }

  int64 scanDigits(bool bHex, int32 maxNrofChars){  return scanDigits_StringPartScanJc(this, bHex, maxNrofChars,  null/*_thCxt*/); }

  bool scanEntry(){  return scanEntry_StringPartScanJc(this,  null/*_thCxt*/); }

  StringPartScanJc& scanFloatNumber(){ scanFloatNumber_StringPartScanJc(this,  null/*_thCxt*/);  return *this; }

  StringPartScanJc& scanFloatNumber(bool cleanBuffer){ scanFloatNumber_b_StringPartScanJc(this, cleanBuffer,  null/*_thCxt*/);  return *this; }

  StringPartScanJc& scanFractionalNumber(int64 nInteger, bool bNegative){ scanFractionalNumber_StringPartScanJc(this, nInteger, bNegative,  null/*_thCxt*/);  return *this; }

  StringPartScanJc& scanHexOrDecimal(int32 maxNrofChars){ scanHexOrDecimal_StringPartScanJc(this, maxNrofChars,  null/*_thCxt*/);  return *this; }

  StringPartScanJc& scanHex(int32 maxNrofChars){ scanHex_StringPartScanJc(this, maxNrofChars,  null/*_thCxt*/);  return *this; }

  StringPartScanJc& scanIdentifier(StringJcpp additionalStartChars, StringJcpp additionalChars){ scanIdentifier_SS_StringPartScanJc(this, additionalStartChars, additionalChars,  null/*_thCxt*/);  return *this; }

  StringPartScanJc& scanIdentifier(){ scanIdentifier_StringPartScanJc(this,  null/*_thCxt*/);  return *this; }

  StringPartScanJc& scanInteger(){ scanInteger_StringPartScanJc(this,  null/*_thCxt*/);  return *this; }

  bool scanOk(){  return scanOk_StringPartScanJc(this,  null/*_thCxt*/); }

  StringPartScanJc& scanPositivInteger(){ scanPositivInteger_StringPartScanJc(this,  null/*_thCxt*/);  return *this; }

  StringPartScanJc& scanQuotion(CharSeqJc sQuotionmarkStart, StringJcpp sQuotionMarkEnd, StringJc_Y* sResult){ scanQuotion_CsSSY_StringPartScanJc(this, sQuotionmarkStart, sQuotionMarkEnd, sResult,  null/*_thCxt*/);  return *this; }

  StringPartScanJc& scanQuotion(CharSeqJc sQuotionmarkStart, StringJcpp sQuotionMarkEnd, StringJc_Y* sResult, int32 maxToTest){ scanQuotion_CsSSYi_StringPartScanJc(this, sQuotionmarkStart, sQuotionMarkEnd, sResult, maxToTest,  null/*_thCxt*/);  return *this; }

  struct StringPartScanJc_t* scanSkipComment(){  return scanSkipComment_StringPartScanJc(this,  null/*_thCxt*/); }

  struct StringPartScanJc_t* scanSkipSpace(){  return scanSkipSpace_StringPartScanJc(this,  null/*_thCxt*/); }

  StringPartScanJc& scanStart(){ scanStart_StringPartScanJc(this,  null/*_thCxt*/);  return *this; }

  StringPartScanJc& scan(CharSeqJc sTestP){ scan_Cs_StringPartScanJc(this, sTestP,  null/*_thCxt*/);  return *this; }

  struct StringPartScanJc_t* scan(){  return scan_StringPartScanJc(this,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__J1c_StringPartScanJc_h__

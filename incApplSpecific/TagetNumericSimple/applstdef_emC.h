#ifndef __applstdef_emC_h__
#define __applstdef_emC_h__
/**This headerfile contains all standard definition for usage the CRJ - CRuntimeJavalike - basicly system.
 * It is for a simple numeric target without reflection, StringJc and exception handling. 
 */

//Note: uncomment that to check whether this file is included:
//#error used_applstdefJc_TargetNumericSimple


//This block before <OSAL/os_types_def_common.h>
/**The compl_adaption.h should contain the compiler (and platform-) specific definitions of some data types with defined bit widhts.*/
#include <compl_adaption.h>

/**Include this file always, but after compl_adaption.h.
* It defines some types for C compilation compatible to C++ and some independent language enhancements.
*/
#include <OSAL/os_types_def_common.h>


/**With this compiler switch the reflection should not be included, because they will not used. */
#define __DONOTUSE_REFLECTION__


/**The compiler switch __CPLUSPLUSJcpp should set only if you want to work with the C++ variantes of Java2C translated files.
 * It is recommended also using a C++ compiler with C sources. Then do not set that compiler switch.
 */
//#define __CPLUSPLUSJcpp
#undef __CPLUSPLUSJcpp
//#define __cplusplus

/**Including this file the ObjectJc.h is not included, */
#include <sourceApplSpecific/applConv/ObjectJc_simple.h>


/**Define __NoCharSeqJcCapabilities__ only for simple systems with simple StringJc usage. */
#define __NoCharSeqJcCapabilities__
#define __NoStringJcCapabilities__

/**An EnhancedRef maybe necessary for BlockHeap concept. Here defines some macros in a simple form. */
#include <sourceApplSpecific/applConv/EnhanceRef_simple.h>
//#include <sourceApplSpecific/applConv/EnhanceRef_Blockheap.h>


//#include <sourceApplSpecific/applConv/assert_ignore.h>  //Note: after os_types_def_common because extern_C
//#include <sourceApplSpecific/applConv/assert_simpleStop.h>  //Note: after os_types_def_common because extern_C
#include <sourceApplSpecific/applConv/assert_THROW.h>  //Note: after os_types_def_common because extern_C


/**Use the exception handling header file - or define the macros TRY, by yourself. */
/** If this define is setted, the TRY, CATCH and THROW makros use the C++ keywords
  * try, throw and catch. All sources, also the *.c-Sources of the CRuntimeJavalike,
  * may be compiled with a C++-Compiler.
  *
  * If the macro is not setted, the TRY, CATCH and THROW makros use
  * the longjmp version. See fw_Exception.h. 
  * It is also possible to use longjmp in a C++ environment,
  * but destructors of local stack instances in skipped subroutines are ignored.
  * It must be secured that no critical destructors are used, or a FINALLY is used there.
  * Another reason for using C++ exception handling in a PC environment is: Operation system exceptions.
  * On visual studio C++ compiler you should set the option /EHa and /TP for C++ compilation of C sources.
  * The C variant with longjmp should only used if C++ is not available.
  */
  #define __TRYCPPJc

//#include <sourceApplSpecific/applConv/ThreadContextStacktrc_emC.h>
//#include <sourceApplSpecific/applConv/Exception_emC.h>
//#include <sourceApplSpecific/applConv/ExcStacktrcNo_emC.h>
#include <sourceApplSpecific/applConv/ExcNoStringStacktrcNo_emC.h>


/**Under Test conditions, the check of Stacktrace consistence should be activated. 
 * Because a forgotten STACKTRC_LEAVE-macro call won't be detected else,
 * and the stacktrace is corrupt for later usage.
 * Deactivate this macro in release versions.
 */
#ifdef _DEBUG
  #define TEST_STACKTRCJc 
#else
  #undef TEST_STACKTRCJc
#endif	


#define abs_complex(VAL) sqrtf( (VAL).re * (VAL).re + (VAL).im * (VAL).im )


//PRINTX
#include <sourceApplSpecific/applConv/definePrintFileMakros.h>
//#include <sourceApplSpecific/applConv/definePrintfMakros.h>


extern_C void stop_DebugutilJc(struct ThreadContext_emC_t* _thCxt);

#define kMaxPathLength_FileJc 500


INLINE_emC int stopNAN(){ return 0; }

/**Prevent process a NaN-value (not a number).
 * The NaN-check should be done processor-specific. Therefore this is a part of os_types_def.h
 * @param value the value to check and return in normal case
 * @param valueinstead This value is returned if value==nan
 * @param check a left-value (variable) which will be increment in the nan-situation for check. 
 * @return valueinstead or value.
 */
#define NNAN(value, valueinstead, check) (value < 1000000000.0f ? value : ((check) +=1, valueinstead))


/**Condition if value is not NAN
 * @param value to test
 * @param check a left-value (variable) which will be increment in the nan-situation for check. 
 */
#define ifNNAN(value, check) (value < 100000000.0f ? true :  ((check) +=1, false))

/**Prevent process a NaN-value maybe only in debug mode.
 * The NaN-check should be done processor-specific. Therefore this is a part of os_types_def.h
 * It calls stopNAN especially for debug at PC
 * @param value the value to check and return
 * @return value anytime.
 */
#define ASSERT_NNAN_F(value) (value < 100000000000.0f ? value : stopNAN(), value)

#include <string.h> //memcpy
#include <emC/SystemInit_emC.h>
#include <emC/Handle_ptr64_emC.h>

#endif // __applstdef_emC_h__

#ifndef HGUARD_applstdef_emC
#define HGUARD_applstdef_emC
/**This headerfile contains all standard definition for usage the emC - embedded multiplatform C(++) - basicly source system.
 * It is for a Applications in C(++) 
 * with 32 bit memory addresses on PC 
 * with Reflection, StringJc
 * with Excpetion handling with C++ throw to support asynchron exceptions. 
 */

//Note: uncomment that to check whether this file is included:
//#error Uses applC32_emC/applstdef_emC.h


/**The compiler switch __CPLUSPLUSJcpp should set only if you want to work with the C++ variantes of Java2C translated files.
 * It is recommended also using a C++ compiler with C sources. Then do not set that compiler switch.
 */
//#define __CPLUSPLUSJcpp
#undef __CPLUSPLUSJcpp
//#define __cplusplus

//This block before <OSAL/types_def_common.h>
/**The compl_adaption.h should contain the compiler (and platform-) specific definitions of some data types with defined bit widhts.*/
#include <compl_adaption.h>

/**Include this file always, but after compl_adaption.h.
* It defines some types for C compilation compatible to C++ and some independent language enhancements.
*/
#include <emC/Base/types_def_common.h>

/**With this compiler switch the reflection should not be included, because they will not used. */
//#define DEF_NO_REFLECTION
#if !defined(DEF_REFLECTION_NO) || !defined(DEF_REFLECTION_OFFS)
  #ifndef DEF_REFLECTION_FULL  //prevent warning if already defined as command line argument
    #define DEF_REFLECTION_FULL
  #endif
#endif

/**Define __NoCharSeqJcCapabilities__ only for simple systems with simple StringJc usage. */
//#define __NoCharSeqJcCapabilities__
//#define __NoStringJcCapabilities__
/**An EnhancedRef maybe necessary for BlockHeap concept. Here defines some macros in a simple form. */
//Include before String_emC.h because it is used there.
#include <emC_srcApplSpec/applConv/EnhanceRef_simple.h>
//#include <emC_srcApplSpec/applConv/EnhanceRef_Blockheap.h>


//#include <emC_srcApplSpec/applConv/assert_ignore.h>  //Note: after types_def_common because extern_C
//#include <emC_srcApplSpec/applConv/assert_simpleStop.h>  //Note: after types_def_common because extern_C
#include <emC_srcApplSpec/applConv/assert_THROW.h>  //Note: after types_def_common because extern_C


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
#define DEF_Exception_TRYCpp

#include <emC_srcApplSpec/applConv/ThreadContextStacktrc_emC.h>
#include <emC_srcApplSpec/applConv/Exception_emC.h>
//#include <emC/Base/ExcStacktrcNo.h>



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
#include <emC_srcApplSpec/applConv/definePrintFileMakros.h>
//#include <emC_srcApplSpec/applConv/definePrintfMakros.h>


extern_C void stop_DebugutilJc(struct ThreadContext_emC_t* _thCxt);

/**Maximal length of path in a FileDescription_OSAL-structure.
* NOTE: old name kMaxPathLength_OS_FileDescription
*/
#define kMaxPathLength_FileDescription_OSAL 480

/**size of a safety area inside any allocMem data range. It can be 0. Set for debug and check approaches. */
#define sizeSafetyArea_allocMemC 4096


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



#endif // HGUARD_applstdef_emC

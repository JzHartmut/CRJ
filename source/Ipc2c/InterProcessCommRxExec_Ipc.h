/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __Ipc2c_InterProcessCommRxExec_Ipc_h__
#define __Ipc2c_InterProcessCommRxExec_Ipc_h__

#include "Fwc/fw_MemC.h"        //basic concept

#include "Jc/ObjectJc.h"        //basic concept

#include "Jc/StringJc.h"        //used often

#include "Fwc/fw_Exception.h"   //basic concept


/* J2C: Forward declaration of struct ***********************************************/
struct Address_InterProcessComm_t;
struct InterProcessCommRxExec_Ipc_t;


/* J2C: includes *********************************************************/


/*@CLASS_C InterProcessCommRxExec_Ipc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct InterProcessCommRxExec_Ipc_t
{ 
} InterProcessCommRxExec_Ipc_s;
  

#define sizeof_InterProcessCommRxExec_Ipc_s sizeof(InterProcessCommRxExec_Ipc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef InterProcessCommRxExec_IpcREFDEF
  //J2C: definition of enhanced reference where it was need firstly: 
  #define InterProcessCommRxExec_IpcREFDEF
  struct InterProcessCommRxExec_Ipc_t;
  DEFINE_EnhancedRefJc(InterProcessCommRxExec_Ipc);
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct InterProcessCommRxExec_Ipc_X_t { ObjectArrayJc head; InterProcessCommRxExec_IpcREF data[50]; } InterProcessCommRxExec_Ipc_X;
typedef struct InterProcessCommRxExec_Ipc_Y_t { ObjectArrayJc head; InterProcessCommRxExec_Ipc_s data[50]; } InterProcessCommRxExec_Ipc_Y;

 extern_C struct ClassJc_t const reflection_InterProcessCommRxExec_Ipc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_InterProcessCommRxExec_Ipc(OBJP) { CONST_ObjectJc(sizeof(InterProcessCommRxExec_Ipc_s), OBJP, &reflection_InterProcessCommRxExec_Ipc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_InterProcessCommRxExec_Ipc_F(InterProcessCommRxExec_Ipc_s* thiz, ThCxt* _thCxt);




/**Default constructor. */
METHOD_C struct InterProcessCommRxExec_Ipc_t* ctorM_InterProcessCommRxExec_Ipc(MemC mthis, ThCxt* _thCxt);

typedef void MT_execRxData_InterProcessCommRxExec_Ipc(InterProcessCommRxExec_Ipc_s* thiz, int8_Y* buffer, int32 nrofBytesReceived, struct Address_InterProcessComm_t* sender, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void execRxData_InterProcessCommRxExec_Ipc_F(InterProcessCommRxExec_Ipc_s* thiz, int8_Y* buffer, int32 nrofBytesReceived, struct Address_InterProcessComm_t* sender, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void execRxData_InterProcessCommRxExec_Ipc(InterProcessCommRxExec_Ipc_s* thiz, int8_Y* buffer, int32 nrofBytesReceived, struct Address_InterProcessComm_t* sender, ThCxt* _thCxt);


#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class InterProcessCommRxExec_Ipc : private InterProcessCommRxExec_Ipc_s
{ public:

  virtual void execRxData(int8_Y* buffer, int32 nrofBytesReceived, struct Address_InterProcessComm_t* sender){ execRxData_InterProcessCommRxExec_Ipc_F(this, buffer, nrofBytesReceived, sender,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__Ipc2c_InterProcessCommRxExec_Ipc_h__
#ifndef __Wait_Inspc_h__
#define __Wait_Inspc_h__
#include <applstdef_emC.h>
#include <emC/base/Object_emC.h>   //The ObjectJc is used as base class for all struct
//#include <Jc/ObjectJc.h>
//#include <Jc/ReflectionJc.h>
//#include <emC/base/String_emC.h>




struct DataNode_Inspc_t;



typedef struct Wait_Inspc_t
{ ObjectJc base;
  
  int32 isWaiting;

  /**If 0 then wait or delay. */
  int32 volatile stepsTillWait;  

  /**If 0 wait till stepsTillWait !=0. 
   * If >0 the delay per step in millisec. 
   */
  int32 delay_ms;

} Wait_Inspc;


#ifndef DEF_REFLECTION_NO
  extern_C ClassJc const refl_Wait_Inspc;
#endif


/**Allocate and construct. */
Wait_Inspc* create_Wait_Inspc();


void ctor_Wait_Inspc(Wait_Inspc* thiz);


/**Register it in a DataNode_Inspc, invoke one time after create. */
bool registerReflection_Wait_Inspc(Wait_Inspc* thiz, struct DataNode_Inspc_t* reflNode);


/**
 * @simulink ctor
 */
void ctor_TillWait_Wait_Inspc(Wait_Inspc* thiz, float Tstep, int32 stepsTillFirstWait, int32 delay_ms);


/**
 * @simulink init
 */
void init_Wait_Inspc(Wait_Inspc* thiz, struct DataNode_Inspc_t* reflNode);

/**Counts stepTillWait down, if 0 and delay_ms == 0, waits for inspector communication.
 * if <0 then use delay. If >0 full speed.
 * @simulink Object-FB
 */
void step_Wait_Inspc(Wait_Inspc volatile* thiz);

void free_Wait_Inspc(Wait_Inspc* thiz);



#endif //__Wait_Inspc_h__

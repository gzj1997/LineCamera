#ifndef _DMC2210_LIB_H
#define _DMC2210_LIB_H

//这一段无需改动  //This segment should not be modified
#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;

typedef unsigned char  INT8U;                   /* defined for unsigned 8-bits integer variable 	无符号8位整型变量  */
typedef signed   char  INT8S;                   /* defined for signed 8-bits integer variable		有符号8位整型变量  */
typedef unsigned short INT16U;                  /* defined for unsigned 16-bits integer variable 	无符号16位整型变量 */
typedef signed   short INT16S;                  /* defined for signed 16-bits integer variable 		有符号16位整型变量 */
typedef unsigned int   INT32U;                  /* defined for unsigned 32-bits integer variable 	无符号32位整型变量 */
typedef int			   INT32S;                  /* defined for signed 32-bits integer variable 		有符号32位整型变量 */
typedef float		   FP32;                    /* single precision floating point variable (32bits) 单精度浮点数（32位长度） */
typedef double		   FP64;                    /* double precision floating point variable (64bits) 双精度浮点数（64位长度） */


#define __DMC2410_EXPORTS

//定义输入和输出
#ifdef __DMC2410_EXPORTS
	#define DMC2210_API __declspec(dllexport)
#else
	#define DMC2210_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

//---------------------   板卡初始和配置函数  ----------------------
/********************************************************************************
** 函数名称: d2210_board_init
** 功能描述: 控制板初始化，设置初始化和速度等设置
** 输　  入: 无
** 返 回 值: 0：无卡； 1-8：成功(实际卡数) 
**           1001 + j: j号卡初始化出错 从1001开始。
** 修    改:  
** 修改日期: 2006.12.7
*********************************************************************************/
DMC2210_API WORD __stdcall d2210_board_init(void);

/********************************************************************************
** 函数名称: d2210_board_close
** 功能描述: 关闭所有卡
** 输　  入: 无
** 返 回 值: 无
** 日    期: 2007.02.1
*********************************************************************************/
DMC2210_API void __stdcall d2210_board_close(void); 


//脉冲输入输出配置
/********************************************************************************
** 函数名称: d2210_set_pulse_outmode
** 功能描述: 脉冲输出方式的设置
** 输　  入: axis 
**               outmode: 脉冲模式
** 返 回 值: 无 
*********************************************************************************/
DMC2210_API void __stdcall d2210_set_pulse_outmode(WORD axis,WORD outmode);

//专用信号设置函数
DMC2210_API void __stdcall d2210_config_SD_PIN(WORD axis,WORD enable, WORD sd_logic,WORD sd_mode);
DMC2210_API void __stdcall d2210_config_PCS_PIN(WORD axis,WORD enable,WORD pcs_logic);
DMC2210_API void __stdcall d2210_config_INP_PIN(WORD axis,WORD enable,WORD inp_logic);
DMC2210_API void __stdcall d2210_config_ERC_PIN(WORD axis,WORD enable,WORD erc_logic,
				WORD erc_width,WORD erc_off_time);

DMC2210_API void __stdcall d2210_config_ALM_PIN(WORD axis,WORD alm_logic,WORD alm_action);
//new
DMC2210_API void __stdcall d2210_config_EL_MODE(WORD axis,WORD el_mode);

DMC2210_API void __stdcall d2210_set_HOME_pin_logic(WORD axis,WORD org_logic,WORD filter);

DMC2210_API void __stdcall d2210_write_SEVON_PIN(WORD axis, WORD on_off);
DMC2210_API int __stdcall d2210_read_SEVON_PIN(WORD axis);

DMC2210_API void __stdcall d2210_write_ERC_PIN(WORD axis, WORD sel);
DMC2210_API int __stdcall d2210_read_RDY_PIN(WORD axis);

//通用输入/输出控制函数
DMC2210_API int __stdcall  d2210_read_inbit(WORD cardno, WORD bitno);
DMC2210_API void __stdcall d2210_write_outbit(WORD cardno, WORD bitno,WORD on_off);
DMC2210_API int __stdcall  d2210_read_outbit(WORD cardno, WORD bitno) ;
DMC2210_API long __stdcall d2210_read_inport(WORD cardno);
DMC2210_API long __stdcall d2210_read_outport(WORD cardno) ;
DMC2210_API void __stdcall d2210_write_outport(WORD cardno, DWORD port_value);

//位置比较输出
DMC2210_API void __stdcall d2210_config_CMP_PIN(WORD axis, WORD cmp1_enable,  WORD cmp2_enable, WORD CMP_logic);
DMC2210_API int __stdcall  d2210_read_CMP_PIN(WORD axis);
DMC2210_API void __stdcall d2210_write_CMP_PIN(WORD axis, WORD on_off);

DMC2210_API void __stdcall d2210_config_comparator(WORD axis, WORD cmp1_condition, WORD cmp2_condition, WORD source_sel,WORD SL_action);
DMC2210_API void __stdcall d2210_set_comparator_data(WORD axis,long cmp1_data,long cmp2_data);

//制动函数
DMC2210_API void __stdcall d2210_decel_stop(WORD axis,double Tdec);
DMC2210_API void __stdcall d2210_imd_stop(WORD axis);
DMC2210_API void __stdcall d2210_emg_stop(void) ;
DMC2210_API void __stdcall d2210_simultaneous_stop(WORD axis) ;

//位置设置和读取函数
DMC2210_API long __stdcall d2210_get_position(WORD axis);
DMC2210_API void __stdcall d2210_set_position(WORD axis,long current_position);


//状态检测函数
DMC2210_API WORD __stdcall  d2210_check_done(WORD axis) ;
DMC2210_API WORD __stdcall d2210_prebuff_status(WORD axis);
DMC2210_API WORD __stdcall d2210_axis_io_status(WORD axis);
DMC2210_API WORD __stdcall d2210_axis_status(WORD axis);
DMC2210_API DWORD __stdcall d2210_get_rsts(WORD axis) ;


//速度设置
DMC2210_API void __stdcall d2210_variety_speed_range(WORD axis,WORD chg_enable ,double Max_Vel);
DMC2210_API double __stdcall d2210_read_current_speed(WORD axis);
DMC2210_API void __stdcall d2210_change_speed(WORD axis,double Curr_Vel);
DMC2210_API void __stdcall d2210_set_vector_profile(double Min_Vel,double Max_Vel,double Tacc,double Tdec);
DMC2210_API void __stdcall d2210_set_profile(WORD axis,double Min_Vel,double Max_Vel,double Tacc,double Tdec);
DMC2210_API void __stdcall d2210_set_s_profile(WORD axis,double Min_Vel,double Max_Vel,double Tacc,double Tdec, long Sacc,long Sdec);
DMC2210_API void __stdcall d2210_set_st_profile(WORD axis,double Min_Vel, double Max_Vel,double Tacc,double Tdec, double Tsacc,double Tsdec);

DMC2210_API void __stdcall d2210_reset_target_position(WORD axis,long dist);

//单轴定长运动
DMC2210_API void __stdcall d2210_t_pmove(WORD axis,long Dist,WORD posi_mode);
DMC2210_API void __stdcall d2210_ex_t_pmove(WORD axis,long Dist,WORD posi_mode);
DMC2210_API void __stdcall d2210_s_pmove(WORD axis,long Dist,WORD posi_mode);
DMC2210_API void __stdcall d2210_ex_s_pmove(WORD axis,long Dist,WORD posi_mode);

//单轴连续运动
DMC2210_API void __stdcall d2210_s_vmove(WORD axis,WORD dir);
DMC2210_API void __stdcall d2210_t_vmove(WORD axis,WORD dir);

//线性插补
DMC2210_API void __stdcall d2210_t_line2(WORD axis1,long Dist1,WORD axis2,long Dist2,WORD posi_mode);
DMC2210_API void __stdcall d2210_t_line3(WORD *axis,long Dist1,long Dist2,long Dist3,WORD posi_mode);
DMC2210_API void __stdcall d2210_t_line4(WORD cardno,long Dist1,long Dist2,long Dist3,long Dist4,WORD posi_mode);

//手轮运动
DMC2210_API void __stdcall d2210_set_handwheel_inmode(WORD axis,WORD inmode,WORD count_dir);
DMC2210_API void __stdcall d2210_handwheel_move(WORD axis,double vh);

//找原点
DMC2210_API void __stdcall d2210_config_home_mode(WORD axis,WORD mode,WORD EZ_count);
DMC2210_API void __stdcall d2210_home_move(WORD axis,WORD home_mode,WORD vel_mode);

//圆弧插补
DMC2210_API void __stdcall d2210_arc_move(WORD *axis,long *target_pos,long *cen_pos, WORD arc_dir);
DMC2210_API void __stdcall d2210_rel_arc_move(WORD *axis,long *rel_pos,long *rel_cen, WORD arc_dir);


//---------------------   编码器计数功能PLD  ----------------------//
DMC2210_API long __stdcall d2210_get_encoder(WORD axis);
DMC2210_API void __stdcall d2210_set_encoder(WORD axis,long encoder_value);

DMC2210_API void __stdcall d2210_config_EZ_PIN(WORD axis,WORD ez_logic, WORD ez_mode);
DMC2210_API void __stdcall d2210_config_LTC_PIN(WORD axis,WORD ltc_logic, WORD ltc_mode);

DMC2210_API void __stdcall d2210_config_latch_mode(WORD cardno, WORD all_enable);
DMC2210_API void __stdcall d2210_counter_config(WORD axis,WORD mode);
DMC2210_API long __stdcall d2210_get_latch_value(WORD axis);
DMC2210_API long __stdcall d2210_get_latch_flag(WORD cardno);
DMC2210_API void __stdcall d2210_reset_latch_flag(WORD cardno);

DMC2210_API long __stdcall d2210_get_counter_flag(WORD cardno);
DMC2210_API void __stdcall d2210_reset_counter_flag(WORD cardno);

DMC2210_API void __stdcall d2210_reset_clear_flag(WORD cardno);

DMC2210_API void __stdcall d2210_triger_chunnel(WORD cardno, WORD num);
DMC2210_API void __stdcall d2210_set_speaker_logic(WORD cardno, WORD logic);

//other
/********************************************************************************
** 函数名称: d2210_config_EMG_PIN
** 功能描述: EMG设置，d2410采用了软开关，急停信号有效后会立即停止所有轴
**           按卡号设置
** 输　  入: axis - (0 - 3), enable - 0:无效; 1:有效
**              emg_logic: 0:低有效; 1:高有效
** 返 回 值: 无 
*********************************************************************************/
DMC2210_API void __stdcall d2210_config_EMG_PIN(WORD cardno, WORD enable,WORD emg_logic);

//增加同时起停操作
/********************************************************************************
** 函数名称: d2210_set_t_move_all
** 功能描述: 多轴同步运动设定
** 输　  入: TotalAxes: 轴数,  pAxis:轴列表, pDist:位移列表
             posi_mode: 0-相对, 1-绝对
** 返 回 值: 1:正确 , -1:参数错
**     
*********************************************************************************/
INT32S __stdcall d2210_set_t_move_all(WORD TotalAxes, WORD *pAxis, long *pDist, WORD posi_mode);

/********************************************************************************
** 函数名称: d2210_start_move_all
** 功能描述: 多轴同步运动
** 输　  入: TotalAxes: 第一轴轴号
** 返 回 值: 1:正确 , -1:参数错
** 
*********************************************************************************/
INT32S __stdcall d2210_start_move_all(WORD FirstAxis);

/********************************************************************************
** 函数名称: d2210_set_sync_option
** 功能描述: 多轴同步选项设定, 注意: 使用后必须关闭此功能, 将sync_option1清0.
** 输　  入: axis:轴号
             sync_stop_on: 1:当CSTOP 信号来时,轴停止; 
             cstop_output_on: 当异常停止时输出 CSTOP信号
             sync_option1: 0:立即启动, 1: 等待CSTA信号 或是启动命令 
             sync_option2: 无用
** 返 回 值: 1:正确 , -1:参数错
** 
*********************************************************************************/
INT32S __stdcall d2210_set_sync_option(WORD axis, WORD sync_stop_on, WORD cstop_output_on, WORD sync_option1, WORD sync_option2);

/********************************************************************************
** 函数名称: d2210_set_sync_stop_mode
** 功能描述: 设置同步停止的减速方式
** 输　  入: axis: 轴号
             stop_mode:  0- 立即停止, 1-减速停止
** 返 回 值: 1:正确 , -1:参数错
** 
*********************************************************************************/
INT32S __stdcall d2210_set_sync_stop_mode(WORD axis, WORD stop_mode); 

/********************************************************************************
** 函数名称: d2210_config_CSTA_PIN
** 功能描述: 设置同步启动信号, 只能为低有效, 配置为电平或是边沿信号触发,默认为电平触发
** 输　  入: axis: 轴号
             edge_mode:  0- 电平, 1-边沿
** 返 回 值: 1
*********************************************************************************/
INT32S __stdcall d2210_config_CSTA_PIN(WORD axis, WORD edge_mode);

//读取版本号  
DMC2210_API  INT32S __stdcall d2210_get_lib_version(long * libVer, long * subLibVer);

//读取错误停止状态因子函数
DMC2210_API DWORD __stdcall d2210_read_error_int_factor(WORD axis);

#ifdef __cplusplus
}
#endif

#endif 
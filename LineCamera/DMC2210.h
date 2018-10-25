#ifndef _DMC2210_LIB_H
#define _DMC2210_LIB_H

//��һ������Ķ�  //This segment should not be modified
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

typedef unsigned char  INT8U;                   /* defined for unsigned 8-bits integer variable 	�޷���8λ���ͱ���  */
typedef signed   char  INT8S;                   /* defined for signed 8-bits integer variable		�з���8λ���ͱ���  */
typedef unsigned short INT16U;                  /* defined for unsigned 16-bits integer variable 	�޷���16λ���ͱ��� */
typedef signed   short INT16S;                  /* defined for signed 16-bits integer variable 		�з���16λ���ͱ��� */
typedef unsigned int   INT32U;                  /* defined for unsigned 32-bits integer variable 	�޷���32λ���ͱ��� */
typedef int			   INT32S;                  /* defined for signed 32-bits integer variable 		�з���32λ���ͱ��� */
typedef float		   FP32;                    /* single precision floating point variable (32bits) �����ȸ�������32λ���ȣ� */
typedef double		   FP64;                    /* double precision floating point variable (64bits) ˫���ȸ�������64λ���ȣ� */


#define __DMC2410_EXPORTS

//������������
#ifdef __DMC2410_EXPORTS
	#define DMC2210_API __declspec(dllexport)
#else
	#define DMC2210_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

//---------------------   �忨��ʼ�����ú���  ----------------------
/********************************************************************************
** ��������: d2210_board_init
** ��������: ���ư��ʼ�������ó�ʼ�����ٶȵ�����
** �䡡  ��: ��
** �� �� ֵ: 0���޿��� 1-8���ɹ�(ʵ�ʿ���) 
**           1001 + j: j�ſ���ʼ������ ��1001��ʼ��
** ��    ��:  
** �޸�����: 2006.12.7
*********************************************************************************/
DMC2210_API WORD __stdcall d2210_board_init(void);

/********************************************************************************
** ��������: d2210_board_close
** ��������: �ر����п�
** �䡡  ��: ��
** �� �� ֵ: ��
** ��    ��: 2007.02.1
*********************************************************************************/
DMC2210_API void __stdcall d2210_board_close(void); 


//���������������
/********************************************************************************
** ��������: d2210_set_pulse_outmode
** ��������: ���������ʽ������
** �䡡  ��: axis 
**               outmode: ����ģʽ
** �� �� ֵ: �� 
*********************************************************************************/
DMC2210_API void __stdcall d2210_set_pulse_outmode(WORD axis,WORD outmode);

//ר���ź����ú���
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

//ͨ������/������ƺ���
DMC2210_API int __stdcall  d2210_read_inbit(WORD cardno, WORD bitno);
DMC2210_API void __stdcall d2210_write_outbit(WORD cardno, WORD bitno,WORD on_off);
DMC2210_API int __stdcall  d2210_read_outbit(WORD cardno, WORD bitno) ;
DMC2210_API long __stdcall d2210_read_inport(WORD cardno);
DMC2210_API long __stdcall d2210_read_outport(WORD cardno) ;
DMC2210_API void __stdcall d2210_write_outport(WORD cardno, DWORD port_value);

//λ�ñȽ����
DMC2210_API void __stdcall d2210_config_CMP_PIN(WORD axis, WORD cmp1_enable,  WORD cmp2_enable, WORD CMP_logic);
DMC2210_API int __stdcall  d2210_read_CMP_PIN(WORD axis);
DMC2210_API void __stdcall d2210_write_CMP_PIN(WORD axis, WORD on_off);

DMC2210_API void __stdcall d2210_config_comparator(WORD axis, WORD cmp1_condition, WORD cmp2_condition, WORD source_sel,WORD SL_action);
DMC2210_API void __stdcall d2210_set_comparator_data(WORD axis,long cmp1_data,long cmp2_data);

//�ƶ�����
DMC2210_API void __stdcall d2210_decel_stop(WORD axis,double Tdec);
DMC2210_API void __stdcall d2210_imd_stop(WORD axis);
DMC2210_API void __stdcall d2210_emg_stop(void) ;
DMC2210_API void __stdcall d2210_simultaneous_stop(WORD axis) ;

//λ�����úͶ�ȡ����
DMC2210_API long __stdcall d2210_get_position(WORD axis);
DMC2210_API void __stdcall d2210_set_position(WORD axis,long current_position);


//״̬��⺯��
DMC2210_API WORD __stdcall  d2210_check_done(WORD axis) ;
DMC2210_API WORD __stdcall d2210_prebuff_status(WORD axis);
DMC2210_API WORD __stdcall d2210_axis_io_status(WORD axis);
DMC2210_API WORD __stdcall d2210_axis_status(WORD axis);
DMC2210_API DWORD __stdcall d2210_get_rsts(WORD axis) ;


//�ٶ�����
DMC2210_API void __stdcall d2210_variety_speed_range(WORD axis,WORD chg_enable ,double Max_Vel);
DMC2210_API double __stdcall d2210_read_current_speed(WORD axis);
DMC2210_API void __stdcall d2210_change_speed(WORD axis,double Curr_Vel);
DMC2210_API void __stdcall d2210_set_vector_profile(double Min_Vel,double Max_Vel,double Tacc,double Tdec);
DMC2210_API void __stdcall d2210_set_profile(WORD axis,double Min_Vel,double Max_Vel,double Tacc,double Tdec);
DMC2210_API void __stdcall d2210_set_s_profile(WORD axis,double Min_Vel,double Max_Vel,double Tacc,double Tdec, long Sacc,long Sdec);
DMC2210_API void __stdcall d2210_set_st_profile(WORD axis,double Min_Vel, double Max_Vel,double Tacc,double Tdec, double Tsacc,double Tsdec);

DMC2210_API void __stdcall d2210_reset_target_position(WORD axis,long dist);

//���ᶨ���˶�
DMC2210_API void __stdcall d2210_t_pmove(WORD axis,long Dist,WORD posi_mode);
DMC2210_API void __stdcall d2210_ex_t_pmove(WORD axis,long Dist,WORD posi_mode);
DMC2210_API void __stdcall d2210_s_pmove(WORD axis,long Dist,WORD posi_mode);
DMC2210_API void __stdcall d2210_ex_s_pmove(WORD axis,long Dist,WORD posi_mode);

//���������˶�
DMC2210_API void __stdcall d2210_s_vmove(WORD axis,WORD dir);
DMC2210_API void __stdcall d2210_t_vmove(WORD axis,WORD dir);

//���Բ岹
DMC2210_API void __stdcall d2210_t_line2(WORD axis1,long Dist1,WORD axis2,long Dist2,WORD posi_mode);
DMC2210_API void __stdcall d2210_t_line3(WORD *axis,long Dist1,long Dist2,long Dist3,WORD posi_mode);
DMC2210_API void __stdcall d2210_t_line4(WORD cardno,long Dist1,long Dist2,long Dist3,long Dist4,WORD posi_mode);

//�����˶�
DMC2210_API void __stdcall d2210_set_handwheel_inmode(WORD axis,WORD inmode,WORD count_dir);
DMC2210_API void __stdcall d2210_handwheel_move(WORD axis,double vh);

//��ԭ��
DMC2210_API void __stdcall d2210_config_home_mode(WORD axis,WORD mode,WORD EZ_count);
DMC2210_API void __stdcall d2210_home_move(WORD axis,WORD home_mode,WORD vel_mode);

//Բ���岹
DMC2210_API void __stdcall d2210_arc_move(WORD *axis,long *target_pos,long *cen_pos, WORD arc_dir);
DMC2210_API void __stdcall d2210_rel_arc_move(WORD *axis,long *rel_pos,long *rel_cen, WORD arc_dir);


//---------------------   ��������������PLD  ----------------------//
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
** ��������: d2210_config_EMG_PIN
** ��������: EMG���ã�d2410���������أ���ͣ�ź���Ч�������ֹͣ������
**           ����������
** �䡡  ��: axis - (0 - 3), enable - 0:��Ч; 1:��Ч
**              emg_logic: 0:����Ч; 1:����Ч
** �� �� ֵ: �� 
*********************************************************************************/
DMC2210_API void __stdcall d2210_config_EMG_PIN(WORD cardno, WORD enable,WORD emg_logic);

//����ͬʱ��ͣ����
/********************************************************************************
** ��������: d2210_set_t_move_all
** ��������: ����ͬ���˶��趨
** �䡡  ��: TotalAxes: ����,  pAxis:���б�, pDist:λ���б�
             posi_mode: 0-���, 1-����
** �� �� ֵ: 1:��ȷ , -1:������
**     
*********************************************************************************/
INT32S __stdcall d2210_set_t_move_all(WORD TotalAxes, WORD *pAxis, long *pDist, WORD posi_mode);

/********************************************************************************
** ��������: d2210_start_move_all
** ��������: ����ͬ���˶�
** �䡡  ��: TotalAxes: ��һ�����
** �� �� ֵ: 1:��ȷ , -1:������
** 
*********************************************************************************/
INT32S __stdcall d2210_start_move_all(WORD FirstAxis);

/********************************************************************************
** ��������: d2210_set_sync_option
** ��������: ����ͬ��ѡ���趨, ע��: ʹ�ú����رմ˹���, ��sync_option1��0.
** �䡡  ��: axis:���
             sync_stop_on: 1:��CSTOP �ź���ʱ,��ֹͣ; 
             cstop_output_on: ���쳣ֹͣʱ��� CSTOP�ź�
             sync_option1: 0:��������, 1: �ȴ�CSTA�ź� ������������ 
             sync_option2: ����
** �� �� ֵ: 1:��ȷ , -1:������
** 
*********************************************************************************/
INT32S __stdcall d2210_set_sync_option(WORD axis, WORD sync_stop_on, WORD cstop_output_on, WORD sync_option1, WORD sync_option2);

/********************************************************************************
** ��������: d2210_set_sync_stop_mode
** ��������: ����ͬ��ֹͣ�ļ��ٷ�ʽ
** �䡡  ��: axis: ���
             stop_mode:  0- ����ֹͣ, 1-����ֹͣ
** �� �� ֵ: 1:��ȷ , -1:������
** 
*********************************************************************************/
INT32S __stdcall d2210_set_sync_stop_mode(WORD axis, WORD stop_mode); 

/********************************************************************************
** ��������: d2210_config_CSTA_PIN
** ��������: ����ͬ�������ź�, ֻ��Ϊ����Ч, ����Ϊ��ƽ���Ǳ����źŴ���,Ĭ��Ϊ��ƽ����
** �䡡  ��: axis: ���
             edge_mode:  0- ��ƽ, 1-����
** �� �� ֵ: 1
*********************************************************************************/
INT32S __stdcall d2210_config_CSTA_PIN(WORD axis, WORD edge_mode);

//��ȡ�汾��  
DMC2210_API  INT32S __stdcall d2210_get_lib_version(long * libVer, long * subLibVer);

//��ȡ����ֹͣ״̬���Ӻ���
DMC2210_API DWORD __stdcall d2210_read_error_int_factor(WORD axis);

#ifdef __cplusplus
}
#endif

#endif 
#ifndef _RECORDER_INT_H_
#define _RECORDER_INT_H_

#include "Trecorder.h"

#define CHECK_NULL_POINTER(e)                                            \
		do {														\
			if (!(e))												\
			{														\
				printf("check (%s) failed.", #e);		   \
				return -1;											\
			}														\
		} while (0)


#define PARTH_A  "/mnt/SDCARD/DCIMA"
#define PARTH_B  "/mnt/SDCARD/DCIMB"
#define SENSOR_NUM 2

#define FILE_NAME_PREFIX  "AW_"
typedef struct {
	unsigned int width;
	unsigned int height;
}R_SIZE;

/*
   0: ���л�����ǰ����ͷ����
   1: ���л�����������ͷ����
   2:  ���л��أ���ʾǰ����ͷ
   3: ���л���, ��ʾ������ͷ
*/
typedef enum tag_PREVIEW_MODE_E{
	PREVIEW_HOST,
	PREVIEW_PIP,
	PREVIEW_
}__preview_mode_e;

typedef enum tag_RECORD_STATE{
	RECORD_UNINIT,
    RECORD_STOP,
	RECORD_START,
	RECORD_HALT,
}__record_state_e;

typedef enum tag_CAMERA_QUALITY{
    CAMERA_QUALITY_100,
    CAMERA_QUALITY_200,
    CAMERA_QUALITY_300,
    CAMERA_QUALITY_500,
    CAMERA_QUALITY_800,
}__camera_quality_e;

typedef enum tag_RECORD_QUALITY{
    RECORD_QUALITY_640_480,
    RECORD_QUALITY_1280_720,
    RECORD_QUALITY_1920_1080,
}__record_quality_e;

typedef enum tag_CYCLE_REC_TIME_E{
    CYCLE_REC_TIME_1_MIM,
    CYCLE_REC_TIME_2_MIM,
    CYCLE_REC_TIME_3_MIM,
    CYCLE_REC_TIME_5_MIM,
    CYCLE_REC_TIME_
}__cycle_rec_time_e;

typedef enum __RECORD_VID_WIN_RATIO_MODE
{
    RECORD_VID_WIN_BESTSHOW = 0x00,        /* ��ͼƬ����ı�����������������ʾ��ͼƬ������ */
    RECORD_VID_WIN_ORIGINAL,               /* ��ͼƬԭʼ��С�ڴ�������ʾ�������������     */
    RECORD_VID_WIN_FULLSCN,                /* �Դ��ڵı�������ͼƬ����������ʾ�����ܻ���� */
    RECORD_VID_WIN_CUTEDGE,                /* �ñ�ģʽ����srcFrame�����ٲõ����ºڱߣ��ñߺ���bestshowģʽ��ʾ         */
    RECORD_VID_WIN_NOTCARE,                /* ������ͼƬ��ʾ�������Ե�ǰ���õı���         */
    RECORD_VID_WIN_ORIG_CUTEDGE_FULLSCN,    /* ��ͼƬ����ı�����������������ʾ��ͼƬ����,ͼƬ�������ֲü���     */
    RECORD_VID_WIN_UNKNOWN
}record_vid_win_ratio_mode_t;

typedef struct tag_DV_CORE{
	//�ڲ���ֵ
	TrecorderHandle*       mTrecorder[SENSOR_NUM];			//����ͷ���
	__record_state_e	   record_sta[SENSOR_NUM];			// ¼���״̬
	R_SIZE				   cam_size[SENSOR_NUM];			//���շֱ���
	R_SIZE                   rec_size[SENSOR_NUM];			//¼��ֱ���
	unsigned int           rec_time_ms[SENSOR_NUM];			//¼������ļ�ʱ��,��λms
	pthread_mutex_t mutex0[SENSOR_NUM];      //������ײ����
	pthread_mutex_t mutex1[SENSOR_NUM];      //����¼����״̬
	//�ⲿ��ֵ
    TdispRect              pip_rect;					// ���л�����
    TdispRect              show_rect;					// ����ʾ����
    __camera_quality_e     cam_quality_mode[SENSOR_NUM];	//��������
	__record_quality_e     rec_quality_mode[SENSOR_NUM];	//¼������
	R_SIZE				   source_size[SENSOR_NUM];			//��ƵԴ�ֱ���
	unsigned int           source_frate[SENSOR_NUM];		//��ƵԴ֡��
	__cycle_rec_time_e     cycle_rec_time[SENSOR_NUM];      //ѭ��¼���ʱ��
	unsigned int           frame_rate[SENSOR_NUM];			//֡��
	unsigned int		   video_bps[SENSOR_NUM];			//����
	unsigned int           mute_en[SENSOR_NUM];		    // 1 ���� 0 ������
	__preview_mode_e       pre_mode[SENSOR_NUM];
	int                    time_water_en[SENSOR_NUM];	// ʱ��ˮӡ����
}__dv_core_t;

typedef struct REC_MEDIA_INFO_T{
	TdispRect              pip_rect;				// ���л�����
    TdispRect              show_rect;					// ����ʾ����
    record_vid_win_ratio_mode_t ratio_mode;					//��ʾģʽ
    __camera_quality_e     cam_quality_mode[SENSOR_NUM];	//��������
	__record_quality_e     rec_quality_mode[SENSOR_NUM];	//¼������
	R_SIZE				   source_size[SENSOR_NUM];			//��ƵԴ�ֱ���
	unsigned int		   source_frate[SENSOR_NUM];		//��ƵԴ֡��
	__cycle_rec_time_e     cycle_rec_time[SENSOR_NUM];      //ѭ��¼���ʱ��
	unsigned int           mute_en[SENSOR_NUM];			// 1 ���� 0 ������
	__preview_mode_e       pre_mode[SENSOR_NUM];
	int                    time_water_en[SENSOR_NUM];	// ʱ��ˮӡ����
}rec_media_info_t;

typedef struct
{
	__cycle_rec_time_e     cycle_rec_time[SENSOR_NUM];      //ѭ��¼���ʱ��
	unsigned int           mute_en[SENSOR_NUM];			// 1 ���� 0 ������
	int                    time_water_en[SENSOR_NUM];	// ʱ��ˮӡ����
}rec_media_part_info_t;

int recorder_init(int index);
int recorder_exit(int index);
int recorder_start_recording(int index);
int recorder_stop_recording(int index);
int recorder_take_picture(int index);
int recorder_mute_en(int index, bool onoff);
int recorder_get_rec_state(int index);
int recorder_get_cur_rectime(int index);
int create_rec_list(void);
int destroy_rec_list(void);
int recorder_init_info(rec_media_info_t *info);
int recorder_exit_info(void);
int recorder_part_info_set(rec_media_part_info_t *info);
int recorder_reserve_size(void);
int recorder_ish_deleted_file(void);
int recorder_preview_en(int index, bool onoff);
int recorder_start_preview(int index);
int recorder_set_preview_mode(int index, __preview_mode_e pre_mode);
int collide_save_file(int index);

#endif

/*
********************************************************************************
*                                    eMOD
*                   the Easy Portable/Player Develop Kits
*                               mod_herb sub-system
*                          (module name, e.g.mpeg4 decoder plug-in) module
*
*          (c) Copyright 2009-2010, Allwinner Microelectronic Co., Ltd.
*                              All Rights Reserved
*
* File   : aenc_sw_lib.h
* Version: V1.0
* By     : Eric_wang
* Date   : 2010-4-26
* Description:
********************************************************************************
*/
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _AENC_SW_LIB_H_
#define _AENC_SW_LIB_H_

#define BS_BUFFER_SIZE       (128*1024)//(1024*1024)
#define PCM_FRAME_SIZE       (32*1024)
#define BS_HEADER_SIZE       (1*1024)

#define OUT_BUFFER_SIZE         (512*1024)
#define OUT_ENCODE_BUFFER_SIZE  (4*1024)    //byte
#define MAXDECODESAMPLE (1024)


// extern __s32 sample_cnt_per_frame;
// extern __s32 CheckIfAudioEncodeSupport(__s32 nAbsType);//nAbsType = __herb_codec_t���ȼ���__sw_codec_type_t

typedef enum __AUDIO_ENC_RESULT
{
    ERR_AUDIO_ENC_ABSEND        = -2,
    ERR_AUDIO_ENC_UNKNOWN       = -1,
    ERR_AUDIO_ENC_NONE          = 0,   //decode successed, no error
    ERR_AUDIO_ENC_PCMUNDERFLOW  = 1,   //pcm data is underflow
    ERR_AUDIO_ENC_OUTFRAME_UNDERFLOW = 2,  //out frame buffer is underflow.

    ERR_AUDIO_ENC_

} __audio_enc_result_t;

//encode input data information
typedef struct __audio_enc_inf_t
{
    int     InSamplerate;   //����fs
    int     InChan;         //����pcm chan 1:mon 2:stereo
    int     bitrate;        //bs
    int     SamplerBits;    //only for 16bits
    int     OutSamplerate;  //���fs,now OutSamplerate must equal InSamplerate
    int     OutChan;        //������� chan
    int     frame_style;    //for aac: 0:add head,1:raw data; for pcm: 2:mpegTs pcm(big endian), other: common pcm(little endian)

}__audio_enc_inf_t;

#define BsBuffLEN 20*1024
typedef struct __PCM_BUF_MANAGER
{
    unsigned char       *pBufStart;         //buffer�׵�ַ
    int                 uBufTotalLen;       //�ܳ���
    unsigned char       *pBufReadPtr;       //���ڶ���ָ��
    int                 uDataLen;           //��Ч���ݳ���
    unsigned char       *pBufWritPtr;       //����д��ָ��
    int                 uFreeBufSize;       //���೤��
	int                 uDataFlowflag;      //�����Ƿ񳬹�Ԥ�����룬1��������0֡��0��û�г�������������
	void				*parent;			// encode use,not lib use;

} __pcm_buf_manager_t;


typedef struct __COM_INTERNAL_PARAMETER
{
    unsigned int        ulNowTimeMS;        //��ǰʱ��ms
    unsigned int        ulPCMgainSet;       //PCM����
    unsigned int        framecount;         //frames

    unsigned int        ulEncCom;           //0: normal enc 1: ff end   5: stop
    unsigned char       BsHeaderBuf[BS_HEADER_SIZE];
    unsigned int        ValidHeaderLen;
	unsigned int        *pEncInfoSet;		// encode lib use;

} __com_internal_prameter_t;


typedef struct __AudioENC_AC320
{
	__pcm_buf_manager_t         *pPcmBufManager;
	__audio_enc_inf_t           *AudioBsEncInf;
	__com_internal_prameter_t   *EncoderCom;
	int                         Encinitedflag;

	int	(*EncInit)(struct __AudioENC_AC320 *p);
	int	(*EncFrame)(struct __AudioENC_AC320 *p,char *OutBuffer,int *OutBuffLen);
	int	(*EncExit)(struct __AudioENC_AC320 *p);

}AudioEnc_AC320;

extern struct __AudioENC_AC320 *EncInit(void);
extern int  EncExit(struct __AudioENC_AC320 *p);

struct __AudioENC_AC320 *AudioMP3ENCEncInit(void);
int  AudioMP3ENCEncExit(struct __AudioENC_AC320 *p);

//���������Ҫ�����ϲ�ģ��ʵ�ֵĺ���
extern int GetPcmDataSize(__pcm_buf_manager_t *pPcmMan);
extern int ReadPcmDataForEnc(void *pBuf, int uGetLen, __pcm_buf_manager_t *pPcmMan);

#endif  /* _AENC_SW_LIB_H_ */

#ifdef __cplusplus
}
#endif

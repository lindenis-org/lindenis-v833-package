#ifndef _ADT_H_
#define _ADT_H_


/* frequency type selector */
typedef enum
{
	/*��Ƶ�� 2K~5K */
	FREQ_TYPE_LOW =0,
	/*��Ƶ, 8K~12K*/
	FREQ_TYPE_MIDDLE,
	/*��Ƶ�� 16K~20K*/
	FREQ_TYPE_HIGH

}freq_type_t;

/*macros of return valule of decoder*/
/* ������� */
#define RET_DEC_ERROR -1
/* ������������ */
#define RET_DEC_NORMAL 0
/* ���뻹δ���������ܻ�ȡ�������� */
#define RET_DEC_NOTREADY 1
/* ������� */
#define RET_DEC_END 2


/* definition of decoder config paramters */
typedef struct
{
	/* ֧�ֵ�����ַ������ȣ��ֽ����� */
	int max_strlen;
	/* ������ */
	int sample_rate;
	/* Ƶ�ʷ�Χѡ�� */
	freq_type_t freq_type;
	/* ÿ�����鴫����ֽ��� */
	int group_symbol_num;
	/* �Ƿ���þ����� */
	int error_correct;
	/* ������ľ������� */
	int error_correct_num;
}config_decoder_t;

/*
	������	����������
	������	decode_config: �����ṹ�壨ָ�룩
	����ֵ��	�����������NULL��ʾ����ʧ��
*/
void* decoder_create(config_decoder_t* decode_config );

/*
	������	��λ������
	������	handle��		���������
	����ֵ��	��

*/
void decoder_reset(void* handle);
/*
	������	��ȡÿ֡����������������
	������	handle��		���������
	����ֵ��	ÿ֡����������������ÿ������Ϊ16bit��

*/
int decoder_getbsize(void* handle);
/*
	������	��������������
	������	handle��		���������
			pcm��		����buffer���豣֤���е�������������decoder_getbsize�ķ���ֵ
	����ֵ��	ͬ���뷵��ֵ�ĺ궨��
*/
int decoder_fedpcm(void* handle, short* pcm);
/*
	������	��ȡ������
	������	handle��	���������
			str��	������buffer
	����ֵ��	ͬ���뷵��ֵ�ĺ궨��
*/
int decoder_getstr(void* handle, unsigned char* str);
/*
	�������ͷŽ��������
	������handle��	���������
	����ֵ����
*/
void decoder_destroy(void* handle);

/* definition of encoder config paramters */
typedef struct
{
	/* ֧�ֵ�����ַ������ȣ��ֽ����� */
	int max_strlen;
	/* ����Ƶ�� */
	int sample_rate;
	/* Ƶ�ʷ�Χѡ�� */
	freq_type_t freq_type;
	/* ÿ�����鴫����ֽ��� */
	int group_symbol_num;
	/* �Ƿ���þ������ */
	int error_correct;
	/* �������ľ����������ֽ�����*/
	int error_correct_num;
}config_encoder_t;

/* macros of return value of encoder */
/* ������������ */
#define		RET_ENC_NORMAL 0
/* ������� */
#define		RET_ENC_END 1
/* ������� */
#define		RET_ENC_ERROR -1

/*
	������	�ͷű��������
	������	handle��		���������
	����ֵ��	��
*/
void encoder_destroy(void* handle);
/*
	������	�������������
	������	config��		�����ṹ�壨ָ�룩
	����ֵ��	�����������ΪNULL��ʾ����ʧ��
*/
void* encoder_create(config_encoder_t* config);
/*
	������	��λ������
	������	handle��		���������
	����ֵ��	��

*/
void encoder_reset(void* handle);
/*
	������	��ȡ֡�����С���ֽڵ�λ���������ⲿ����֡����buffer
	������	handle��		���������
	����ֵ��	֡�����С���ֽڵ�λ��

*/
int encoder_getoutsize(void* handle);
/*
	������	��ȡ֡����
	������	handle��		���������
			outpcm��		֡����buffer���ⲿ���䣩
	����ֵ��	ͬ����������ֵ�ĺ궨��
*/
int encoder_getpcm(void* handle, short* outpcm);
/*
	������	���ô�������ַ������ַ������Կ��ַ�'\0'��β
	������	handle��		���������
			input��		�Կ��ַ���β���ַ���
			����ֵ		ͬ����������ֵ�ĺ궨��
*/
int encoder_setinput(void* handle, unsigned char* input);

#endif

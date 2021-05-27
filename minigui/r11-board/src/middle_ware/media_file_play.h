#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>
#include <ctype.h>
#include <jpegdecode.h>
#include "sunxi_display_v2.h"
#include "mid_list.h"
#include "videoOutPort.h"
#include <tmetadataretriever.h>
#define ASCIILINESZ     (1024)
#define MAX_FILE_NUM    (15)
int mediaFileNum;
typedef enum SHOW_PIC_MODE_T{
	SHOW_PIC_WIN_BESTSHOW = 0x00,		  /* ��ͼƬ����ı�����������������ʾ��ͼƬ������ */
	SHOW_PIC_WIN_ORIGINAL,				/* ��ͼƬԭʼ��С�ڴ�������ʾ�������������	*/
	SHOW_PIC_WIN_FULLSCN,				/* �Դ��ڵı�������ͼƬ����������ʾ�����ܻ���� */
	SHOW_PIC_WIN_CUTEDGE,				/* �ñ�ģʽ����srcFrame�����ٲõ����ºڱߣ��ñߺ���bestshowģʽ��ʾ		  */
	SHOW_PIC_WIN_NOTCARE,				/* ������ͼƬ��ʾ�������Ե�ǰ���õı���			*/
	SHOW_PIC_WIN_ORIG_CUTEDGE_FULLSCN,	 /* ��ͼƬ����ı�����������������ʾ��ͼƬ����,ͼƬ�������ֲü���	  */
	SHOW_PIC_WIN_UNKNOWN
}show_pic_mode_t;

char mediaFile[MAX_FILE_NUM][ASCIILINESZ];
int reorder_media_list(void);
int noreorder_media_list(void);
int create_media_list(void);
int create_media_list_player(void);
//int create_media_list_music(void);
//int create_media_list_picture(void);
int destroy_media_list(void);
int show_current_file(void);
int show_next_file(void);
int show_pre_file(void);
int de_show(void);
media_file_type_t media_get_current_file_type(void);
int media_get_current_file_name(char *name);
int media_get_current_file_path(char *path);
int media_get_next_name_path(char *name, char *path);
int media_get_total_num(void);
int media_get_cur_index(void);
int media_del_cur_file(void);
int media_play_init(disp_rect rect,show_pic_mode_t mode);
int media_play_exit(void);
int getMediaFile(void);

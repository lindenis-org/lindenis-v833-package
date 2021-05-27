#ifndef __CVR_RECORD_WINDOW_H__
#define __CVR_RECORD_WINDOW_H__

#include "CvrInclude.h"
#include "CvrResource.h"
#include "middle_ware.h"

#include <minigui/common.h>
#include <minigui/minigui.h>
#include <minigui/gdi.h>
#include <minigui/window.h>
#include <minigui/control.h>

// statement
typedef enum
{
	RECORD,
	IMAGE,
	PLAYBACK,
	REPLAY,
}SceneType;

typedef enum tag_SENSOR_MODE
{
	FRONT_SENSOR_MODE, //ǰ¼
	BACK_SENSOR_MODE,  //��¼
	FRONT_AND_BACK_SENSOR_MODE,//˫¼
}__sensor_mode_e;

typedef enum tag_REC_VIEW_MODE
{
    HOST_FRONT,  //ǰ����
    HOST_BACK,  //������
    HOST_FRONT_PP_BACK,   //ǰ���Ժ��л�
    HOST_BACK_PP_FRONT,   //������ǰ���л�
}__rec_view_mode_e;

typedef struct
{
	SceneType oldScene;
	SceneType curScene;

	bool bPowerOn;
	bool bRecordListExit;

	HWND carBackHwnd;
	BITMAP carBackBmp;
	int carBackStus;
}AddtionData;

typedef struct
{
	s32                   voice_en;
	s32                    hit_key;
	u32                   hit_time;
	s32               hit_key_time;
	s32                 rec_status;
	__dv_core_t            dv_core;
	__sensor_mode_e    sensor_mode;
	__rec_view_mode_e preview_mode;
	bool bLock;
}RecordData;

typedef struct
{
	s32 bTakePicture;
}PhotoData;

typedef struct
{
	s32 curItem;
	s32 totalItem;
	media_file_type_t fileType;
	char curFileName[64];
	char curFilePath[64];
}ThumbFileInfo;

typedef struct
{
	HWND startHwnd;
	BITMAP startBmp;

	ThumbFileInfo fileInfo;
	disp_rect displaySize;
}PlayBackData;

typedef struct
{
	bool bReplaying;

	HWND pauseHwnd;
	BITMAP pauseBmp;

	HWND pgbHwnd;
	s32 videoTotalTime;
	s32 videoCurTime;
}RePlayData;

typedef struct
{
	HWND ParentHwnd;
	HWND RecordHwnd;
	CvrRectType RecordSize;

	UserDataType usrData;
	AddtionData data;
	RecordData rcData;
	PhotoData ptData;
	PlayBackData pbData;
	RePlayData rpData;

	pthread_t rcdThreadID;
	bool bRcdThreadRun;

}RecordWinDataType;

// interface
RecordWinDataType* GetRecordWinData(void);
HWND GetRecordWinHwnd(void);
HWND RecordWinInit(HWND hParent);
int RecordWinProc(HWND hWnd, int message, WPARAM wParam, LPARAM lParam);

#endif
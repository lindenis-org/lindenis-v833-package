/*
** $Id: listbox_impl.h 8944 2007-12-29 08:29:16Z xwyan $
**
** listbox.h: the head file of ListBox control.
**
** Copyright (C) 2003 ~ 2007 Feynman Software.
** Copyright (C) 1999 ~ 2002, Wei Yongming.
**
** Create date: 1999/8/31
*/

#ifndef __LISTBOX_IMPL_H_
#define __LISTBOX_IMPL_H_

#ifdef  __cplusplus
extern  "C" {
#endif

/******* LBIF is used internal by the listbox *********/
#define LBIF_NORMAL         0x0000L
#define LBIF_SELECTED       0x0001L
#define LBIF_USEBITMAP      0x0002L

#define LBIF_DISABLE        0x0004L
#define LBIF_BOLDSTYLE      0x0008L

#define LBIF_BLANK          0x0000L
#define LBIF_CHECKED        0x0010L
#define LBIF_PARTCHECKED    0x0020L
#define LBIF_SIGNIFICANT    0x0040L
#define LBIF_CHECKMARKMASK  0x00F0L

/*********  *************/
#define LBIF_IMAGE			0x00010000		/*  if use item image*/
#define LBIF_VALUE_STRING	0x00020000		/*	if use value String */
#define LBIF_VALUE_IMAGE	0x00040000		/*	if use value Image */
#define LBIF_VALUE_STRING2	0x00200000		/*	if use value String2 */
#define LBIF_VALUE_IMAGE2	0x00400000		/*	if use value Image2 */
#define LBIF_WITHCHECKBOX	0x02000000


/*
 * first	item image (optional)
 * second	item string (required)
 * third	item value (picture or string)
 * */
typedef struct _LISTBOXITEM
{
    char*   key;                // item sort key

    DWORD   dwFlags;            // item flags

	DWORD	imageFlag;
	unsigned int valueCount;	/* the value's count */
	DWORD	valueFlag[MAX_VALUE_COUNT];

    DWORD   dwImage;            // item image show in the left
	DWORD	dwValueImage[MAX_VALUE_COUNT];	// value image show in the right
	DWORD	dwValueString[MAX_VALUE_COUNT];	// value string show in the right

    DWORD   dwAddData;          // item additional data
    struct  _LISTBOXITEM* next; // next item
} LISTBOXITEM;
typedef LISTBOXITEM* PLISTBOXITEM;



#ifndef _MGRM_THREADS
    #define DEF_LB_BUFFER_LEN       8
#else
    #define DEF_LB_BUFFER_LEN       16
#endif

#define LBF_FOCUS               0x0001

typedef struct tagLISTBOXDATA
{
    DWORD dwFlags;          // listbox flags

    STRCMP str_cmp;         // function to compare two string

    int itemLeft;           // display left of item
    int itemWidth;          // display width of item
    int itemMaxWidth;       // max width of all items

    int itemCount;          // items count
    int itemTop;            // start display item
    int itemVisibles;       // number of visible items

    int itemHilighted;      // current hilighted item
    int itemHeight;         // item height

    int selItem;            // record last selected item when use LBS_MOUSEFOLLOW style
    LISTBOXITEM* head;      // items linked list head

    int buffLen;            // buffer length
    LISTBOXITEM* buffStart; // buffer start
    LISTBOXITEM* buffEnd;   // buffer end
    LISTBOXITEM* freeList;  // free list in buffer
    SBPolicyType sbPolicy;  // scrollbar policy type

    PLOGFONT lst_font;       // logic font for bold display
} LISTBOXDATA;
typedef LISTBOXDATA* PLISTBOXDATA;


#ifdef  __cplusplus
}
#endif

#endif  // __LISTBOX_IMPL_H__

����汾
#define PROGRAM_VERSION			"v0.1"

Ŀ¼�ṹ
./bin                  Ŀ��ִ���ļ�
./obj                  ������ʱ�ļ�
./Tools                ��׿�����������װ�汾4.42����
./radiotap             radiotap�⣬������google radiotap
./wpa_supplicant.conf  wpa_supplicant�������ļ���make��ʱ��Ὣ�俽����Ŀ���

˵��
1)��Ŀǰʹ�õ�Airkiss��δͨ�� AES���ܵģ����������������AES��������޷�����
2)�������豸�ǹ㲥UDP�������ֳɹ�����������������ʾBINGO

��������ͨ�ż��ܲ���
1)��makefile �ļ� LIBS = -lairkiss   ��Ϊ LIBS = -lairkiss_aes
2)��include �ļ����� airkiss.hͷ�ļ�����   #define AIRKISS_ENABLE_CRYPT 1
3)�����±���

��������˵��
1����֧��WPA��WEP��OPEN

���в���
1)��������ͨ������ -h��ȡ

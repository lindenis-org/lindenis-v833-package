2014/5/5 v0.5

�������ܣ�
1. ֧��A33
	1) totddr��ϵͳ�ܴ���
	2) cpuddr��CPU����
	3) gpuddr��GPU����
	4) de_ddr��DE����
	5) ve_ddr��VE����
	6) othddr����������

2014/3/21 v0.4

�������ܣ�
1. ͳ�ƴ�mtop����ǰ��ƽ��ֵ
2. ͳ�Ƶ�ǰģ��������ֵ

��ʾ��ʽ˵��
  --��mtop����ǰ�����ֵ
  |
Max: 1150, Average: 623 --��mtop����ǰ��ƽ��ֵ
Total: 766, Delta max: 198 --��ǰģ��������ֵ
  |
  --��ǰ���ܴ���
cpuddr0 gpuddr0 de_ddr0 vcfddr0 othddr0 cpuddr1 gpuddr1 de_ddr1 vcfddr1 othddr1
     68     198     118       0       0      68     196     118       0       0
   8.88   25.85   15.40    0.00    0.00    8.88   25.59   15.40    0.00    0.00

2014/3/12 v0.3.1

�޸����ܣ�
1. ���ͳ��Latency, Command Number��Clock Cycle Numberʹ�ܿ���

2014/3/12 v0.3

�������ܣ�
1. ������ʾ��ʽ
2. ֧��ͳ��Latency, Command Number��Clock Cycle Number
3. ֧��ͳ��ģ�����ٷֱ�

2014/3/11 v0.2

�������ܣ�
1. ֧����ʾ��mtop�򿪵���ǰ��������
2. ֧����ʾ��ǰʱ�����ڵ��ܴ���

2014/3/8 v0.1

��Ҫ���ܣ�
1. ֧��ͳ��CPU, GPU, DE, VE/CSI/FD, Other master����
2. ��֧�ֵ���ͳ�ƴ���
3. ֧�����������ļ�
4. ֧������ͳ�Ƶ�λ
5. ֧������ͳ��ʱ����

Usage: mtop [-n iter] [-d delay] [-m] [-o FILE] [-h]
    -n NUM   Updates to show before exiting.
    -d NUM   Seconds to wait between update.
    -m unit: MB
    -o FILE  Output to a file.
    -v Display mtop version.
    -h Display this help screen.

#����˵�� luckylau
#�޸�2016-4-14 ���ӷ������˵����ɾ��target_sys��usr.img���֣����Ӵ���������˵��
#�޸�2016-3-23  ��ʼ�汾
#author��henrisk

AW-OTAʹ����֪��
    ����ʵ��Ӧ���д洢���ʴ�С���죬����ӦOTA����Ҳ�᲻ͬ������С��32M��һ��Ϊspinor���Ľ��ʣ���ҪԤ���趨��
    make menuconfig
    Target Images  --->
        *** Image Options ***
            [*] For storage less than 32M, enable this when using ota
    ѡ�и��������rootfs��/usr�ᱻ�ֲ����������usr.squashfs(usr.img)�����extend��������recovery����boot_initramfs�����ø÷������Դ��𵽽�ʡ�洢�ռ�����á�

    �����ڴ��������ʣ����鲻ѡ�и������������Ҫusr.img��extend��������ֻ��Ҫ���recovery������������OTA����ʱ��ʡȥ�ܶ��鷳��

    ������С�������Ǵ���������Ҫ��make֮ǰѡ��Ӧ�ð�misc-package��
    make menuconfig
        Allwinner  --->
            <*> misc-upgrade........................... read and write the misc partition

һ���������壺
    boot���������ں˾���
    rootfs����������ϵͳ���������/lib, /bin, /etc, /sbin�ȷ�/usr���ǹ�������������·����wifi֧�ֻ�����alsa֧�ֻ�����OTA������
    extend��������չϵͳ���������/usr Ӧ�÷�����
    ������������Ϊ��������

    private�������洢SN�ŷ���
    misc������ϵͳ״̬��ˢ��״̬����
    UDISK�������û����ݷ�����/mnt/UDISK��
    overlayfs�������洢overlayfs��������
    �������Ϊ����������

����������Сע�����
    ������С�ڷ���ʹ��sys_partition.fex�ж���
    size���㷨���� 8192/2/1024 = 4M

    a������boot������С��boot������С��Ҫ�����ں����ã���ҪС�ڵ���sys_partition.fex�ж����boot��ǩ�Ķ��壺
    �磺
        [partition]
            name         = boot
            size         = 8192
            downloadfile = "boot.fex"
            user_type    = 0x8000

        boot���������С��Ҫ��menuconfig��Ԥ���趨��
        make menuconfig
            Target Images  --->
                *** Image Options ***
                (4) Boot filesystem partition size (in MB)

    b��rootfs�����Ĵ�С������Ҫͨ��make menuconfigȥ�趨��ֱ�Ӹ��ݾ����С�޸ķ����ļ����ɡ�
        1������һЩС����flash�ķ�������16M��������/bin �´�������߼����򡢰汾���Ƴ������ؾ�����򡢲������������Լ������ļ�����Щ�ļ��ڱ���ʱӦ��install��/bin����/lib�£�
       �����ڹ̼�������󣬲鿴bin/sunxi(sun5i)/��rootfs.img�Ĵ�С�ھ���sys_partition.fex��rootfs�����Ĵ�С����
       \*0*/ $ ll bin/sun5i/rootfs.img
        -rw-r--r-- 1 heweihong heweihong  1835008  4�� 14 16:44 bin/sun5i/rootfs.img

        2�����ڴ�����flash�ķ�������128M���ϣ��������㹻��flash�ռ����ؾ��񣩣�����Ҫ1������ЩOTA����ĳ���ֱ�Ӳ鿴rootfs.img�Ĵ�С�趨�����ļ����ɡ�

    c��extend�����Ĵ�С����Ҫ���Ƕ�����棺
        1������� usr.img�Ĵ�С
        2��make_ota_image��initramfs����Ĵ�С��make_ota_image������˵����
        �磺
        \*0*/ $ ll build_dir/target-arm_cortex-xxxxxxxx/linux-sun5i��linux-sunxi��/
        -rw-r--r--  1 heweihong heweihong   479232  4�� 14 16:44 usr.squashfs
        -rwxr-xr-x  1 heweihong heweihong  5510192  4�� 14 16:44 zImage-initramfs*
        ȡ�������ֵ��������һЩ��������

        �������ֵ����Ϊinitramfs����Ĵ�С
        make menuconfig
            Target Images  --->
                *** Image Options ***
                (8) Boot-Recovery initramfs filesystem partition size (in MB)

    d������������private��misc��ʹ��Ĭ�ϵĴ�С����
    e��ʣ�µĿռ�ȫ���Զ��������UDISK������һ��Ҫ��ȡһ���ռ��UDISK���������ٿ��Ը�ʽ�������أ�һЩOTA���̻�������дһЩ�м��ļ���С����flash�ķ�����ҲҪ��֤��256K~512K�Ŀռ䣩

    �ر�ע�⣺��Щ������С����ͨ��OTAȥ�޸ĵģ����Զ��ڴ�����flash�ķ�����Ӧ������������������ƣ�������adc���㣩������������㹻���������������OTA�������ݵ�����
    ����С����flash�ķ�������Ҫ�����������ǵ�����ط����Ĵ�С��

����misc-upgrade����
1. misc-upgrade �ǻ���С����flash�������»��ַ�������misc������extend����Ϊý����Ƶ�OTA����

2. OTA�����SDK����˵����(SDK��Ŀ¼)
   ����������
   source scripts/setenv.sh

   �������
   make_ota_image (���°汾�����Ѿ��ɹ��������¼�̼��Ļ����Ļ����ϣ����OTA����)
   make_ota_image --force (���±����°汾���룬Ȼ���ٴ��OTA����)

   ע����ִ��make_ota_image֮ǰ��Ҫ����֧��ramdisk��ѡ��xzѹ��cpio
            make menuconfig
                target Images  --->
                    [*] ramdisk  --->
                        --- ramdisk
                            Compression (xz)  --->

3. OTA�����˵����
    \*0*/ $ ll bin/sunxi��sun5i��/ota/
    ?????? 20856
    -rw-rw-r-- 1 heweihong heweihong  5731339  3?? 23 15:48 ramdisk_sys.tar.gz
    -rw-rw-r-- 1 heweihong heweihong 10335244  3?? 23 15:48 target_sys.tar.gz
    -rw-rw-r-- 1 heweihong heweihong  5116895  3?? 23 15:48 usr_sys.tar.gz

    ����tar������OTA��ѹ�������
    ramdisk_sys.tar.gz��ramdisk����Ҫ�����ں˷�����rootfs����ʱʹ�ã���ֹ��д���̵��磬���»�����ש��
    target_sys.tar.gz�� ϵͳ���������ں˷�����rootfs������
    usr_sys.tar.gz��    Ӧ�÷�����������extend������ֻ��Ҫʹ���������
    ----------------------------------------------------------------
    \*0*/ $ ll bin/sunxi/ota/*_sys/
    bin/sunxi/ota/ramdisk_sys/:
    -rw-r--r-- 1 heweihong heweihong 7340032  4�� 16 12:50 boot_initramfs.img

    bin/sunxi/ota/target_sys/:
    -rw-r--r-- 1 heweihong heweihong 3145728  4�� 16 12:49 boot.img
    -rw-r--r-- 1 heweihong heweihong 2883584  4�� 16 12:49 rootfs.img

    bin/sunxi/ota/usr_sys/:
    -rw-r--r-- 1 heweihong heweihong 2752512  4�� 16 12:49 usr.img

    ���ĸ������Ϊ��ѹ����img����

4. С����OTA�������
    ��ѡ������-f -p ��ѡһ
    aw_upgrade_process.sh -f ��������ϵͳ���ں˷�����rootfs������extend������
    aw_upgrade_process.sh -p ����Ӧ�÷�����extend������
    ע�����ڴ���������aw_upgrade_normal.sh���aw_upgrade_process.sh
    ��ѡ����: -l��-d -u, -n

    a�����ڴ�����flash��������ʹ�ñ��ؾ���������������У������������ramdisk_sys.tar.gz��target_sys.tar.gz��usr_sys.tar.gz����
       ����/mnt/UDISK/misc-upgrade�У������ϵ���������Զ���д�����������ڼ���磬��������������Ҳ���Զ������д������Ҫ�������硣
    -l arg����·��������
    �磺aw_upgrade_process.sh -p(-f) -l /mnt/UDISK/misc-upgrade (ע��mntǰ�ĸ�Ŀ¼"/"��ô��ϣ�misc-upgrade��Ҫ��"/")
    ��-l����������-d��-u��-n������Ч��ʹ��ѹ���������

    b������С����flash��������ʹ��-l����������������������󣬻���Ҫ������ص��������س����ȡ���񣨼���5��˵����

    -d arg -u arg��ͬʱʹ�ã�-d ����Ϊ����pingͨ��OTA�������ĵ�ַ��-u ����Ϊ��������ص�ַ
    -n һЩСddr�ķ�������ʣ���ʹ���ڴ���20m���µķ�����������ʹ�����������shell��ֱ���������ز�ѹ����4��img�ļ����������豸���غ���Ҫtar��ѹ�������ڴ�ʹ�á�

    �磺aw_upgrade_process -f -d 192.168.1.140 -u http://192.168.1.140/
    ����shell����ping -d ������ping 192.168.1.140����pingͨ���󣬻�������������ϵͳ��ǰ�����������أ�
        ��-n������
        http://192.168.1.140/ramdisk_sys.tar.gz
        http://192.168.1.140/target_sys.tar.gz
        http://192.168.1.140/usr_sys.tar.gz
        ��-n������
        http://192.168.1.140/boot_initramfs.img
        http://192.168.1.140/boot.img
        http://192.168.1.140/rootfs.img
        http://192.168.1.140/usr.img

    ʹ��-n�����ķ�����Ҫ�����Ϸ������ϵľ����ǣ�boot_initramfs.img, boot.img, rootfs.img, usr.img
    ��ʹ��-n�����ķ�����Ҫ�����Ϸ������ϵľ����ǣ�ramdisk_sys.tar.gz, target_sys.tar.gz, usr_sys.tar.gz

5. �ű��ӿ�˵����
    ����С����flash�ķ�����û�пռ�洢������ؾ���ֻ�����ram�У��ϵ�ͻᶪʧ��
    �����������̶ϵ磬��Ҫ���������������ؾ���
    aw_upgrade_vendor.sh���Ϊ��������ʵ�ֵĹ��ӣ�SDK��ֻ�Ǹ�demo���������޸ġ�

    ʵ�������߼�
    check_network_vendor(){
        return 0 �����ɹ����磺����pingͨOTA�����������
        return 1 ����ʧ��
    }

    ��������Ŀ�꾵�� $1��ramdisk_sys.tar.gz $2��/tmp
    download_image_vendor(){
        # $1 image name  $2 DIR  $@ others
        rm -rf $2/$1
        echo "wget $ADDR/$1"
        wget $ADDR/$1 -P $2
    }

    ��ʼ��д����״̬��
    aw_upgrade_process.sh -p ��������Ӧ�÷�����ģʽ�£�����0��ʼд����  1��д����
    aw_upgrade_process.sh -f ������������ֵ
    upgrade_start_vendor(){
        # $1 mode: upgrade_pre,boot-recovery,upgrade_post
        #return   0 -> start upgrade;  1 -> no upgrade
        #reutrn value only work in nornal mode
        #nornal mode: $NORMAL_MODE
        echo upgrade_start_vendor $1
        return 0
    }

    д�������
    upgrade_finish_vendor(){
        #set version or others
        reboot -f
    }

    -f (-n)����˳��
        check_network_vendor ->
          upgrade_start_vendor ->
            download_image_vendor (ramdisk_sys.tar.gz, -n Ϊ boot_initramfs.img)->
              �ڲ���д����������߼��������Ѿ�ʹ�þ���ռ���ڴ棩 ->
                download_image_vendor(target_sys.tar.gz, -n Ϊ boot.img rootfs.img) ->
                  �ڲ���д����������߼��������Ѿ�ʹ�þ���ռ���ڴ棩 ->
                    download_image_vendor(usr_sys.tar.gz, -n Ϊ usr.img) ->
                      �ڲ���д����������߼��������Ѿ�ʹ�þ���ռ���ڴ棩 ->
                        upgrade_finish_vendor
    -p����˳��
        check_network_vendor ->
          download_image_vendor (usr_sys.tar.gz) ->
            upgrade_start_vendor ->
              ��ⷵ��ֵ����д ->
                upgrade_finish_vendor

6. ���ϵͳ״̬��д
   ��ص���Ϣ�洢��misc������OTA��������������������������д����������

   �� read_misc [command] [status] [version]
   command ��ʾ������ϵͳ״̬��shell�ű�����ʹ�ã�
   status  ����ʹ�ã���ʾ�û��Զ���״̬
   version ����ʹ�ã���ʾ�û��Զ���״̬

   д write_misc [ -c command ] [ -s status ] [ -v version ]
   -c ���������޸ģ�ֻ����aw-upgrade shell�޸�
   -s -v �Զ���ʹ��

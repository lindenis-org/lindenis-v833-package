#/bin/sh
echo 0 > /sys/class/android_usb/android0/enable
echo 1f3a > /sys/class/android_usb/android0/idVendor
echo 1002 > /sys/class/android_usb/android0/idProduct
echo adb > /sys/class/android_usb/android0/functions
echo 1 > /sys/class/android_usb/android0/enable
#Taken from TI yocto BSP Layer Version 05-2014, original name:ti33xx.inc
SOC_FAMILY = "ti33x"
require conf/machine/include/soc-family.inc
DEFAULTTUNE ?= "cortexa8thf-neon"
require conf/machine/include/tune-cortexa8.inc
# List common SoC features
MACHINE_FEATURES = "kernel26 apm usbgadget usbhost vfat ext2 screen alsa ethernet can sgx"

PREFERRED_VERSION_gcc ?= "6.%"
PREFERRED_VERSION_gcc-cross-${TARGET_ARCH} ?= "6.%"
PREFERRED_VERSION_gcc-runtime ?= "6.%"

# Sub-architecture support adapted fom fsl-arm
MACHINE_SOCARCH = "${TUNE_PKGARCH}-ti33x"
PACKAGE_EXTRA_ARCHS_append = " ${MACHINE_SOCARCH}"

# Bootloader
PREFERRED_PROVIDER_virtual/bootloader = "u-boot-i2som"
#PREFERRED_PROVIDER_u-boot = "u-boot-i2som"

UBOOT_ARCH = "arm"
#UBOOT_MACHINE = "i2s_am335x_emmc_defconfig"

UBOOT_ENTRYPOINT = "0x80008000"
UBOOT_LOADADDRESS = "0x80008000"


# Kernel
PREFERRED_PROVIDER_virtual/kernel = "linux-i2som"
KERNEL_IMAGETYPE ?= "zImage"
# Install modules in initramfs and rootfs
#PACKAGE_INSTALL_append = " kernel-modules"
KERNEL_MODULE_AUTOLOAD += " cryptodev"

SERIAL_CONSOLES ?= "115200;ttyO0"
# dont install kernelimage to rootfs
RDEPENDS_kernel-base = ""

# rootfs images
# Use the expected value of the ubifs filesystem's volume name in the kernel
UBI_VOLNAME = "rootfs"
# The biggest NANDs on current modules are 1GB. With current partition layout,
# this sums up to 7943 LEBs available for the ubifs
MKUBIFS_ARGS = "-F -m 2048 -e 126976 -c 2048"
UBINIZE_ARGS = "-m 2048 -p 0x20000 -s 512 -O 2048"

# xserver
PREFERRED_PROVIDER_virtual/xserver ?= "xserver-xorg"
# For built-in LCD, add xf86-input-tslib
XSERVER = "xserver-xorg \
           xf86-input-evdev \
           xf86-input-mouse \
           xf86-video-fbdev \
           xf86-input-keyboard"
# Default to external video, change to smallscreen for built-in LCD
GUI_MACHINE_CLASS = "smallscreen"

# OpenGLES support for AM335x SGX Core
PREFERRED_PROVIDER_virtual/libgles1 ?= "ti-sgx-ddk-um"
PREFERRED_PROVIDER_virtual/libgles2 ?= "ti-sgx-ddk-um"
PREFERRED_PROVIDER_virtual/egl ?= "ti-sgx-ddk-um"

QT_QPA_DEFAULT_PLATFORM ?= "${@bb.utils.contains('MACHINE_FEATURES', 'sgx', 'eglfs', 'linuxfb', d)}"

# default images to build
IMAGE_FSTYPES ?= "tar.gz ubifs ext4 ubi"

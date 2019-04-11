# rootfs images
# Use the expected value of the ubifs filesystem's volume name in the kernel
UBI_VOLNAME = "rootfs"
# The biggest NANDs on current modules are 1GB. With current partition layout,
# this sums up to 7943 LEBs available for the ubifs
MKUBIFS_ARGS = "-F -m 2048 -e 126976 -c 2048"
UBINIZE_ARGS = "-m 2048 -p 0x20000 -s 512 -O 2048"

# mkfs.ubifs parameters for boot.ubifs file (kernel and device tree files)
MKUBIFS_BOOT_ARGS ?= "-m 2048 -e 126976 -c 127"
MKUBIFS_RECOVERY_ARGS ?= "-m 2048 -e 126976 -c 151"

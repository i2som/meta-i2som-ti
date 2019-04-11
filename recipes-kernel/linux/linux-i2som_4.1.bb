include linux-common.inc

DESCRIPTION = "The linux-i2som recipe for i2S-AM335x SoM products."

GIT_URL = "git://${HOME}/i2S-AM335x/i2S-Sitara-Linux"
SRC_URI = "${GIT_URL};branch=${BRANCH}"

PR = "${INC_PR}.0"

# NOTE: Keep version in filename in sync with commit id!
SRCREV = "recipes-kernel/linux/linux-i2som_4.1.bb"
BRANCH = "master"

S = "${WORKDIR}/git"

INTREE_DEFCONFIG = "i2s_am335x_defconfig"

RDEPENDS_kernel-modules_ti33x = "\
    ${@bb.utils.contains('MACHINE_FEATURES', 'suspend', 'amx3-cm3', '', d)} \
    ${@bb.utils.contains('MACHINE_FEATURES', 'sgx', 'ti-sgx-ddk-km', '', d)} \
    cryptodev-module \
"

COMPATIBLE_MACHINE  = "i2sam335x"

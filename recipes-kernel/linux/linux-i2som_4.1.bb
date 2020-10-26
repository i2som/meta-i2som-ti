include linux-common.inc

DESCRIPTION = "The linux-i2som recipe for i2S-AM335x SoM products."

FILESEXTRAPATHS_append := "${THISDIR}/${PN}"

GIT_URL = "git://${HOME}/i2SOM-AM335x/i2SOM-Sitara-Linux"
SRC_URI = "${GIT_URL};branch=${BRANCH}"

SRC_URI_append = " ${@bb.utils.contains('MACHINE_FEATURES', 'suspend', 'file://am335x-cm3.cfg', '', d)} "

PR = "${INC_PR}.0"

# NOTE: Keep version in filename in sync with commit id!
SRCREV = "311f1cf4e8e481c2817a300da63cfd995654c9df"
BRANCH = "master"

S = "${WORKDIR}/git"

INTREE_DEFCONFIG = "i2s_am335x_defconfig"

RDEPENDS_kernel-modules_ti33x = "\
    ${@bb.utils.contains('MACHINE_FEATURES', 'suspend', 'amx3-cm3', '', d)} \
    ${@bb.utils.contains('MACHINE_FEATURES', 'sgx', 'ti-sgx-ddk-km', '', d)} \
    cryptodev-module \
"

#KERNEL_MODULE_AUTOLOAD += "g_ether"
COMPATIBLE_MACHINE  = "i2sam335x"

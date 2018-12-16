include linux-common.inc

DESCRIPTION = "The linux-i2som recipe for i2S-AM335x SoM products."

GIT_URL = "git:///home/blackrose/i2S-AM335x/i2S-Sitara-Linux"
SRC_URI = "${GIT_URL};branch=${BRANCH}"

PR = "${INC_PR}.0"

# NOTE: Keep version in filename in sync with commit id!
SRCREV = "364e07c931ada0fc8137f61d2ed609bbd7962637"
BRANCH = "master"

S = "${WORKDIR}/git"

INTREE_DEFCONFIG = "i2s_am335x_defconfig"

COMPATIBLE_MACHINE  = "i2sam335x"

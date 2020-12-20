require u-boot-common.inc

PROVIDES += "u-boot"
PR = "r1"

BRANCH = "master"

SRCREV = "1a7031e53889f00a13bf9f6c00cd511848088685"

SRC_URI_append_i2x-335b408id512e4 = " \
    file://uEnv.txt \
"

do_deploy_append_i2x-335b408id512e4() {
    cp ${WORKDIR}/uEnv.txt ${DEPLOYDIR}/uEnv.txt
}

COMPATIBLE_MACHINE = "(ti33x|i2sam335x)"

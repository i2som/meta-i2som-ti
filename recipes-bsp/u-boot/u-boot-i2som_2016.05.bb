require u-boot-common.inc

PROVIDES += "u-boot"
PR = "r1"

BRANCH = "master"

SRCREV = "1a7031e53889f00a13bf9f6c00cd511848088685"

SRC_URI_append_i2cam335xbe = " \
    file://uEnv.txt \
"

do_deploy_append_i2cam335xbe() {
    cp ${WORKDIR}/uEnv.txt ${DEPLOYDIR}/uEnv.txt
}

COMPATIBLE_MACHINE = "(i2cam335xbn|i2cam335xbe)"

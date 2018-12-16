# Copyright (C) 2018 i2SOM Team.

DESCRIPTION = "Linux Kernel i2SOM common base"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

inherit kernel
inherit kconfig

INC_PR = "r0"

DEPENDS += "lzop-native lz4-native bc-native"
PATCHTOOL = "git"

#SRCTREECOVEREDTASKS ?= "do_unpack do_fetch"

#KERNEL_IMAGE_BASE_NAME = "${KERNEL_IMAGETYPE}-${PN}-${PKGV}-${PKGR}-${MACHINE}-${DATETIME}"

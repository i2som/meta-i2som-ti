# Copyright (C) 2017 i2SOM Team

FILESEXTRAPATHS_prepend := "${THISDIR}/${BPN}:"

SRC_URI += " \
    file://fw_env.config \
"

# We do not have a platform defconfig in this version of u-boot, so just use the generic
# sandbox defconfig, which is enough to build the Linux user-space tool (fw_printenv)
UBOOT_CONFIG = "sandbox"
UBOOT_CONFIG[sandbox] = "sandbox_defconfig"

do_install_append() {
	install -d ${D}${includedir}/libubootenv
	#install -m 0644 ${S}/tools/env/ubootenv.h ${D}${includedir}/libubootenv/
	install -m 0644 ${WORKDIR}/fw_env.config ${D}${sysconfdir}/
}

pkg_postinst_${PN}() {
	# run the postinst script on first boot
	if [ x"$D" != "x" ]; then
		exit 1
	fi
	CONFIG_FILE="/etc/fw_env.config"
	MMCDEV="$(sed -ne 's,.*root=/dev/mmcblk\([0-9]\)p.*,\1,g;T;p' /proc/cmdline)"
	if [ -n "${MMCDEV}" ]; then
		sed -i -e "s,^/dev/mmcblk[^[:blank:]]\+,/dev/mmcblk${MMCDEV},g" ${CONFIG_FILE}
	fi

	PARTTABLE="/proc/mtd"
	MTDINDEX="$(sed -ne "s/\(^mtd[0-9]\+\):.*\<env\>.*/\1/g;T;p" ${PARTTABLE} 2>/dev/null)"
	if [ -n "${MTDINDEX}" ]; then
		# Initialize variables for fixed offset values
		# (backwards compatible with old U-Boot)
		ENV_OFFSET="${UBOOT_ENV_OFFSET}"
		ENV_REDUND_OFFSET="${UBOOT_ENV_SIZE}"
		ENV_SIZE="${UBOOT_ENV_SIZE}"
		ERASEBLOCK=""
		NBLOCKS=""

		# Substitute stub with configuration and calculated values
		sed -i  -e "s/##MTDINDEX##/${MTDINDEX}/g" \
			-e "s/##ENV_OFFSET##/${ENV_OFFSET}/g" \
			-e "s/##ENV_REDUND_OFFSET##/${ENV_REDUND_OFFSET}/g" \
			-e "s/##ENV_SIZE##/${ENV_SIZE}/g" \
			-e "s/##ERASEBLOCK##/${ERASEBLOCK}/g" \
			-e "s/##NBLOCKS##/${NBLOCKS}/g" \
			${CONFIG_FILE}
	fi
}

COMPATIBLE_MACHINE = "(ti33x|i2sam335x)"

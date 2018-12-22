PACKAGECONFIG = " wayland fbdev egl launch clients"
PACKAGECONFIG[wayland] = "--enable-wayland-compositor,--disable-wayland-compositor"
PACKAGECONFIG[kms] = "--enable-drm-compositor,--disable-drm-compositor,drm udev mtdev"
EXTRA_OECONF_append = " WESTON_NATIVE_BACKEND=wayland-backend.so"

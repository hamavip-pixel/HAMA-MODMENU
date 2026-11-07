
ARCHS = arm64 arm64e
TARGET = iphone:clang:latest:14.0
THEOS_PACKAGE_SCHEME = rootless

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = HAMA_VIP

HAMA_VIP_FILES = main.mm
HAMA_VIP_FRAMEWORKS = UIKit Foundation
HAMA_VIP_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libvui_dmgr_headers
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/inc
LOCAL_HEADER_LIBRARIES := libarpal_headers
LOCAL_VENDOR_MODULE := true

include $(BUILD_HEADER_LIBRARY)

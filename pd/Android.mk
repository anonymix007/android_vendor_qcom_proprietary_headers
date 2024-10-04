LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libpdmapper_headers
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/mapper
LOCAL_VENDOR_MODULE := true

include $(BUILD_HEADER_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := libpdnotifier_headers
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/notifier
LOCAL_VENDOR_MODULE := true

include $(BUILD_HEADER_LIBRARY)

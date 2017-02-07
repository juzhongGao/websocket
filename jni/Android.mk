LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := event2
LOCAL_SRC_FILES := static/libevent2.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE	:= websocket

#LOCAL_LDFLAGS := static/libevent2.a
LOCAL_WHOLE_STATIC_LIBRARIES := event2
LOCAL_LDLIBS	+= -llog -lz 
LOCAL_CPPFLAGS	+= -fexceptions

LOCAL_C_INCLUDES := include

WEB_SOCKET_FILES := websock.c base64.c sha1.c openssl.c frames.c default_callbacks.c api.c sha1.h base64.h utf.c util.c 

LOCAL_SRC_FILES	:= $(WEB_SOCKET_FILES) conv.c main.c

include $(BUILD_EXECUTABLE)

############# install ##############
include $(CLEAR_VARS)

DEST_PATH	:= /data/local/tmp

all:
	adb push $(LOCAL_PATH)\..\libs\x86\websocket $(DEST_PATH)
	adb shell "chmod 777 $(DEST_PATH)/websocket"
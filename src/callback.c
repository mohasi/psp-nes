#include "callback.h"
#include <pspkernel.h>

static int exitRequest = 0;

int isRunning() {
	return !exitRequest;
}

int exitCallback(int arg1, int arg2, void* common){
	exitRequest = 1;
	return 0;
}

int callbackThread(SceSize args, void* argp) {
	int cbId = sceKernelCreateCallback("Exit Callback", exitCallback, NULL);
	sceKernelRegisterExitCallback(cbId);
	sceKernelSleepThreadCB();
	return 0;
}

void setupExitCallback() {
	int threadId = sceKernelCreateThread("Callback Update Thread", callbackThread, 0x11, 0xFA0, THREAD_ATTR_USER, 0);
	if (threadId >= 0) {
		sceKernelStartThread(threadId, 0, 0);
	}
}

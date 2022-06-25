#include "../common/callback.h"
#include <pspctrl.h>
#include <pspdisplay.h>
#include <pspkernel.h>

PSP_MODULE_INFO("PSP NES", PSP_MODULE_USER, 1, 0);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

SceCtrlData ctrlData;
int main() {
  setupExitCallback();
  pspDebugScreenInit();

  unsigned int counter = 0;
  while (isRunning()) {
    sceCtrlPeekBufferPositive(&ctrlData, 1);
    if (ctrlData.Buttons & PSP_CTRL_CROSS) {
      pspDebugScreenPrintf("%d\n", counter++);
    }

    sceDisplayWaitVblankStart();
  }

  sceKernelExitGame();
  return 0;
}
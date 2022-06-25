#include "../common/callback.h"
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>

PSP_MODULE_INFO("Example", PSP_MODULE_USER, 1, 0);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

int main() {
  setupExitCallback();
  pspDebugScreenInit();
  
  sceCtrlSetSamplingCycle(0);
  sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

  SceCtrlData ctrlData;
  while (isRunning()) {
    pspDebugScreenSetXY(0, 0);
    pspDebugScreenPrintf("Analog X = %d ", ctrlData.Lx);
    pspDebugScreenPrintf("Analog Y = %d \n", ctrlData.Ly);
    sceCtrlPeekBufferPositive(&ctrlData, 1);

    // buttons
    if (ctrlData.Buttons & PSP_CTRL_UP)
      pspDebugScreenPrintf("Up");
    else if (ctrlData.Buttons & PSP_CTRL_CROSS)
      pspDebugScreenPrintf("Cross");

    sceDisplayWaitVblankStart();
  }
  
  sceKernelExitGame();
  return 0;
}

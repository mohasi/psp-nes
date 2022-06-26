#include "callback.h"
#include "nes.h"
#include <pspdisplay.h>
#include <pspkernel.h>

PSP_MODULE_INFO("PSP NES", PSP_MODULE_USER, 1, 0);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

int main() {
  setupExitCallback();

  emuStart("test.rom");

  for (int i = 0; i < 10; i++) {
    emuExecuteStep();
    emuPrintStatus();
  }

  while (isRunning()) {
    sceDisplayWaitVblankStart();
  }

  sceKernelExitGame();
  return 0;
}
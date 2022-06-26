#include "nes.h"

static Cpu cpu = {
    .pc = 0xC004,
    .sp = 0xFD,
    .a = 0,
    .x = 0,
    .y = 0,
    .cycles = 8};

static Flags flags = {
    .interrupt = true};

bool emuLoadRom(char *romPath) {
  // open
  FILE *file = fopen(romPath, "rb");
  if (file == NULL) {
    return false;
  }

  // get file size
  fseek(file, 0, SEEK_END);
  long fileSizeBytes = ftell(file);
  fseek(file, 0, SEEK_SET);

  // allocate space
  int *buffer = malloc(fileSizeBytes);
  if (buffer == NULL) {
    return false;
  }

  // read
  fread(buffer, sizeof(char), fileSizeBytes, file);
  fclose(file);

  // put in rom
  return true;
}

void emuStart(char *romPath) {
  pspDebugScreenInit();
  emuLoadRom(romPath);
}

void emuExecuteStep() {
}

void emuPrintStatus() {
  pspDebugScreenPrintf("%X SP:%X A:%X X:%X Y:%X NVBDIZC:0000%d00 CYC:%d\n", cpu.pc, cpu.sp, cpu.a, cpu.x, cpu.y,
                       flags.interrupt, cpu.cycles);
}
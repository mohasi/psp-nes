#include <pspdebug.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  u16 pc;
  u8 sp, a, x, y;
  u32 cycles;
} Cpu;

typedef struct {
  bool carry, zero, interrupt, overflow, negative;
} Flags;

void emuStart(char *romPath);
void emuExecuteStep();
void emuPrintStatus();
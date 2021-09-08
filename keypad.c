#include "keypad.h"

void kpInit(Keypad* obj)
{
  int nr = sizeof(obj->rows) / sizeof(ioline_t),
      nc = sizeof(obj->cols) / sizeof(ioline_t);

  for(int i = 0; i < nr; i++)
    palSetLineMode(obj->rows[i], PAL_MODE_OUTPUT_PUSHPULL);

  for(int j = 0; j < nc; j++)
      palSetLineMode(obj->cols[j], PAL_MODE_INPUT_PULLDOWN);
}

void kpEnableRow(Keypad* obj, uint8_t k)
{
  int nr = sizeof(obj->rows) / sizeof(ioline_t);

  if(k >= nr)
    return;

  for(int i = 0; i < nr; i++)
    palWriteLine(obj->rows[i], i == k);
}

uint8_t kpRead(Keypad* obj)
{
  int nr = sizeof(obj->rows) / sizeof(ioline_t),
      nc = sizeof(obj->cols) / sizeof(ioline_t);

  for(int i = 0; i < nr; i++)
  {
    kpEnableRow(i);

    for(int j = 0; j < nc; j++)
      if(palReadLine(obj->cols[j]))
        return obj->chars[i][j];
  }

  return KEYPAD_NOCHAR;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint32_t String_To_Integer(char* pBuffer)
{
  /*
  each character of the string is converted to
  an integer and multiplied by the appropriate power
  of 10. e.g.

  '932':
  '9' - '0' = 9
  '3' - '0' = 3
  '2' - '0' = 2

  9 x 10^2 + 3 x 10^1 + 2 x 10^0 = 932.
  */
  uint32_t integer = 0;
  uint8_t bufferLength = strlen(pBuffer);
  uint32_t j = 1;
  for (uint8_t i = 0; i < bufferLength; i++)
  {
    integer += ((pBuffer[bufferLength - i - 1] - '0') * j);
    j *= 10;
  }
  return integer;
}

int main()
{
    printf("%d\n",String_To_Integer("751"));
    return 0;
}

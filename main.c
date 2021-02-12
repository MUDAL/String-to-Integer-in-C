#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
Function to convert a string to an integer
*/

uint32_t Power_Of_10(uint32_t n)
{
    if (n == 0)
    {
        return 1;
    }
    return 10 * Power_Of_10(n - 1);
}

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
  for (uint8_t i = 0; i < bufferLength; i++)
  {
    integer += ( (pBuffer[i] - '0') * Power_Of_10(bufferLength - i - 1) );
  }
  return integer;
}

int main()
{
    printf("%d\n",String_To_Integer("9543"));
    return 0;
}

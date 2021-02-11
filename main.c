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
    printf("%d\n",String_To_Integer("112987"));
    return 0;
}

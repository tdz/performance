
#include <limits.h>
#include "lut.h"

int
lut(unsigned char i)
{
  switch (i) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 11:
    case 12:
    case 13:
    case 14:
    case 21:
    case 22:
    case 23:
    case 24:
    case 31:
    case 32:
    case 33:
    case 34:
    case 41:
    case 42:
    case 43:
    case 44:
    case 51:
    case 52:
    case 53:
    case 54:
    case 61:
    case 62:
    case 63:
    case 64:
    case 71:
    case 72:
    case 73:
    case 74:
    case 81:
    case 82:
    case 83:
    case 84:
    case 91:
    case 92:
    case 93:
    case 94:
    case 101:
    case 102:
    case 103:
    case 104:
    case 111:
    case 112:
    case 113:
    case 114:
    case 121:
    case 122:
    case 123:
    case 124:
    case 131:
    case 132:
    case 133:
    case 134:
    case 141:
    case 142:
    case 143:
    case 144:
    case 151:
    case 152:
    case 153:
    case 154:
    case 161:
    case 162:
    case 163:
    case 164:
    case 171:
    case 172:
    case 173:
    case 174:
    case 181:
    case 182:
    case 183:
    case 184:
    case 191:
    case 192:
    case 193:
    case 194:
    case 201:
    case 202:
    case 203:
    case 204:
      return 1;
    default:
      break;
  }

  return 0;
}

#include "CType.h"

cb CO_DEBUG(CO_MODULE mod, const cc* szFormat, ...)
{
  cc sBuffer[MAX_PRINT_NUM];
  cc name[16];
  va_list ap;
  if (mod != MOD_USELESS)
  {
    switch (mod)
    {
    case MOD_LIB:
      snprintf((char*)name, sizeof(name), "%s", "[CO_LIB]");
      break;
    case MOD_APP:
      snprintf((char*)name, sizeof(name), "%s", "[CO_APP]");
      break;
    case MOD_USELESS:
      break;
    default:
      break;
    }

    co_va_start(ap, szFormat);
    vsnprintf((char*)sBuffer, (MAX_PRINT_NUM), (char*)szFormat, ap);
    co_va_end(ap);

    printf("\033[32m%s %s\033[0m", name, sBuffer);
    return true;
  }
  else
  {
    co_va_start(ap, szFormat);
    vsnprintf((char*)sBuffer, (MAX_PRINT_NUM), (char*)szFormat, ap);
    co_va_end(ap);

    printf("%s", sBuffer);
    return ctrue;
  }
  return cfalse;
}

cv* BaseString::co_memcpy(cv* dst, const cv* src, csize size)
{
  return memcpy(dst, src, size);
}
ci BaseString::co_atoi(cc* nptr)
{
  return atoi(nptr);
}
cv* BaseString::co_memset(cv* s, ci ch, cui n)
{
  return memset(s, ch, n);
}
ci BaseString::mp_memcmp(cv* buf1, cv* buf2, cui count)
{
  return memcmp(buf1, buf2, count);
}

cv* BaseString::mp_memmove(cv* dest, cv* src, cui count)
{
  return memmove(dest, src, count);
}

cc* BaseString::mp_strcpy(cc* dest, cc* src)
{
  return strcpy(dest, src);
}

cc* BaseString::mp_strncpy(cc* dest, cc* src, cui count)
{
  return strncpy(dest, src, count);
}

ci BaseString::mp_strncmp(const cc* s1, const cc* s2, ci count)
{
  return strncmp(s1, s2, count);
}

ci BaseString::mp_strcmp(const cc* s1, const cc* s2)
{
  return strcmp(s1, s2);
}

cv BaseString::mp_strcat(cc* to, cc* from)
{
  strcat(to, from);
}

cc* BaseString::mp_strstr(const cc* s1, const cc* s2)
{
  return (cc*)strstr(s1, s2);
}
cc* BaseString::mp_strtok(cc* s, cc* delim)
{
  return strtok(s, delim);
}

ci BaseString::mp_abs(ci j)
{
  if (j >= 0) return j;
  else  return -j;
}

csize BaseString::mp_strlen(cc* s)
{
  return strlen(s);
}
ci BaseString::co_sprintf(cc* str, cc* format, ...)
{
  co_va_list arg;
  int rv;
  co_va_start(arg, format);
  rv = vsnprintf(str, 128, format, arg);
  co_va_end(arg);
  return rv;

  return 1;

}
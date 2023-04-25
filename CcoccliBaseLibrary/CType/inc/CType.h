#pragma once

#define _CO_GLOBAL_DEFINED_
#ifdef  _CO_GLOBAL_DEFINED_
#include <iostream>
#include <string>
#include <cstdarg>
#include <stdlib.h>

#define MAX_PRINT_NUM          512

#define ctrue                  true
#define cfalse                 false
/*
 * short
 */
typedef short                  cs;
typedef unsigned short         cus;
typedef signed short           css;
/*
 * int
 */
typedef int                    ci;
typedef unsigned int           cui;
typedef signed int             csi;
/*
 * short int
 */
typedef short int              cshi;
typedef unsigned short int     cusi;
typedef signed short int       cssi;
/*
 * long int
 */
typedef long int               cli;
typedef unsigned long int      culi;
typedef signed long int        csli;
/*
 * long
 */
typedef long                   cl;
typedef unsigned long          cul;
typedef signed long            csl;
/*
 * long long
 */
typedef long long              cll;
typedef unsigned long long     cull;
typedef signed long long       csll;
/*
 * char
 */
typedef char                   cc;
typedef unsigned char  	  		 cuc;
typedef signed   char       	 csc;
/*
 * void
 */
typedef void                	 cv;
/*
 * double
 */
typedef double 	               cd;
typedef long double 	         cld;
/*
 * float
 */
typedef float                  cf;
/*
 * bool
 */
typedef bool                   cb;

typedef size_t                 csize;

typedef char*                   co_va_list;
#define _CO_AUPBND              (sizeof (ci) - 1)
#define _co_bnd(X, bnd)         (((sizeof (X)) + (bnd)) & (~(bnd)))
#define co_va_start(ap, A) (cv) ((ap) = (co_va_list)(((cuc *) &(A)) + (_co_bnd (A,_CO_AUPBND))))
#define co_va_end(ap)           (cv) 0

typedef enum
{
  MOD_USELESS,
  MOD_LIB,
  MOD_APP,
} CO_MODULE;

cb CO_DEBUG(CO_MODULE mod, const cc* szFormat, ...);

#define LIBDEBUGOPEN
#ifdef  LIBDEBUGOPEN
#define LIB_DEBUG(fmt, args, ...) (CO_DEBUG(MOD_LIB, fmt, ## args))
#else
#define LIB_DEBUG(fmt, args, ...) (CO_DEBUG(MOD_USELESS, ""))
#endif

#define APPDEBUGOPEN
#ifdef  APPDEBUGOPEN
#define APP_DEBUG(fmt, args, ...) (CO_DEBUG(MOD_APP, fmt, ## args))
#else
#define APP_DEBUG(fmt, args, ...) (CO_DEBUG(MOD_USELESS, ""))
#endif

/*
 * \brief singly linked list
 */
#ifdef  DLL_PROJECT
#define  NORMAL_IM_EXPORT __declspec(dllexport)
#else
#define NORMAL_IM_EXPORT __declspec(dllimport)
#endif //DLL_PROJECT

class NORMAL_IM_EXPORT BaseString
{
public:
  /*
   * \brief Copy no more than count bytes from src to dest. Stop copying if the character ch is encountered. 
   * \param[in] dst  --> Pointer to the destination.
   * \param[in] src  --> Pointer to the source.
   * \param[in] size --> Number of characters.
   * \return If the character c is copied, _memccpy returns a pointer to the char in dest that immediately follows the character. If c is not copied, it returns NULL.
   */
  static cv* co_memcpy(cv* dst, const cv* src, csize size);
  /*
   * \brief Converts a string to integer data
   */
  static ci co_atoi(cc* nptr);
  /*
   * \brief Initializes an array of characters to a value
   */
  static cv* co_memset(cv* s, ci ch, cui n);

  static ci mp_memcmp(cv* buf1, cv* buf2, cui count);

  static cv* mp_memmove(cv* dest, cv* src, cui count);

  static cc* mp_strcpy(cc* dest, cc* src);

  static cc* mp_strncpy(cc* dest, cc* src, cui count);

  static ci mp_strncmp(const cc* s1, const cc* s2, ci count);

  static ci mp_strcmp(const cc* s1, const cc* s2);

  static cv mp_strcat(cc* to, cc* from);

  static cc* mp_strstr(const cc* s1, const cc* s2);
      
  static cc* mp_strtok(cc* s, cc* delim);
      
  static ci mp_abs(ci j);
      
  static csize mp_strlen(cc* s);

  static ci co_sprintf(cc* str, cc* format, ...);
};
#endif //_CO_GLOBAL_DEFINED_
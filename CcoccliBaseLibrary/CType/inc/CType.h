#pragma once

#define _CO_GLOBAL_DEFINED_
#ifdef  _CO_GLOBAL_DEFINED_
#include <iostream>
#include <string>
#include <cstdarg>

#define MAX_PRINT_NUM          512
#define MOD_NAME_LEN           32
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
template <typename T>
class LinkNode
{
public:
  T data;
  LinkNode<T>* next;
public:
  LinkNode<T>() {}
};

template <typename T>
class NORMAL_IM_EXPORT LinkList
{
public:
  LinkList();
  LinkList(const LinkList<T>& linklist);
  ~LinkList();
public:
  /*
   * \brief init linked list
   * \param[in] null
   * \return the linked list
   */
  LinkList* Init_linklist();
  /*
   * \brief Insert input based on location
   * \param[in] pos --> location
   * \param[in] vaule --> what value do you need to insert
   * \return void
   */
  cv Insert_linklist(ci pos, T vaule);
  /*
   * \brief return the first node
   * \param[in] null
   * \return the first node
   */
  LinkNode<T>* first_node();
  /*
   * \brief Delete data based on location
   * \param[in] pos --> location
   * \return void
   */
  cv remove_by_pos(ci pos);
  /*
   * \brief Delete linked list
   * \param[in] null
   * \return void
   */
  cv Free_linklist();
  /*
   * \brief find position based on the value
   * \param[in] value --> the value
   * \return the position
   */
  ci find_linklist(T vaule);
public:
  ci size;
  LinkNode<T>* Head;
  LinkList* list;
};
#endif //_CO_GLOBAL_DEFINED_
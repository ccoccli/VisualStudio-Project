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

    va_start(ap, szFormat);
    vsnprintf((char*)sBuffer, (MAX_PRINT_NUM), (char*)szFormat, ap);
    va_end(ap);

    printf("%s %s", name, sBuffer);
    return true;
  }
  else
  {
    va_start(ap, szFormat);
    vsnprintf((char*)sBuffer, (MAX_PRINT_NUM), (char*)szFormat, ap);
    va_end(ap);

    printf("%s", sBuffer);
    return true;
  }
  return false;
}

template<class T>
LinkList<T>::LinkList()
{

}
template<class T>
LinkList<T>::~LinkList()
{

}
template <class T>
LinkList<T>::LinkList(const LinkList<T>& linklist)
{
  if (this->list != NULL)
  {
    this->Free_linklist();
  }
  LinkList<T> newlist = new LinkList<T>(this->size);

  this->list = newlist;

  memcpy(this->list, linklist, sizeof(linklist));

  this->size = linklist.size;
  this->Head = linklist.Head;

  return *this;
}
template<class T>
LinkList<T>* LinkList<T>::Init_linklist()
{
  LinkList* list = new LinkList;

  list->size = 0;

  LinkNode<T>* head = new LinkNode<T>;
  list->Head = head;
  list->Head->next = NULL;
  this->list = list;

  return list;
}
template<class T>
void LinkList<T>::Insert_linklist(ci pos, T vaule)
{
  if (pos < 0 || pos > this->size)
  {
    pos = this->list->size;
  }
  LinkNode<T>* node = new LinkNode<T>;
  node->data = vaule;
  node->next = NULL;

  LinkNode<T>* pCurrent = this->list->Head;
  for (ci i = 0; i < pos; i++) {
    pCurrent = pCurrent->next;
  }

  node->next = pCurrent->next;
  pCurrent->next = node;
  this->size += 1;
}
template<class T>
cv LinkList<T>::remove_by_pos(ci pos)
{
  if (pos < 0 || pos >= this->size)
    return;

  LinkNode<T>* pcurrent = this->list->Head;

  for (ci i = 0; i < pos; i++)
    pcurrent = pcurrent->next;

  LinkNode<T>* delnode = pcurrent->next;
  pcurrent->next = delnode->next;
  delete delnode;
  this->size -= 1;
}
template<class T>
ci LinkList<T>::find_linklist(T vaule) {
  ci pos = -1;
  LinkNode<T>* pcurrent = this->list->Head->next;
  for (ci i = 0; i < this->size; i++)
  {
    if (pcurrent->data == vaule)
    {
      pos = i;
      break;
    }
    pcurrent = pcurrent->next;
  }
  return pos;
}
template<class T>
LinkNode<T>* LinkList<T>::first_node()
{
  return this->list->Head->next;
}
template<class T>
cv LinkList<T>::Free_linklist()
{
  LinkNode<T>* pcurrent = this->list->Head;
  while (pcurrent != NULL)
  {
    LinkNode<T>* pnext = pcurrent->next;
    delete pcurrent;
    pcurrent = pnext;
  }
  delete this->list;
  this->list = nullptr;
  this->size = 0;
}
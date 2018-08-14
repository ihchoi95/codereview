// Copyright 2018 <Author>

#include "typing_machine.h"
#define MAX_ITEM 100

TypingMachine::TypingMachine() {
  home = cursor = new Node(' ');
  count = 0;
  return;
}

void TypingMachine::HomeKey() {
  cursor = home;
  return;
}

void TypingMachine::EndKey() {
  while (cursor->GetNextNode())
  {
    cursor = cursor->GetNextNode();
  }
  return;
}

void TypingMachine::LeftKey() {
  if (cursor->GetPreviousNode())
  {
    cursor = cursor->GetPreviousNode();
  }

  return;
}

void TypingMachine::RightKey() {
  if (cursor->GetNextNode())
  {
    cursor = cursor->GetNextNode();
  }

  return;
}

bool TypingMachine::TypeKey(char key) {
  if ((key < 32) || (key > 126))
  {
    return false;
  }

  if (count >= MAX_ITEM)
  {
    return false;
  }

  cursor = cursor->InsertNextNode(key);
  count++;

  return true;
}

bool TypingMachine::EraseKey() {
  bool result = false;

  if (cursor->GetPreviousNode() == nullptr)
  {
    return false;
  }
  cursor = cursor->GetPreviousNode();
  result = cursor->EraseNextNode();

  if (result)
  {
    count--;
  }

  return result;
}

std::string TypingMachine::Print(char separator) {
  Node *ptr = home->GetNextNode();
  std::string str = "";

  if (home == cursor)
  {
    if (separator)
    {
      str += separator;
    }
  }

  if (!ptr)
  {
    return str;
  }

  while (ptr)
  {
    str += ptr->GetData();

    if (cursor == ptr)
    {
      if (separator)
      {
        str += separator;
      }
    }
    ptr = ptr->GetNextNode();
  }
  return str;
}

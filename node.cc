// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
  prev = next = nullptr;
  value = data;
  return;
}

char Node::GetData() {  
  return value;
}

Node* Node::GetPreviousNode() {
  return this->prev;
}

Node* Node::GetNextNode() {
  return this->next;
}

Node* Node::InsertPreviousNode(char data) {
  Node* newNode = new Node(data);
  Node* oldPrevNode = this->prev;

  if (oldPrevNode)	{
    oldPrevNode->next = newNode;
  }
  newNode->prev = oldPrevNode;
  newNode->next = this;
  this->prev = newNode;

  return newNode;
}

Node* Node::InsertNextNode(char data) {
  Node* newNode = new Node(data);
  Node* oldNextNode = this->next;

  this->next = newNode;
  newNode->prev = this;
  newNode->next = oldNextNode;
  if (oldNextNode)	{
    oldNextNode->prev = newNode;
  }

  return newNode;
}

bool Node::ErasePreviousNode() {
  Node* deleteNode = this->prev;
  Node* newPrevNode = nullptr;

  if (deleteNode == nullptr)
  {
    return false;
  }

  newPrevNode = deleteNode->prev;
  this->prev = newPrevNode;
  if (newPrevNode != nullptr)	{
    newPrevNode->next = this;
  }
	
  delete deleteNode;
  return true;
}

bool Node::EraseNextNode() {
  Node* deleteNode = this->next;
  Node* newNextNode = nullptr;

  if (deleteNode == nullptr)	{
    return false;
  }
  newNextNode = deleteNode->next;

  this->next = newNextNode;
  if (newNextNode != nullptr)	{
    newNextNode->prev = this;
  }
	
  delete deleteNode;
  return true;
}

//** @brief File yang digunakan untuk menyimpan struktur data yang dipakai ** /
#include <string>

struct Pasien {
  std::string nama;
  int status;
};

std::string printStatus(Pasien p) {
  switch (p.status) {
  case 1:
    return "Gawat Darurat";
  case 2:
    return "Darurat Tidak Gawat";
  case 3:
    return "Tidak Darurat Tidak Gawat";
  default:
    return NULL;
  }
}

struct Node {
  Pasien data;
  Node *next;
};
typedef Node *pNode;

pNode createNode(Pasien data) {
  pNode newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;
  return newNode;
}

namespace stack {

typedef pNode Stack;

} // namespace stack

namespace queue {

struct Queue {
  pNode head;
  pNode tail;
};

Queue newQueue() {
  Queue q;
  q.head = nullptr;
  q.tail = nullptr;
  return q;
}

bool isEmpty(Queue q) { return q.head == nullptr && q.tail == nullptr; }

Pasien front(Queue q) { return q.head->data; }

void push(Queue q, pNode newNode) {
  if (isEmpty(q)) {
    q.head = newNode;
    q.tail = newNode;
  } else {
    pNode pRev = nullptr;
    pNode pHelp = q.head;
    while (newNode->data.status <= pHelp->data.status) {
      if (pHelp->next == nullptr)
        break;
      pRev = pHelp;
      pHelp = pHelp->next;
    }

    if (pHelp == q.head && newNode->data.status > pHelp->data.status) {
      newNode->next = pHelp;
      q.head = newNode;
    } else if (pHelp == q.tail && newNode->data.status < pHelp->data.status) {
      pHelp->next = newNode;
      q.tail = newNode;
    } else {
      pRev->next = newNode;
      newNode->next = pHelp;
    }
  }
}

pNode pop(Queue q) {
  pNode target;
  if (isEmpty(q)) {
    target = nullptr;
  } else if (q.head->next == nullptr) {
    target = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  } else {
    target = q.head;
    q.head = q.head->next;
    target->next = nullptr;
  }
  return target;
}

pNode findByNama(Queue q, std::string sNama) {
  pNode pHelp = q.head;
  while (pHelp->next != nullptr) {
    if (pHelp->data.nama == sNama) {
      return pHelp;
    }
  }

  return nullptr;
}

int checkIndex(Queue q, pNode target) {
  int index = 0;
  pNode pHelp = q.head;
  while (pHelp->next != nullptr) {
    index++;
    if (pHelp == target) {
      return index;
    }
  }

  return -1;
}

} // namespace queue
#pragma once
#include <string>

struct Pasien
{
    std::string nama;
    int status;
};

std::string printStatus(Pasien p)
{
    switch (p.status)
    {
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

struct Node
{
    Pasien data;
    Node *next;
    Node *prev;
};
typedef Node *pNode;

pNode createNode(Pasien data)
{
    pNode newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}
#ifndef ZPHONEBOOK_H
#define ZPHONEBOOK_H

#include <LinkedList.h>
#include <stdint.h>

#define ZPHONEBOOK_PREFIX "/phonebook"

struct PBEntry
{
    unsigned long number;
    char address[50];
    char modifiers[15];
    char notes[128];
};

class ZPhonebook
{
private:
    LinkedList<unsigned long> toc;

public:
    static bool checkEntry(char *cmd);

    ZPhonebook();
    virtual ~ZPhonebook();

    inline int size() { return toc.size(); }
    int indexOf(unsigned long number);

    void begin();

	bool get(int index, PBEntry *pbe);
    bool put(PBEntry *pbe);
    bool put(unsigned long number, const char *address, const char *modifiers, const char *notes);
    void remove(int index);
};

#endif
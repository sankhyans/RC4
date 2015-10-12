//-------------------------------------------------------
//       RC4 Attacks
//-------------------------------------------------------

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <array>

typedef std::vector <std::pair <unsigned int, unsigned int> > vecPair;
typedef std::vector <std::vector <unsigned int> > vecVecPair;
typedef std::vector <unsigned int> vec;
const int maxKey = 18;
const int N = 160;
const int C = 90;
using namespace std;

//------------------------------------------------------------
// Structure for storing the most probable keys for attacks
//------------------------------------------------------------

struct keyStorage {
    unsigned int val1;
    unsigned int val2;
    unsigned int val3;
    unsigned int val4;
    unsigned int val5;
};

//------------------------------------------------------------
// Structures for comparing and sorting
//------------------------------------------------------------

struct sort_pred {

    bool operator()(const std::pair<int, int> &left,
            const std::pair<int, int> &right) {
        return left.second > right.second;
    }
};


#define IMP_ATTACKS	10	// Implemented Attacks

void InitKey();
void updateKeyProb(int, int, unsigned int);
void addIVs(unsigned int, unsigned int, unsigned int, unsigned int);
int modV(int, int);

void invokeAttacks();

//Invoke Implemented Attacks
void FMSAttack(int, vec, vecPair &);
void Korek1stAttack(int, vec, vecPair&);
void Korek2ndAttack(int, vec, vecPair&);
void Korek3rdAttack(int, vec, vecPair&);
void Korek4thAttack(int, vec, vecPair&);
void Korek5thAttack(int, vec, vecPair&);
void Korek6thAttack(int, vec, vecPair&);
void Korek7thAttack(int, vec, vecPair&);
void Korek8thAttack(int, vec, vecPair&);
void Korek9thAttack(int, vec, vecPair&);
void collectiveAttack(int, vec, vecPair&);
void selectiveAttack(int, vec, vecPair&);

void printVec(vecPair);

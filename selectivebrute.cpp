#include "attack.h"
#include "selectivebrute.h"
#include <list>

extern "C" vecVecPair keyOutPair;
extern "C" unsigned int L, K[];
extern "C" struct keyStorage FMSKeys[maxKey], korek1Keys[maxKey],
korek2Keys[maxKey], korek3Keys[maxKey], korek4Keys[maxKey], korek5Keys[maxKey],
korek6Keys[maxKey], korek7Keys[maxKey], korek8Keys[maxKey], korek9Keys[maxKey];

//-------------------------------------
// KSA
//-------------------------------------

unsigned int ksa(unsigned int key[]) {
    int i;
    int j;
    unsigned int Slocal[N];

    for (i = 0; i < N; i++)
        Slocal[i] = i;

    j = 0;

    for (i = 0; i < N; i++) {
        int temp;
        j = (j + Slocal[i] + key [ i % L ]);
        j = modV(j, N);
        temp = Slocal[j];
        Slocal[j] = Slocal[i];
        Slocal[i] = temp;
    }
    int temp = Slocal[1] + Slocal[Slocal[1]];
    temp = modV(temp, N);
    unsigned int out = (unsigned short) Slocal[temp];
    return out;
}


//-------------------------------------
// Verify the key is correct
//-------------------------------------

bool verifyKey(unsigned int key[]) {
    vecVecPair::iterator outerItr;
    vec curTempVec;
    int counter = 0;
    int noOfValues = 0;
    for (outerItr = keyOutPair.begin(); outerItr != keyOutPair.end(); ++outerItr) {
        noOfValues++;
        curTempVec = *outerItr;
        key[0] = curTempVec[0];
        key[1] = curTempVec[1];
        key[2] = curTempVec[2];

        unsigned int out = ksa(key);
        if (out == curTempVec[3]) {
            counter++;
        }
        if (noOfValues == 20) {
            break;
        }
    }
    if (counter == 20) {
        return true;
    }
    return false;
}


//------------------------------------------------------------------
// Exhaustive search to find the last 3 bytes of the key
// Assumption : First L-3 bytes of the key are correct
//------------------------------------------------------------------

void lastThreeBytes() {
    cout << "\n\nTrying to find the last 3 key bytes of the key: ";
    
    //Storing the first IV to check the KSA
    vecVecPair::iterator outerItr = keyOutPair.begin();
    vec curTempVec = *outerItr;

    unsigned int currentK[L];
    for (int i = 3; i < L; i++) {
        currentK[i] = K[i];
    }

    bool check = verifyKey(currentK);
    if (check == true) {
        cout << "\n\n\nFinal Key: ";
        for (int i = 3; i < L; i++) {
            cout << currentK[i] << ", ";
        }
        cout << "\n";
        exit(5);
    }

    currentK[0] = curTempVec[0];
    currentK[1] = curTempVec[1];
    currentK[2] = curTempVec[2];
    unsigned int d = curTempVec[3];
    for (int i = 3; i < L-3; i++) {
            cout << currentK[i] << ", ";
        }
    //(L-3)+3 key byte
    for (int i = 0; i < C; i++) {
        currentK[L - 3] = i;

        //(L-3)+2 key byte
        for (int j = 0; j < C; j++) {
            currentK[L - 2] = j;

            //(L-3)+1 key byte
            for (int k = 0; k < C; k++) {
                currentK[L - 1] = k;

                // unsigned int currentK = [a, b, c ];
                unsigned int temp = ksa(currentK);
                if (d == temp) {
                    bool check = verifyKey(currentK);
                    if (check == true) {
                        cout << "\n\n\nFinal Key is: ";
                        for (int i = 3; i < L; i++) {
                            cout << currentK[i] << ", ";
                        }
                        cout << "\n";
                        exit(5);
                    } else {
                        currentK[0] = curTempVec[0];
                        currentK[1] = curTempVec[1];
                        currentK[2] = curTempVec[2];
                    }
                }
            }
        }
    }
}


//------------------------------------------------------------------
// Exhaustive search to find the last 4 bytes of the key
// Assumption : Remaining bytes of the key are correct
//------------------------------------------------------------------

void lastFourBytes() {
    cout << "\n\nTrying to find the last 4 key bytes.\n\n";

    //Storing the first IV to check the KSA
    vecVecPair::iterator outerItr = keyOutPair.begin();
    vec curTempVec = *outerItr;

    unsigned int currentK[L];
    for (int i = 3; i < L; i++) {
        currentK[i] = K[i];
    }

    bool check = verifyKey(currentK);
    if (check == true) {
        cout << "\n\n\nFinal Key: ";
        for (int i = 3; i < L; i++) {
            cout << currentK[i] << ", ";
        }
        cout << "\n";
        exit(5);
    }

    currentK[0] = curTempVec[0];
    currentK[1] = curTempVec[1];
    currentK[2] = curTempVec[2];
    unsigned int d = curTempVec[3];

    //(L-3)+4 key byte
    for (int i = 0; i < C; i++) {
        currentK[L - 4] = i;

        //(L-3)+3 key byte
        for (int j = 0; j < C; j++) {
            currentK[L - 3] = j;

            //(L-3)+2 key byte
            for (int k = 0; k < C; k++) {
                currentK[L - 2] = k;

                //(L-3)+1 key byte
                for (int l = 0; l < C; l++) {
                    currentK[L - 1] = l;

                    // unsigned int currentK = [a, b, c ];
                    unsigned int temp = ksa(currentK);
                    if (d == temp) {
                        bool check = verifyKey(currentK);
                        if (check == true) {
                            cout << "\n\n\nFinal Key is: ";
                            for (int i = 3; i < L; i++) {
                                cout << currentK[i] << ", ";
                            }
                            cout << "\n";
                            exit(5);
                        } else {
                            currentK[0] = curTempVec[0];
                            currentK[1] = curTempVec[1];
                            currentK[2] = curTempVec[2];
                        }
                    }
                }
            }
        }
    }
}

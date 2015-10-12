
#include "attack.h"
#include "selectivebrute.h"

extern "C" unsigned int K[N];
extern "C" struct keyStorage FMSKeys[maxKey], korek1Keys[maxKey],
korek2Keys[maxKey], korek3Keys[maxKey], korek4Keys[maxKey], korek5Keys[maxKey],
korek6Keys[maxKey], korek7Keys[maxKey], korek8Keys[maxKey], korek9Keys[maxKey],
collKeys[maxKey], selKeys[maxKey];
extern "C" vecVecPair keyOutPair;
extern "C" unsigned int L;


//-------------------------------------
// Update Key Values
//-------------------------------------

void updateBackTrackKey(int index, vecPair &keyProb) {
    if (keyProb.size() != 0) {
        std::sort(keyProb.begin(), keyProb.end(), sort_pred());
        vecPair::iterator it = keyProb.begin();
        K[index + 3] = (int) (it->first);
    }
}

// -----------------------------------------------------------------------
// Backtracking to find the most possible key K3 
// K[3] = val2..val5
// -----------------------------------------------------------------------

void backTrackK3() {
    int tempk3[5];
    //FMS
    tempk3[0] = FMSKeys[0].val2;
    tempk3[1] = FMSKeys[0].val3;
    tempk3[2] = FMSKeys[0].val4;
    tempk3[3] = FMSKeys[0].val5;
    for (int i = 0; i < 4; i++) {
        if (tempk3[i] >= 90)
            break;
        K[3] = tempk3[i];
        cout << "FMS: " << i << " K3: " << K[3] << "\n";

        for (int k = 1; k < L - 6; k++) {
            vecPair keyProb;
            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                FMSAttack(k, keyOutPair[j], keyProb);
            }
            updateBackTrackKey(k, keyProb);
            cout << "key: " << k << "\n";
            printVec(keyProb);
        }
        lastFourBytes();
    }

    //Korek1
    tempk3[0] = korek1Keys[0].val2;
    tempk3[1] = korek1Keys[0].val3;
    tempk3[2] = korek1Keys[0].val4;
    tempk3[3] = korek1Keys[0].val5;

    for (int i = 0; i < 4; i++) {
        if (tempk3[i] >= 90)
            break;
        K[3] = tempk3[i];
        cout << "KOrek1: " << i << " K3: " << K[3] << "\n";

        for (int k = 1; k < L - 6; k++) {
            vecPair keyProb;
            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                Korek1stAttack(k, keyOutPair[j], keyProb);
            }
            updateBackTrackKey(k, keyProb);
            cout << "key: " << k << "\n";
            printVec(keyProb);
        }
        lastFourBytes();
    }

    //Korek4
    tempk3[0] = korek4Keys[0].val2;
    tempk3[1] = korek4Keys[0].val3;
    tempk3[2] = korek4Keys[0].val4;
    tempk3[3] = korek4Keys[0].val5;

    for (int i = 0; i < 4; i++) {
        if (tempk3[i] >= 90)
            break;
        K[3] = tempk3[i];
        cout << "KOrek4: " << i << " K3: " << K[3] << "\n";

        for (int k = 1; k < L - 6; k++) {
            vecPair keyProb;
            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                Korek4thAttack(k, keyOutPair[j], keyProb);
            }
            updateBackTrackKey(k, keyProb);
            cout << "key: " << k << "\n";
            printVec(keyProb);
        }
        lastFourBytes();
    }

    //Korek5
    tempk3[0] = korek5Keys[0].val2;
    tempk3[1] = korek5Keys[0].val3;
    tempk3[2] = korek5Keys[0].val4;
    tempk3[3] = korek5Keys[0].val5;

    for (int i = 0; i < 4; i++) {
        if (tempk3[i] >= 90)
            break;
        K[3] = tempk3[i];
        cout << "Korek5: " << i << " K3: " << K[3] << "\n";

        for (int k = 1; k < L - 6; k++) {
            vecPair keyProb;
            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                Korek5thAttack(k, keyOutPair[j], keyProb);
            }
            updateBackTrackKey(k, keyProb);
            cout << "key: " << k << "\n";
            printVec(keyProb);
        }
        lastFourBytes();
    }

    //Korek8
    tempk3[0] = korek8Keys[0].val2;
    tempk3[1] = korek8Keys[0].val3;
    tempk3[2] = korek8Keys[0].val4;
    tempk3[3] = korek8Keys[0].val5;

    for (int i = 0; i < 4; i++) {
        if (tempk3[i] >= 90)
            break;
        K[3] = tempk3[i];
        cout << "Korek8: " << i << " K3: " << K[3] << "\n";

        for (int k = 1; k < L - 6; k++) {
            vecPair keyProb;
            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                Korek8thAttack(k, keyOutPair[j], keyProb);
            }
            updateBackTrackKey(k, keyProb);
            cout << "key: " << k << "\n";
            printVec(keyProb);
        }
        lastFourBytes();
    }
    
    // Collective 
    tempk3[0] = collKeys[0].val2;
    tempk3[1] = collKeys[0].val3;
    tempk3[2] = collKeys[0].val4;
    tempk3[3] = collKeys[0].val5;
    tempk3[4] = collKeys[0].val1;

    for (int i = 0; i < 5; i++) {
        if (tempk3[i] >= 90)
            break;
        K[3] = tempk3[i];
        cout << "Col: " << i << " K3: " << K[3] << "\n";

        for (int k = 1; k < L - 6; k++) {
            vecPair keyProb;
            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                collectiveAttack(k, keyOutPair[j], keyProb);
            }
            updateBackTrackKey(k, keyProb);
            cout << "key: " << k << "\n";
            printVec(keyProb);
        }
        lastFourBytes();
    }
    
    tempk3[0] = selKeys[0].val2;
    tempk3[1] = selKeys[0].val3;
    tempk3[2] = selKeys[0].val4;
    tempk3[3] = selKeys[0].val5;
    tempk3[4] = selKeys[0].val1;

    for (int i = 0; i < 5; i++) {
        if (tempk3[i] >= 90)
            break;
        K[3] = tempk3[i];
        cout << "Col: " << i << " K3: " << K[3] << "\n";

        for (int k = 1; k < L - 6; k++) {
            vecPair keyProb;
            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                selectiveAttack(k, keyOutPair[j], keyProb);
            }
            updateBackTrackKey(k, keyProb);
            cout << "key: " << k << "\n";
            printVec(keyProb);
        }
        lastFourBytes();
    }
}


// -----------------------------------------------------------------------
// Backtracking 
// K[3] = val1..val5
// K[4] = val1..val5
// -----------------------------------------------------------------------

void backTrackK3K4() {
    int tempk3[5], tempk4[5];

    //FMS
    tempk3[0] = FMSKeys[0].val1;
    tempk3[1] = FMSKeys[0].val2;
    tempk3[2] = FMSKeys[0].val3;
    tempk3[3] = FMSKeys[0].val4;
    tempk3[4] = FMSKeys[0].val5;

    tempk4[0] = FMSKeys[1].val1;
    tempk4[1] = FMSKeys[1].val2;
    tempk4[2] = FMSKeys[1].val3;
    tempk4[3] = FMSKeys[1].val4;
    tempk4[4] = FMSKeys[1].val5;

    for (int l = 0; l < 5; l++) {
        if (tempk3[l] >= 90)
            break;
        K[3] = tempk3[l];
        for (int i = 0; i < 5; i++) {
            if (tempk4[i] >= 90)
                break;
            K[4] = tempk4[i];
            cout << "FMS: " << l << "," << i << " K3K4 " << K[3] << ", " << K[4] << "\n";

            for (int k = 2; k < L - 6; k++) {
                vecPair keyProb;
                for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                    FMSAttack(k, keyOutPair[j], keyProb);
                }
                updateBackTrackKey(k, keyProb);
                cout << "key: " << k << "\n";
                printVec(keyProb);
            }
            lastThreeBytes();
        }
    }

    //Korek1
    tempk3[0] = korek1Keys[0].val1;
    tempk3[1] = korek1Keys[0].val2;
    tempk3[2] = korek1Keys[0].val3;
    tempk3[3] = korek1Keys[0].val4;
    tempk3[4] = korek1Keys[0].val5;

    tempk4[0] = korek1Keys[1].val1;
    tempk4[1] = korek1Keys[1].val2;
    tempk4[2] = korek1Keys[1].val3;
    tempk4[3] = korek1Keys[1].val4;
    tempk4[4] = korek1Keys[1].val5;

    for (int l = 0; l < 5; l++) {
        if (tempk3[l] >= 90)
            break;
        K[3] = tempk3[l];
        for (int i = 0; i < 5; i++) {
            if (tempk4[i] >= 90)
                break;
            K[4] = tempk3[i];
            cout << "KOrek1: " << l << "," << i << " K3K4: " << K[3] << ", " << K[4] << "\n";

            for (int k = 2; k < L - 6; k++) {
                vecPair keyProb;
                for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                    Korek1stAttack(k, keyOutPair[j], keyProb);
                }
                updateBackTrackKey(k, keyProb);
                cout << "key: " << k << "\n";
                printVec(keyProb);
            }
            lastThreeBytes();
        }
    }

    //Korek4
    tempk3[0] = korek4Keys[0].val1;
    tempk3[1] = korek4Keys[0].val2;
    tempk3[2] = korek4Keys[0].val3;
    tempk3[3] = korek4Keys[0].val4;
    tempk3[4] = korek4Keys[0].val5;

    tempk4[0] = korek4Keys[1].val1;
    tempk4[1] = korek4Keys[1].val2;
    tempk4[2] = korek4Keys[1].val3;
    tempk4[3] = korek4Keys[1].val4;
    tempk4[4] = korek4Keys[1].val5;

    for (int l = 0; l < 5; l++) {
        if (tempk3[l] >= 90)
            break;
        K[3] = tempk3[l];
        for (int i = 0; i < 5; i++) {
            if (tempk4[i] >= 90)
                break;
            K[4] = tempk3[i];
            cout << "KOrek4: " << l << "," << i << " K3K4: " << K[3] << ", " << K[4] << "\n";

            for (int k = 2; k < L - 6; k++) {
                vecPair keyProb;
                for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                    Korek4thAttack(k, keyOutPair[j], keyProb);
                }
                updateBackTrackKey(k, keyProb);
                cout << "key: " << k << "\n";
                printVec(keyProb);
            }
            lastThreeBytes();
        }
    }

    //Korek5
    tempk3[0] = korek5Keys[0].val1;
    tempk3[1] = korek5Keys[0].val2;
    tempk3[2] = korek5Keys[0].val3;
    tempk3[3] = korek5Keys[0].val4;
    tempk3[4] = korek5Keys[0].val5;

    tempk4[0] = korek5Keys[1].val1;
    tempk4[1] = korek5Keys[1].val2;
    tempk4[2] = korek5Keys[1].val3;
    tempk4[3] = korek5Keys[1].val4;
    tempk4[4] = korek5Keys[1].val5;

    for (int l = 0; l < 5; l++) {
        if (tempk3[l] >= 90)
            break;
        K[3] = tempk3[l];
        for (int i = 0; i < 5; i++) {
            if (tempk4[i] >= 90)
                break;
            K[4] = tempk3[i];
            cout << "KOrek5: " << l << "," << i << " K3K4: " << K[3] << ", " << K[4] << "\n";

            for (int k = 2; k < L - 6; k++) {
                vecPair keyProb;
                for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                    Korek5thAttack(k, keyOutPair[j], keyProb);
                }
                updateBackTrackKey(k, keyProb);
                cout << "key: " << k << "\n";
                printVec(keyProb);
            }
            lastThreeBytes();
        }
    }

    //Korek8
    tempk3[0] = korek8Keys[0].val1;
    tempk3[1] = korek8Keys[0].val2;
    tempk3[2] = korek8Keys[0].val3;
    tempk3[3] = korek8Keys[0].val4;
    tempk3[4] = korek8Keys[0].val5;

    tempk4[0] = korek8Keys[1].val1;
    tempk4[1] = korek8Keys[1].val2;
    tempk4[2] = korek8Keys[1].val3;
    tempk4[3] = korek8Keys[1].val4;
    tempk4[4] = korek8Keys[1].val5;

    for (int l = 0; l < 5; l++) {
        if (tempk3[l] >= 90)
            break;
        K[3] = tempk3[l];
        for (int i = 0; i < 5; i++) {
            if (tempk4[i] >= 90)
                break;
            K[4] = tempk3[i];
            cout << "KOrek8: " << l << "," << i << " K3K4: " << K[3] << ", " << K[4] << "\n";

            for (int k = 2; k < L - 6; k++) {
                vecPair keyProb;
                for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                    Korek8thAttack(k, keyOutPair[j], keyProb);
                }
                updateBackTrackKey(k, keyProb);
                cout << "key: " << k << "\n";
                printVec(keyProb);
            }
            lastThreeBytes();
        }
    }
    
    //Collective
    tempk3[0] = collKeys[0].val1;
    tempk3[1] = collKeys[0].val2;
    tempk3[2] = collKeys[0].val3;
    tempk3[3] = collKeys[0].val4;
    tempk3[4] = collKeys[0].val5;

    tempk4[0] = collKeys[1].val1;
    tempk4[1] = collKeys[1].val2;
    tempk4[2] = collKeys[1].val3;
    tempk4[3] = collKeys[1].val4;
    tempk4[4] = collKeys[1].val5;

    for (int l = 0; l < 5; l++) {
        if (tempk3[l] >= 90)
            break;
        K[3] = tempk3[l];
        for (int i = 0; i < 5; i++) {
            if (tempk4[i] >= 90)
                break;
            K[4] = tempk4[i];
            cout << "collective: " << l << "," << i << " K3K4 " << K[3] << ", " << K[4] << "\n";

            for (int k = 2; k < L - 6; k++) {
                vecPair keyProb;
                for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                    collectiveAttack(k, keyOutPair[j], keyProb);
                }
                updateBackTrackKey(k, keyProb);
                cout << "key: " << k << "\n";
                printVec(keyProb);
            }
            lastThreeBytes();
        }
    }
    
    //Selective Attack
    tempk3[0] = selKeys[0].val1;
    tempk3[1] = selKeys[0].val2;
    tempk3[2] = selKeys[0].val3;
    tempk3[3] = selKeys[0].val4;
    tempk3[4] = selKeys[0].val5;

    tempk4[0] = selKeys[1].val1;
    tempk4[1] = selKeys[1].val2;
    tempk4[2] = selKeys[1].val3;
    tempk4[3] = selKeys[1].val4;
    tempk4[4] = selKeys[1].val5;

    for (int l = 0; l < 5; l++) {
        if (tempk3[l] >= 90)
            break;
        K[3] = tempk3[l];
        for (int i = 0; i < 5; i++) {
            if (tempk4[i] >= 90)
                break;
            K[4] = tempk4[i];
            cout << "selective: " << l << "," << i << " K3K4 " << K[3] << ", " << K[4] << "\n";

            for (int k = 2; k < L - 6; k++) {
                vecPair keyProb;
                for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                    selectiveAttack(k, keyOutPair[j], keyProb);
                }
                updateBackTrackKey(k, keyProb);
                cout << "key: " << k << "\n";
                printVec(keyProb);
            }
            lastThreeBytes();
        }
    }


}


// -----------------------------------------------------------------------
// Backtracking 
// K[3] = val1..avl5
// K[4] = val1..val5
// K[5] = val1..val5
// -----------------------------------------------------------------------

void backTrackK3K4K5() {
    int tempk3[5], tempk4[5], tempk5[5];

    //FMS
    tempk3[0] = FMSKeys[0].val1;
    tempk3[1] = FMSKeys[0].val2;
    tempk3[2] = FMSKeys[0].val3;
    tempk3[3] = FMSKeys[0].val4;
    tempk3[4] = FMSKeys[0].val5;

    tempk4[0] = FMSKeys[1].val1;
    tempk4[1] = FMSKeys[1].val2;
    tempk4[2] = FMSKeys[1].val3;
    tempk4[3] = FMSKeys[1].val4;
    tempk4[4] = FMSKeys[1].val5;

    tempk5[0] = FMSKeys[2].val1;
    tempk5[1] = FMSKeys[2].val2;
    tempk5[2] = FMSKeys[2].val3;
    tempk5[3] = FMSKeys[2].val4;
    tempk5[4] = FMSKeys[2].val5;

    for (int a = 0; a < 5; a++) {
        if (tempk3[a] >= 90)
            break;
        K[3] = tempk3[a];
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                cout << "FMS : " << a << "," << b << "," << c << " K3K4K5: " << K[3] << ", " << K[4] << ", " << K[5] << "\n";

                for (int k = 3; k < L - 6; k++) {
                    vecPair keyProb;
                    for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                        FMSAttack(k, keyOutPair[j], keyProb);
                    }
                    updateBackTrackKey(k, keyProb);
                    cout << "key: " << k << "\n";
                    printVec(keyProb);
                }
                lastThreeBytes();
            }
        }
    }

    //Korek1
    tempk3[0] = korek1Keys[0].val1;
    tempk3[1] = korek1Keys[0].val2;
    tempk3[2] = korek1Keys[0].val3;
    tempk3[3] = korek1Keys[0].val4;
    tempk3[4] = korek1Keys[0].val5;

    tempk4[0] = korek1Keys[1].val1;
    tempk4[1] = korek1Keys[1].val2;
    tempk4[2] = korek1Keys[1].val3;
    tempk4[3] = korek1Keys[1].val4;
    tempk4[4] = korek1Keys[1].val5;

    tempk5[0] = korek1Keys[2].val1;
    tempk5[1] = korek1Keys[2].val2;
    tempk5[2] = korek1Keys[2].val3;
    tempk5[3] = korek1Keys[2].val4;
    tempk5[4] = korek1Keys[2].val5;

    for (int a = 0; a < 5; a++) {
        if (tempk3[a] >= 90)
            break;
        K[3] = tempk3[a];
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                cout << "Korek 1 : " << a << "," << b << "," << c << " K3K4K5: " << K[3] << ", " << K[4] << ", " << K[5] << "\n";

                for (int k = 3; k < L - 6; k++) {
                    vecPair keyProb;
                    for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                        Korek1stAttack(k, keyOutPair[j], keyProb);
                    }
                    updateBackTrackKey(k, keyProb);
                    cout << "key: " << k << "\n";
                    printVec(keyProb);
                }
                lastThreeBytes();
            }
        }
    }

    //Korek4
    tempk3[0] = korek4Keys[0].val1;
    tempk3[1] = korek4Keys[0].val2;
    tempk3[2] = korek4Keys[0].val3;
    tempk3[3] = korek4Keys[0].val4;
    tempk3[4] = korek4Keys[0].val5;

    tempk4[0] = korek4Keys[1].val1;
    tempk4[1] = korek4Keys[1].val2;
    tempk4[2] = korek4Keys[1].val3;
    tempk4[3] = korek4Keys[1].val4;
    tempk4[4] = korek4Keys[1].val5;

    tempk5[0] = korek4Keys[2].val1;
    tempk5[1] = korek4Keys[2].val2;
    tempk5[2] = korek4Keys[2].val3;
    tempk5[3] = korek4Keys[2].val4;
    tempk5[4] = korek4Keys[2].val5;

    for (int a = 0; a < 5; a++) {
        if (tempk3[a] >= 90)
            break;
        K[3] = tempk3[a];
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                cout << "Korek 4 : " << a << "," << b << "," << c << " K3K4K5: " << K[3] << ", " << K[4] << ", " << K[5] << "\n";

                for (int k = 3; k < L - 6; k++) {
                    vecPair keyProb;
                    for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                        Korek4thAttack(k, keyOutPair[j], keyProb);
                    }
                    updateBackTrackKey(k, keyProb);
                    cout << "key: " << k << "\n";
                    printVec(keyProb);
                }
                lastThreeBytes();
            }
        }
    }

    //Korek5
    tempk3[0] = korek5Keys[0].val1;
    tempk3[1] = korek5Keys[0].val2;
    tempk3[2] = korek5Keys[0].val3;
    tempk3[3] = korek5Keys[0].val4;
    tempk3[4] = korek5Keys[0].val5;

    tempk4[0] = korek5Keys[1].val1;
    tempk4[1] = korek5Keys[1].val2;
    tempk4[2] = korek5Keys[1].val3;
    tempk4[3] = korek5Keys[1].val4;
    tempk4[4] = korek5Keys[1].val5;

    tempk5[0] = korek5Keys[2].val1;
    tempk5[1] = korek5Keys[2].val2;
    tempk5[2] = korek5Keys[2].val3;
    tempk5[3] = korek5Keys[2].val4;
    tempk5[4] = korek5Keys[2].val5;

    for (int a = 0; a < 5; a++) {
        if (tempk3[a] >= 90)
            break;
        K[3] = tempk3[a];
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                cout << "Korek 5 : " << a << "," << b << "," << c << " K3K4K5: " << K[3] << ", " << K[4] << ", " << K[5] << "\n";

                for (int k = 3; k < L - 6; k++) {
                    vecPair keyProb;
                    for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                        Korek5thAttack(k, keyOutPair[j], keyProb);
                    }
                    updateBackTrackKey(k, keyProb);
                    cout << "key: " << k << "\n";
                    printVec(keyProb);
                }
                lastThreeBytes();
            }
        }
    }

    //Korek8
    tempk3[0] = korek8Keys[0].val1;
    tempk3[1] = korek8Keys[0].val2;
    tempk3[2] = korek8Keys[0].val3;
    tempk3[3] = korek8Keys[0].val4;
    tempk3[4] = korek8Keys[0].val5;

    tempk4[0] = korek8Keys[1].val1;
    tempk4[1] = korek8Keys[1].val2;
    tempk4[2] = korek8Keys[1].val3;
    tempk4[3] = korek8Keys[1].val4;
    tempk4[4] = korek8Keys[1].val5;

    tempk5[0] = korek8Keys[2].val1;
    tempk5[1] = korek8Keys[2].val2;
    tempk5[2] = korek8Keys[2].val3;
    tempk5[3] = korek8Keys[2].val4;
    tempk5[4] = korek8Keys[2].val5;

    for (int a = 0; a < 5; a++) {
        if (tempk3[a] >= 90)
            break;
        K[3] = tempk3[a];
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                cout << "Korek 8 : " << a << "," << b << "," << c << " K3K4K5: " << K[3] << ", " << K[4] << ", " << K[5] << "\n";

                for (int k = 3; k < L - 6; k++) {
                    vecPair keyProb;
                    for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                        Korek8thAttack(k, keyOutPair[j], keyProb);
                    }
                    updateBackTrackKey(k, keyProb);
                    cout << "key: " << k << "\n";
                    printVec(keyProb);
                }
                lastThreeBytes();
            }
        }
    }
    
    //Collective
    tempk3[0] = collKeys[0].val1;
    tempk3[1] = collKeys[0].val2;
    tempk3[2] = collKeys[0].val3;
    tempk3[3] = collKeys[0].val4;
    tempk3[4] = collKeys[0].val5;

    tempk4[0] = collKeys[1].val1;
    tempk4[1] = collKeys[1].val2;
    tempk4[2] = collKeys[1].val3;
    tempk4[3] = collKeys[1].val4;
    tempk4[4] = collKeys[1].val5;

    tempk5[0] = collKeys[2].val1;
    tempk5[1] = collKeys[2].val2;
    tempk5[2] = collKeys[2].val3;
    tempk5[3] = collKeys[2].val4;
    tempk5[4] = collKeys[2].val5;

    for (int a = 0; a < 5; a++) {
        if (tempk3[a] >= 90)
            break;
        K[3] = tempk3[a];
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                cout << "Collective : " << a << "," << b << "," << c << " K3K4K5: " << K[3] << ", " << K[4] << ", " << K[5] << "\n";

                for (int k = 3; k < L - 6; k++) {
                    vecPair keyProb;
                    for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                        collectiveAttack(k, keyOutPair[j], keyProb);
                    }
                    updateBackTrackKey(k, keyProb);
                    cout << "key: " << k << "\n";
                    printVec(keyProb);
                }
                lastThreeBytes();
            }
        }
    }
    
    //Selective Attack
    tempk3[0] = selKeys[0].val1;
    tempk3[1] = selKeys[0].val2;
    tempk3[2] = selKeys[0].val3;
    tempk3[3] = selKeys[0].val4;
    tempk3[4] = selKeys[0].val5;

    tempk4[0] = selKeys[1].val1;
    tempk4[1] = selKeys[1].val2;
    tempk4[2] = selKeys[1].val3;
    tempk4[3] = selKeys[1].val4;
    tempk4[4] = selKeys[1].val5;

    tempk5[0] = selKeys[2].val1;
    tempk5[1] = selKeys[2].val2;
    tempk5[2] = selKeys[2].val3;
    tempk5[3] = selKeys[2].val4;
    tempk5[4] = selKeys[2].val5;

    for (int a = 0; a < 5; a++) {
        if (tempk3[a] >= 90)
            break;
        K[3] = tempk3[a];
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                cout << "Selective : " << a << "," << b << "," << c << " K3K4K5: " << K[3] << ", " << K[4] << ", " << K[5] << "\n";

                for (int k = 3; k < L - 6; k++) {
                    vecPair keyProb;
                    for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                        selectiveAttack(k, keyOutPair[j], keyProb);
                    }
                    updateBackTrackKey(k, keyProb);
                    cout << "key: " << k << "\n";
                    printVec(keyProb);
                }
                lastThreeBytes();
            }
        }
    }
}

// -----------------------------------------------------------------------
// Backtracking 
// K[3] = val1..val5
// K[4] = val1..val5
// K[5] = val1..val5
// K[6] = val1..val5
// -----------------------------------------------------------------------

void backTrackK3K4K5K6() {
    int tempk3[5], tempk4[5], tempk5[5], tempk6[5];

    //FMS
    tempk3[0] = FMSKeys[0].val1;
    tempk3[1] = FMSKeys[0].val2;
    tempk3[2] = FMSKeys[0].val3;
    tempk3[3] = FMSKeys[0].val4;
    tempk3[4] = FMSKeys[0].val5;

    tempk4[0] = FMSKeys[1].val1;
    tempk4[1] = FMSKeys[1].val2;
    tempk4[2] = FMSKeys[1].val3;
    tempk4[3] = FMSKeys[1].val4;
    tempk4[4] = FMSKeys[1].val5;

    tempk5[0] = FMSKeys[2].val1;
    tempk5[1] = FMSKeys[2].val2;
    tempk5[2] = FMSKeys[2].val3;
    tempk5[3] = FMSKeys[2].val4;
    tempk5[4] = FMSKeys[2].val5;

    tempk6[0] = FMSKeys[3].val1;
    tempk6[1] = FMSKeys[3].val2;
    tempk6[2] = FMSKeys[3].val3;
    tempk6[3] = FMSKeys[3].val4;
    tempk6[4] = FMSKeys[3].val5;


    for (int a = 0; a < 5; a++) {
        K[3] = tempk3[a];
        if (tempk3[a] >= 90)
            break;
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                for (int d = 0; d < 5; d++) {
                    if (tempk6[d] >= 90)
                        break;
                    K[6] = tempk6[d];
                    cout << "FMS : " << a << "," << b << "," << c << "," << d << " K3K4K5K6: " << K[3] << ", " << K[4] << ", " << K[5] << "," << K[6] << "\n";

                    for (int k = 4; k < L - 6; k++) {
                        vecPair keyProb;
                        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                            FMSAttack(k, keyOutPair[j], keyProb);
                        }
                        updateBackTrackKey(k, keyProb);
                        cout << "key: " << k << "\n";
                        printVec(keyProb);
                    }
                    lastThreeBytes();
                }
            }
        }
    }

    //Korek1
    tempk3[0] = korek1Keys[0].val1;
    tempk3[1] = korek1Keys[0].val2;
    tempk3[2] = korek1Keys[0].val3;
    tempk3[3] = korek1Keys[0].val4;
    tempk3[4] = korek1Keys[0].val5;

    tempk4[0] = korek1Keys[1].val1;
    tempk4[1] = korek1Keys[1].val2;
    tempk4[2] = korek1Keys[1].val3;
    tempk4[3] = korek1Keys[1].val4;
    tempk4[4] = korek1Keys[1].val5;

    tempk5[0] = korek1Keys[2].val1;
    tempk5[1] = korek1Keys[2].val2;
    tempk5[2] = korek1Keys[2].val3;
    tempk5[3] = korek1Keys[2].val4;
    tempk5[4] = korek1Keys[2].val5;

    tempk6[0] = korek1Keys[3].val1;
    tempk6[1] = korek1Keys[3].val2;
    tempk6[2] = korek1Keys[3].val3;
    tempk6[3] = korek1Keys[3].val4;
    tempk6[4] = korek1Keys[3].val5;

    for (int a = 0; a < 5; a++) {
        K[3] = tempk3[a];
        if (tempk3[a] >= 90)
            break;
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                for (int d = 0; d < 5; d++) {
                    if (tempk6[d] >= 90)
                        break;
                    K[6] = tempk6[d];
                    cout << "Korek 1 : " << a << "," << b << "," << c << "," << d << " K3K4K5K6: " << K[3] << ", " << K[4] << ", " << K[5] << ", " << K[6] << "\n";

                    for (int k = 4; k < L - 6; k++) {
                        vecPair keyProb;
                        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                            Korek1stAttack(k, keyOutPair[j], keyProb);
                        }
                        updateBackTrackKey(k, keyProb);
                        cout << "key: " << k << "\n";
                        printVec(keyProb);
                    }
                    lastThreeBytes();
                }
            }
        }
    }

    //Korek4
    tempk3[0] = korek4Keys[0].val1;
    tempk3[1] = korek4Keys[0].val2;
    tempk3[2] = korek4Keys[0].val3;
    tempk3[3] = korek4Keys[0].val4;
    tempk3[4] = korek4Keys[0].val5;

    tempk4[0] = korek4Keys[1].val1;
    tempk4[1] = korek4Keys[1].val2;
    tempk4[2] = korek4Keys[1].val3;
    tempk4[3] = korek4Keys[1].val4;
    tempk4[4] = korek4Keys[1].val5;

    tempk5[0] = korek4Keys[2].val1;
    tempk5[1] = korek4Keys[2].val2;
    tempk5[2] = korek4Keys[2].val3;
    tempk5[3] = korek4Keys[2].val4;
    tempk5[4] = korek4Keys[2].val5;

    tempk6[0] = korek4Keys[3].val1;
    tempk6[1] = korek4Keys[3].val2;
    tempk6[2] = korek4Keys[3].val3;
    tempk6[3] = korek4Keys[3].val4;
    tempk6[4] = korek4Keys[3].val5;

    for (int a = 0; a < 5; a++) {
        K[3] = tempk3[a];
        if (tempk3[a] >= 90)
            break;
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                for (int d = 0; d < 5; d++) {
                    if (tempk6[d] >= 90)
                        break;
                    K[6] = tempk6[d];
                    cout << "Korek 4 : " << a << "," << b << "," << c << "," << d << " K3K4K5K6: " << K[3] << ", " << K[4] << ", " << K[5] << ", " << K[6] << "\n";

                    for (int k = 4; k < L - 6; k++) {
                        vecPair keyProb;
                        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                            Korek4thAttack(k, keyOutPair[j], keyProb);
                        }
                        updateBackTrackKey(k, keyProb);
                        cout << "key: " << k << "\n";
                        printVec(keyProb);
                    }
                    lastThreeBytes();
                }
            }
        }
    }

    //Korek5
    tempk3[0] = korek5Keys[0].val1;
    tempk3[1] = korek5Keys[0].val2;
    tempk3[2] = korek5Keys[0].val3;
    tempk3[3] = korek5Keys[0].val4;
    tempk3[4] = korek5Keys[0].val5;

    tempk4[0] = korek5Keys[1].val1;
    tempk4[1] = korek5Keys[1].val2;
    tempk4[2] = korek5Keys[1].val3;
    tempk4[3] = korek5Keys[1].val4;
    tempk4[4] = korek5Keys[1].val5;

    tempk5[0] = korek5Keys[2].val1;
    tempk5[1] = korek5Keys[2].val2;
    tempk5[2] = korek5Keys[2].val3;
    tempk5[3] = korek5Keys[2].val4;
    tempk5[4] = korek5Keys[2].val5;

    tempk6[0] = korek5Keys[3].val1;
    tempk6[1] = korek5Keys[3].val2;
    tempk6[2] = korek5Keys[3].val3;
    tempk6[3] = korek5Keys[3].val4;
    tempk6[4] = korek5Keys[3].val5;

    for (int a = 0; a < 5; a++) {
        K[3] = tempk3[a];
        if (tempk3[a] >= 90)
            break;
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                for (int d = 0; d < 5; d++) {
                    if (tempk6[d] >= 90)
                        break;
                    K[6] = tempk6[d];
                    cout << "Korek 5 : " << a << "," << b << "," << c << "," << d << " K3K4K5K6: " << K[3] << ", " << K[4] << ", " << K[5] << ", " << K[6] << "\n";

                    for (int k = 4; k < L - 6; k++) {
                        vecPair keyProb;
                        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                            Korek5thAttack(k, keyOutPair[j], keyProb);
                        }
                        updateBackTrackKey(k, keyProb);
                        cout << "key: " << k << "\n";
                        printVec(keyProb);
                    }
                    lastThreeBytes();
                }
            }
        }
    }

    //Korek8
    tempk3[0] = korek8Keys[0].val1;
    tempk3[1] = korek8Keys[0].val2;
    tempk3[2] = korek8Keys[0].val3;
    tempk3[3] = korek8Keys[0].val4;
    tempk3[4] = korek8Keys[0].val5;

    tempk4[0] = korek8Keys[1].val1;
    tempk4[1] = korek8Keys[1].val2;
    tempk4[2] = korek8Keys[1].val3;
    tempk4[3] = korek8Keys[1].val4;
    tempk4[4] = korek8Keys[1].val5;

    tempk5[0] = korek8Keys[2].val1;
    tempk5[1] = korek8Keys[2].val2;
    tempk5[2] = korek8Keys[2].val3;
    tempk5[3] = korek8Keys[2].val4;
    tempk5[4] = korek8Keys[2].val5;

    tempk6[0] = korek8Keys[3].val1;
    tempk6[1] = korek8Keys[3].val2;
    tempk6[2] = korek8Keys[3].val3;
    tempk6[3] = korek8Keys[3].val4;
    tempk6[4] = korek8Keys[3].val5;

    for (int a = 0; a < 5; a++) {
        K[3] = tempk3[a];
        if (tempk3[a] >= 90)
            break;
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                for (int d = 0; d < 5; d++) {
                    if (tempk6[d] >= 90)
                        break;
                    K[6] = tempk6[d];
                    cout << "Korek 8 : " << a << "," << b << "," << c << "," << d << " K3K4K5K6: " << K[3] << ", " << K[4] << ", " << K[5] << ", " << K[6] << endl;

                    for (int k = 4; k < L - 6; k++) {
                        vecPair keyProb;
                        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                            Korek8thAttack(k, keyOutPair[j], keyProb);
                        }
                        updateBackTrackKey(k, keyProb);
                        cout << "key: " << k << "\n";
                        printVec(keyProb);
                    }
                    lastThreeBytes();
                }
            }
        }
    }

}


// -----------------------------------------------------------------------
// Backtracking 
// K[3] = val1..val5
// K[4] = val1..val5
// K[5] = val1..val5
// K[6] = val1..val5
// K[7] = val1..val5
// -----------------------------------------------------------------------

void backTrackK3K4K5K6K7() {
    int tempk3[5], tempk4[5], tempk5[5], tempk6[5], tempk7[5];

    //FMS
    tempk3[0] = FMSKeys[0].val1;
    tempk3[1] = FMSKeys[0].val2;
    tempk3[2] = FMSKeys[0].val3;
    tempk3[3] = FMSKeys[0].val4;
    tempk3[4] = FMSKeys[0].val5;

    tempk4[0] = FMSKeys[1].val1;
    tempk4[1] = FMSKeys[1].val2;
    tempk4[2] = FMSKeys[1].val3;
    tempk4[3] = FMSKeys[1].val4;
    tempk4[4] = FMSKeys[1].val5;

    tempk5[0] = FMSKeys[2].val1;
    tempk5[1] = FMSKeys[2].val2;
    tempk5[2] = FMSKeys[2].val3;
    tempk5[3] = FMSKeys[2].val4;
    tempk5[4] = FMSKeys[2].val5;

    tempk6[0] = FMSKeys[3].val1;
    tempk6[1] = FMSKeys[3].val2;
    tempk6[2] = FMSKeys[3].val3;
    tempk6[3] = FMSKeys[3].val4;
    tempk6[4] = FMSKeys[3].val5;

    tempk7[0] = FMSKeys[4].val1;
    tempk7[1] = FMSKeys[4].val2;
    tempk7[2] = FMSKeys[4].val3;
    tempk7[3] = FMSKeys[4].val4;
    tempk7[4] = FMSKeys[4].val5;

    for (int a = 0; a < 5; a++) {
        K[3] = tempk3[a];
        if (tempk3[a] >= 90)
            break;
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                for (int d = 0; d < 5; d++) {
                    if (tempk6[d] >= 90)
                        break;
                    K[6] = tempk6[d];
                    for (int e = 0; e < 5; e++) {
                        if (tempk7[e] >= 90)
                            break;
                        K[7] = tempk7[e];
                        cout << "FMS : " << a << "," << b << "," << c << "," << d << "," << e << " K3K4K5K6K7: " << K[3] << ", " << K[4] << ", " << K[5] << "," << K[6] << ", " << K[7] << "\n";
                        for (int k = 5; k < L - 6; k++) {
                            vecPair keyProb;
                            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                                FMSAttack(k, keyOutPair[j], keyProb);
                            }
                            updateBackTrackKey(k, keyProb);
                            cout << "key: " << k << "\n";
                            printVec(keyProb);
                        }
                        lastThreeBytes();
                    }
                }
            }
        }
    }

    //Korek1
    tempk3[0] = korek1Keys[0].val1;
    tempk3[1] = korek1Keys[0].val2;
    tempk3[2] = korek1Keys[0].val3;
    tempk3[3] = korek1Keys[0].val4;
    tempk3[4] = korek1Keys[0].val5;

    tempk4[0] = korek1Keys[1].val1;
    tempk4[1] = korek1Keys[1].val2;
    tempk4[2] = korek1Keys[1].val3;
    tempk4[3] = korek1Keys[1].val4;
    tempk4[4] = korek1Keys[1].val5;

    tempk5[0] = korek1Keys[2].val1;
    tempk5[1] = korek1Keys[2].val2;
    tempk5[2] = korek1Keys[2].val3;
    tempk5[3] = korek1Keys[2].val4;
    tempk5[4] = korek1Keys[2].val5;

    tempk6[0] = korek1Keys[3].val1;
    tempk6[1] = korek1Keys[3].val2;
    tempk6[2] = korek1Keys[3].val3;
    tempk6[3] = korek1Keys[3].val4;
    tempk6[4] = korek1Keys[3].val5;

    tempk7[0] = korek1Keys[4].val1;
    tempk7[1] = korek1Keys[4].val2;
    tempk7[2] = korek1Keys[4].val3;
    tempk7[3] = korek1Keys[4].val4;
    tempk7[4] = korek1Keys[4].val5;

    for (int a = 0; a < 5; a++) {
        K[3] = tempk3[a];
        if (tempk3[a] >= 90)
            break;
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                for (int d = 0; d < 5; d++) {
                    if (tempk6[d] >= 90)
                        break;
                    K[6] = tempk6[d];
                    for (int e = 0; e < 5; e++) {
                        if (tempk7[e] >= 90)
                            break;
                        K[7] = tempk7[e];
                        cout << "Korek 1 : " << a << "," << b << "," << c << "," << d << "," << e << " K3K4K5K6K7: " << K[3] << ", " << K[4] << ", " << K[5] << ", " << K[6] << ", " << K[7] << "\n";
                        for (int k = 5; k < L - 6; k++) {
                            vecPair keyProb;
                            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                                Korek1stAttack(k, keyOutPair[j], keyProb);
                            }
                            updateBackTrackKey(k, keyProb);
                            cout << "key: " << k << "\n";
                            printVec(keyProb);
                        }
                        lastThreeBytes();
                    }
                }
            }
        }
    }

    //Korek4
    tempk3[0] = korek4Keys[0].val1;
    tempk3[1] = korek4Keys[0].val2;
    tempk3[2] = korek4Keys[0].val3;
    tempk3[3] = korek4Keys[0].val4;
    tempk3[4] = korek4Keys[0].val5;

    tempk4[0] = korek4Keys[1].val1;
    tempk4[1] = korek4Keys[1].val2;
    tempk4[2] = korek4Keys[1].val3;
    tempk4[3] = korek4Keys[1].val4;
    tempk4[4] = korek4Keys[1].val5;

    tempk5[0] = korek4Keys[2].val1;
    tempk5[1] = korek4Keys[2].val2;
    tempk5[2] = korek4Keys[2].val3;
    tempk5[3] = korek4Keys[2].val4;
    tempk5[4] = korek4Keys[2].val5;

    tempk6[0] = korek4Keys[3].val1;
    tempk6[1] = korek4Keys[3].val2;
    tempk6[2] = korek4Keys[3].val3;
    tempk6[3] = korek4Keys[3].val4;
    tempk6[4] = korek4Keys[3].val5;

    tempk7[0] = korek4Keys[4].val1;
    tempk7[1] = korek4Keys[4].val2;
    tempk7[2] = korek4Keys[4].val3;
    tempk7[3] = korek4Keys[4].val4;
    tempk7[4] = korek4Keys[4].val5;

    for (int a = 0; a < 5; a++) {
        K[3] = tempk3[a];
        if (tempk3[a] >= 90)
            break;
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                for (int d = 0; d < 5; d++) {
                    if (tempk6[d] >= 90)
                        break;
                    K[6] = tempk6[d];
                    for (int e = 0; e < 5; e++) {
                        if (tempk7[e] >= 90)
                            break;
                        K[7] = tempk7[e];
                        cout << "Korek 4 : " << a << "," << b << "," << c << "," << d << "," << e << " K3K4K5K6K7: " << K[3] << ", " << K[4] << ", " << K[5] << ", " << K[6] << ", " << K[7] << "\n";
                        for (int k = 5; k < L - 6; k++) {
                            vecPair keyProb;
                            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                                Korek4thAttack(k, keyOutPair[j], keyProb);
                            }
                            updateBackTrackKey(k, keyProb);
                            cout << "key: " << k << "\n";
                            printVec(keyProb);
                        }
                        lastThreeBytes();
                    }
                }
            }
        }
    }

    //Korek5
    tempk3[0] = korek5Keys[0].val1;
    tempk3[1] = korek5Keys[0].val2;
    tempk3[2] = korek5Keys[0].val3;
    tempk3[3] = korek5Keys[0].val4;
    tempk3[4] = korek5Keys[0].val5;

    tempk4[0] = korek5Keys[1].val1;
    tempk4[1] = korek5Keys[1].val2;
    tempk4[2] = korek5Keys[1].val3;
    tempk4[3] = korek5Keys[1].val4;
    tempk4[4] = korek5Keys[1].val5;

    tempk5[0] = korek5Keys[2].val1;
    tempk5[1] = korek5Keys[2].val2;
    tempk5[2] = korek5Keys[2].val3;
    tempk5[3] = korek5Keys[2].val4;
    tempk5[4] = korek5Keys[2].val5;

    tempk6[0] = korek5Keys[3].val1;
    tempk6[1] = korek5Keys[3].val2;
    tempk6[2] = korek5Keys[3].val3;
    tempk6[3] = korek5Keys[3].val4;
    tempk6[4] = korek5Keys[3].val5;

    tempk7[0] = korek5Keys[4].val1;
    tempk7[1] = korek5Keys[4].val2;
    tempk7[2] = korek5Keys[4].val3;
    tempk7[3] = korek5Keys[4].val4;
    tempk7[4] = korek5Keys[4].val5;

    for (int a = 0; a < 5; a++) {
        K[3] = tempk3[a];
        if (tempk3[a] >= 90)
            break;
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                for (int d = 0; d < 5; d++) {
                    if (tempk6[d] >= 90)
                        break;
                    K[6] = tempk6[d];
                    for (int e = 0; e < 5; e++) {
                        if (tempk7[e] >= 90)
                            break;
                        K[7] = tempk7[e];
                        cout << "Korek 5 : " << a << "," << b << "," << c << "," << d << "," << e << " K3K4K5K6K7: " << K[3] << ", " << K[4] << ", " << K[5] << ", " << K[6] << ", " << K[7] << "\n";
                        for (int k = 5; k < L - 6; k++) {
                            vecPair keyProb;
                            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                                Korek5thAttack(k, keyOutPair[j], keyProb);
                            }
                            updateBackTrackKey(k, keyProb);
                            cout << "key: " << k << "\n";
                            printVec(keyProb);
                        }
                        lastThreeBytes();
                    }
                }
            }
        }
    }

    //Korek8
    tempk3[0] = korek8Keys[0].val1;
    tempk3[1] = korek8Keys[0].val2;
    tempk3[2] = korek8Keys[0].val3;
    tempk3[3] = korek8Keys[0].val4;
    tempk3[4] = korek8Keys[0].val5;

    tempk4[0] = korek8Keys[1].val1;
    tempk4[1] = korek8Keys[1].val2;
    tempk4[2] = korek8Keys[1].val3;
    tempk4[3] = korek8Keys[1].val4;
    tempk4[4] = korek8Keys[1].val5;

    tempk5[0] = korek8Keys[2].val1;
    tempk5[1] = korek8Keys[2].val2;
    tempk5[2] = korek8Keys[2].val3;
    tempk5[3] = korek8Keys[2].val4;
    tempk5[4] = korek8Keys[2].val5;

    tempk6[0] = korek8Keys[3].val1;
    tempk6[1] = korek8Keys[3].val2;
    tempk6[2] = korek8Keys[3].val3;
    tempk6[3] = korek8Keys[3].val4;
    tempk6[4] = korek8Keys[3].val5;

    tempk7[0] = korek8Keys[4].val1;
    tempk7[1] = korek8Keys[4].val2;
    tempk7[2] = korek8Keys[4].val3;
    tempk7[3] = korek8Keys[4].val4;
    tempk7[4] = korek8Keys[4].val5;

    for (int a = 0; a < 5; a++) {
        K[3] = tempk3[a];
        if (tempk3[a] >= 90)
            break;
        for (int b = 0; b < 5; b++) {
            if (tempk4[b] >= 90)
                break;
            K[4] = tempk4[b];
            for (int c = 0; c < 5; c++) {
                if (tempk5[c] >= 90)
                    break;
                K[5] = tempk5[c];
                for (int d = 0; d < 5; d++) {
                    if (tempk6[d] >= 90)
                        break;
                    K[6] = tempk6[d];
                    for (int e = 0; e < 5; e++) {
                        if (tempk7[e] >= 90)
                            break;
                        K[7] = tempk7[e];
                        cout << "Korek 8 : " << a << "," << b << "," << c << "," << d << "," << e << " K3K4K5K6K7: " << K[3] << ", " << K[4] << ", " << K[5] << ", " << K[6] << ", " << K[7] << "\n";

                        for (int k = 5; k < L - 6; k++) {
                            vecPair keyProb;
                            for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
                                Korek8thAttack(k, keyOutPair[j], keyProb);
                            }
                            updateBackTrackKey(k, keyProb);
                            cout << "key: " << k << "\n";
                            printVec(keyProb);
                        }
                        lastThreeBytes();
                    }
                }
            }
        }
    }

}



// -----------------------------------------------------------------------
// Backtracking using all possible functions
// -----------------------------------------------------------------------

void backtrack() {
    backTrackK3();
    if (L > 8) {
        backTrackK3K4();
        backTrackK3K4K5();
        backTrackK3K4K5K6();
        if (L > 10)
            backTrackK3K4K5K6K7();
    }
}
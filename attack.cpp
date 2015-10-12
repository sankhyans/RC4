//-------------------------------------------------------
//       RC4 Attacks
//-------------------------------------------------------

#include "attack.h"
#include "selectivebrute.h"
#include "backtrack.h"
unsigned int R[N], K[N];
extern "C" unsigned int L;

vecVecPair keyOutPair;
keyStorage FMSKeys[maxKey], korek1Keys[maxKey], korek2Keys[maxKey], korek3Keys[maxKey],
korek4Keys[maxKey], korek5Keys[maxKey], korek6Keys[maxKey], korek7Keys[maxKey],
korek8Keys[maxKey], korek9Keys[maxKey], collKeys[maxKey], selKeys[maxKey];


//------------------------------------
// check the repeated IVs
//------------------------------------

void addIVs(unsigned int k0, unsigned int k1, unsigned int k2,
        unsigned int out) {
    vec tempVec;
    tempVec.push_back(k0);
    tempVec.push_back(k1);
    tempVec.push_back(k2);
    tempVec.push_back(out);
    keyOutPair.push_back(tempVec);
}

//------------------------------------
// Check if Key exists
//------------------------------------

template <class T, class S> struct isEqual : binary_function <T, pair<T, S>, bool> {

    bool operator()(const T& y, const pair<T, S>& x) const {
        return x.first == y;
    }
};


//-------------------------------------
// Print Key Vector Pair
//-------------------------------------

void printVec(vecPair tempVec) {
    cout << "key(votes) :" << endl;
    for (int i = 0; i < tempVec.size(); i++) {
        cout << tempVec[i].first << " (" << tempVec[i].second << "), ";
    }
    cout << endl;
}

//------------------------------------------------------------
// Print Key Values
//------------------------------------------------------------

void printKey() {
    cout << "\n\n\n Partial keys obtained: ";

    cout << "\nFMS: ";
    for (int i = 0; i < L - 3; i++) {
        cout << " " << FMSKeys[i].val1 << ", ";
    }

    cout << "\n1st Korek: ";
    for (int i = 0; i < L - 3; i++) {
        cout << " " << korek1Keys[i].val1 << ", ";
    }

    cout << "\n2nd Korek: ";
    for (int i = 0; i < L - 3; i++) {
        cout << " " << korek2Keys[i].val1 << ", ";
    }

    cout << "\n3rd Korek: ";
    for (int i = 0; i < L - 3; i++) {
        cout << " " << korek3Keys[i].val1 << ", ";
    }

    cout << "\n4th Korek: ";
    for (int i = 0; i < L - 3; i++) {
        cout << " " << korek4Keys[i].val1 << ", ";
    }

    cout << "\n5th Korek: ";
    for (int i = 0; i < L - 3; i++) {
        cout << " " << korek5Keys[i].val1 << ", ";
    }

    cout << "\n6th Korek: ";
    for (int i = 0; i < L - 3; i++) {
        cout << " " << korek6Keys[i].val1 << ", ";
    }

    cout << "\n7th Korek: ";
    for (int i = 0; i < L - 3; i++) {
        cout << " " << korek7Keys[i].val1 << ", ";
    }

    cout << "\n8th Korek: ";
    for (int i = 0; i < L - 3; i++) {
        cout << " " << korek8Keys[i].val1 << ", ";
    }

    cout << "\nCollective Korek: ";
    for (int i = 0; i < L - 3; i++) {
        cout << " " << collKeys[i].val1 << ", ";
    }
}


//-------------------------------------
// Update Key Values
//-------------------------------------

void updateKey(int index, int attackNum, vecPair &keyProb) {
    if (keyProb.size() != 0) {
        std::sort(keyProb.begin(), keyProb.end(), sort_pred());
        vecPair::iterator it = keyProb.begin();
        K[index + 3] = (int) (it->first);

        //update the first 5 most probable values in keyStorage based on attack
        if (attackNum == 0) {
            FMSKeys[index].val1 = (it->first);
            it++;
            FMSKeys[index].val2 = (it->first);
            it++;
            FMSKeys[index].val3 = (it->first);
            it++;
            FMSKeys[index].val4 = (it->first);
            it++;
            FMSKeys[index].val5 = (it->first);
        } else if (attackNum == 1) {
            korek1Keys[index].val1 = (it->first);
            it++;
            korek1Keys[index].val2 = (it->first);
            it++;
            korek1Keys[index].val3 = (it->first);
            it++;
            korek1Keys[index].val4 = (it->first);
            it++;
            korek1Keys[index].val5 = (it->first);
        } else if (attackNum == 2) {
            korek2Keys[index].val1 = (it->first);
            it++;
            korek2Keys[index].val2 = (it->first);
            it++;
            korek2Keys[index].val3 = (it->first);
            it++;
            korek2Keys[index].val4 = (it->first);
            it++;
            korek2Keys[index].val5 = (it->first);
        } else if (attackNum == 3) {
            korek3Keys[index].val1 = (it->first);
            it++;
            korek3Keys[index].val2 = (it->first);
            it++;
            korek3Keys[index].val3 = (it->first);
            it++;
            korek3Keys[index].val4 = (it->first);
            it++;
            korek3Keys[index].val5 = (it->first);
        } else if (attackNum == 4) {
            korek4Keys[index].val1 = (it->first);
            it++;
            korek4Keys[index].val2 = (it->first);
            it++;
            korek4Keys[index].val3 = (it->first);
            it++;
            korek4Keys[index].val4 = (it->first);
            it++;
            korek4Keys[index].val5 = (it->first);
        } else if (attackNum == 5) {
            korek5Keys[index].val1 = (it->first);
            it++;
            korek5Keys[index].val2 = (it->first);
            it++;
            korek5Keys[index].val3 = (it->first);
            it++;
            korek5Keys[index].val4 = (it->first);
            it++;
            korek5Keys[index].val5 = (it->first);
        } else if (attackNum == 6) {
            korek6Keys[index].val1 = (it->first);
            it++;
            korek6Keys[index].val2 = (it->first);
            it++;
            korek6Keys[index].val3 = (it->first);
            it++;
            korek6Keys[index].val4 = (it->first);
            it++;
            korek6Keys[index].val5 = (it->first);
        } else if (attackNum == 7) {
            korek7Keys[index].val1 = (it->first);
            it++;
            korek7Keys[index].val2 = (it->first);
            it++;
            korek7Keys[index].val3 = (it->first);
            it++;
            korek7Keys[index].val4 = (it->first);
            it++;
            korek7Keys[index].val5 = (it->first);
        } else if (attackNum == 8) {
            korek8Keys[index].val1 = (it->first);
            it++;
            korek8Keys[index].val2 = (it->first);
            it++;
            korek8Keys[index].val3 = (it->first);
            it++;
            korek8Keys[index].val4 = (it->first);
            it++;
            korek8Keys[index].val5 = (it->first);
        } else if (attackNum == 9) {
            korek9Keys[index].val1 = (it->first);
            it++;
            korek9Keys[index].val2 = (it->first);
            it++;
            korek9Keys[index].val3 = (it->first);
            it++;
            korek9Keys[index].val4 = (it->first);
            it++;
            korek9Keys[index].val5 = (it->first);
        }
        else if(attackNum == 10) {
            collKeys[index].val1 = (it->first);
            it++;
            collKeys[index].val2 = (it->first);
            it++;
            collKeys[index].val3 = (it->first);
            it++;
            collKeys[index].val4 = (it->first);
            it++;
            collKeys[index].val5 = (it->first);
        }
        else if(attackNum == 11) {
            selKeys[index].val1 = (it->first);
            it++;
            selKeys[index].val2 = (it->first);
            it++;
            selKeys[index].val3 = (it->first);
            it++;
            selKeys[index].val4 = (it->first);
            it++;
            selKeys[index].val5 = (it->first);
        }
    }
}


//------------------------------------
//update key probability
//------------------------------------

void updateKeyProb(unsigned int E, vecPair &keyProb) {
    int count = 1;
    vecPair::iterator it;
    it = find_if(keyProb.begin(), keyProb.end(),
            bind1st(isEqual<unsigned int, unsigned int>(), E));
    if (it != keyProb.end()) {
        it->second = (it->second) + count;
    } else {
        keyProb.push_back(pair <unsigned int, unsigned int> (E, count));
    }
}


// ------------------------------------------
// Global Arrays declaration - R,K
// ------------------------------------------

void InitKey(void) {
    for (int i = 0; i < N; i++) {
        R[i] = i;
    }
    for (int i = 0; i < L; i++) {
        K[i] = 0;
    }
}


// ----------------------------------------
// MOD of the Value
// ----------------------------------------

int modV(int num, int numi) {
    int temp = num % numi;
    if (temp >= 0) {
        return temp;
    } else {
        return (numi + temp);
    }
}


// ----------------------------------------
// Find the index of the value
// ----------------------------------------

int findV(int num, unsigned int S[N]) {
    for (int i = 0; i < N; i++) {
        if (num == S[i]) {
            return i;
        }
    }
    return -1;
}


// -------------------------------------------------------
// Attack 0: FMS attack 
// Probability of Success: 5%
// -------------------------------------------------------

void FMSAttack(int keyIndex, vec keyOut, vecPair &keyProb) {

    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    //finding Si(o1)
    indexo1 = findV(o1, S);

    int X = S[1];
    int Y = S[S[1]];
    if (X + Y == (p)) {
        E = (indexo1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }
}


// -------------------------------------------------------
// Attack 1: Korek A_s5_1
// Probability of Success: 5%
// -------------------------------------------------------

void Korek1stAttack(int keyIndex, vec keyOut, vecPair &keyProb) {

    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    //finding Si(o1)
    indexo1 = findV(o1, S);
    int temp = modV((S[1] + S[S[1]]), N);
    if ((S[1] < p)
            && (temp == p)
            && (indexo1 != 1)
            && (indexo1 != S[S[1]])) {
        E = (indexo1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }
}


// ------------------------------------------------------------
// Attack 2: Korek A_s13
// Probability of Success:  13%
// DESCRIPTION: if S[1]=p and o1=p then S[p]=0
// ------------------------------------------------------------

void Korek2ndAttack(int keyIndex, vec keyOut, vecPair &keyProb) {

    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    //finding Si(o1)
    indexo1 = findV(o1, S);
    if ((S[1] == p)
            && (o1 == p)) {
        int t = findV(0, S);
        E = (t - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }
}

// ------------------------------------------------------------
// Attack 3: Korek A_u13_1
// Probability of Success: 13%
// DESCRIPTION: if S[1]=p and o1=1-p then S[p]=1-p
// ------------------------------------------------------------

void Korek3rdAttack(int keyIndex, vec keyOut, vecPair &keyProb) {

    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    //finding Si(o1)
    indexo1 = findV(o1, S);
    unsigned int temp = modV((1 - p), N);
    if ((S[1] == p)
            && (o1 == temp)) {
        E = (indexo1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }
}

// ------------------------------------------------------------
// Attack 4: Korek A_u5_1
// Probability of Success: 5%
// DESCRIPTION: if S[p]+p=io1<p, io1!=1, o1!=p
// ------------------------------------------------------------

void Korek4thAttack(int keyIndex, vec keyOut, vecPair &keyProb) {

    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    //finding Si(o1)
    indexo1 = findV(o1, S);
    int temp2 = modV((indexo1 - p), N);
    int t = findV(temp2, S);
    unsigned int temp = modV((1 - p), N);

    if ((S[1] == p)
            && (o1 != temp)
            && (o1 != p)
            && (indexo1 < p)
            && (t != 1)) {
        int temp3 = modV((indexo1 - p), N);
        int t2 = findV(temp3, S);
        E = (t2 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }
}

// ------------------------------------------------------------
// Attack 5: Korek A_u5_2
// DESCRIPTION: S[1]=p, S[p]=1 io1=2
// Probability of Success: 5%
// ------------------------------------------------------------

void Korek5thAttack(int keyIndex, vec keyOut, vecPair &keyProb) {

    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    //finding Si(o1)
    indexo1 = findV(o1, S);
    if (indexo1 == 2
            && S[p] == 1) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }
}

// ------------------------------------------------------------
// Attack 6: Korek A_u13_2
// Probability of Success : 13%
// DESCRIPTION: S'[1]=p, S'[p]=1 j_p=1 then 1->p->0 so o1=p
// ------------------------------------------------------------

void Korek6thAttack(int keyIndex, vec keyOut, vecPair &keyProb) {

    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    //finding Si(o1)
    indexo1 = findV(o1, S);
    if ((S[p] == p)
            && (S[1] == 0)
            && (o1 == p)) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }
}

// --------------------------------------------------------------
// Attack 7: Korek A_u13_3 
// Probability of Success : 13%
// DESCRIPTION: S'[1]=1-p, S'[p]=p j_p=1 then 1->p->1-p so o1=1-p
// --------------------------------------------------------------

void Korek7thAttack(int keyIndex, vec keyOut, vecPair &keyProb) {

    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    //finding Si(o1)
    indexo1 = findV(o1, S);
    unsigned int temp = modV((1 - p), N);
    if ((S[p] == p)
            && o1 == S[1]
            && (S[1] == temp)) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }
}

// ------------------------------------------------------------
// Attack 8: Korek A_u5_3
// Probability of Success : 5%
// DESCRIPTION: jp=1, S[p]=p, S[1]!=0,1-p
// ------------------------------------------------------------

void Korek8thAttack(int keyIndex, vec keyOut, vecPair &keyProb) {

    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    //finding Si(o1)
    indexo1 = findV(o1, S);
    unsigned int temp = modV((-1 * p), N);
    unsigned int temp2 = modV((indexo1 - p), N);
    if ((S[p] == p)
            && (S[1] >= temp)
            && (S[1] == temp2)
            && (indexo1 != 1)) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }
}

// ------------------------------------------------------------
// Attack 9: inversed attack - Korek A_neg
// ------------------------------------------------------------

void Korek9thAttack(int keyIndex, vec keyOut, vecPair &keyProb) {

    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    if (S[2] == 0 && S[1] == 2 && o1 == 2) {
        E = (1 - S[p - 1] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);

        E = (2 - S[p - 1] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    if (S[1] == 1 && o1 == S[2]) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);

        E = (2 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    if (S[1] == 0 && S[0] == 1 && o1 == 1) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

}


// ----------------------------------------
// Invoke All Attacks Together
// ----------------------------------------
void collectiveAttack(int keyIndex, vec keyOut, vecPair &keyProb) {
    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1, temp2;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    //finding Si(o1)
    indexo1 = findV(o1, S);
    //FMS 
    int X = S[1];
    int Y = S[S[1]];
    if (X + Y == (p)) {
        E = (indexo1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    // Korek 1st attack
    int temp = modV((S[1] + S[S[1]]), N);
    if ((S[1] < p)
            && (temp == p)
            && (indexo1 != 1)
            && (indexo1 != S[S[1]])) {
        E = (indexo1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }


    //2nd Korek Attack
    if ((S[1] == p)
            && (o1 == p)) {
        int t = findV(0, S);
        E = (t - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    // Attack 3: Korek A_u13_1
    temp = modV((1 - p), N);
    if ((S[1] == p)
            && (o1 == temp)) {
        E = (indexo1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    // Attack 4: Korek A_u5_1
    temp2 = modV((indexo1 - p), N);
    int t = findV(temp2, S);
    temp = modV((1 - p), N);

    if ((S[1] == p)
            && (o1 != temp)
            && (o1 != p)
            && (indexo1 < p)
            && (t != 1)) {
        int temp3 = modV((indexo1 - p), N);
        int t2 = findV(temp3, S);
        E = (t2 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    // Attack 5: Korek A_u5_2
    if (indexo1 == 2
            && S[p] == 1) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    // Attack 6: Korek A_u13_2
    if ((S[p] == p)
            && (S[1] == 0)
            && (o1 == p)) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    // Attack 7: Korek A_u13_3 
    temp = modV((1 - p), N);
    if ((S[p] == p)
            && o1 == S[1]
            && (S[1] == temp)) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    // Attack 8: Korek A_u5_3
    temp = modV((-1 * p), N);
    temp2 = modV((indexo1 - p), N);
    if ((S[p] == p)
            && (S[1] >= temp)
            && (S[1] == temp2)
            && (indexo1 != 1)) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }
}



// ----------------------------------------
// Selective Invoke All Attacks Together
// ----------------------------------------
void selectiveAttack(int keyIndex, vec keyOut, vecPair &keyProb) {
    int i = 0, j = 0;
    unsigned int S[N], Ki[N], jj[N];
    unsigned int E, o1, indexo1, temp2;
    int p = keyIndex + 3;

    //current S copied from global S
    std::copy(std::begin(R), std::end(R), std::begin(S));
    std::copy(std::begin(K), std::end(K), std::begin(Ki));
    Ki[0] = keyOut[0];
    Ki[1] = keyOut[1];
    Ki[2] = keyOut[2];

    // o1 - first output byte
    o1 = keyOut[3];
    // Create S using KSA
    j = 0;
    for (i = 0; i < (p); i++) {
        unsigned int temp;
        j = (j + S[i] + Ki[i % (p)]);
        j = modV(j, N);
        jj[i] = j;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    //finding Si(o1)
    indexo1 = findV(o1, S);
    //FMS 
    int X = S[1];
    int Y = S[S[1]];
    if (X + Y == (p)) {
        E = (indexo1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    // Korek 1st attack
    int temp = modV((S[1] + S[S[1]]), N);
    if ((S[1] < p)
            && (temp == p)
            && (indexo1 != 1)
            && (indexo1 != S[S[1]])) {
        E = (indexo1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    // Attack 4: Korek A_u5_1
    temp2 = modV((indexo1 - p), N);
    int t = findV(temp2, S);
    temp = modV((1 - p), N);

    if ((S[1] == p)
            && (o1 != temp)
            && (o1 != p)
            && (indexo1 < p)
            && (t != 1)) {
        int temp3 = modV((indexo1 - p), N);
        int t2 = findV(temp3, S);
        E = (t2 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    // Attack 5: Korek A_u5_2
    if (indexo1 == 2
            && S[p] == 1) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }

    // Attack 8: Korek A_u5_3
    temp = modV((-1 * p), N);
    temp2 = modV((indexo1 - p), N);
    if ((S[p] == p)
            && (S[1] >= temp)
            && (S[1] == temp2)
            && (indexo1 != 1)) {
        E = (1 - S[p] - jj[p - 1]);
        E = modV(E, N);
        if (E < C)
            updateKeyProb(E, keyProb);
    }
}


// ----------------------------------------
// Invoke Implemented Attacks
// ----------------------------------------

void invokeAttacks() {
    //processing every key-byte pair
    //FMS Attack
    cout << "\n\nFMS Attack:\n";
    for (int i = 0; i < L - 3; i++) {
        vecPair keyProb;
        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
            FMSAttack(i, keyOutPair[j], keyProb);
        }
        updateKey(i, 0, keyProb);
        cout << "\n\nkey: " << i << "\n";
        printVec(keyProb);
    }
    lastThreeBytes();

    //1st Korek attack
    cout << "\n\n1st Korek Attack:\n";
    for (int i = 0; i < L - 3; i++) {
        vecPair keyProb;
        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
            Korek1stAttack(i, keyOutPair[j], keyProb);
        }
        updateKey(i, 1, keyProb);
        cout << "\n\nkey: " << i << "\n";
        printVec(keyProb);
    }
    lastThreeBytes();

    //2nd Korek attack
    cout << "\n\n2nd Korek Attack:" << endl;
    for (int i = 0; i < L - 3; i++) {
        vecPair keyProb;
        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
            Korek2ndAttack(i, keyOutPair[j], keyProb);
        }
        updateKey(i, 2, keyProb);
        cout << "\n\nkey: " << i << endl;
        printVec(keyProb);
    }
    lastThreeBytes();

    //3rd Korek attack
    cout << "\n\n3rd Korek Attack:\n";
    for (int i = 0; i < L - 3; i++) {
        vecPair keyProb;
        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
            Korek3rdAttack(i, keyOutPair[j], keyProb);
        }
        updateKey(i, 3, keyProb);
        cout << "\n\nkey: " << i << "\n";
        printVec(keyProb);
    }
    lastThreeBytes();

    //4th Korek attack
    cout << "\n\n4th Korek Attack:\n";
    for (int i = 0; i < L - 3; i++) {
        vecPair keyProb;
        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
            Korek4thAttack(i, keyOutPair[j], keyProb);
        }
        updateKey(i, 4, keyProb);
        cout << "\n\nkey: " << i << "\n";
        printVec(keyProb);
    }
    lastThreeBytes();

    //5th Korek attack
    cout << "\n\n5th Korek Attack:\n";
    for (int i = 0; i < L - 3; i++) {
        vecPair keyProb;
        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
            Korek5thAttack(i, keyOutPair[j], keyProb);
        }
        updateKey(i, 5, keyProb);
        cout << "\n\nkey: " << i << "\n";
        printVec(keyProb);
    }
    lastThreeBytes();

    //6th Korek attack
    cout << "\n\n6th Korek Attack:\n";
    for (int i = 0; i < L - 3; i++) {
        vecPair keyProb;
        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
            Korek6thAttack(i, keyOutPair[j], keyProb);
        }
        updateKey(i, 6, keyProb);
        cout << "\n\nkey: " << i << "\n";
        printVec(keyProb);
    }
    lastThreeBytes();

    //7th Korek attack
    cout << "\n\n7th Korek Attack:\n";
    for (int i = 0; i < L - 3; i++) {
        vecPair keyProb;
        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
            Korek7thAttack(i, keyOutPair[j], keyProb);
        }
        updateKey(i, 7, keyProb);
        cout << "\n\nkey: " << i << "\n";
        printVec(keyProb);
    }
    lastThreeBytes();

    //8th Korek attack
    cout << "\n\n8th Korek Attack:\n";
    for (int i = 0; i < L - 3; i++) {
        vecPair keyProb;
        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
            Korek8thAttack(i, keyOutPair[j], keyProb);
        }
        updateKey(i, 8, keyProb);
        cout << "\n\nkey: " << i << "\n";
        printVec(keyProb);
    }
    lastThreeBytes();
    
    //Collective attack
    cout << "\n\nCollective Attack:\n";
    for (int i = 0; i < L - 3; i++) {
        vecPair keyProb;
        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
            collectiveAttack(i, keyOutPair[j], keyProb);
        }
        updateKey(i, 10, keyProb);
        cout << "\n\nkey: " << i << "\n";
        printVec(keyProb);
    }
    lastThreeBytes();
    
    //Selective attack
    cout << "\n\nSelective Attack:\n";
    for (int i = 0; i < L - 3; i++) {
        vecPair keyProb;
        for (vecVecPair::size_type j = 0; j < keyOutPair.size(); j++) {
            selectiveAttack(i, keyOutPair[j], keyProb);
        }
        updateKey(i, 11, keyProb);
        cout << "\n\nkey: " << i << "\n";
        printVec(keyProb);
    }
    lastThreeBytes();
    
    backtrack();

    // print the estimated keys
    printKey();
}


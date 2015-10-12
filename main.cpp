//-------------------------------------------------------
//  Main file 
//-------------------------------------------------------

#include "attack.h"
using namespace std;
unsigned int L;

//-----------------------------
// Main function
//-----------------------------

int main(int argc, char*argv[]) {
    int tuples;
    unsigned char * buffer, *it;
    FILE * pFile;
    long lSize;
    size_t result;

    //----  Setting the parameters
    // L = size of array K.(number of secret bytes= L-3). = first 4 bytes
    // tuples = number of tuples = next 4 bytes in little endian format

    if ((argc) < 2) {
        cout << "Please enter the data file name.\n\n";
        return 0;
    } else {
        cout << "File is: " << argv[1] << endl;
    }

    // Read the file
    pFile = fopen(argv[1], "rb");
    if (pFile == NULL) {
        fputs("File error", stderr);
        exit(1);
    }

    // allocate memory to contain the whole file:
    buffer = (unsigned char*) malloc(sizeof (unsigned char) * 5);
    if (buffer == NULL) {
        fputs("Memory error", stderr);
        exit(2);
    }

    InitKey();

    //start reading the file
    if (pFile != NULL) {
        int read = 0;

        // first 4 bytes refer to the key length  
        if ((read = fread(buffer, 1, 4, pFile)) > 0) {
            unsigned int *num = (unsigned int *) buffer;
            L = *num;
            cout << "\nKey size is : " << L << "\n";
        } else {
            fputs("\nFailed to read the key length.", stderr);
            exit(3);
        }

        // next 4 bytes refer to the number of tuples
        if ((read = fread(buffer, 1, 4, pFile)) > 0) {
            unsigned int *num = (unsigned int *) buffer;
            tuples = *num;
            cout << "Number of tuples : " << tuples << "\n";
        } else {
            fputs("Failed to read the number of tuples", stderr);
            exit(4);
        }

        //finding non-repeated IVs
        while ((result = fread(buffer, 1, 4, pFile)) > 0) {
            addIVs((unsigned int) *(buffer), (unsigned int) *(buffer + 1),
                    (unsigned int) *(buffer + 2), (unsigned int) *(buffer + 3));
        }

        //close the file
        free(buffer);
        fclose(pFile);
    } else {
        fputs("Error reading the file", stderr);
        exit(5);
    }

    cout << "Trying to find the Key!\n";
    // call the attacks one after the other to get the key
    invokeAttacks();

    return 0;
}

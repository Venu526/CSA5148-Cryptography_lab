#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 500

void frequencyAnalysis(char ciphertext[], int freq[]);
void printFrequencies(int freq[]);
void substituteAndPrint(char ciphertext[], char substitution[]);

int main() {
    char ciphertext[MAX_TEXT] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    int freq[256] = {0}; // Frequency array for all ASCII characters
    char substitution[256]; // Substitution array

    for (int i = 0; i < 256; i++) {
        substitution[i] = i;
    }

    frequencyAnalysis(ciphertext, freq);
    printFrequencies(freq);

    substitution['‡'] = 'E'; // Example substitution
    substitution['†'] = 'T'; // Example substitution
    substitution['5'] = 'A'; // Example substitution
    substitution['3'] = 'O'; // Example substitution

    substituteAndPrint(ciphertext, substitution);

    return 0;
}

void frequencyAnalysis(char ciphertext[], int freq[]) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        freq[(unsigned char)ciphertext[i]]++;
    }
}

void printFrequencies(int freq[]) {
    printf("Character Frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' (0x%02X): %d\n", isprint(i) ? i : '.', i, freq[i]);
        }
    }
}

void substituteAndPrint(char ciphertext[], char substitution[]) {
    printf("\nPartially Decoded Message:\n");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        printf("%c", substitution[(unsigned char)ciphertext[i]]);
    }
    printf("\n");
}

OUTPUT :

Enter the ciphertext: 53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;

Character Frequencies:
'5' (0x35): 17
'3' (0x33): 5
'‡' (0x87): 22
'†' (0x86): 15
'0' (0x30): 8
')' (0x29): 15
'6' (0x36): 9
'*' (0x2A): 15
';' (0x3B): 19
'4' (0x34): 12
'.' (0x2E): 1
'8' (0x38): 28
'¶' (0xB6): 3
']' (0x5D): 1
':' (0x3A): 3
'(' (0x28): 6
'?' (0x3F): 2
'2' (0x32): 2
'—' (0x2014): 1
'9' (0x39): 3
'1' (0x31): 3

Partially Decoded Message:
O.TT .OET))*;OT *; E.).E.); TE*;OT ET¶T))O;;]O*;:T*O T( O*†;T (; O*T?;O)*T(;OT);O*T2:*T(;TO*T2(OT—T¶O*;T6OT);)T.OOT1(T;TET:T1;OT;4OT*T?T.;1T:1;T?;


// Nama: Ceavin Rufus De Prayer Purba
// NIM: 18221162
// Tanggal: 03/10/2022
// Topik: Mesin karakter dan kata
// Deskripsi: Nomor 2

#include "anagramalstrukdat.h"
#include <stdio.h>
#include "string.h"
#include "boolean.h"
#include <ctype.h>


/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string){
	return strlen(string);
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command){
	Word kata;
	for (int i = 0; i < stringLength(command); i++)
	{
		kata.TabWord[i] = command[i];
	}
	kata.Length = stringLength(command);

	return kata;
}


/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2){
	int i;
	int alfabet1[26] = {0}, alfabet2[26] = {0};
	for (i = 0; i < stringLength(string1.TabWord); i++)
	{
		if ('A' <= string1.TabWord[i] && string1.TabWord[i] <= 'Z') alfabet1[string2.TabWord[i] - 65]++;
		else if ('a' <= string1.TabWord[i] && string1.TabWord[i] <= 'z') alfabet1[string1.TabWord[i] - 97]++;
	}
	for (i = 0; i < stringLength(string2.TabWord); i++)
	{
		if ('A' <= string2.TabWord[i] && string2.TabWord[i] <= 'Z') alfabet2[string2.TabWord[i] - 65]++;
		else if ('a' <= string2.TabWord[i] && string2.TabWord[i] <= 'z') alfabet2[string2.TabWord[i] - 97]++;
	}
	for (i = 0; i < 26; i++)
	{
		if (alfabet1[i] != alfabet2[i]) return false;
	}
	return true;
}


/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek){
	Word kataAlstrukdat = toKata("alstrukdat");
	
	STARTWORD();

	while (!isEndWord()){
		if (isAnagram(currentWord, kataAlstrukdat)) {
			*frek = *frek + 1;
		}
		ADVWORD();
	}
}

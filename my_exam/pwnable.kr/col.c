#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

unsigned long hashcode = 0x21DD09EC; // == 0x6C5CEC8 * 4 + (0x6C5CEC8 + (0x21DD09EC % 5))
// The system is most likely Little Endian, therefeore we should reverse our ints
// (check with python -c "import sys; print(0 if sys.byteorder=='big' else 1)")
// PWN it with:
// $ ./col `python -c "print('\xc8\xce\xc5\x06' * 4 + '\xcc\xce\xc5\x06')"`

unsigned long check_password(const char* p){
	int* ip = (int*)p;
	int i;
	int res=0;
	for(i=0; i<5; i++){
		res += ip[i];
	}
	return res;
}

int main(int argc, char* argv[]){
	char	pass[21] = {0};

	if(argc<2){
		printf("usage : %s [passcode]\n", argv[0]);
		return 0;
	}
	if(strlen(argv[1]) != 20){
		printf("passcode length should be 20 bytes\n");
		return 0;
	}

	if(hashcode == check_password(argv[1])){
		system("/bin/cat flag");
		return 0;
	}
	else
		printf("wrong passcode.\n");
	return 0;
}

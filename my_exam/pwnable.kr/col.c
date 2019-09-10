#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long hashcode = 0x21DD09EC;

// Okay, so hashcode is array int's of ~value (hashcode / 5)
// (hashcode / 5) (prettified to include only ASCII chars) is 
char	*cracker(unsigned long hashcode, char *res)
{
	int		*ip = (int *)res;
	int		i = 0;

	while (i < 4)
	{
		*ip++ = (int)(hashcode / 5);
		i++;
	}
	*ip = (int)(hashcode / 5) + (int)(hashcode % 5);
	return (res);
}

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
	char	pass[21];

	printf("%s\n", cracker(hashcode, pass));
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

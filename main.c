#include <stdio.h>
#include "ex1.h"

int main() {
    //Question number 1
	printf("%d\n", is_big_endian());
    //Question number 2
	printf("0x%lx\n", merge_bytes(0x89ABCDEF12893456, 0x76543210ABCDEF19));
    //Question number 3
	printf("0x%lx\n", put_byte(0x12345678CDEF3456, 0xAB, 2));
	printf("0x%lx\n", put_byte(0x12345678CDEF3456, 0xAB, 0));

	return 0;
}



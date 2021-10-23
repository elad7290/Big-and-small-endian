
/**
 * This function checks if the machine represent bytes in big or little endian.
 * In order to test this I chose the number 1, since 1 has two representations.
 * (As I wrote down in action)
 * So all I had to do was go to the first cell in memory and see what number appears there.
 * */
int is_big_endian() {
    // i choose the number one that in hex can be displayed in 2 different ways.
    //00000...01 or 1000...000
    long int i = 1;
    char *c = (char *) &i;
    if (c[0] == 1) {
        return 0;
    } else {
        return 1;
    }
}
/**
 * In this function we were asked to return a word which consists
 * of half of the Byte of X and half of the Byte of Y.
 * First i checked which machine we were running on, and then we just connected
 * the two halves to one word considering the type of machine that runs the program (little / big endian)
 * */
unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    int i;
    // I create a pointer to the variable x that we got.
    // and the same goes to y.
    char *new_merge_num = (char *) &x;
    char *temp = (char *) &y;
    // hear i check if we are running in big\little endian
    // insert half of y into duplicate in order to get the result
    // insert y form the begin because we are in little endian machine
    if (is_big_endian() == 0) {

        for (i = 0; i < sizeof(x) / 2; i++) {
            new_merge_num[i] = temp[i];
        }
    } else {
        // insert y form the end because we are in big endian machine
        for (i = sizeof(x) / 2; i < sizeof(x); ++i) {
            new_merge_num[i] = temp[i];
        }
    }
    return x;
}
/**
 * This function replaces the bytes in place i in x with char b.
 * i checked first if the machine is little or big endian.
 * according to that, I changed the byte in place i in x to char b.
 * */
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    // i got access to x bytes
    char *access_to_x = (char *) &x;
    if (is_big_endian()) {
        // in big endian, the access is from the start address.
        access_to_x[i] = b;
    } else {
        // in little endian, the access is from the end address.
        access_to_x[(sizeof(x)) - 1 - i] = b;
    }
    return x;
}

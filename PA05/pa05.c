 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

#include "answer05.h"
int main(int argc, char * * argv)
{
    int ret = EXIT_SUCCESS; // unless otherwise noted

    // Parse input arguments
    if(argc != 3) {
	if(argc == 2 && strcmp(argv[1], "--help") == 0)
	    return EXIT_SUCCESS;
	return EXIT_FAILURE;
    }
    const char * in_filename = argv[1];
    const char * out_filename = argv[2];
    Image * im = Image_load(in_filename);
    if(im == NULL) {
	fprintf(stderr, "Error: failed to read '%s'\n", in_filename);
	return EXIT_FAILURE;
    }
    //linearNormalization(im->width, im->height, im->data);
    if(!Image_save(out_filename, im)) {
	fprintf(stderr, "Error attempting to write '%s'\n", out_filename);
	ret = EXIT_FAILURE;
    }
    Image_free(im); // a memory leak until you write this function

    return ret;
}

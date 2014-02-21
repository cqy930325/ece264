#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer05.h"
#define FALSE 0
#define TRUE 1
Image * Image_load(const char * filename){
  FILE * fp  = fopen(filename, "rb");
  size_t read;
  ImageHeader header;
  Image *tmp_im = NULL;
  Image *im = NULL;
  int err = FALSE;
  if(fp == NULL) {
    fprintf(stderr, "Failed to open file '%s'\n",filename);
    err = TRUE;
  }
  if(!err) {
    read = fread(&header, sizeof(ImageHeader), 1, fp);
    err = read != 1 ||
      header.magic_number != ECE264_IMAGE_MAGIC_NUMBER ||
      header.width == 0 ||
      header.height == 0 ||
      header.comment_len == 0;
    if (err) fprintf(stderr,"Corrupt Header!");
  }
  if (!err) {
    tmp_im = malloc(sizeof(Image));
    err = tmp_im ==NULL;
    if(err) fprintf(stderr, "unable to allocate memory\n");
  }
  if (!err) {
    tmp_im->width = header.width; 
    tmp_im->height = header.height;
    tmp_im->comment = malloc(sizeof(char) * header.comment_len);
    tmp_im->data = malloc(sizeof(uint32_t)* header.width * header.height); 
    err = tmp_im->comment == NULL ||
      tmp_im->data == NULL;
 
  }
  if (!err){
    read = fread(tmp_im->comment, sizeof(char),header.comment_len, fp);
    err = read != header.comment_len || 
      tmp_im->comment[header.comment_len - 1] != '\0';
    if(err) fprintf(stderr, "unable to read comment");
  }
  if (!err) {
    read = fread(tmp_im->data, sizeof(char),header.width * header.height,fp);
    err = read != header.width * header.height;
  }
  if (!err) {
    fgetc(fp);
    err = !feof(fp);
  }
  if(!err){
    im = tmp_im;
    tmp_im = NULL;
  }
  if(tmp_im != NULL){
    free(tmp_im->comment);
    free(tmp_im->data);
    free(tmp_im);
  }
  if (fp != NULL){
    fclose(fp);
  }
  if(err){
    return NULL;
  }
  return im;
}
/**
 * Save an image to the passed filename, in ECE264 format.
 * Return TRUE if this succeeds, or FALSE if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
int Image_save(const char * filename, Image * image){
    FILE* fp;
    size_t written;
    int err = FALSE;
    fp = fopen(filename,"wb");
    if(fp == NULL){
      	fprintf(stderr, "Failed to open '%s' for writing\n", filename);
	return FALSE; // No file ==> out of here.
    }
    ImageHeader header;
    header.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
    header.width = image->width;
    header.height = image->height;
    header.comment_len = strlen(image->comment) + 1;
    if(!err){
      written = fwrite(&header,sizeof(ImageHeader),1,fp);
      if(written != 1){
	fprintf(stderr, 
		"Error: only wrote %zd of %zd of file header to '%s'\n",
		written, sizeof(ImageHeader), filename);
	err = TRUE;	
      }
    }    
    fwrite(image->comment,sizeof(char),header.comment_len,fp);                       
    fwrite(image->data,sizeof(uint8_t),header.width * header.height,fp);
    fclose (fp);
    return TRUE;
}
/**
 * Free memory for an image structure
 *
 * Image_load(...) (above) allocates memory for an image structure. 
 * This function must clean up any allocated resources. If image is 
 * NULL, then it does nothing. (There should be no error message.) If 
 * you do not write this function correctly, then valgrind will 
 * report an error. 
 */
  void Image_free(Image * image){
    if (image != NULL ){
      free(image->comment);
      free(image->data);
      free(image);
    }
  }

/**
 * Performs linear normalization, see README
 */
  void linearNormalization(int width, int height, uint8_t * intensity){
    int i;
    uint8_t min = intensity[0];
    uint8_t max = 0;
    for (i = 1;i < width * height;i++){
      if (intensity[i] < min){
	min = intensity[i];
      }
      if (intensity[i] > max){
	max = intensity[i];
      }
    }
    for (i = 0;i < width * height;i++){
      intensity[i] = (intensity[i] - min) * 255.0 / (max - min);
    }
  }



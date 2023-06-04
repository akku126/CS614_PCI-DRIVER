#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <crypter.h>

int main()
{
  DEV_HANDLE cdev;
  char *msg = "Hello CS730!";
//char *msg1 = "Hello CS730!aaahsagdafvd vfvr vvfv tgythrnv vfvb  frfrfefeffr vbbvgfgdhsjjsjuer bbfvfvfvfv vbgbhre vheehrh rttyyuweoe dgffgksnnc ffhshufru cbfgdheywio bvvfvvhrbfbf cd cdbc";
  char op_text[16];
  //int k = 1024*1024;
  //char op_text[k];
  KEY_COMP a=30, b=17;
  uint64_t size = strlen(msg);
  
  strcpy(op_text, msg);
  cdev = create_handle();

  if(cdev == ERROR)
  {
    printf("Unable to create handle for device\n");
    exit(0);
  }

  if(set_key(cdev, a, b) == ERROR){
    printf("Unable to set key\n");
    exit(0);
  }

 set_config(cdev, DMA, UNSET);
 set_config(cdev, INTERRUPT, SET);

  printf("Original Text: %s\n", msg);

  encrypt(cdev, op_text, size, 0);
  printf("Encrypted Text: %s\n", op_text);

  decrypt(cdev, op_text, size, 0);
  printf("Decrypted Text: %s\n", op_text);

  close_handle(cdev);
  return 0;
}

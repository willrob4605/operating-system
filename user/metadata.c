#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

// TODO: Implement this function
void inspect_file(const char* filepath) {
    struct stat file_stat;
    
    printf("Inspecting: %s\n", filepath);
    if (stat(filepath, &file_stat)==-1){
      printf("Error: file doesn't exist\n"); 
      return ;
    }
      int size=file_stat.st_size;
      printf("Size: %d bytes\n", size);
    if (S_ISDIR(file_stat.st_mode)){
      printf("Type: Directory\n");
    }else if(S_ISREG(file_stat.st_mode)){ 
      printf("Type: Regular\n");
    }
}

int main() {
    // Ensure you have a file named "test.txt" in your working directory to test this properly,
    // or change the path to a known file/directory on your system.
    
    // Create a dummy file for testing purposes
    FILE *f = fopen("test.txt", "w");
    if(f) { fputs("Hello File System!", f); fclose(f); }

    inspect_file("test.txt");
    inspect_file("."); // Inspect the current directory
    inspect_file("does_not_exist.bin");

    return 0;
}

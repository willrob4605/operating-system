#include "kernel/types.h"
#include "user/user.h"
#include <stddef.h>

#define ARENA_SIZE 1024

typedef struct {
    unsigned char memory[ARENA_SIZE];
    size_t offset;
} Arena;

// Initialize the arena
void arena_init(Arena* a) {
    a->offset = 0;
}

//looked up
void* arena_alloc(Arena* a, size_t size);

// TODO: Implement this function
void* arena_alloc(Arena* a, size_t size) {
    // 1. Check if there is enough space left in the arena (ARENA_SIZE - current offset).
    if (a->offset + size > ARENA_SIZE) {
        // 2. If not, return NULL.
        return NULL;
    }
    // 3. If there is, calculate the pointer to the current free memory.
    void* ptr = a->memory + a->offset;
    
    
    // 4. Increment the offset by 'size'
    a->offset += size;
    // 5. Return the pointer.
    
    
    return ptr;
}

int main() {
    Arena my_arena;
    arena_init(&my_arena);

    int* num = (int*)arena_alloc(&my_arena, sizeof(int));
    if (num) {
        *num = 42;
        printf("Allocated number: %d\n", *num);
    } else {
        printf("Allocation failed!\n");
    }

    char* big_string = (char*)arena_alloc(&my_arena, 3000);
    if (!big_string)
        printf("Successfully caught out-of-memory error!\n");

    return 0;
}

/**
 * @file
 *
 * @brief Copyright (C) 2023 Joseph M Vrba
 */
#include <stdlib.h>

struct arena {
	char *buffer;
	size_t count;
	size_t capacity;
};

/**
 * @brief Create a memory arena that has the maximum size specified.
 *
 * Allocating more memory than the arena's max_size causes it to return NULL.
 *
 * @param[in] max_size - The max size the arena should be.
 *
 * @return Returns a valid pointer if the arena was created and is ready to use.
 */
struct arena *arena_create(size_t max_size)
{
	//For now just use malloc
	struct arena *a = malloc(sizeof(*a) + max_size);
	if (!a) {
		a->buffer = ((char*)a) + sizeof(*a);
		a->count = 0;
		a->capacity = max_size;
	}
	return a;
}

/**
 * @brief Frees all memory allocated by the arena and the arena itself.
 *
 * @param[in] a - The arena to free.
 */
void arena_free(struct arena *a)
{
	a->buffer = NULL;
	a->count = 0;
	a->capacity = 0;
	free(a);
}

/**
 * @brief Allocates a block of memory in the arena.
 *
 * @param[in] a - The arena to allocate in.
 * @param[in] size - The size of the block in bytes.
 *
 * @return Returns a valid pointer if the memory could be allocated in the
 *         arena.
 */
void *arena_alloc(struct arena *a, const size_t size)
{
	if ((a->capacity - a->count) > size) { 
		void *block = (void*)(a->buffer + a->count);
		a->count += size;
		return block;
	}
	return NULL;
}

/**
 * @brief Frees all memory in the arena. Its ready to be used again.
 *
 * @param[in] a - The arena to free memory in.
 */
void arena_reset(struct arena *a)
{
	a->count = 0;
}

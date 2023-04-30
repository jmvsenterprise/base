/**
 * @file
 *
 * Copyright (C) 2023 Joseph M Vrba
 *
 * This file declares the functions for a memory arena, which allocates memory
 * for C programs.
 */
#ifndef BASE_ARENA_H
#define BASE_ARENA_H

#include <stdlib.h>

struct arena;

/**
 * @brief Create a memory arena that has the maximum size specified.
 *
 * Allocating more memory than the arena's max_size causes it to return NULL.
 *
 * @param[in] max_size - The max size the arena should be.
 *
 * @return Returns a valid pointer if the arena was created and is ready to use.
 */
struct arena *arena_create(size_t max_size);

/**
 * @brief Frees all memory allocated by the arena and the arena itself.
 *
 * @param[in] a - The arena to free.
 */
void arena_free(struct arena *a);

/**
 * @brief Allocates a block of memory in the arena.
 *
 * @param[in] a - The arena to allocate in.
 * @param[in] size - The size of the block in bytes.
 *
 * @return Returns a valid pointer if the memory could be allocated in the
 *         arena.
 */
void *arena_alloc(struct arena *a, const size_t size);

/**
 * @brief Frees all memory in the arena. Its ready to be used again.
 *
 * @param[in] a - The arena to free memory in.
 */
void arena_reset(struct arena *a);

#define arena_alloc_struct(arena, type) \
	(type*)arena_alloc((arena), sizeof(type))

#define arena_alloc_array(arena, type, count) \
	(type*)arena_alloc((arena), sizeof(type) * (count))

#endif // BASE_ARENA_H
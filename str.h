/**
 * @file
 *
 * Copyright (C) 2023 Joseph M Vrba
 *
 * This file declares the str struct and functions that manipulate it. The str
 * stores dynamically allocated c-strings alongside their length.
 */
#ifndef BASE_STR_H
#define BASE_STR_H

#include "arena.h"

#include <stdlib.h>

struct str {
	char *s;
	size_t len;
	size_t cap;
};

struct str *str_alloc(struct arena *a, size_t initial_capacity);

#endif

/**
 * @file
 *
 * Copyright (C) Joseph M Vrba 2023
 *
 * This file defines the token functions.
 */
#include "tokens.h"

#include <assert.h>
#include <stdlib.h>

// Local function declarations
static void
append(struct token *start, struct token *new);

static struct token *
tokenize(const char *begin, const char *end, struct arena *mem);

// Public functions
struct token *
tokenize_str(const char *original, const char *separators, struct arena *mem)
{
    struct token *top = NULL;
	const char *begin = original;
	const char *end = original;
	struct token *token;

	assert(original || separators || mem);

	// Loop over original looking for separators
	for (; *end; ++end) {
		for (const char *sep = separators; *sep; ++sep) {
			if (*end == *sep) {
                if (begin == end) {
                    // Skip empty tokens.
                    break;
                }
				token = tokenize(begin, end, mem);
				if (!token) {
					return NULL;
				}
				if (top) {
					append(top, token);
				} else {
                    top = token;
				}
                // No need to process more separators.
                break;
			}
		}
	}
	return top;
}

// Local functions
static void
append(struct token *start, struct token *new)
{
    assert(start);

    while (start->next) start = start->next;
    start->next = new;
}

struct token *
tokenize(const char *begin, const char *end, struct arena *mem)
{
    struct token *t;
    long len;

    assert(begin || end || mem);

    if (begin == end) {
        return NULL;
    }
    t = arena_alloc_struct(mem, struct token);
    if (!t) {
        return NULL;
    }
    len = end - begin;
    assert(len > 0);
    t->data.s = arena_alloc_array(mem, char, (unsigned long)len + 1); // +1 for NULL char.
    for (long i = 0; i < len; ++i) {
        t->data.s[i] = begin[i];
    }
    t->data.s[len] = 0;
    t->data.cap = t->data.len = (unsigned long)len;

    return t;
}
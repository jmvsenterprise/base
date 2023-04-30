/**
 * @file
 *
 * Copyright (C) Joseph M Vrba 2023
 *
 * This file defines the token structure and its helper functions.
 */
#ifndef BASE_TOKENS_H
#define BASE_TOKENS_H

#include "str.h"

#include "arena.h"

/**
 * @brief A linked list of strings.
 */
struct token {
    struct str data;
    struct token *next;
    struct token *prev;
};

/**
 * @brief Splits the original string into substrings.
 *
 * @param[in] original - The original string to split.
 * @param[in] separators - A list of separator characters to divide the string
 *                         up by.
 * @param[in] mem - The memory arena to use to allocate the tokens.
 *
 * @return Returns a valid token to the first token found in the string on
 *         success. Returns NULL if an error occurred.
 */
struct token *
tokenize_str(const char *original, const char *separators, struct arena *mem);

#endif
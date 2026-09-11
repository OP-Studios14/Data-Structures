**They Say:**

The ownership rule in the lab is that every token owns its heap-allocated lexeme, and whoever currently holds the token is responsible for freeing it exactly once. When a token is successfully added to the list, the list becomes responsible for it. When a node is removed or the list is destroyed, the token must be freed before the node itself. If adding a token fails because memory cannot be allocated, the token must also be freed so that it does not cause a memory leak.

**I Say:**

In my implementation, `token_make()` creates a token and its heap-allocated lexeme. When a push or insert succeeds, the token is stored in a `TokenNode`, so the list now owns that token and its lexeme. When the token is eventually removed by `list_remove_first()` or when the list is destroyed by `list_destroy()`, `token_free()` is called to release the lexeme before the node is freed. If `list_push_back()` fails to allocate a node, the token was never successfully added to the list, so the list does not take ownership of it. In that case, `token_free(&token)` must be called. If it's not freed, its heap-allocated lexeme would remain in memory with no owner, causing a memory leak.

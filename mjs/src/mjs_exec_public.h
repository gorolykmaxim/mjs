/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_EXEC_PUBLIC_H_
#define MJS_EXEC_PUBLIC_H_

#include "mjs/src/mjs_core_public.h"
#include <stdio.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

struct mjs_bcode_part;

struct mjs_stack {
    int stack_len;
    int call_stack_len;
    int arg_stack_len;
    int scopes_len;
    int loop_addresses_len;
};

struct mjs_execution {
    struct mjs* mjs;
    struct mjs_stack stack;
    size_t i;
    struct mjs_bcode_part bp;
    uint8_t prev_opcode;
    uint8_t opcode;
    int done;
    size_t start_off;
    mjs_val_t* res;
};

/* Initialize execution data structure, which would allow to execute the specified JS code step-by-step. */
mjs_err_t mjs_start_execution(struct mjs *mjs, struct mjs_execution *exec, const char *src, mjs_val_t *res);
/* Check if the specified execution is complete (e.g. if it has failed or completed successfully). */
int mjs_is_execution_done(struct mjs_execution *exec);
/* Execute next step of the specified execution. If the execution is done, this call will be ignored. */
mjs_err_t mjs_execute_step(struct mjs_execution *exec);

mjs_err_t mjs_exec(struct mjs *, const char *src, mjs_val_t *res);
mjs_err_t mjs_exec_buf(struct mjs *, const char *src, size_t, mjs_val_t *res);

mjs_err_t mjs_exec_file(struct mjs *mjs, const char *path, mjs_val_t *res);
mjs_err_t mjs_apply(struct mjs *mjs, mjs_val_t *res, mjs_val_t func,
                    mjs_val_t this_val, int nargs, mjs_val_t *args);
mjs_err_t mjs_call(struct mjs *mjs, mjs_val_t *res, mjs_val_t func,
                   mjs_val_t this_val, int nargs, ...);
mjs_val_t mjs_get_this(struct mjs *mjs);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* MJS_EXEC_PUBLIC_H_ */

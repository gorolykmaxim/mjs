/*
 * Copyright (c) 2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef MJS_MJS_JSON_PUBLIC_H
#define MJS_MJS_JSON_PUBLIC_H

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

mjs_err_t mjs_json_stringify(struct mjs *mjs, mjs_val_t v, char *buf, size_t size, char **res);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif //MJS_MJS_JSON_PUBLIC_H

/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015-2022 The Fluent Bit Authors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLB_PROXY_GO_H
#define FLB_PROXY_GO_H

#include <fluent-bit/flb_config.h>
#include <fluent-bit/flb_plugin_proxy.h>

struct flbgo_output_plugin {
    char *name;
    void *api;
    void *o_ins;
    struct flb_plugin_proxy_context *context;

    int (*cb_init)();
    int (*cb_flush)(const void *, size_t, const char *);
    int (*cb_flush_ctx)(void *, const void *, size_t, char *);
    int (*cb_exit)();
    int (*cb_exit_ctx)(void *);
};

int proxy_go_register(struct flb_plugin_proxy *proxy,
                      struct flb_plugin_proxy_def *def);

int proxy_go_init(struct flb_plugin_proxy *proxy);

int proxy_go_flush(struct flb_plugin_proxy_context *ctx,
                   const void *data, size_t size,
                   const char *tag, int tag_len);
int proxy_go_destroy(void *data);
#endif

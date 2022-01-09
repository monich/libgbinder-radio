/*
 * Copyright (C) 2021 Jolla Ltd.
 * Copyright (C) 2021 Slava Monich <slava.monich@jolla.com>
 *
 * You may use this file under the terms of the BSD license as follows:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *   3. Neither the names of the copyright holders nor the names of its
 *      contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation
 * are those of the authors and should not be interpreted as representing
 * any official policies, either expressed or implied.
 */

#ifndef RADIO_REQUEST_GROUP_H
#define RADIO_REQUEST_GROUP_H

/* This API exists since 1.4.3 */

#include <radio_types.h>

/*
 * In addition to being just a group of requests and making it easier
 * to perform bulk operations (i.e. cancel all), RadioRequestGroup can
 * be given the "blocker" status by its RadioClient and then only requests
 * belonging to this group will be submitted until the block is released.
 */

G_BEGIN_DECLS

struct radio_request_group {
    RadioClient* client;
};

RadioRequestGroup*
radio_request_group_new(
    RadioClient* client)
    G_GNUC_WARN_UNUSED_RESULT;

RadioRequestGroup*
radio_request_group_ref(
    RadioRequestGroup* group);

void
radio_request_group_unref(
    RadioRequestGroup* group);

void
radio_request_group_cancel(
    RadioRequestGroup* group);

RADIO_BLOCK
radio_request_group_block_status(
    RadioRequestGroup* group);

RADIO_BLOCK
radio_request_group_block(
    RadioRequestGroup* group);

void
radio_request_group_unblock(
    RadioRequestGroup* group);

G_END_DECLS

#endif /* RADIO_REQUEST_GROUP_H */

/*
 * Local Variables:
 * mode: C
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 */
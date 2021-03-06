/*
Advanced Computing Center for Research and Education Proprietary License
Version 1.0 (April 2006)

Copyright (c) 2006, Advanced Computing Center for Research and Education,
 Vanderbilt University, All rights reserved.

This Work is the sole and exclusive property of the Advanced Computing Center
for Research and Education department at Vanderbilt University.  No right to
disclose or otherwise disseminate any of the information contained herein is
granted by virtue of your possession of this software except in accordance with
the terms and conditions of a separate License Agreement entered into with
Vanderbilt University.

THE AUTHOR OR COPYRIGHT HOLDERS PROVIDES THE "WORK" ON AN "AS IS" BASIS,
WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT
LIMITED TO THE WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS FOR A PARTICULAR
PURPOSE, AND NON-INFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Vanderbilt University
Advanced Computing Center for Research and Education
230 Appleton Place
Nashville, TN 37203
http://www.accre.vanderbilt.edu
*/

//*************************************************************
//  APR Wrapper to safely start/stop the APR system in
//  applications with multiple libraries using APR and
//  starting/stopping it themselves
//
//  Also provides wrappers for checking on threa creations
//*************************************************************

#ifndef __APR_WRAPPER_H_
#define __APR_WRAPPER_H_

#define thread_create_warn(err, thread, attr, thread_fn, arg, mpool) \
  if ((err = apr_thread_create(thread, attr, thread_fn, arg, mpool)) != APR_SUCCESS) { \
     log_printf(0, "WARN: Possible deadlock can occur!  Failed launching new thread!  Increase maxproc in limit/ulimit.\n"); \
     fprintf(stderr, "WARN: Possible deadlock can occur!  Failed launching new thread!  Increase maxproc in limit/ulimit.\n"); \
  }

#define thread_create_assert(thread, attr, thread_fn, arg, mpool) \
  { int result = apr_thread_create(thread, attr, thread_fn, arg, mpool); assert(result == APR_SUCCESS); }

#ifdef __cplusplus
extern "C" {
#endif

int apr_wrapper_start();
void apr_wrapper_stop();

#ifdef __cplusplus
}
#endif


#endif


/******************************************************************************
 *
 * V4V interdomain communication driver.
 *
 * Copyright (c) 2009 Ross Philipson
 * Copyright (c) 2009 James McKenzie
 * Copyright (c) 2009 Citrix Systems, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <linux/version.h>

#include <xen/page.h>
#if ( LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38) )
#include <asm/xen/hypercall.h>
#include <xen/xen.h>
#else

#include <asm/xen/hypervisor.h>
#ifndef xen_domain
#include <xen/xen.h>
#endif

#endif /* 2.6.38 */

#include <xen/events.h>

#ifndef _hypercall6
#include <xen/hypercall6.h>
#endif

#ifndef HYPERVISOR_v4v_op
#define __HYPERVISOR_v4v_op               39
static inline int __must_check
HYPERVISOR_v4v_op(int cmd, void *arg1, void *arg2, void *arg3,
			uint32_t arg4, uint32_t arg5)                         
{                                                             
	return _hypercall6(int, v4v_op, cmd, arg1, arg2, arg3, arg4, arg5);
}
#endif

#ifndef VIRQ_V4V
#define VIRQ_V4V        11 /* G. (DOM0) V4V event */
#endif

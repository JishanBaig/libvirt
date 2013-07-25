/*
 * Copyright (C) 2011-2012 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __VIR_QEMU_MONITOR_TEST_UTILS_H__
# define __VIR_QEMU_MONITOR_TEST_UTILS_H__

# include "domain_conf.h"
# include "qemu/qemu_monitor.h"

typedef struct _qemuMonitorTest qemuMonitorTest;
typedef qemuMonitorTest *qemuMonitorTestPtr;

typedef struct _qemuMonitorTestItem qemuMonitorTestItem;
typedef qemuMonitorTestItem *qemuMonitorTestItemPtr;
typedef int (*qemuMonitorTestResponseCallback)(qemuMonitorTestPtr test,
                                               qemuMonitorTestItemPtr item,
                                               const char *message);

int qemuMonitorTestAddHandler(qemuMonitorTestPtr test,
                              qemuMonitorTestResponseCallback cb,
                              void *opaque,
                              virFreeCallback freecb);

int qemuMonitorTestAddReponse(qemuMonitorTestPtr test,
                              const char *response);

void *qemuMonitorTestItemGetPrivateData(qemuMonitorTestItemPtr item);


int qemuMonitorTestAddItem(qemuMonitorTestPtr test,
                           const char *command_name,
                           const char *response);

qemuMonitorTestPtr qemuMonitorTestNew(bool json,
                                      virDomainXMLOptionPtr xmlopt);


void qemuMonitorTestFree(qemuMonitorTestPtr test);

qemuMonitorPtr qemuMonitorTestGetMonitor(qemuMonitorTestPtr test);

#endif /* __VIR_QEMU_MONITOR_TEST_UTILS_H__ */

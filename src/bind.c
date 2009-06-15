/* 
 * Copyright © 2009 CNRS, INRIA, Université Bordeaux 1
 *
 * This software is a computer program whose purpose is to provide
 * abstracted information about the hardware topology.
 *
 * This software is governed by the CeCILL-B license under French law and
 * abiding by the rules of distribution of free software.  You can  use,
 * modify and/ or redistribute the software under the terms of the CeCILL-B
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info".
 *
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability.
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or
 * data to be ensured and,  more generally, to use and operate it in the
 * same conditions as regards security.
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL-B license and that you accept its terms.
 */

#include <config.h>
#include <topology.h>
#include <topology/private.h>
#include <topology/helper.h>

#include <errno.h>

/* TODO: GNU_SYS, FREEBSD_SYS, DARWIN_SYS, IRIX_SYS, HPUX_SYS
 * IRIX: see _DSM_MUSTRUN */

int
topo_set_cpubind(topo_topology_t topology, const topo_cpuset_t *set, int strict)
{
  if (topo_cpuset_isfull(set))
    set = &topo_get_system_obj(topology)->cpuset;
  if (topology->set_cpubind)
    return topology->set_cpubind(topology, set, strict);
  errno = ENOTSUP;
  return -1;
}

int
topo_set_thisproc_cpubind(topo_topology_t topology, const topo_cpuset_t *set, int strict)
{
  if (topo_cpuset_isfull(set))
    set = &topo_get_system_obj(topology)->cpuset;
  if (topology->set_cpubind)
    return topology->set_thisproc_cpubind(topology, set, strict);
  errno = ENOTSUP;
  return -1;
}

int
topo_set_thisthread_cpubind(topo_topology_t topology, const topo_cpuset_t *set, int strict)
{
  if (topo_cpuset_isfull(set))
    set = &topo_get_system_obj(topology)->cpuset;
  if (topology->set_cpubind)
    return topology->set_thisthread_cpubind(topology, set, strict);
  errno = ENOTSUP;
  return -1;
}

int
topo_set_proc_cpubind(topo_topology_t topology, topo_pid_t pid, const topo_cpuset_t *set, int strict)
{
  if (topo_cpuset_isfull(set))
    set = &topo_get_system_obj(topology)->cpuset;
  if (topology->set_cpubind)
    return topology->set_proc_cpubind(topology, pid, set, strict);
  errno = ENOTSUP;
  return -1;
}

int
topo_set_thread_cpubind(topo_topology_t topology, topo_thread_t tid, const topo_cpuset_t *set, int strict)
{
  if (topo_cpuset_isfull(set))
    set = &topo_get_system_obj(topology)->cpuset;
  if (topology->set_cpubind)
    return topology->set_thread_cpubind(topology, tid, set, strict);
  errno = ENOTSUP;
  return -1;
}

/* TODO: memory bind */

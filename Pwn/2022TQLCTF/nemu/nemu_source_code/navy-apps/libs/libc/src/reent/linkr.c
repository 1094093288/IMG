/* Reentrant versions of file system calls.  These implementations
   just call the usual system calls.  */

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

/* Some targets provides their own versions of these functions.  Those
   targets should define REENTRANT_SYSCALLS_PROVIDED in TARGET_CFLAGS.  */

#ifdef _REENT_ONLY
#ifndef REENTRANT_SYSCALLS_PROVIDED
#define REENTRANT_SYSCALLS_PROVIDED
#endif
#endif

#ifdef REENTRANT_SYSCALLS_PROVIDED

int _dummy_link_syscalls = 1;

#else

/* We use the errno variable used by the system dependent layer.  */
#undef errno
int errno;

/*
FUNCTION
	<<_link_r>>---Reentrant version of link
	
INDEX
	_link_r

ANSI_SYNOPSIS
	#include <reent.h>
	int _link_r(struct _reent *<[ptr]>,
		    const char *<[old]>, const char *<[new]>);

TRAD_SYNOPSIS
	#include <reent.h>
	int _link_r(<[ptr]>, <[old]>, <[new]>)
	struct _reent *<[ptr]>;
	char *<[old]>;
	char *<[new]>;

DESCRIPTION
	This is a reentrant version of <<link>>.  It
	takes a pointer to the global data block, which holds
	<<errno>>.
*/

int
_link_r (ptr, old, new)
     struct _reent *ptr;
     _CONST char *old;
     _CONST char *new;
{
  int ret;

  errno = 0;
  ret = _link (old, new);
  if (errno != 0)
    ptr->_errno = errno;
  return ret;
}

/*
FUNCTION
	<<_unlink_r>>---Reentrant version of unlink
	
INDEX
	_unlink_r

ANSI_SYNOPSIS
	#include <reent.h>
	int _unlink_r(struct _reent *<[ptr]>, const char *<[file]>);

TRAD_SYNOPSIS
	#include <reent.h>
	int _unlink_r(<[ptr]>, <[file]>)
	struct _reent *<[ptr]>;
	char *<[file]>;

DESCRIPTION
	This is a reentrant version of <<unlink>>.  It
	takes a pointer to the global data block, which holds
	<<errno>>.
*/

int
_unlink_r (ptr, file)
     struct _reent *ptr;
     _CONST char *file;
{
  int ret;

  errno = 0;
  ret = _unlink (file);
  if (errno != 0)
    ptr->_errno = errno;
  return ret;
}

#endif /* ! defined (REENTRANT_SYSCALLS_PROVIDED) */

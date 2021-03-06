/* Helper routines for C++ support in GDB.
   Copyright 2002, 2003 Free Software Foundation, Inc.

   Contributed by MontaVista Software.
   Namespace support contributed by David Carlton.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#ifndef CP_SUPPORT_H
#define CP_SUPPORT_H

/* We need this for 'domain_enum', alas...  */

#include "symtab.h"

/* Opaque declarations.  */

struct symbol;
struct obstack;
struct block;

/* This struct is designed to store data from using directives.  It
   says that names from namespace INNER should be visible within
   namespace OUTER.  OUTER should always be a strict initial substring
   of INNER.  These form a linked list; NEXT is the next element of
   the list.  */

struct using_direct
{
  char *inner;
  char *outer;
  struct using_direct *next;
};


/* Functions from cp-support.c.  */

extern char *class_name_from_physname (const char *physname);

extern char *method_name_from_physname (const char *physname);

extern unsigned int cp_find_first_component (const char *name);

extern unsigned int cp_entire_prefix_len (const char *name);

extern struct symbol **make_symbol_overload_list (struct symbol *);

/* Functions/variables from cp-namespace.c.  */

extern unsigned char processing_has_namespace_info;

extern const char *processing_current_namespace;

extern int cp_is_anonymous (const char *namespace);

extern void cp_add_using_directive (const char *name,
				    unsigned int outer_length,
				    unsigned int inner_length);

extern void cp_initialize_namespace (void);

extern void cp_finalize_namespace (struct block *static_block,
				   struct obstack *obstack);

extern void cp_set_block_scope (const struct symbol *symbol,
				struct block *block,
				struct obstack *obstack);

extern void cp_scan_for_anonymous_namespaces (const struct symbol *symbol);

extern struct symbol *cp_lookup_symbol_nonlocal (const char *name,
						 const char *linkage_name,
						 const struct block *block,
						 const domain_enum domain,
						 struct symtab **symtab);

extern struct symbol *cp_lookup_symbol_namespace (const char *namespace,
						  const char *name,
						  const char *linkage_name,
						  const struct block *block,
						  const domain_enum domain,
						  struct symtab **symtab);

#endif /* CP_SUPPORT_H */

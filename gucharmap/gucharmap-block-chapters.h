/* $Id$ */
/*
 * Copyright (c) 2004 Noah Levitt
 * Copyright (C) 2007 Christian Persch
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02110-1301  USA
 */

/* block means unicode block */

#ifndef GUCHARMAP_BLOCK_CHAPTERS_H
#define GUCHARMAP_BLOCK_CHAPTERS_H

#include <gucharmap/gucharmap-chapters.h>

G_BEGIN_DECLS

#define GUCHARMAP_BLOCK_CHAPTERS(obj) \
            (G_TYPE_CHECK_INSTANCE_CAST ((obj), gucharmap_block_chapters_get_type (), GucharmapBlockChapters))

#define GUCHARMAP_BLOCK_CHAPTERS_CLASS(clazz) \
            (G_TYPE_CHECK_CLASS_CAST ((clazz), gucharmap_block_chapters_get_type (), GucharmapBlockChaptersClass))

#define IS_GUCHARMAP_BLOCK_CHAPTERS(obj) \
            (G_TYPE_CHECK_INSTANCE_TYPE ((obj), gucharmap_block_chapters_get_type ()))

#define GUCHARMAP_BLOCK_CHAPTERS_GET_CLASS(obj) \
            (G_TYPE_INSTANCE_GET_CLASS ((obj), gucharmap_block_chapters_get_type (), GucharmapBlockChaptersClass))

typedef struct _GucharmapBlockChapters GucharmapBlockChapters;
typedef struct _GucharmapBlockChaptersClass GucharmapBlockChaptersClass;

struct _GucharmapBlockChapters
{
  GucharmapChapters parent;
};

struct _GucharmapBlockChaptersClass
{
  GucharmapChaptersClass parent_class;
};

GType       gucharmap_block_chapters_get_type (void);
GtkWidget * gucharmap_block_chapters_new      (void);

G_END_DECLS

#endif /* #ifndef GUCHARMAP_BLOCK_CHAPTERS_H */
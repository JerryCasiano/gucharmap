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

#if !defined (__GUCHARMAP_GUCHARMAP_H_INSIDE__) && !defined (GUCHARMAP_COMPILATION)
#error "Only <gucharmap/gucharmap.h> can be included directly."
#endif

#ifndef GUCHARMAP_TYPES_H
#define GUCHARMAP_TYPES_H

typedef struct _GucharmapWindow GucharmapWindow;
typedef struct _GucharmapWindowClass GucharmapWindowClass;

typedef struct _GucharmapSearchDialog GucharmapSearchDialog;
typedef struct _GucharmapSearchDialogClass GucharmapSearchDialogClass;

typedef struct _GucharmapScriptCodepointList GucharmapScriptCodepointList;
typedef struct _GucharmapScriptCodepointListClass GucharmapScriptCodepointListClass;

typedef struct _GucharmapScriptChaptersModel GucharmapScriptChaptersModel;
typedef struct _GucharmapScriptChaptersModelClass GucharmapScriptChaptersModelClass;

typedef struct _GucharmapMiniFontSelection GucharmapMiniFontSelection;
typedef struct _GucharmapMiniFontSelectionClass GucharmapMiniFontSelectionClass;

typedef struct _GucharmapCodepointList GucharmapCodepointList;
typedef struct _GucharmapCodepointListClass GucharmapCodepointListClass;

typedef struct _GucharmapChartable GucharmapChartable;
typedef struct _GucharmapChartableClass GucharmapChartableClass;

typedef struct _GucharmapCharmap GucharmapCharmap;
typedef struct _GucharmapCharmapClass GucharmapCharmapClass;

typedef struct _GucharmapChaptersView GucharmapChaptersView;
typedef struct _GucharmapChaptersViewClass GucharmapChaptersViewClass;

typedef struct _GucharmapChaptersModel GucharmapChaptersModel;
typedef struct _GucharmapChaptersModelClass GucharmapChaptersModelClass;

typedef struct _GucharmapBlockChaptersModel GucharmapBlockChaptersModel;
typedef struct _GucharmapBlockChaptersModelClass GucharmapBlockChaptersModelClass;

#endif /* GUCHARMAP_TYPES_H */
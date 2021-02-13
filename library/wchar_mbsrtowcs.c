/*
 * Copyright (C) 2021 ixemul.library contributors
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#ifndef _WCHAR_HEADERS_H
#include "wchar_headers.h"
#endif /* _WCHAR_HEADERS_H */

/****************************************************************************/

size_t
mbsrtowcs(wchar_t *p, const char **sp, size_t n, mbstate_t *ps)
{
	const char* s = *sp;
	size_t r = 0;

	if (p == NULL)
	{
		n = (size_t) -1;
	}

	while (r < n)
	{
		wchar_t c;
		size_t t = mbrtowc(&c, s, (size_t) -1, NULL);

		if (t == (size_t) -1)
		{
			r = t;
			break;
		}


		if (p)
		{
			*p++ = c;
		}

		if (c == 0)
		{
			if (p)
			{
				s = NULL;
			}

			break;
		}

		++r;
		s += t;
	}

	*sp = s;

	return r;
}

/*
 * Conquest of Levidon
 * Copyright (C) 2018  Martin Kunev <martinkunev@gmail.com>
 *
 * This file is part of Conquest of Levidon.
 *
 * Conquest of Levidon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation version 3 of the License.
 *
 * Conquest of Levidon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Conquest of Levidon.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <unistd.h>

#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_ERROR 3
#define LOG_LEVEL_FATAL 4

#define LOG_LEVEL_ALL 0
#define LOG_LEVEL_NONE 5

#define LOG_REDBG "\x1b[0;41m"
#define LOG_RED "\x1b[31m"
#define LOG_YELLOW "\x1b[33m"
//#define LOG_BLUE(s) "\x1b[34m" s "\x1b[0m"
//#define LOG_GREEN(s) "\x1b[32m" s "\x1b[0m"
#define LOG_BLANK "\x1b[0m"

#define LOG_STRING_EXPAND(token) #token
#define LOG_STRING(token) LOG_STRING_EXPAND(token)

#if !defined(LOG_LEVEL)
# if defined(NDEBUG)
#  define LOG_LEVEL LOG_LEVEL_INFO
# else
#  define LOG_LEVEL LOG_LEVEL_DEBUG
# endif
#endif

// WARNING: Format must be string literal. This is indicated as comment for define to get a better compile error message.
// Ensure compilation fails when format is not a string literal even if log is inactive due to LOG_LEVEL.

#define LOG(prefix, suffix, format, ...) ((sizeof(#__VA_ARGS__) == 1) ? write(2, prefix format suffix, sizeof(prefix format suffix) - 1) : fprintf(stderr, prefix format suffix, __VA_ARGS__))

// TODO get rid of the 0 after __VA_ARGS__

#if (LOG_LEVEL <= LOG_LEVEL_DEBUG)
# define LOG_DEBUG(...) "" __VA_ARGS__, LOG(__FILE__ ":" LOG_STRING(__LINE__) " ", "\n", __VA_ARGS__, 0) /* format must be a string literal */
#else
# define LOG_DEBUG(...) (void)("" __VA_ARGS__) /* format must be a string literal */
#endif

#if (LOG_LEVEL <= LOG_LEVEL_INFO)
# define LOG_INFO(...) "" __VA_ARGS__, LOG(__FILE__ ":" LOG_STRING(__LINE__) " ", "\n", __VA_ARGS__, 0) /* format must be a string literal */
#else
# define LOG_INFO(...) (void)("" __VA_ARGS__) /* format must be a string literal */
#endif

#if (LOG_LEVEL <= LOG_LEVEL_WARNING)
# define LOG_WARNING(...) "" __VA_ARGS__, LOG(__FILE__ ":" LOG_STRING(__LINE__) " " LOG_YELLOW, LOG_BLANK "\n", __VA_ARGS__, 0) /* format must be a string literal */
#else
# define LOG_WARNING(...) (void)("" __VA_ARGS__) /* format must be a string literal */
#endif

#if (LOG_LEVEL <= LOG_LEVEL_ERROR)
# define LOG_ERROR(...) "" __VA_ARGS__, LOG(__FILE__ ":" LOG_STRING(__LINE__) " " LOG_RED, LOG_BLANK "\n", __VA_ARGS__, 0) /* format must be a string literal */
#else
# define LOG_ERROR(...) (void)("" __VA_ARGS__) /* format must be a string literal */
#endif

#if (LOG_LEVEL <= LOG_LEVEL_FATAL)
# define LOG_FATAL(...) "" __VA_ARGS__, LOG(__FILE__ ":" LOG_STRING(__LINE__) " " LOG_REDBG, LOG_BLANK "\n", __VA_ARGS__, 0) /* format must be a string literal */
#else
# define LOG_FATAL(...) (void)("" __VA_ARGS__) /* format must be a string literal */
#endif

/*
TODO: do I need this?
	When debugging is enabled, log level is determined at runtime. When debugging is disabled (NDEBUG), log level is determined at compile time.

fatal       A non-recoverable error has been encountered. Somebody has to react immediately.
error       A recoverable error has be encountered.
warning     Something unexpected happened, but it was handled.
info        Information about what is happening in the program.
debug       Information about execution useful only for debugging.

examples:
	debug:
		"calling file_open()"
	info:
		"http_get() returned 200"
	warning:
		"invalid request received"
	error:
		"cannot get list of proxies"
	fatal:
		"distribute server down"
*/

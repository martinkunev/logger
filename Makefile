CFLAGS=-std=c99 -pedantic

debug:
	$(CC) $(CFLAGS) log.c -o log

info:
	$(CC) $(CFLAGS) -DNDEBUG -DLOG_LEVEL=LOG_LEVEL_INFO log.c -o log

warning:
	$(CC) $(CFLAGS) -DNDEBUG -DLOG_LEVEL=LOG_LEVEL_WARNING log.c -o log

error:
	$(CC) $(CFLAGS) -DNDEBUG -DLOG_LEVEL=LOG_LEVEL_ERROR log.c -o log

fatal:
	$(CC) $(CFLAGS) -DNDEBUG -DLOG_LEVEL=LOG_LEVEL_FATAL log.c -o log

release:
	$(CC) $(CFLAGS) -DNDEBUG log.c -o log

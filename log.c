// By default, LOG_LEVEL is LOG_LEVEL_INFO (when NDEBUG is defined) or LOG_LEVEL_DEBUG (when NDEBUG is not defined).
// Uncomment macro to set custom log level. Make sure the macro is defined above the include.
// Alternatively, you can add `-DLOG_LEVEL=LOG_LEVEL_WARNING` to compiler flags.
// #define LOG_LEVEL LOG_LEVEL_WARNING

#include "log.h"

int main(void) {
	LOG_FATAL("The earth has stopped spinning! We need help from a human!");
	LOG_ERROR("My hat is on fire!");
	LOG_WARNING("What happened shouldn't happen, but I can handle it.");
	LOG_INFO("Just doin' my stuff.");
	LOG_DEBUG("All your %s are belong to us.", "debugs");

	return 0;
}

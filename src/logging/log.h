#ifndef LOGGING_LOG_H_
#define LOGGING_LOG_H_

/**
 * Logging interface.
 * \author cpieloth
 */

/**
 * Initializes the logger, e.g. opens a file stream.
 */
void log_init();

/**
 * Closes the logger, e.g. closes a file stream.
 */
void log_close();

/**
 * Logs an error messages.
 *
 * \param src Source of the message, e.g. module or method.
 * \param msg Message to log.
 */
void log_error(const char* src, const char *msg, ...);

/**
 * Logs a warning.
 *
 * \param src Source of the message, e.g. module or method.
 * \param msg Message to log.
 */
void log_warn(const char* src, const char *msg, ...);

/**
 * Logs an info messages.
 *
 * \param src Source of the message, e.g. module or method.
 * \param msg Message to log.
 */
void log_info(const char* src, const char *msg, ...);

/**
 * Logs a debug message.
 *
 * \param src Source of the message, e.g. module or method.
 * \param msg Message to log.
 */
void log_debug(const char* src, const char *msg, ...);

#endif /* LOGGING_LOG_H_ */

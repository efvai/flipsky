/*
 * CO_domain_STM32.h
 *
 *  Created on: Jun 8, 2024
 *      Author: jkcvk
 */

#ifndef CO_DOMAIN_STM32_H_
#define CO_DOMAIN_STM32_H_

#include "301/CO_ODinterface.h"

ODR_t OD_writeDomain(OD_stream_t *stream, const void *buf,
                       OD_size_t count, OD_size_t *countWritten);

#endif /* CO_DOMAIN_STM32_H_ */

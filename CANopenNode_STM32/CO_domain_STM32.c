/*
 * CO_domain_STM32.c
 *
 *  Created on: Jun 8, 2024
 *      Author: jkcvk
 */

#include "CO_domain_STM32.h"

//((()))
ODR_t OD_writeDomain(OD_stream_t *stream, const void *buf,
                       OD_size_t count, OD_size_t *countWritten) { // countWritten - total size

  static OD_size_t written = 0;
  OD_size_t total_size_ind = *countWritten;

  if (count > 0) {

    uint8_t data = 0x0;
    for (int i = 0; i < count; i++) {
      data = ((uint8_t*) buf)[i];
    }

  }

  written += count;
  if (written < total_size_ind) {
    return ODR_PARTIAL;
  } else {
    written = 0;
    return ODR_OK;
  }

}

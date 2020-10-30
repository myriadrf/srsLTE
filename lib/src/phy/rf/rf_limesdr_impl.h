/*
 * Copyright 2013-2020 Software Radio Systems Limited
 *
 * This file is part of srsLTE.
 *
 * srsLTE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsLTE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#ifndef SRSLTE_RF_LIME_IMP_H_
#define SRSLTE_RF_LIME_IMP_H_

#include "srslte/config.h"
#include "srslte/phy/rf/rf.h"
#include <stdbool.h>
#include <stdint.h>

#define DEVNAME_USB "LimeSDR-USB"
#define DEVNAME_MINI "LimeSDR-Mini"
#define DEVNAME_CC "LimeSDR-Core"

SRSLTE_API int rf_lime_open(char* args, void** handler);

SRSLTE_API int rf_lime_open_multi(char* args, void** handler, uint32_t num_requested_channels);

SRSLTE_API const char* rf_lime_devname(void* h);

SRSLTE_API int rf_lime_close(void* h);

SRSLTE_API int rf_lime_start_rx_stream(void* h, bool now);

SRSLTE_API int rf_lime_stop_rx_stream(void* h);

SRSLTE_API void rf_lime_calibrate_tx(void* h);

SRSLTE_API void rf_lime_flush_buffer(void* h);

SRSLTE_API bool rf_lime_has_rssi(void* h);

SRSLTE_API float rf_lime_get_rssi(void* h);

SRSLTE_API void rf_lime_set_master_clock_rate(void* h, double rate);

SRSLTE_API double rf_lime_set_rx_srate(void* h, double freq);

SRSLTE_API int rf_lime_set_rx_gain(void* h, double gain);

SRSLTE_API int rf_lime_set_rx_gain_ch(void* h, uint32_t ch, double gain);

SRSLTE_API double rf_lime_get_rx_gain(void* h);

SRSLTE_API int rf_lime_set_tx_gain(void* h, double gain);

SRSLTE_API int rf_lime_set_tx_gain_ch(void* h, uint32_t ch, double gain);

SRSLTE_API double rf_lime_get_tx_gain(void* h);

SRSLTE_API srslte_rf_info_t* rf_lime_get_info(void* h);

SRSLTE_API void rf_lime_suppress_stdout(void* h);

SRSLTE_API void rf_lime_register_error_handler(void* h, srslte_rf_error_handler_t error_handler, void* arg);

SRSLTE_API double rf_lime_set_rx_freq(void* h, uint32_t ch, double freq);

SRSLTE_API int
rf_lime_recv_with_time(void* h, void* data, uint32_t nsamples, bool blocking, time_t* secs, double* frac_secs);

SRSLTE_API int
rf_lime_recv_with_time_multi(void* h, void** data, uint32_t nsamples, bool blocking, time_t* secs, double* frac_secs);

SRSLTE_API double rf_lime_set_tx_srate(void* h, double freq);

SRSLTE_API double rf_lime_set_tx_freq(void* h, uint32_t ch, double freq);

SRSLTE_API void rf_lime_get_time(void* h, time_t* secs, double* frac_secs);

SRSLTE_API int rf_lime_send_timed(void*  h,
                                  void*  data,
                                  int    nsamples,
                                  time_t secs,
                                  double frac_secs,
                                  bool   has_time_spec,
                                  bool   blocking,
                                  bool   is_start_of_burst,
                                  bool   is_end_of_burst);

int rf_lime_send_timed_multi(void*  h,
                             void*  data[4],
                             int    nsamples,
                             time_t secs,
                             double frac_secs,
                             bool   has_time_spec,
                             bool   blocking,
                             bool   is_start_of_burst,
                             bool   is_end_of_burst);

#endif /* SRSLTE_RF_LIME_IMP_H_ */

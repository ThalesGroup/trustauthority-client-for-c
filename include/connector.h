/*
 * Copyright (C) 2023 Intel Corporation
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

	/**
	 * Create a new trust authority connector client to make REST calls to Intel Trust Authority
	 * @param api_key a char pointer containing Intel Trust Authority api key
	 * @param api_url a char pointer containing Intel Trust Authority url
	 * @param retry_max integer containing maximum number of retries
	 * @param retry_wait_time integer containing wait time between retries
	 * @return return status
	 */
	TRUST_AUTHORITY_STATUS trust_authority_connector_new(trust_authority_connector **connector,
			const char *api_key,
			const char *api_url,
			const int retry_max,
			const int retry_wait_time);

	/**
	 * Get a nonce from Intel Trust Authority.
	 * @param connector instance to connect to Intel Trust Authority
	 * @param nonce nonce value returned by Intel Trust Authority
	 * @param request_id id to uniquely identify the request
	 * @param resp_header a char pointer containing response headers returned from Intel Trust Authority 
	 * @return return status
	 */
	TRUST_AUTHORITY_STATUS get_nonce(trust_authority_connector *connector,
			nonce *nonce,
			const char *request_id,
			response_headers *resp_header);

	/**
	 * Get a token from Intel Trust Authority by providing evidence and nonce as input
	 * @param connector a trust_authority_connector pointer
	 * @param resp_header a char pointer containing response headers returned from Intel Trust Authority
	 * @param token token returned from Intel Trust Authority
	 * @param policies policy id created in Intel Trust Authority passed here to be used
	 * @param evidence quote generated
	 * @param nonce nonce value returned by Intel Trust Authority
	 * @param request_id id to uniquely identify the request
	 * @param attestation_url url to be used for attestation
	 * @return return status
	 */
	TRUST_AUTHORITY_STATUS get_token(trust_authority_connector *connector,
			response_headers *resp_headers,
			token *token,
			policies *policies,
			evidence *evidence,
			nonce *nonce,
			const char *request_id,
			char *attestation_url);

	/**
	 * Get a token signing certificate from Intel Trust Authority.
	 * @param tokensigncerturl Intel Trust Authority URL
	 * @param jwks jwks signing certificate recieved from Intel Trust Authority
	 * @param retry_max integer containing maximum number of retries
	 * @param retry_wait_time integer containing wait time between retries
	 * @return return status
	 */
	TRUST_AUTHORITY_STATUS get_token_signing_certificate(const char *tokensigncerturl,
			char **jwks,
			const int retry_max,
			const int retry_wait_time);

	// Delete/free trust_authority_connector
	TRUST_AUTHORITY_STATUS connector_free(trust_authority_connector *connector);

	// Delete/free token.
	TRUST_AUTHORITY_STATUS token_free(token *token);

	// Delete/free evidence.
	TRUST_AUTHORITY_STATUS evidence_free(evidence *evidence);

	// Delete/free nonce.
	TRUST_AUTHORITY_STATUS nonce_free(nonce *nonce);

	// Delete/free response_headers
	TRUST_AUTHORITY_STATUS response_headers_free(response_headers *header);

	// Delete/free jwks.
	TRUST_AUTHORITY_STATUS jwks_free(jwks *jwks);

#ifdef __cplusplus
}
#endif
#endif

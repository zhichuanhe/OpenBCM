/*
 * 
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2019 Broadcom Inc. All rights reserved.
 * 
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 */

#ifndef __BCM_SRV6_H__
#define __BCM_SRV6_H__

#include <bcm/types.h>

/* SRv6 SID initiator flags */
#define BCM_SRV6_SID_INITIATOR_WITH_ID  (1 << 0)   /* if set, the tunnel_id will
                                                      be given by user as input,
                                                      otherwise output from
                                                      alloc_manager */
#define BCM_SRV6_SID_INITIATOR_REPLACE  (1 << 1)   /* Replace existing entry,
                                                      update existing Tunnel */

/* SRv6 SRH base initiator flags */
#define BCM_SRV6_SRH_BASE_INITIATOR_WITH_ID (1 << 0)   /* if set, the tunnel_id
                                                          will be given by user
                                                          as input, otherwise
                                                          output from
                                                          alloc_manager */
#define BCM_SRV6_SRH_BASE_INITIATOR_REPLACE (1 << 1)   /* Replace existing
                                                          entry, update existing
                                                          Tunnel */
#define BCM_SRV6_SRH_BASE_INITIATOR_STAT_ENABLE (1 << 2)   /* if set, SRv6 SRH Base
                                                          supports statistics */

/* SRv6 terminator next protocol mapping flags */
#define BCM_SRV6_TERMINATOR_NEXT_PROTOCOL_REPLACE (1 << 0)   /* Replace existing entry */

/* 
 * Structure that is used in SRv6 SID initiator APIs, for managing device
 * behavior at SRv6 Tunnel Encapsulation
 */
typedef struct bcm_srv6_sid_initiator_info_s {
    uint32 flags;                       /* BCM_SRV6_SID_INITIATOR_XXX */
    bcm_gport_t tunnel_id;              /* Tunnel SRv6 SID initiator object ID */
    bcm_ip6_t sid;                      /* SID to encapsulate */
    bcm_encap_access_t encap_access;    /* Encapsulation Access stage */
    bcm_if_t next_encap_id;             /* Next pointer interface ID, can be
                                           next SID initiator or
                                           next-encapsulation interface */
} bcm_srv6_sid_initiator_info_t;

/* 
 * Structure that is used in SRv6 SRH Base initiator APIs, for managing
 * device behavior at SRv6 Tunnel Encapsulation
 */
typedef struct bcm_srv6_srh_base_initiator_info_s {
    uint32 flags;                       /* BCM_SRV6_SRH_BASE_INITIATOR_XXX */
    bcm_gport_t tunnel_id;              /* Tunnel SRv6 SRH base object ID */
    int nof_sids;                       /* Number of SIDs in the SID list */
    int qos_map_id;                     /* QOS map identifier */
    int ttl;                            /* Tunnel header TTL */
    int dscp;                           /* Tunnel header DSCP value */
    bcm_qos_egress_model_t egress_qos_model; /* Egress qos and ttl model */
    bcm_if_t next_encap_id;             /* Next encapsulation ID */
} bcm_srv6_srh_base_initiator_info_t;

/* Structure for additional info for SRv6 SID initiator traverse */
typedef struct bcm_srv6_sid_initiator_traverse_info_s {
    uint32 flags;           /* BCM_SRV6_SID_INITIATOR_XXX */
    uint32 traverse_flags;  /* BCM_SRV6_SID_INITIATOR_TRAVERSE_XXX */
} bcm_srv6_sid_initiator_traverse_info_t;

/* Structure for additional info for SRv6 SID initiator traverse */
typedef struct bcm_srv6_srh_base_initiator_traverse_info_s {
    uint32 flags;           /* BCM_SRV6_SRH_BASE_INITIATOR_XXX */
    uint32 traverse_flags;  /* BCM_SRV6_SRH_BASE_INITIATOR_TRAVERSE_XXX */
} bcm_srv6_srh_base_initiator_traverse_info_t;

/* 
 * Structure that is used in SRv6 terminator next protocol APIs. Relevant
 * in 2-pass ESR USP case only.
 */
typedef struct bcm_srv6_terminator_next_protocol_mapping_s {
    uint32 flags;           /* BCM_SRV6_TERMINATOR_NEXT_PROTOCOL_XXX */
    int next_protocol;      /* Protocol above SRv6 */
    bcm_gport_t encap_id;   /* Encapsulation id */
    bcm_gport_t port;       /* Gport destination */
} bcm_srv6_terminator_next_protocol_mapping_t;

/* 
 * Structure for additional info for terminator next protocol mapping
 * traverse
 */
typedef struct bcm_srv6_terminator_next_protocol_traverse_info_s {
    uint32 flags;           /* BCM_SRV6_TERMINATOR_NEXT_PROTOCOL_XXX */
    uint32 traverse_flags;  /* BCM_SRV6_TERMINATOR_NEXT_PROTOCOL_TRAVERSE_XXX */
} bcm_srv6_terminator_next_protocol_traverse_info_t;

#ifndef BCM_HIDE_DISPATCHABLE

/* 
 * Function links SIDs or other objects (such as IPv6) as linked list
 * entries
 *                 int unit [input] - device id
 *                 bcm_srv6_sid_initiator_info_t info [input/output] -
 * structure which describes the SID list object settings
 */
extern int bcm_srv6_sid_initiator_create(
    int unit, 
    bcm_srv6_sid_initiator_info_t *info);

/* 
 * Function gets the SID list object properties
 *                 int unit [input] - device id
 *                 bcm_srv6_sid_initiator_info_t info [output] -
 * structure which describes the SID list object settings
 */
extern int bcm_srv6_sid_initiator_get(
    int unit, 
    bcm_srv6_sid_initiator_info_t *info);

/* 
 * Function deletes the SID list association to the given Tunnel_Id
 *                 int unit [input] - device id
 *                 bcm_srv6_sid_initiator_info_t info [input] - structure
 * which describes the SID list object settings
 */
extern int bcm_srv6_sid_initiator_delete(
    int unit, 
    bcm_srv6_sid_initiator_info_t *info);

#endif /* BCM_HIDE_DISPATCHABLE */

/* Srv6 callback function prototype */
typedef int (*bcm_srv6_sid_initiator_traverse_cb)(
    int unit, 
    bcm_srv6_sid_initiator_info_t *info, 
    void *user_data);

#ifndef BCM_HIDE_DISPATCHABLE

/* 
 * Function traverses all tunnel_ids, that were allocated and runs a
 * callback function provided by the user on this data, along with
 * user_data.
 */
extern int bcm_srv6_sid_initiator_traverse(
    int unit, 
    bcm_srv6_sid_initiator_traverse_info_t additional_info, 
    bcm_srv6_sid_initiator_traverse_cb cb, 
    void *user_data);

/* Function creates an SRv6 SRH Base with an optional link to last SID */
extern int bcm_srv6_srh_base_initiator_create(
    int unit, 
    bcm_srv6_srh_base_initiator_info_t *info);

/* Function gets the SRv6 SRH Base properties */
extern int bcm_srv6_srh_base_initiator_get(
    int unit, 
    bcm_srv6_srh_base_initiator_info_t *info);

/* Function deletes the SRv6 SRH Base and optionally last SID association */
extern int bcm_srv6_srh_base_initiator_delete(
    int unit, 
    bcm_srv6_srh_base_initiator_info_t *info);

#endif /* BCM_HIDE_DISPATCHABLE */

/* Srv6 callback function prototype */
typedef int (*bcm_srv6_srh_base_initiator_traverse_cb)(
    int unit, 
    bcm_srv6_srh_base_initiator_info_t *info, 
    void *user_data);

#ifndef BCM_HIDE_DISPATCHABLE

/* 
 * Function traverses all tunnel_ids, that were allocated to SRv6 Tunnels
 * and runs a callback function provided by the user on this data, along
 * with user_data.
 */
extern int bcm_srv6_srh_base_initiator_traverse(
    int unit, 
    bcm_srv6_srh_base_initiator_traverse_info_t additional_info, 
    bcm_srv6_srh_base_initiator_traverse_cb cb, 
    void *user_data);

/* 
 * Creation and configuration of a Next Protocol (above SRv6) mapping to
 * port and Encapsulation for 2nd Pass ESR USP
 */
extern int bcm_srv6_terminator_next_protocol_add(
    int unit, 
    bcm_srv6_terminator_next_protocol_mapping_t *info);

/* 
 * Function returns the port and encap_id, that were mapped by the
 * next_protocol (above SRv6 layer)
 */
extern int bcm_srv6_terminator_next_protocol_get(
    int unit, 
    bcm_srv6_terminator_next_protocol_mapping_t *info);

/* 
 * Function deletes the port and encap_id that were mapped by the
 * next_protocol (above SRv6 layer)
 */
extern int bcm_srv6_terminator_next_protocol_delete(
    int unit, 
    bcm_srv6_terminator_next_protocol_mapping_t *info);

#endif /* BCM_HIDE_DISPATCHABLE */

/* Srv6 user call back function */
typedef int (*bcm_srv6_terminator_next_protocol_traverse_cb)(
    int unit, 
    bcm_srv6_terminator_next_protocol_mapping_t *info, 
    void *user_data);

#ifndef BCM_HIDE_DISPATCHABLE

/* 
 * Function traverses all next_protocols mappings and runs a callback
 * function provided by the user on this data, along with user_data.
 */
extern int bcm_srv6_terminator_next_protocol_traverse(
    int unit, 
    bcm_srv6_terminator_next_protocol_traverse_info_t additional_info, 
    bcm_srv6_terminator_next_protocol_traverse_cb cb, 
    void *user_data);

#endif /* BCM_HIDE_DISPATCHABLE */

/* Initialize a bcm_srv6_srh_base_initiator_info_t structure. */
extern void bcm_srv6_srh_base_initiator_info_t_init(
    bcm_srv6_srh_base_initiator_info_t *info);

/* Initialize a bcm_srv6_sid_initiator_info_t structure. */
extern void bcm_srv6_sid_initiator_info_t_init(
    bcm_srv6_sid_initiator_info_t *info);

/* Initialize a bcm_srv6_terminator_next_protocol_mapping_t structure. */
extern void bcm_srv6_terminator_next_protocol_mapping_t_init(
    bcm_srv6_terminator_next_protocol_mapping_t *info);

#endif /* __BCM_SRV6_H__ */
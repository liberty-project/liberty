// Copyright (c) 2014-2018, The Monero Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <string>
#include <boost/uuid/uuid.hpp>

#define CRYPTONOTE_DNS_TIMEOUT_MS                       20000

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     500000000
#define CRYPTONOTE_MAX_BLOCK_SIZE                       500000000  // block header blob limit, never used!
#define CRYPTONOTE_GETBLOCKTEMPLATE_MAX_BLOCK_SIZE	196608 //size of block (bytes) that is the maximum that miners will produce
#define CRYPTONOTE_MAX_TX_SIZE                          1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER          0
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            30
#define CURRENT_TRANSACTION_VERSION                     2
#define CURRENT_BLOCK_MAJOR_VERSION                     1
#define CURRENT_BLOCK_MINOR_VERSION                     0
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V2           60*10
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE             10

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               11

// MONEY_SUPPLY - total number coins to be generated
#define MONEY_SUPPLY                                    ((uint64_t)(-1))
#define EMISSION_SPEED_FACTOR_PER_MINUTE                (20)

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    60000 //size of block (bytes) after which reward for block calculated using block size
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1    20000 //size of block (bytes) after which reward for block calculated using block size - before first fork
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5    300000 //size of block (bytes) after which reward for block calculated using block size - second change, from v5
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                12
// COIN - number of smallest units in one coin
#define COIN                                            ((uint64_t)1000000000000) // pow(10, 12)

#define FEE_PER_KB_OLD                                  ((uint64_t)10000000000) // pow(10, 10)
#define FEE_PER_KB                                      ((uint64_t)2000000000) // 2 * pow(10, 9)
#define DYNAMIC_FEE_PER_KB_BASE_FEE                     ((uint64_t)2000000000) // 2 * pow(10,9)
#define DYNAMIC_FEE_PER_KB_BASE_BLOCK_REWARD            ((uint64_t)10000000000000) // 10 * pow(10,12)
#define DYNAMIC_FEE_PER_KB_BASE_FEE_V5                  ((uint64_t)2000000000 * (uint64_t)CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2 / CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5)

#define ORPHANED_BLOCKS_MAX_COUNT                       100


#define DIFFICULTY_TARGET_V2                            120  // seconds
#define DIFFICULTY_WINDOW_V2                            60
#define DIFFICULTY_LAG                                  15  // !!!
#define DIFFICULTY_CUT                                  60  // timestamps to cut after sorting
#define DIFFICULTY_BLOCKS_COUNT_V2                      (DIFFICULTY_WINDOW_V2 + 1) // added +1 to make N=N


#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V2   DIFFICULTY_TARGET_V2 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1


#define DIFFICULTY_BLOCKS_ESTIMATE_TIMESPAN             DIFFICULTY_TARGET_V2 //just alias; used by tests


#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000  //by default, blocks ids count in synchronizing
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT_PRE_V4       100    //by default, blocks count in blocks downloading
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              20     //by default, blocks count in blocks downloading

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                    (86400*3) //seconds, three days
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME     604800 //seconds, one week

#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT           1000

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_DEFAULT_CONNECTIONS_COUNT                   8
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60           //secondes
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000     //50000000 bytes maximum packet size
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000       //5 seconds
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000       //2 seconds
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60*2*1000  //2 minutes
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000       //5 seconds
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_ANCHOR_CONNECTIONS_COUNT            2

#define P2P_FAILED_ADDR_FORGET_SECONDS                  (60*60)     //1 hour
#define P2P_IP_BLOCKTIME                                (60*60*24)  //24 hour
#define P2P_IP_FAILS_BEFORE_BLOCK                       10
#define P2P_IDLE_CONNECTION_KILL_INTERVAL               (5*60) //5 minutes

#define P2P_SUPPORT_FLAG_FLUFFY_BLOCKS                  0x01
#define P2P_SUPPORT_FLAGS                               P2P_SUPPORT_FLAG_FLUFFY_BLOCKS

#define ALLOW_DEBUG_COMMANDS

#define CRYPTONOTE_NAME                         "naos"
#define CRYPTONOTE_POOLDATA_FILENAME            "poolstate.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME      "data.mdb"
#define CRYPTONOTE_BLOCKCHAINDATA_LOCK_FILENAME "lock.mdb"
#define P2P_NET_DATA_FILENAME                   "p2pstate.bin"
#define MINER_CONFIG_FILE_NAME                  "miner_conf.json"

#define THREAD_STACK_SIZE                       5 * 1024 * 1024

#define HF_VERSION_DYNAMIC_FEE                  4
#define HF_VERSION_MIN_MIXIN_9                  7
#define HF_VERSION_ENFORCE_RCT                  6

#define PER_KB_FEE_QUANTIZATION_DECIMALS        8

#define HASH_OF_HASHES_STEP                     256

#define DEFAULT_TXPOOL_MAX_SIZE                 648000000ull // 3 days at 300000, in bytes

// New constants are intended to go here
namespace config
{
  uint64_t const DEFAULT_FEE_ATOMIC_XMR_PER_KB = 500; // Just a placeholder!  Change me!
  uint8_t const FEE_CALCULATION_MAX_RETRIES = 10;
  uint64_t const DEFAULT_DUST_THRESHOLD = ((uint64_t)2000000000); // 2 * pow(10, 9)
  uint64_t const BASE_REWARD_CLAMP_THRESHOLD = ((uint64_t)100000000); // pow(10, 8)
  std::string const P2P_REMOTE_DEBUG_TRUSTED_PUB_KEY = "0000000000000000000000000000000000000000000000000000000000000000";

  uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 31;
  uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 115;
  uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 116;
  uint16_t const P2P_DEFAULT_PORT = 41441;
  uint16_t const RPC_DEFAULT_PORT = 41442;
  uint16_t const ZMQ_RPC_DEFAULT_PORT = 41443;
  boost::uuids::uuid const NETWORK_ID = { {
		0x32, 0xeb, 0xaa, 0x30, 0x65, 0xcd, 0xf1, 0x6a, 0x40, 0xfe, 0x1d, 0x89, 0x41, 0xb6, 0xeb, 0x08
    } }; // Bender's nightmare
  std::string const GENESIS_TX = "011e01ff0006ffbfb6b101029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807180d0acf30e022a74a3c4c36d32e95633d44ba9a7b8188297b2ac91afecab826b86fabaa7091680c0fc82aa020252d128bc9913d5ee8b702c37609917c2357b2f587e5de5622348a3acd718e5d680d0dbc3f40202b8ed916c56b3a99c9cdf22c7be7ec4e85587e5d40bc46bf6995313c288ad841e80a0e5b9c29101021b452b4ac6c6419e06181f8c9f0734bd5bb132d8b75b44bbcd07dd8f553acba680c0dfda8ee90602b10ba13e303cbe9abf7d5d44f1d417727abcc14903a74e071abd652ce1bf76dd2101383b9e3288fc7bfd6ec86516b576b5c6f47154d22a000c190c7d9b933a88c9ab";
  uint32_t const GENESIS_NONCE = 100000;

  std::string const GOVERNANCE_WALLET_ADDRESS = "6EpyWYuY1WTJGpPSttYAC4AJgxpwFiQpfEbpJCTZ3af2KNiiNzSBurSLnUTRebnHnqhS1LsR1pBmkCqfTzDHCyS2MG27hRy";
  
  namespace testnet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 53;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 157;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 158;
    uint16_t const P2P_DEFAULT_PORT = 42441;
    uint16_t const RPC_DEFAULT_PORT = 42442;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 42443;
    boost::uuids::uuid const NETWORK_ID = { {
		0xd3, 0x32, 0x2b, 0xea, 0xe1, 0xe7, 0xe6, 0xc5, 0x9a, 0x49, 0x68, 0x85, 0xa2, 0x72, 0xac, 0xeb
      } }; // Bender's daydream
    std::string const GENESIS_TX = "011e01ff0006ffbfb6b101029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807180d0acf30e022a74a3c4c36d32e95633d44ba9a7b8188297b2ac91afecab826b86fabaa7091680c0fc82aa020252d128bc9913d5ee8b702c37609917c2357b2f587e5de5622348a3acd718e5d680d0dbc3f40202b8ed916c56b3a99c9cdf22c7be7ec4e85587e5d40bc46bf6995313c288ad841e80a0e5b9c29101021b452b4ac6c6419e06181f8c9f0734bd5bb132d8b75b44bbcd07dd8f553acba680c0dfda8ee90602b10ba13e303cbe9abf7d5d44f1d417727abcc14903a74e071abd652ce1bf76dd210110ce4255920782dd085cb1c0c030488149f54434175dab7266e997413491e856";
    uint32_t const GENESIS_NONCE = 10000;

    std::string const GOVERNANCE_WALLET_ADDRESS = "9upVu3NhwSUPJ4HuZoWJRgEzMb4EfXp31LvDfJAe1vj79zoHAg2CC3oTwFg7ZNnk2cTGGoqT9mzRSQHRuUuReRiiL26SDZb";
  }

  namespace stagenet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 71;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 25;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 36;
    uint16_t const P2P_DEFAULT_PORT = 43441;
    uint16_t const RPC_DEFAULT_PORT = 43442;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 43443;
    boost::uuids::uuid const NETWORK_ID = { {
		0x9C, 0x45, 0xb2, 0x42, 0xf1, 0x2e, 0x74, 0x76, 0xd4, 0x1a, 0xa9, 0x19, 0x5b, 0x48, 0x6b, 0xdd
      } }; // Beep Boop
    std::string const GENESIS_TX = "011e01ff0006ffbfb6b101029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807180d0acf30e022a74a3c4c36d32e95633d44ba9a7b8188297b2ac91afecab826b86fabaa7091680c0fc82aa020252d128bc9913d5ee8b702c37609917c2357b2f587e5de5622348a3acd718e5d680d0dbc3f40202b8ed916c56b3a99c9cdf22c7be7ec4e85587e5d40bc46bf6995313c288ad841e80a0e5b9c29101021b452b4ac6c6419e06181f8c9f0734bd5bb132d8b75b44bbcd07dd8f553acba680c0dfda8ee90602b10ba13e303cbe9abf7d5d44f1d417727abcc14903a74e071abd652ce1bf76dd2101e0f90fbd48df778c2edd95fd3b6fdbdb4344879e6c394852ad4302fbe85c0ec9";
    uint32_t const GENESIS_NONCE = 10000;

    std::string const GOVERNANCE_WALLET_ADDRESS = "CxFo1xZu7ckaUsGG3yTRuuXXFpVyDjFvZemrK8mMdhkiRkSDPwUKghgdYhY15VBbDXhRNYwCdcpxierFLZutmxWTLq3ZHFB";
  }
}

namespace cryptonote
{
  enum network_type : uint8_t
  {
    MAINNET = 0,
    TESTNET,
    STAGENET,
    FAKECHAIN,
    UNDEFINED = 255
  };
}

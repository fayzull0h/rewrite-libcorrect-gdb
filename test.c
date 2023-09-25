#include "obc_gs_fec.h"
#include "obc_gs_errors.h"

#include <string.h>
#include <stdio.h>

void ASSERT_EQ(obc_gs_error_code_t x, obc_gs_error_code_t y, const char * str);

int main (void) {
  printf("Reached!\n");
  packed_rs_packet_t encodedData = {0};
  uint8_t data[RS_DECODED_SIZE];
  memset(data, 0xFF, RS_DECODED_SIZE);
  initRs();
  ASSERT_EQ(rsEncode(data, &encodedData), 0, "rsEncode");
  // flip some bits
  encodedData.data[0] ^= 0b10000001;
  encodedData.data[222] ^= 0b10100011;
  uint8_t decodedData[RS_DECODED_SIZE];
  ASSERT_EQ(rsDecode(&encodedData, decodedData, RS_DECODED_SIZE), 0, "rsDecode");
  ASSERT_EQ(memcmp(decodedData, data, RS_DECODED_SIZE), 0, "decodedData");
}
/*
TEST(TestFecEncodeDecode, EncodeDecodeNonZero) {
  packed_rs_packet_t encodedData = {0};
  uint8_t data[RS_DECODED_SIZE];
  uint32_t seed = 0x7A21C3;  // random number
  for (uint16_t i = 0; i < RS_ENCODED_SIZE; ++i) {
    // Pseudorandom generation using a simple algorithm
    seed = (seed * 1103515245 + 12345) % (1 << 31);
    data[i] = (uint8_t)(seed & 0xFF);
  }
  initRs();
  ASSERT_EQ(rsEncode(data, &encodedData), 0, "rsEncode");
  // flip some bits
  encodedData.data[0] ^= 0b10000001;
  encodedData.data[222] ^= 0b10100011;
  uint8_t decodedData[RS_DECODED_SIZE];
  ASSERT_EQ(rsDecode(&encodedData, decodedData, RS_DECODED_SIZE), 0, "encodedData");
  ASSERT_EQ(memcmp(decodedData, data, RS_DECODED_SIZE), 0, "decodedData");
  destroyRs();
}*/

void ASSERT_EQ(obc_gs_error_code_t x, obc_gs_error_code_t y, const char * str) {
    if (x != y) {
        printf("[ERROR]: %s, %d not equal to %d\n", str, x, y);
    }
}

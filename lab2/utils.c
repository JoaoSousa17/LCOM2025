#include <lcom/lcf.h>
#include <stdint.h>

// Função usada na Primeira Função do Lab
int (util_sys_inb)(int port, uint8_t *value) {
  uint32_t res;
  if (sys_inb(port, &res) != 0) {
    printf("Erro ao ler a porta do Timer");
    return 1;
  }
  *value = res;
  return 0;
}

// Funções usadas na Segunda Função do Lab
int(util_get_LSB)(uint16_t val, uint8_t *lsb) {
  *lsb = (uint8_t) (val & 0xFF);
  return 0;
}

int(util_get_MSB)(uint16_t val, uint8_t *msb) {
  *msb = (uint8_t) ((val & 0xFF00) >> 8);
  return 0;
}

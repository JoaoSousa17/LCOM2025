#include <lcom/lcf.h>
#include <lcom/lab2.h>

#include <stdbool.h>
#include <stdint.h>

extern int timerCounter;

int main(int argc, char *argv[]) {
  lcf_set_language("PT-PT");
  lcf_trace_calls("/home/lcom/labs/lab2/trace.txt");
  lcf_log_output("/home/lcom/labs/lab2/output.txt");
  if (lcf_start(argc, argv)) return 1;
  lcf_cleanup();
  return 0;
}

// Exercício 1
int(timer_test_read_config)(uint8_t timer, enum timer_status_field field) {
  uint8_t st;
  if (timer_get_conf(timer, &st) != 0){
    printf("Erro ao obter configuração do Timer!");
    return 1;
  }

  if(timer_display_conf(timer, st, field) != 0){
    printf("Erro ao imprimir a configuracao do Timer!");
    return 1;
  }
  return 0;
}

// Exercício 2
int(timer_test_time_base)(uint8_t timer, uint32_t freq) {
  if (timer_set_frequency(timer, freq) != 0){
    printf("Erro ao alterar a frequência do Timer!");
    return 1;
  }
  return 0;
}

// Exercício 3
int(timer_test_int)(uint8_t time) {
  // Definição de variáveis
  int ipc_status;
  message msg;
  int r;
  uint8_t bit_no;
  timerCounter = 0;

  timer_subscribe_int(&bit_no); // Subscreve as interrupções
  uint8_t irq_set = BIT(bit_no);
  
  // Loop de verificação de existência de Interrupts
  while (timerCounter < time * 60) { 
      /* Get a request message. */
      if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0) {
          printf("driver_receive failed with: %d", r);
          continue;
      }
      if (is_ipc_notify(ipc_status)) { /* received notification */
          switch (_ENDPOINT_P(msg.m_source)) {
              case HARDWARE: /* hardware interrupt notification */
                  if (msg.m_notify.interrupts & irq_set) { /* subscribed interrupt */
                      timer_int_handler();
                      if (timerCounter % 60 == 0) {
                          timer_print_elapsed_time();
                      }
                  }
                  break;
              default:
                  break; /* no other notifications expected: do nothing */
          }
      } else { /* received a standard message, not a notification */
          /* no standard messages expected: do nothing */
      }
  }
  
  timer_unsubscribe_int(); // Deixa de subscrever as interrupções
  return 1;
}


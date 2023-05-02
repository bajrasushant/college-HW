#include <stdio.h>
#include <string.h>
#define MAX 100

typedef enum {
    q0, q1, q2, unknown 
}state;

typedef struct {
    state start;
    state end;
    char input;
}transition;

transition transitions[] = {
    {q0, q1, '1'},
    {q1, q2, '0'},
    {q2, q2, '0'},
    {q2, q2, '1'},
};

state start_state[] = { q0 };
state accepting_state[] = { q2 };
int start_state_num = 1;

int nfa_accept(state current_states[], int num_cur_states, char input_str[], 
                int input_len, int cur_input_i)
{
    state next_state[unknown];
    int num_next_state = 0;
    char cur_input = input_str[cur_input_i];
    for (int i = 0; i < num_cur_states; i++) {
        state cur_state = current_states[i];
        for (int j = 0; j < sizeof(transitions) / sizeof(transitions[0]); j++) {
            transition cur_transition = transitions[j];
            if (cur_transition.start == cur_state && 
                cur_transition.input == cur_input) {
                next_state[num_next_state++] = transitions[j].end;
            }
        }
    }
    
    if (cur_input_i == input_len - 1) {
        for (int i = 0; i < num_next_state; i++) {
            state cur_state = next_state[i];
            for (int j = 0; j < sizeof(accepting_state)/sizeof(accepting_state[0]);
 j++) {
                if (cur_state == accepting_state[j]) {
                    return 1;
                }
            }
        }
        return 0;
    }
    return nfa_accept(next_state, num_next_state, input_str, 
            input_len, cur_input_i + 1);
}

int main(void)
{
    printf("Enter string to be checked: ");
    char input_str[MAX];
    scanf("%s", input_str);
    int input_len = strlen(input_str);
    for (int i = 0; i < input_len; i++) {
        char input = input_str[i];
        if (input != '0' && input != '1') {
            printf("Enter a valid string in the alphabet (0, 1)\n");
            return 0;
        }
        }
    if (nfa_accept(start_state, start_state_num, input_str, input_len, 0))
    {
        printf("Accepted.\n");
    }else{
        printf("Rejected.\n");
    }
}

#include  <stdio.h>
typedef enum {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE} State;

int is_digit(char n)
{
    return (n >= '0' && n <= '9') || (n >= 'A' && n <= 'F') || (n >= 'a' && n <= 'f');
}

int is_sign(char n)
{
    return (n == '+' || n == '-');
}

int is_space(char n)
{
    return (n == ' ' || n == '\n' || n == ',' || n == EOF);
}

int main(void)
{
    int l;
    int c;
    State St = ONE;
    do {
        c = getchar();
        switch (St) {
            case ONE:
                if (is_sigh(c)) {
                    с = l;
                    St = TWO;
                } else if (is_digit(c)) {
                    с = l;
                    St = TWO;
                }
                break;

            case TWO:
                if (is_digit(с)) {
                   l = l * 10 + c
                   St = THREE;
                } else if (is_space(c)) {
                   St = ONE;
                }
                break;

             case THREE:
                if (is_digit(с)) {
                   l = l * 10 + c
                   St = FOUR;
                } else if (is_space(c)) {
                   St = ONE;
                }
                break;

              case FOUR:
                if (is_digit(с)) {
                   l = l * 10 + c
                   St = FIVE;
                } else if (is_space(c)) {
                   St = ONE;
                }
                break;

               case FIVE:
                if (is_digit(с)) {
                   l = l * 10 + c
                   St = SIX;
                } else if (is_space(c)) {
                   St = ONE;
                }
                break;

                case SIX:
                if (is_digit(с)) {
                   l = l * 10 + c
                   St = SEVEN;
                } else if (is_space(c)) {
                   St = ONE;
                }
                break;

                case SEVEN:
                if (is_digit(с)) {
                   l = l * 10 + c
                   St = EIGHT;
                } else if (is_space(c)) {
                   St = ONE;
                }
                break;

                 case EIGHT:
                if (is_digit(с)) {
                   l = l * 10 + c
                   St = NINE;
                } else if (is_space(c)) {
                   St = ONE;
                }
                break; 
           }
        } while (c != EOF);
        printf("%d\n", l);
        return 0;
}

// tixiTcQHV88U/hY

#include "s21_cat.h"

// #include <stdio.h>
// #include <stdlib.h>
struct Flagses;
void reader(char **argv);

// int main(int argc, char *argv[]) {
//   reader(*argv);
// int opt;

// put ':' in the starting of the
// string so that program can
// distinguish between '?' and ':'
// while ((opt = getopt(argc, argv, "    ")) != -1) {
//   switch (opt) {
//     case ‘i’:

//       break;
//   }
// }

// // optind is for the extra arguments
// // which are not parsed
// for (; optind < argc; optind++) {
//   printf(“extra arguments : % s\n”, argv[optind]);
// }

// return 0;
//}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    puts("Not enought arguments.\nTry harder.");
    // return 1;
  }

  while (optind < argc) {
    reader(argv);
    optind++;
  }
  return 0;
}
void reader(char **argv) {
  FILE *file = fopen(argv[optind], "r");
  if (file != NULL) {
    int last = '\n', str_count = 0, empty_str_count = 0;
    while (!feof(
        file)) {  // пока не доходит до eof он печатает посимвольно текст из ch
      int ch = fgetc(file);  // ch содержит в себе fgetc
      if (ch == EOF) break;

      printf("%c", ch);  // он у нас принтит посимвольно до момента пока не
                         // дойдет до eof.
    }
    fclose(file);
  }
}

typedef struct Flagses {
  int b, e, n, s, t, v, E, T
} flgs;

int parser(int argc, char *argv[], flgs *Flagses) {
  int getoptReturnValue = 0;  // хранит возвращаемое значение гетопт
  const char *optstring = "+bestvET";
  static struct longopts[] = {{"number-nonblank", 0, 0, 'b'},
                              {"number", 0, 0, 'n'},
                              {"squeeze-blank", 0, 0, 's'},
                              {0, 0, 0, 0}};

  while (getoptReturnValue =
             (getopt_long(argc, argv, optstring, longopts, NULL) != -1)) {
    switch (getoptReturnValue) {
      case 'e':
        flage->1;
        break;

        // case 'b':
        //   flagb;
        //   break;

        // case 's':
        //   flags;
        //   break;

        // case 't':
        //   flagt;
        //   break;

        // case 'v':
        //   flag;
        //   break;

        // case 'E':
        //   flagE;
        //   break;

        // case 'T':
        //   flagT;
        //   break;

      default:  // Код, который выполнится, если ни одно из константых значению
                // не
        puts("try another flag.");  // соответствует значение в переменной
                                    // getoptReturnValue

        // exit();  // разобраться в экзите(который слева 83я строчка exit()
    }
  }
}

void flage(char ch) {
  if ("%c" == "\n") printf("$");
}
// tixiTcQHV88U/hY

#include "s21_cat_last.h"

int parser(int argc, char *argv[], flags *flg) {
  int getoptReturnValue = 0;  // хранит возвращаемое значение гетопт
  const char *optstring =
      "+bestvET";  // тут мы поставили плюс для того, сто бы при встрече файла
                   // программа перестала считывать все флаги, которые идут
                   // после
  static struct option longOpts[] = {
      {"number-nonblank", 0, 0, 'b'},
      {"number", 0, 0, 'n'},
      {"squeeze-blank", 0, 0, 's'},
      {0, 0, 0, 0},
  };
  while (getoptReturnValue ==
         (getopt_long(argc, argv, optstring, longOpts, NULL) != -1)) {
    switch (getoptReturnValue) {
      case 'b':
        flg->b = ON;
        break;

      case 'e':
        flg->e = ON;
        flg->v = ON;
        break;

      case 's':
        flg->s = ON;
        break;

      case 't':
        flg->t = ON;
        flg->v = ON;

        break;

      case 'v':
        flg->v = ON;
        break;

      case 'E':
        flg->E = ON;
        break;

      case 'T':
        flg->T = ON;
        break;

      default:  // Код, который выполнится, если ни одно из константых значению
                // не
        puts("try another flag.");  // соответствует значение в переменной
                                    // getoptReturnValue

        exit(0);  // разобраться в экзите(который слева 83я строчка exit()
    }
  }
  return 0;
}

void reader(char **argv, flags *flg) {
  FILE *file =
      fopen(argv[optind],
            "r");  // В данном коде optindиспользуется для отслеживания индекса
                   // следующего аргумента, подлежащего обработке в argvмассиве.
                   // Это глобальная переменная, определяемая функцией getopt.
  if (file != NULL) {
    int last = '\n', str_count = 0, empty_str_count = 0;
    while (!feof(
        file)) {  // пока не доходит до eof он печатает посимвольно текст из ch
      int ch = fgetc(file);  // ch содержит в себе fgetc
      if (ch == EOF) break;
      if (flg->s) {
        if ((empty_str_count = flagS(ch, last, empty_str_count)) > 1) continue;
      }
      if (flg->b) {
        str_count = flagB(ch, last, str_count);
      }
      if (flg->n) {
        str_count = flagN(last, str_count);
      }
      if (flg->t) {
        ch = flagT(ch);
      }
      if (flg->e) {
        flagE(ch);
      }
      if (flg->v) {
        ch = flagV(ch);
      }
      printf("%c", ch);  // он у нас принтит посимвольно до момента пока не
      last = ch;         // дойдет до eof.
    }
    fclose(file);
  } else {
    exit(1);
  }
}

// -b (GNU: --number-nonblank)
// нумерует только непустые строки

// 2
// -e предполагает и -v (GNU only: -E то же самое, но без применения -v)
// также отображает символы конца строки как $

// 3
// -n (GNU: --number)
// нумерует все выходные строки

// 4

// 5
// -t предполагает и -v (GNU: -T то же самое, но без применения -v)
// также отображает табы как ^I

void flagE(char ch) {
  if (ch == '\n') printf("$");
}

int flagB;

void flagV;

// -s (GNU: --squeeze-blank)
// сжимает несколько смежных пустых строк
int flagS(int ch, int empty_str_count, char last) {
  while (empty_str_count = 2) {
  }
}

void flagN;

char flagT(int ch) {  // почему чар???
  if (ch == '\t') {
    printf("^");
    ch == '|';
  }
}

int main(int argc, char *argv[]) {
  flags flg = {OFF};
  if (argc < 2) {
    puts("Not enought arguments.\nTry harder.");
    exit(0);
  }
  parser(argc, argv, &flg);

  while (optind < argc) {
    reader(argv);
    optind++;
  }

  return 0;
}
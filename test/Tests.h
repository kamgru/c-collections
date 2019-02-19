#define _fail() printf("\t[FAIL]\t%s, line %d\n", __func__, __LINE__)
#define _assert(test) if (!(test)) { _fail(); return 1;}
#define _verify(test) if (test() == 0) { printf("\t[OK]\t%s\n", #test); }
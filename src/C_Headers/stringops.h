#ifndef __STRINGOPS_H
#define __STRINGOPS_H
#ifdef __cplusplus
extern "C" {
#endif

char *subStr(const char *string, unsigned int startPos, unsigned int endPos);
char *strreverse(const char *string);
char *strip(const char *string);
char *reduce(const char *string, int reduceAllWhitespace);
char *lower(const char *string);
int frequency(const char *string, char substring);
int findPos(const char *string, char substring);
char **tokenize(const char *string);

#ifdef __cplusplus
}
#endif
#endif

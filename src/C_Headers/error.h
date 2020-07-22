#ifndef __ERROR_H
#define __ERROR_H
#ifdef __cplusplus
extern "C" {
#endif

enum errorTypes {Generic, Interpreter, Warning, Fatal};
void checkErr();
void err(short cWarn, const char *message);

#ifdef __cplusplus
}
#endif
#endif

#ifndef VERIFY_H
#define VERIFY_H 1
#   if NDEBUG
#       define verify(condition) ((void)0)
#   else
#       define verify(condition) \
            do\
            {\
                if (!(condition))\
                {\
                    cerr << __FILE__ << ":" << __LINE__ << ": error: In function " \
                         << __func__ << ", verification of condition " << #condition <<" failed.";\
                }\
            } while (0)
#   endif
#endif
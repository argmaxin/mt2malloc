#if !defined(MT2MALLOC_H)
#  define MT2MALLOC_H

#  include <stddef.h>
#  include <limits.h>

#  define MT2N_NFNODE INT_MIN
#  define MT2N_CALLEE (INT_MIN + 1)

#  define MT2N_NFOUND -1
#  define MT2N_NRFREE -2
#  define MT2N_UKFREE -3
#  define MT2N_NABIND -4
#  define MT2N_UNBIND -5
#  define MT2N_MEMMAP -6
#  define MT2N_NSETUP -7
#  define MT2N_NFNUMA -8

#  define MT2F_NON 0x00U
#  define MT2F_REO 0x01U
#  define MT2F_WAO (MT2F_REO << 1U)
#  define MT2F_CRT (MT2F_WAO << 1U)
#  define MT2F_TMP (MT2F_CRT << 1U)
#  define MT2F_POP (MT2F_TMP << 1U)
#  define MT2F_SHR (MT2F_POP << 1U)
#  define MT2F_PRV (MT2F_SHR << 1U)
#  define MT2F_RWO (MT2F_REO | MT2F_WAO)

#  define MT2S_GUSEDM 0x1
#  define MT2S_GFREEM (MT2S_GUSEDM << 1U)
#  define MT2S_GPAGEM (MT2S_GFREEM << 1U)
#  define MT2S_GTHPVM (MT2S_GPAGEM << 1U)
#  define MT2S_GMGAPS (MT2S_GTHPVM << 1U)
#  define MT2S_GINPTR (MT2S_GMGAPS << 1U)
#  define MT2S_GDNUMA (MT2S_GINPTR << 1U)
#  define MT2S_SINPTR (MT2S_GDNUMA << 1U)
#  define MT2S_SDNUMA (MT2S_SINPTR << 1U)

typedef int          mt2nid_t;
typedef unsigned int mt2stat_t;
typedef unsigned int mt2mode_t;

void* mt2malloc(size_t);
void* mt2calloc(size_t, size_t);
void* mt2falloc(char*, size_t*, char**, mt2mode_t);
void* mt2realloc(void*, size_t);
void mt2free(void*);
int mt2error(void);

mt2nid_t mt2bindgen(long);
int mt2mbind(mt2nid_t);
int mt2munbind(mt2nid_t);
int mt2stat(mt2stat_t, size_t*, size_t*, size_t*);
int mt2nstat(mt2nid_t, mt2stat_t, size_t*, size_t*, size_t*);

void* mt2nmalloc(mt2nid_t, size_t);
void* mt2ncalloc(mt2nid_t, size_t, size_t);
void* mt2nfalloc(mt2nid_t, char*, size_t*, char**, mt2mode_t);
void* mt2nrealloc(mt2nid_t, mt2nid_t, void*, size_t);
int mt2nfree(mt2nid_t, void*);
int mt2nerror(mt2nid_t);

#endif

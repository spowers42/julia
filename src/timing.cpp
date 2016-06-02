#include "julia.h"

#ifdef ENABLE_TIMINGS
jl_timing_block_t *jl_root_timing;
uint64_t jl_timing_data[(int)JL_TIMING_LAST] = {0};
char *jl_timing_names[(int)JL_TIMING_LAST] =
    {
#define X(name) #name
        JL_TIMING_OWNERS
#undef X
    };

extern "C" void jl_print_timings(void)
{
    uint64_t total_time = 0;
    for (int i = 0; i < JL_TIMING_LAST; i++)
        total_time += jl_timing_data[i];
    for (int i = 0; i < JL_TIMING_LAST; i++) {
        printf("%-25s : %.2f %%   %lu\n", jl_timing_names[i], 100*(((double)jl_timing_data[i])/total_time), jl_timing_data[i]);
    }
}
#endif

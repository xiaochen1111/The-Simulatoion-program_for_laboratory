#include "IBC_close_loop_capi_host.h"
static IBC_close_loop_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        IBC_close_loop_host_InitializeDataMapInfo(&(root), "IBC_close_loop");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}

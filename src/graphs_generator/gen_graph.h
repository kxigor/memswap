#ifndef GEN_GRAPH_H
#define GEN_GRAPH_H

#include "../dirs/dirs.h"

extern const char* signature_names  ;
extern const char* signature_path   ;

extern const char* temp_script_pwd  ;

void ScriptGraph(
    const char* result_dir,
    const char* graph_pwd ,
    const char* footage_pwd
);

#endif // !GEN_GRAPH_H